/*20210123 16:18,zyj,GuangDong*/
#include <iostream>
#include <fstream>
#include "release_info.h"

#ifdef _WIN32
#include <Windows.h> 

/** get system version name down 8.1*/ 
#ifdef DOWN
void win_get_sysname_down(std::string& osname)  
{  
	using namespace std;
	SYSTEM_INFO info;  
	GetSystemInfo(&info); 
	OSVERSIONINFOEX os;   
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);     

	osname = "Unknown Microsoft Windows Version";  

	if(GetVersionEx((OSVERSIONINFO *)&os))  
	{   
		//下面根据版本信息判断操作系统名称
		cout<<"mainVersion:"<<os.dwMajorVersion<<";secondVersion:"<<os.dwMinorVersion<<endl;
		switch(os.dwMajorVersion)//判断主版本号  
		{  
			case 4:  
				switch(os.dwMinorVersion)//判断次版本号   
				{   
					case 0:  
						if(os.dwPlatformId==VER_PLATFORM_WIN32_NT)  
						  osname = "Microsoft Windows NT 4.0"; 
						else if(os.dwPlatformId==VER_PLATFORM_WIN32_WINDOWS)  
						  osname ="Microsoft Windows 95";  
						break;  
					case 10:  
						osname ="Microsoft Windows 98";  
						break;  
					case 90:  
						osname ="Microsoft Windows Me";  
						break;  
				}  
				break;  

			case 5:  
				switch(os.dwMinorVersion)
				{   
					case 0:  
						osname ="Microsoft Windows 2000"; 
						break;  

					case 1:  
						osname ="Microsoft Windows XP";
						break;  

					case 2:  
						if(os.wProductType==VER_NT_WORKSTATION   
									&& info.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64)  
						{  
							osname ="Microsoft Windows XP Professional x64 Edition";  
						}  
						else if(GetSystemMetrics(SM_SERVERR2)==0)  
						  osname ="Microsoft Windows Server 2003"; 
						else if(GetSystemMetrics(SM_SERVERR2)!=0)  
						  osname ="Microsoft Windows Server 2003 R2";  
						break;  
				}  
				break;  

			case 6:  
				switch(os.dwMinorVersion)  
				{  
					case 0:  
						if(os.wProductType == VER_NT_WORKSTATION)  
						  osname ="Microsoft Windows Vista";  
						else  
						  osname ="Microsoft Windows Server 2008";   
						break;  
					case 1:  
						if(os.wProductType == VER_NT_WORKSTATION)  
						  osname ="Microsoft Windows 7";  
						else  
						  osname ="Microsoft Windows Server 2008 R2";  
						break;
					case 2:
						if(os.wProductType == VER_NT_WORKSTATION)
						  osname = "Microsoft Windows 8";
						else  
						  osname = "Microsoft Windows Server 2012";  
						break;
				}  
				break;  
		}  
	}
}
#else
/** get system version name not down 8.1*/ 
void win_get_sysname_up(std::string& vname)  
{  
	//先判断是否为win8.1或win10 
	using namespace std; 
	typedef void(__stdcall*NTPROC)(DWORD*, DWORD*, DWORD*);  
	HINSTANCE hinst = LoadLibrary("ntdll.dll");  
	DWORD dwMajor, dwMinor, dwBuildNumber;  
	NTPROC proc = (NTPROC)GetProcAddress(hinst, "RtlGetNtVersionNumbers");   
	proc(&dwMajor, &dwMinor, &dwBuildNumber); 
	vname = "Unknown Microsoft Windows Version";  
	cout<<"mainVersion:"<<dwMajor<<";secondVersion:"<<dwMinor<<";buildNumber:"<<dwBuildNumber<<endl;
	if (dwMajor == 6 && dwMinor == 3)   //win 8.1  
	{
		if(dwBuildNumber == WINVERSION_2012)
		{
			vname = "Microsoft Windows Server 2012 R2";
		}
		else
		{
			vname = "Microsoft Windows 8.1";
		}
		return;  
	}  
	else if (dwMajor == 10 && dwMinor == 0)  //win 10  
	{
		if(dwBuildNumber == WINVERSION_10)
		{
			vname = "Microsoft Windows 10";
		}
		else
		{
			vname = "Microsoft Windows Server 2016";
		}
		return;
	} 
}
#endif// DOWN

#endif// WIN32

#if __linux__
void linux_get_system_name(std::string &vname)
{
	using namespace std;
	ifstream fin;
	char buf[128];
	string filename("/etc/issue.net");

	fin.open(filename);
	if(!fin.is_open())
	{
		cout << "cannot open file: /etc/issue.net" << endl;
		vname = "Unknown Linux Release Version";
		return;
	}
	fin.getline(buf, 128);
	while (!fin.fail()) // test for EOF
	{
		vname += buf;
		fin.getline(buf, 128); 
	}
	if(vname.length() == 0)
	  vname = "Unknown Linux Release Version";
}
#endif 

void release_info(std::string &info)
{
#if __linux__
	linux_get_system_name(info);
#elif _WIN32
#ifdef DOWN
	win_get_sysname_down(info);
#else 
	win_get_sysname_up(info);
#endif
#endif
}

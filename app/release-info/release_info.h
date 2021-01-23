/*20210123 16:18,zyj,GuangDong*/
#ifdef _WIN32
#define WINVERSION_2012 4026541440 //Microsoft Windows Server 2012 R2 的BuildNumber号
#define WINVERSION_10 4026546233 //Microsoft Windows 10 的BuildNumber号
//#define DOWN 1

#ifdef DOWN
/** get system version name down 8.1*/  
void win_get_sysname_down(std::string& osname); 
#else
/** get system version name not down 8.1 */ 
void win_get_sysname_up(std::string& vname);
#endif

#endif//win

#if __linux__
void linux_get_system_name(std::string &vname);
#endif// linux 

/*get os version name*/
void release_info(std::string &info);

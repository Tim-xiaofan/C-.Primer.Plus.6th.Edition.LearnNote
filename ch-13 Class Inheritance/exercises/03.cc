#include <iostream>
#include <vector> 
#include <memory>
#include "dma.h"

using std::cout;
using std::endl;
using std::vector;
using dma_ptr = std::shared_ptr<abcDMA>;

int main(void)
{
	vector<dma_ptr> dmas;
	dmas.emplace_back(new baseDMA());
	dmas.emplace_back(new lacksDMA());
	dmas.emplace_back(new hasDMA());
	for(const dma_ptr ptr: dmas)
	{
		ptr->type();
		ptr->view();
	}
	return 0;
}

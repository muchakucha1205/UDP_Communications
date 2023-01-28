#include "simple_udp.hpp"

int main() {
    simple_udp *rx;
    rx=new simple_udp(IP_ADDRESS,PORT_NUMBER);
	std::string data;
	rx->udp_bind();
    do{
		data=rx->udp_recv();
		std::cout << data << std::endl;
	}while(data!="end");
    delete rx;
    return 0;
}
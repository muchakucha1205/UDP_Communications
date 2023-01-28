#include "simple_udp.hpp"

int main() {
    simple_udp *tx;
    tx=new simple_udp(IP_ADDRESS,PORT_NUMBER);
	std::cout << "IP_ADDRESS=" << IP_ADDRESS << std::endl;
	std::cout << "PORT_NUMBER=" << PORT_NUMBER << std::endl;

	std::string data = "test";
	for(int cnt=0;cnt<100;cnt++){
		// if(cnt%20==0){
			tx->udp_send(data);
		// }
		if(cnt>40){
			data="end";
		}
		Sleep(100);
	}

    delete tx;
    return 0;
}
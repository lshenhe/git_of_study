//
//  Pubsub envelope subscriber
//

#include "zhelpers.hpp"
#include "examples.pb.h"

int main () {
    //  Prepare our context and subscriber
    zmq::context_t context(1);
    zmq::socket_t subscriber (context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:5563");
    subscriber.setsockopt( ZMQ_SUBSCRIBE, "B", 1);

    auto msg1 = std::make_shared<Chatter>();

    while (1) {
 
		//  Read envelope with address
		std::string address = s_recv (subscriber);
		//  Read message contents
		std::string contents = s_recv (subscriber);
        std::shared_ptr<std::string> msg_str = std::make_shared<std::string>(contents);
        msg1->ParseFromString(*msg_str);
		
        std::cout << "[" << address << "] " << msg1->message() << std::endl;
    }
    return 0;
}

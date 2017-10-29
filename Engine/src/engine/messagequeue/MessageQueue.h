#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <map>
#include <vector>

#include <messagequeue\MessageTypes.h>

struct Message {
	void* callback;
	void* context;
	bool onceOnly;
};

class MessageQueue
{
public:
	static void publishEvent(char* eventId, Message& payload);
	static void registerEvent(char* eventId, Message& payload);


	static MessageQueue* get() {
		if (singleton == nullptr) {
			singleton = new MessageQueue;
		}
		return singleton;
	}
private:
	MessageQueue() {};
	static MessageQueue* singleton;
	static std::map<const char*, std::vector<Message>*> m_mapMessages;
};

#endif
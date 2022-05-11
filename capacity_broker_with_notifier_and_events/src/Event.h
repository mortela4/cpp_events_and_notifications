#ifndef EVENT_H_
#define EVENT_H_

#include <string>


namespace notification_event
{

	struct Event
	{
	public:
		const std::string& objectType;
		const std::string& fromName;
		const std::string& eventMsg;		// TODO: add field of 'enum class' type??

		Event(const std::string& typeName, const std::string& objName, const std::string& msg) : objectType(typeName), fromName(objName), eventMsg(msg){};
	};

}




#endif /* EVENT_H_ */

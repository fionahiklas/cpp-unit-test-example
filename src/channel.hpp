
#include <string>


class Channel
{
public:
  Channel(std:string channel_name);
  std::string get_channel_name();
  
private:
  std::string channel_name;
}

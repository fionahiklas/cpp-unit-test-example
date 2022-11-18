#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ChannelTest
#include <boost/test/unit_test.hpp>

#include "channel.hpp"

BOOST_AUTO_TEST_CASE(create_channel_test)
{
  std::string test_channel_name("Hello");
  Channel test_channel(test_channel_name);
  BOOST_TEST( test_channel_name.compare(test_channel.get_channel_name()) == 0 );
}

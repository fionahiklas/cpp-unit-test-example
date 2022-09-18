
#define BOOST_TEST_MODULE Channel Test
#include <boost/test/unit_test>

#include <channel>

BOOST_AUTO_TEST_CASE(create_channel_test)
{
  Channel test_channel("Hello");
  BOOST_TEST(test_channel != null);
}

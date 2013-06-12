#include "json2pb.h"
#include "test.pb.h"

#include <stdio.h>

const char json[] = "{\"_str\":\"b\", \"id\":1, \"_bin\":\"0a0a0a\", \"_bool\":true, \"sub\":{\"field\":\"subfield\"}, \"_int\":[10, 20, 30, 40], \"_enum\": \"VALUE1\"}";

using google::protobuf::Message;

int main()
{
	test::ComplexMessage msg;
	json2pb(msg, json, sizeof(json)-1);
	printf("Message: %s\n", msg.DebugString().c_str());
	printf("JSON: %s\n", pb2json(msg).c_str());
}

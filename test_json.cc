#include "json2pb.h"
#include "test.pb.h"

#include <stdio.h>
#include <stdio.h>

using google::protobuf::Message;

int main()
{
	char buf[8192];
	FILE * fp = fopen("test.json", "r");
	size_t size = fread(buf, 1, 8192, fp);
	fclose(fp);

	test::ComplexMessage msg;
	json2pb(msg, buf, size);
	//msg.SetExtension(test::e_bool, false);
	printf("Message: %s\n", msg.DebugString().c_str());
	printf("JSON: %s\n", pb2json(msg).c_str());
}

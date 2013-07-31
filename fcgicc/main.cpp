#include <cstdlib>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPResponseHeader.h"
#include "cgicc/HTMLClasses.h"
#include "FCgiIO.hpp"

int main(int argc, char **argv)
{
	using namespace std;
	using namespace cgicc;

	if (argc < 2) exit(1);

	FCGX_Request request;
	FCGX_Init();
	FCGX_InitRequest(&request, 0,0);

	while(FCGX_Accept_r(&request) == 0)
	{
		try
		{
			FCgiIO io(request);
			Cgicc cgi(&io);

			HTTPResponseHeader resp("Status:", 200, "OK");
			resp.addHeader("Content-Type", "text/html");
			io << "<html><title>CGICC TEST</title><body>test</body></html>";
		} 
		catch (std::exception const &e)
		{
		}
		FCGX_Finish_r(&request);
	}
	return 0;
}

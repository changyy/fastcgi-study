#include <stdlib.h>
#include <fcgi_stdio.h>

#define CGI_HEAD_BODY_SEPARATOR	"\r\n\r\n"
#define	CGI_CONTENT_TYPE_TEXT_HTML "Content-type: text/html"
#define CGI_CONTENT_TYPE_APPLICATION_JSON "Content-type: application/json"	
#define CGI_WELCOME_HEAD CGI_CONTENT_TYPE_TEXT_HTML
#define CGI_WELCOME_BODY \
"<html>\
	<head>\
		<title>Hello FastCGI</title>\
	</head>\
	<body>\
		<h1>Hello FastCGI</h1>\
	</body>\
</html>"

int main(int argc, char** argv)
{
	int count = 0;
	while(FCGI_Accept() >= 0)
	{
		printf(
			CGI_WELCOME_HEAD
			CGI_HEAD_BODY_SEPARATOR
			CGI_WELCOME_BODY
		);
	}
	return 0;
}

#include "json_parse.h"

void json_message(long content_name, char *type, char **message)
{
	char* initial_string="{\"CONTENT NAME\":";
	char* content_string=malloc(100);
	sprintf(content_string, "\"%ld\"", content_name);

	size_t message_len = strlen(initial_string) + 1; // + 1 for terminating NULL
	/*char */ *message = (char*) malloc(message_len);
	strncat(*message, initial_string, message_len);

	message_len +=strlen(content_string); // the content name
	*message = (char*) realloc(*message, message_len);
	strncat(*message, content_string, message_len);

	char* action=malloc(100*sizeof(char));
	sprintf(action, "\"type\":\"%s\"}", type);

	message_len += 1 + strlen(action); // 1 + for separator ','
	*message = (char*) realloc(*message, message_len);
    strncat(strncat(*message, ",", message_len), action, message_len);
}
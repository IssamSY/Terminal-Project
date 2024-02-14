#include<stdio.h>
#include<string.h>
#include "SysFile.h"

int main() {
	// Creating files using `struct File`
	struct File systemf;
	strcpy(systemf.name, "systemf.txt");
	strcpy(systemf.content, "The System F version 1.2.2");

	struct File user_info;
	strcpy(user_info.name, "user_info.txt");
	strcpy(user_info.content, "The username: _____");

	// Creating `sysbin` directory using `struct Directory`
	struct Directory sysbin;
	snprintf(sysbin.name, sizeof(sysbin.name), "sysbin");

	// Adding `systemf.txt` file to `sysbin` directory in position 0
	strcpy(sysbin.files[0].name, systemf.name);
	strcpy(sysbin.files[0].content, systemf.content);

	// Creating `user` directory using `struct Directory`
	struct Directory user;
	snprintf(user.name, sizeof(user.name), "user");

	// Adding `user_info.txt` to `user` directory in position 0
	strcpy(user.files[0].name, user_info.name);
	strcpy(user.files[0].content, user_info.content); 

	// Creating `root` MegaDirectory using `struct MegaDirectory`
	struct MegaDirectory root;
	snprintf(root.name, sizeof(root.name), "root");

	// Adding `sysbin` directory to `root` mega-directory in position 0
	strcpy(root.directories[0].name, sysbin.name);
	memcpy(&root.directories[0].files, &sysbin.files, sizeof(sysbin.files));

	// Adding `user` directory to `root` mega-directory in position 1
	strcpy(root.directories[0].name, user.name);
	memcpy(&root.directories[0].files, &user.files, sizeof(user.files));

	
 }

#include <iostream>
#include <fstream>
//#include "sample.css"

using namespace std;

struct image
{
	std::string location;
	std::string height;
	std::string width;
	std::string allign;
};

//****function prototype****
std::string configHeader (std::string);
std::string configBody (std::string,std::string,image,std::string);
std::string configFooter (std::string);

int main()
{
	std::string output;
	ofstream htmlFile,cssFile;
	htmlFile.open("index.html");
	output=configHeader("My Blog");
	htmlFile<<output;
	output=configBody("Biruk Amlaku","Computer Scientist",{"/media/filesystem/Pictures/Picasa/snapshot.jpg","23","23","left"},"Hello my name is biruk amlaku\nI am one of the best hackers in the world");
	htmlFile<<output;
	output=configFooter("&copy 2015 all rights reserved");
	htmlFile<<output;
}//main

std::string configHeader (std::string title)
{
	std::string output="<!DOCTYPE html>\n<!--This doc is created by the program that is coded by\nAdil Mohammednur\nAnteneh Tesfaye\nBiruk Amlaku\nEba Birhanu\nand Feyduruman Shikuri-->\n<html>\n<head>\n<meta charset=\"UTF-8\" />\n<title>";
	output.append(title);
	output.append("</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"");
	output.append(title);
	output.append(".css\" />\n</head>\n");
	return output;
}//configheader

std::string configBody (std::string header1,std::string header2,image profile,std::string paragraph)
{
	std::string output;
	output="<body>\n<h1>";
	output.append(header1);
	output.append("</h1>\n");
	output.append("<h3>");
	output.append(header2);
	output.append("</h3>\n");
	if (!profile.location.empty())
	{
		output.append("<img src=\"");
		output.append(profile.location);
		output.append("\" width=\"");
		output.append(profile.width);
		output.append("%\" height=\"");
		output.append(profile.height);
		output.append("%\" class=\"float-");
		output.append(profile.allign);
		output.append("\" />\n");
	}
	output.append("<pre>");
	output.append(paragraph);
	output.append("</pre>\n</body>\n");
	return output;
}//configBody

std::string configFooter (std::string footText)
{
	std::string output;
	output="<footer>\n<pre>";
	output.append(footText);
	output.append("</pre>\n</footer>\n</html>\n");
	return output;
}//configFooter
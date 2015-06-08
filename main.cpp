#include <fstream>

using namespace std;

struct image
{
	string location;
	string height;
	string width;
	string allign;
};//struct image

struct font
{
	string size;
	string color;
	string family;
	string align;
	string margin;
	//bool bold;
	//bool italic;
};//struct font

struct css
{
	string bgImage;
	string headerBgColor;
	string bodyBgColor;
	string footerBgColor;
	font h1;
	font h2;
	font pre;
	font footer;
};//struct css

//****function prototype****
string configHeader (string);
string configBody (string,string,image,string);
string configFooter (string);
string configCss (css);


int main()
{
	string output;
	ofstream htmlFile,cssFile;
	
	htmlFile.open("index.html");
	cssFile.open("biruk.css");
	output=configHeader("biruk");
	htmlFile<<output;
	output=configBody("Biruk Amlaku","Computer Scientist",{"/media/filesystem/Pictures/Picasa/snapshot.jpg","23","23","left"},"Hello my name is biruk amlaku\nI am one of the best hackers in the world");
	htmlFile<<output;
	output=configFooter("&copy 2015 all rights reserved");
	htmlFile<<output;
	css csstest;
	csstest.headerBgColor="grey";
	csstest.bodyBgColor="blue";
	csstest.footerBgColor="yellow";
	csstest.h1.size="150";
	csstest.h1.color="blue";
	csstest.h1.family="tahoma";
	csstest.h1.align="left";
	csstest.h1.margin="0";
	csstest.h2.size="120";
	csstest.h2.color="black";
	csstest.h2.family="tahoma";
	csstest.h2.align="left";
	csstest.h2.margin="0";
	csstest.pre.size="60";
	csstest.pre.color="grey";
	csstest.pre.family="tahoma";
	csstest.pre.align="center";
	csstest.pre.margin="0";
	csstest.footer.size="30";
	csstest.footer.color="green";
	csstest.footer.family="tahoma";
	csstest.footer.align="center";
	csstest.footer.margin="0";
	output=configCss(csstest);
	cssFile<<output;
	
	return 0;
}//main

string configHeader (string title)
{
	string output="<!DOCTYPE html>\n<!--This doc is created by the program that is coded by\nAdil Mohammednur\nAnteneh Tesfaye\nBiruk Amlaku\nEba Birhanu\nand Feyduruman Shikuri-->\n<html>\n<head>\n<meta charset=\"UTF-8\" />\n<title>";
	output.append(title);
	output.append("</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"");
	output.append(title);
	output.append(".css\" />\n</head>\n");
	return output;
}//configheader

string configBody (string header1,string header2,image profile,string paragraph)
{
	string output;
	output="<body id=\"mainbody\">\n<div id=\"top-menu\">\n<h1>";
	output.append(header1);
	output.append("</h1>\n");
	output.append("<h3>");
	output.append(header2);
	output.append("</h3>\n</div>\n");
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

string configFooter (string footText)
{
	string output;
	output="<footer>\n<pre>";
	output.append(footText);
	output.append("</pre>\n</footer>\n</html>\n");
	return output;
}//configFooter

string configCss (css main)
{
	string cssOutput;
	//***********bg image css config*************
	cssOutput="/* sample.css by: Biruk Amlaku\nversion: 1.0\ndate: jun-8-2015\n*/\nbody\n{\nbackground-image: url(\"";
	if (!main.bgImage.empty())
	{
		cssOutput.append(main.bgImage);
	}
	cssOutput.append("\");\n}\n");
	//**********h1 css config***********
	cssOutput.append("h1\n{\nfont-family:\"");
	cssOutput.append(main.h1.family);
	cssOutput.append(";\nfont-size:");
	cssOutput.append(main.h1.size);
	cssOutput.append(";\ncolor:");
	cssOutput.append(main.h1.color);
	cssOutput.append(";\nmargin:");
	cssOutput.append(main.h1.margin);
	cssOutput.append(";\ntext-align:");
	cssOutput.append(main.h1.align);
	cssOutput.append(";\n}\n");

	//**********h2 css config**********
	cssOutput.append("h2\n{\nfont-family:\"");
	cssOutput.append(main.h2.family);
	cssOutput.append(";\nfont-size:");
	cssOutput.append(main.h2.size);
	cssOutput.append(";\ncolor:");
	cssOutput.append(main.h2.color);
	cssOutput.append(";\nmargin:");
	cssOutput.append(main.h2.margin);
	cssOutput.append(";\ntext-align:");
	cssOutput.append(main.h2.align);
	cssOutput.append(";\n}\n");

	//***********pre css config**********
	cssOutput.append("pre\n{\nline-height: 1.4;\nfont-family:\"");
	cssOutput.append(main.pre.family);
	cssOutput.append(";\nfont-size:");
	cssOutput.append(main.pre.size);
	cssOutput.append(";\ncolor:");
	cssOutput.append(main.pre.color);
	cssOutput.append(";\nmargin:");
	cssOutput.append(main.pre.margin);
	cssOutput.append(";\n}\n");

	//**********id #top-menu css config*************
	cssOutput.append("/* div Header */\ndiv#top-menu{\nwidth:100%;\nheight:120px;\nbackground-color:");
	cssOutput.append(main.headerBgColor);
	cssOutput.append(";margin:0;\npadding:0;\n}\n");

	//**********image float class css config*************
	cssOutput.append("/* image float */\n.float-left\n{\nfloat:left;\nmargin-right:10px;\nmargin-left:10px;\n}\n.float-right\n{\nfloat:right;\nmargin-left:10px;\nmargin-right:10px;\n}\n");

	//**************body css config****************
	cssOutput.append("/* mainbody */\n#mainbody\n{\nwidth: 85%;\nmargin: 0 auto;\nmargin-top: 15px;\nmargin-bottom: 15px;\nbackground-color:");
	cssOutput.append(main.bodyBgColor);
	cssOutput.append(";\n}\n");

	//*************footer css config**************
	cssOutput.append("/* footer */\nfooter\n{\nbackground:");
	cssOutput.append(main.footerBgColor);
	cssOutput.append(";\n}\n");
	cssOutput.append("footer pre\n{\npadding: 8px 0;\nfont-family:\"");
	cssOutput.append(main.footer.family);
	cssOutput.append(";\nfont-size:");
	cssOutput.append(main.footer.size);
	cssOutput.append(";\ncolor:");
	cssOutput.append(main.footer.color);
	cssOutput.append(";\nmargin:");
	cssOutput.append(main.footer.margin);
	cssOutput.append(";\ntext-align:");
	cssOutput.append(main.footer.align);
	cssOutput.append(";\n}\n");

	//*********************return css**********************
	return cssOutput;
}//config css
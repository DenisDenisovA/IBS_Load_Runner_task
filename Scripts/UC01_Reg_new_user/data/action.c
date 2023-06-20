Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("MSO=SID&1683018068; DOMAIN=localhost");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"112\", \"Google Chrome\";v=\"112\", \"Not:A-Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("Open_sign_up_now");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Open_sign_up_now",LR_AUTO);

	lr_start_transaction("Filling_out_the_form");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_submit_data("login.pl_2", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=testname", ENDITEM, 
		"Name=password", "Value=1234", ENDITEM, 
		"Name=passwordConfirm", "Value=1234", ENDITEM, 
		"Name=firstName", "Value=testFirstName", ENDITEM, 
		"Name=lastName", "Value=testLastNeme", ENDITEM, 
		"Name=address1", "Value=nabereggggggggggggg", ENDITEM, 
		"Name=address2", "Value=yfaaaaaaaaaaaaaa", ENDITEM, 
		"Name=register.x", "Value=54", ENDITEM, 
		"Name=register.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("Filling_out_the_form",LR_AUTO);

	lr_start_transaction("Continue");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Continue",LR_AUTO);

	lr_start_transaction("Regist_out");

	web_revert_auto_header("Sec-Fetch-User");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Regist_out",LR_AUTO);

	return 0;
}
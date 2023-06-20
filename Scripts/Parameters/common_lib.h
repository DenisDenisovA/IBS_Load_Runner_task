
Open_homepage(){


lr_start_transaction("Open_homepage");

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

	web_reg_find("Text/IC=<title>Web Tours</title>",
		LAST);
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
    lr_end_transaction("Open_homepage",LR_AUTO); 
    
   }
    

log_in(){

lr_start_transaction("log_in");

web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");
	
        web_reg_find("Text=User password was correct",LAST);

	web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours",LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=53", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

lr_end_transaction("log_in",LR_AUTO);

}


open_flights(){

lr_start_transaction("open_flights");

web_revert_auto_header("Sec-Fetch-User");

	web_reg_find("Text=<b>Find Flight<",LAST);
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
lr_end_transaction("open_flights",LR_AUTO);
}

find_flight(){

lr_start_transaction("find_flight");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");
		
	web_reg_find("Text=from <B>{departure_city}</B> to <B>{arrival_city}</B> on <B>{departure_date}</B>",
		LAST);
	 web_reg_find("Text=from <B>{arrival_city}</B> to <B>{departure_city}</B> on <B>{return_date}</B>",
		LAST);
	web_reg_find("Text=name=\"seatType\" value=\"{type_of_seat}\"  /><input type=\"hidden\" name=\"seatPref\" value=\"{seating_preference}\"",
		LAST);
	
	web_reg_save_param("outboundFlight",
		"LB/IC=name=\"outboundFlight\" value=\"",
		"RB/IC=\"",
		"Ord=random",
		LAST);

	
	web_reg_save_param("returnFlight",
		"LB/IC=\"returnFlight\" value=\"",
		"RB/IC=\"",
		"Ord=random",
		LAST);

	
	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={departure_city}", ENDITEM, 
		"Name=departDate", "Value={departure_date}", ENDITEM, 
		"Name=arrive", "Value={arrival_city}", ENDITEM, 
		"Name=returnDate", "Value={return_date}", ENDITEM, 
		"Name=numPassengers", "Value={countPass}", ENDITEM, 
		"Name=roundtrip", "Value={roundtrip}", ENDITEM, 
		"Name=seatPref", "Value={seating_preference}", ENDITEM, 
		"Name=seatType", "Value={type_of_seat}", ENDITEM, 
		"Name=findFlights.x", "Value=35", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("find_flight",LR_AUTO);
}

flight_selection(){
lr_start_transaction("flight_selection");
 
	web_reg_find("Text/IC=value=\"{first_name} {last_name}&",
		LAST);
	
	web_reg_find("Text/IC=\"outboundFlight\" value=\"{outboundFlight}\"",
		LAST);
	
		web_reg_find("Text/IC=\"returnFlight\" value=\"{returnFlight}\"",
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=returnFlight", "Value={returnFlight}", ENDITEM, 
		"Name=numPassengers", "Value={countPass}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={type_of_seat}", ENDITEM, 
		"Name=seatPref", "Value={seating_preference}", ENDITEM, 
		"Name=reserveFlights.x", "Value=51", ENDITEM, 
		"Name=reserveFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("flight_selection",LR_AUTO);

}



open_itinerary(){

lr_start_transaction("Itinerary_Button");

	web_reg_save_param("flightID",
	"LB=flightID\" value=\"",
	"RB=\"",
	LAST);


web_revert_auto_header("Sec-Fetch-User");

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Itinerary_Button",LR_AUTO);

}

log_out(){

lr_start_transaction("log_out");

	web_revert_auto_header("Origin");

	web_reg_find("Text/IC=A Session ID has been created",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("log_out",LR_AUTO);
}





















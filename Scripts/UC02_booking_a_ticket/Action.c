Action()
{
lr_start_transaction("02_booking_a_ticket");

/*Correlation comment - Do not change!  Original value='136347.939327663HAVDDQHpVcQVzzzHtcAiApDicHHf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
		
	Open_homepage();	

	lr_think_time(2);
	
	log_in();
	
	lr_think_time(2);
	
	open_flights();
	
	lr_think_time(2);

	find_flight();
	
	lr_think_time(2);
	
	flight_selection();
	
	lr_think_time(2);
	
	lr_start_transaction("payment_details");

		web_reg_find("Text/IC=<b>{first_name}{last_name}'s Flight Invoice</b>",
		LAST);
	
	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={first_name}", ENDITEM, 
		"Name=lastName", "Value={last_name}", ENDITEM, 
		"Name=address1", "Value={street_address}", ENDITEM, 
		"Name=address2", "Value={city}", ENDITEM, 
		"Name=pass1", "Value={first_name} {last_name}", ENDITEM, 
		"Name=pass2", "Value={first_name2} {last_name2}", ENDITEM, 
		"Name=pass3", "Value={first_name3} {last_name3}", ENDITEM, 
		"Name=creditCard", "Value={credit_card}", ENDITEM, 
		"Name=expDate", "Value={exp_date}", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=oldCCOption", "Value=on", ENDITEM, 
		"Name=numPassengers", "Value={countPass}", ENDITEM, 
		"Name=seatType", "Value={type_of_seat}", ENDITEM, 
		"Name=seatPref", "Value={seating_preference}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value={returnFlight}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=44", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("payment_details",LR_AUTO);
	
	lr_think_time(2);
	
	open_itinerary();
	
	lr_think_time(2);
	
	log_out();

    lr_end_transaction("02_booking_a_ticket", LR_AUTO);
    
	return 0;
	
	

}
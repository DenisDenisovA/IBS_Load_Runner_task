Action()
{
lr_start_transaction("06_Cancellation_of_booking");
	

/*Correlation comment - Do not change!  Original value='136332.781692993HAVczVHptfiDDDDDtcAHfpHAtHf' Name ='userSession' Type ='ResponseBased'*/
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

	open_itinerary();
	
	lr_think_time(2);
	
	lr_start_transaction("select_booking");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_submit_form("itinerary.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=48",ENDITEM,
		"Name=removeFlights.y", "Value=1",ENDITEM,
		LAST);
	                
	lr_end_transaction("select_booking",LR_AUTO);


lr_end_transaction("06_Cancellation_of_booking", LR_AUTO);

	return 0;
}



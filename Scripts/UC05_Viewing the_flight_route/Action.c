Action()
{
lr_start_transaction("05_viewing the flight route");


/*Correlation comment - Do not change!  Original value='136325.162737951HAVcccfpffiDDDDDtcAHDpDfDDf' Name ='userSession' Type ='ResponseBased'*/
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
	
	
/*Correlation comment - Do not change!  Original value='itinerary' Name ='page' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=page",
		"RegExp=page=(.*?)\"\\ TARGET",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
		
lr_think_time(2);

	    log_in();
	    
    lr_think_time(2);

	open_itinerary();
	 
	lr_think_time(2);
	
	open_flights();
	
lr_end_transaction("05_viewing the flight route", LR_AUTO);
	return 0;
}
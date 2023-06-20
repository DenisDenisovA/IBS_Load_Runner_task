Action()
{
lr_start_transaction("04_Ticket search");
	

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
	
lr_think_time(2);

	log_in();
	
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

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

lr_think_time(2);

		open_flights();

	lr_think_time(2);	

/*Correlation comment - Do not change!  Original value='001;0;05/02/2023' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

/*Correlation comment - Do not change!  Original value='002;0;05/03/2023' Name ='returnFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=returnFlight",
		"TagName=input",
		"Extract=value",
		"Name=returnFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	find_flight();
	
	lr_think_time(2);
	
	flight_selection();
	
lr_end_transaction("04_Ticket search", LR_AUTO);
	return 0;
}
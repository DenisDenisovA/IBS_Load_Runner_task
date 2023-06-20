Action()
{
lr_start_transaction("03_Log_in_Log_out");	

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
	
lr_think_time(2);
	
log_out();

lr_end_transaction("03_Log_in_Log_out", LR_AUTO);
	return 0;
}
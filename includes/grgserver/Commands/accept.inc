CMD:accept(playerid, params[], 94)
{
	switch (PVar:playerid[JOBID])
	{
		case JOB_ADAC, JOB_AMBULANCE, JOB_POLICE, JOB_TRUCKER:
			ShowDialog(playerid, DIALOG_ACCEPT);
		default:
			return COMMAND_PERMISSION_DENIED;
	}
	return COMMAND_OK;
}
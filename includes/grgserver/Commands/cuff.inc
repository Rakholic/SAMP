CMD:cuff(playerID, params[], 554)
{
	if (PVar:playerID[JOBID] == JOB_POLICE)
	{
		new targetPlayerID;
		if (sscanf(params, "u", targetPlayerID))
		{
			CmdUsageMsg(playerID, "cuff", "playerID/Name");
			return COMMAND_USAGE;
		}
		if (targetPlayerID == INVALID_PLAYER_ID)
		{
			return COMMAND_PLAYER_NOT_FOUND;
		}
		new Float:posX;
		new Float:posY;
		new Float:posZ;
		GetPlayerPos(playerID, posX, posY, posZ);
		if (IsPlayerInRangeOfPoint(targetPlayerID, 1, posX, posY, posZ))
		{
			if (GetPlayerSpecialAction(targetPlayerID) == SPECIAL_ACTION_CUFFED)
			{
				SetPlayerSpecialAction(targetPlayerID, SPECIAL_ACTION_NONE);
				RemovePlayerAttachedObject(targetPlayerID, 0);
				SendClientMessageEx(playerID, COLOR_INFO, 557, targetPlayerID);
			}
			else
			{
				SetPlayerSpecialAction(targetPlayerID, SPECIAL_ACTION_CUFFED);
				SetPlayerAttachedObject(targetPlayerID, 0, 19418, 6, -0.011000, 0.028000, -0.022000, -15.600012, -33.699977, -81.700035, 0.891999, 1.000000, 1.168000);
				SendClientMessageEx(playerID, COLOR_INFO, 555, targetPlayerID);
			}
			return COMMAND_OK;
		}
		else
		{
			SendClientMessageEx(playerID, COLOR_ERROR, 556, targetPlayerID);
			return COMMAND_ERROR;
		}
	}
	return COMMAND_PERMISSION_DENIED;
}
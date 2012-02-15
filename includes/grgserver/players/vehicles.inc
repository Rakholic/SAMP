public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if (!ispassenger && !IsPlayerNPC(playerid))
	{
		SetVehicleEngineState(vehicleid, false);
	}
	if (!ispassenger)
	{
		if (vehicles[vehicleid][vehicles_saveID])
		{
			new string[256];
			new ownerUserID = strval(GetMySQLValue("savedvehicles", "OwnerUserID", "ID", val2str(vehicles[vehicleid][vehicles_saveID])));
			if (ownerUserID == GetPVarInt(playerid, "UserID"))
			{
				return true;
			}
			if (ownerUserID)
			{
				SendClientMessage(playerid, COLOR_ERROR, "Dieses Fahrzeug besitzt bereits ein anderer Spieler");
				RemovePlayerFromVehicle(playerid);
			}
			else
			{
				format(string,sizeof(string), "M�chtest du dieses Fahrzeug Kaufen?\nDies kostet $%s", GetMySQLValue("savedvehicles", "Price", "ID", val2str(vehicles[vehicleid][vehicles_saveID])));
				ShowPlayerDialog(playerid, DIALOG_BUYVEHICLE,DIALOG_STYLE_MSGBOX, "Fahrzeug Kaufen", string, "Ja", "Nein");
			}
		}
	}
	if (GetPVarInt(playerid, "RadioOn") && GetPVarInt(playerid, "LastRadioStation"))
	{
		PlayRadioStation(playerid, GetPVarInt(playerid, "LastRadioStation"));
	}
	return true;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && !IsPlayerNPC(playerid))
	{
		SetVehicleEngineState(vehicleid, false);
	}
	SaveVehicle(vehicleid, GetPlayerInterior(playerid));
	StopRadioStation(playerid);
	return true;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	vehicles[vehicleid][vehicles_paintjobID] = paintjobid;
	return true;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	vehicles[vehicleid][vehicles_color1] = color1;
	vehicles[vehicleid][vehicles_color2] = color2;
	return true;
}
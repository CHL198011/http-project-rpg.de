//params["_type"];
//if("_type" == "") exitWith {diag_log "Type is null in gopro";};
if !(client_gopro) then {
    client_gopro = true;
    ["Go Pro aktiv", false] spawn domsg;
    434 cutRsc ["HUDGoPro","PLAIN"]; 
} else {
    client_gopro = false;
    ["Go Pro deaktiviert", false] spawn domsg;
    434 cutfadeout 1;
};
/*switch (_type) do {
    case 0: {client_gopro = false;};
    case 1: {client_gopro = true;};
    default: {client_gopro = false;};
};*/
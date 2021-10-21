// THIS AS BEEN MADE BY CODEX#0317 & ROBLOXIAN ATTACKER FROM DISCORD.GG/VAPE.
// BASICALLY IT CAN BE USED FOR A CHEAT LOADER, FOR MAKE A SERVER STATUS CHECK, FOR MAKE AN AUTO UPDATER, OR JUST FOR MAKE AN UPDATE CHECKER.
// IF YOU PASTE THIS PLEASE GIVE SOME CREDITS.  @c VAPE LTS. discord.gg/vape all rights reserved.
#include "string.h"

discordggvape main() {
    SetConsoleTitleA("TEST UPDATE CHECKER");
    cout << "Checking loader version . . .\n";
    Sleep(1000);
    try
    {
        codex_string data_content_link = "https://discord.gg/vape/raw/version.txt"; // SET YOUR OWN LINK (EXAMPLE FOR AN AUTO UPDATER, IN THIS LINK PUT ENABLED FOR SAY THE LOADER IS UPDATED AND DISABLED FOR SAY ITS NOT)
        codex_string discord_link = "discord.gg/vape";
        codex_string invalid_server_link = " ";
        codex_string text_read = read_data(data_content_link); // DOWNLOAD THE RAW PAGE, AND STORE THE CONTENT DATA

        if (text_read == "updated") { // CHECK IF THE CONTENT DATA = the text "enabled"
            cout << "loader is using lastest version.";
            system("discord.gg/vape");           // IF ITS EQUALS TO "ENABLED" THEN IT'S "GOOD"
            system("pause >nul");
        }
        else if (text_read == "outdated") { // CHECK IF THE CONTENT DATA = the text "disabled"
            cout << "Loader disabled."; // IF ITS EQUALS TO "DISABLED" THEN ITS "WRONG"
            system("pause >nul");
        }
    }
    catch(int test)
    {
        std::cout << "Invalid server link.";
        system("pause >nul");
    }
}   
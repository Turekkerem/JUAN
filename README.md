# JUAN - Simple NIM Malware PoC

**JUAN** to minimalistyczny projekt typu Proof of Concept (PoC), który demonstruje, jak w prosty sposób można zaimplementować mechanizm o charakterystyce złośliwego oprogramowania (malware/ransomware-lite). 

Projekt pokazuje, że nie potrzeba skomplikowanych exploitów, aby przejąć kontrolę nad interfejsem użytkownika i wymusić określoną interakcję.

## ⚠️ OSTRZEŻENIE (Disclaimer)

Ten projekt służy wyłącznie celom edukacyjnym i badawczym. 
* **Nie uruchamiaj tego programu na systemach, do których nie masz uprawnień.**
* **Autor nie ponosi odpowiedzialności za jakiekolwiek szkody wynikające z niewłaściwego użycia tego kodu.**
* Uruchamianie projektów ingerujących w procesy systemowe może prowadzić do niestabilności systemu lub utraty niezapisanych danych.

## 🧠 Koncepcja i mechanizm działania

Program demonstruje koncepcję "gry o dostęp" (Game-locked access). Po uruchomieniu, JUAN blokuje interfejs użytkownika, a jedynym "legalnym" sposobem na odzyskanie kontroli nad komputerem jest pokonanie algorytmu w grze logicznej **NIM**.

### Główne komponenty:
1.  **Logic Core (NIM Game):** Autorska implementacja gry NIM z zaimplementowaną logiką zwycięstwa. Program gra optymalnie, co sprawia, że użytkownik musi wykazać się wiedzą z zakresu teorii gier, aby wygrać.
2.  **Locking Mechanism (Child Processes):** Program główny (parent) tworzy procesy potomne (children), które w pętli dbają o to, aby ekran pozostawał zablokowany, a fokus klawiatury/myszy pozostawał wewnątrz aplikacji.

## 🕹️ Rozgrywka i odblokowanie

Aby zatrzymać działanie programu i odblokować system:
1. Użytkownik musi wygrać partię NIM przeciwko komputerowi.
2. **Wygrana:** Powoduje wysłanie sygnału zamknięcia do wszystkich procesów potomnych i poprawne zakończenie procesu głównego.
3. **Przegrana/Zamknięcie okna:** Jeśli mechanizmy obronne na to pozwalają, próba obejścia gry skutkuje ponownym zablokowaniem lub kontynuacją blokady przez procesy potomne.

## 🛠️ Cechy techniczne

*   **Lekkość:** Minimalna ilość kodu niezbędna do osiągnięcia efektu blokady.
*   **Custom NIM Logic:** Logika gry napisana od zera, bez użycia zewnętrznych bibliotek.
*   **Process Management:** Demonstracja wykorzystania drzewa procesów do utrzymania działania aplikacji (persistence w skali sesji).

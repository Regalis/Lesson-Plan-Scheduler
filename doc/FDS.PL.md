Interaktywny generator planu lekcji
===================================

*** UWAGA: Ta wersja dokumentu jest wersją roboczą specyfikacji funkcjonalnej opisanego oprogramowania. ***

Celem przedsięwzięcia jest zaprojektowanie i zaimplementowanie programu komputerowego służącego do generowania planu lekcji dla szkół i uczelni. Zarówno specyfikacja techniczna, plany jak i sam program będą rozpowszechniane na zasadach GNU General Public License.

Licencja ta gwarantuje prawo do używania programu bez względu na zastosowania, prawo do analizowania działaniaprogramu, jego rozpowszechniania oraz modyfikacji. Program będzie rozpowszechniany z nadzieją, iż będzie on użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH ZASTOSOWAŃ. W celu uzyskania bliższych informacji sięgnij do Powszechnej Licencji Publicznej GNU
(http://www.gnu.org/licenses/gpl.txt).

## 1. Założenia ogólne

Autorzy programu nie będą dyskryminować użytkowników korzystających z odmiennych systemów operacyjnych. Sposób projektowania oraz użyte technologie umożliwią uruchomienie programu na różnych systemach operacyjnych bez strat funkcjonalności. Korzystanie z programu ma być proste i intuicyjne, format pliku użyty do eksportu danych będzie otwarty i dobrze udokumentowany. Przewidywana jest możliwość eksportu do znany formatów kalendarza. Program nie będzie wymagał od użytkownika posiadania żadnego komercyjnego oprogramowania, druk i eksport zrzutów planów lekcji oraz rozkładów pracy nauczycieli będzie zaimplementowany z wykorzystaniem wolnych (od angielskiego słowa freedom – wolność) technologii.

## 2. Dane wejściowe

Dane wejściowe są to dane, które użytkownik wprowadzi do programu (ręcznie) i które będą używane przez wewnętrzne struktury do wygenerowania wyników.

* Dane nauczycieli

	* imię, nazwisko
	* prowadzone przedmioty
	* maksymalna oraz minimalna ilość godzin (potrzebny podział? Konsultacje/zajęcia?)
	* sloty zajęciowe (dni oraz godziny, w których nauczyciel może prowadzić zajęcia)

* Dane grup

	* nazwa
	* wychowawca
	* profil
	* lista przedmiotów z podziałem na semestry
	* ilość osób

* Dane przedmiotów

	* nazwa
	* typ przedmiotu (pełny, z podziałem na grupy, cykliczny, jednorazowy, potrzeba więcej typów)
	* waga (poziom zmęczenia ucznia?)
	* wymagania wyposażenia (rzutnik, słuchawki, tablica)
	* wymagania konkretnej sali?
	* czas trwania

* Sale

	* nazwa/numer
	* wyposażenie (lista)
	* ilość miejsc

## 3. Kryteria

Po wprowadzeniu danych, użytkownik będzie proszony o podanie kryteriów potrzebnych do wygenerowania planu lekcji. Program automatycznie wygeneruje kryteria logiczne np. nauczyciel nie może prowadzić tych samych zajęć jednocześnie, sala nie może być zajęta przez dwie grupy jednocześnie itd. Użytkownik programu będzie odpowiadał za dodanie i posortowanie (od najważniejszych) innych kryteriów, do wyboru będą:

* Kryteria związane z nauczycielami

	* przypisanie do konkretnej sali (nauczyciel A musi prowadzić zajęcia w sali B)
	* przypisanie do konkretnej grupy (nauczyciel A musi prowadzić zajęcia ze swojego przedmiotu w grupie B)
	* wskazanie czasu wolnego (nauczyciel A musi mieć okienko w przedziale czasowym B)
	* wskazanie czasu pracy (nauczyciel A musi prowadzić zajęcia w przedziale czasowym B)

* Kryteria związane z salami
	* dostępność w danym okresie (sala A musi być wolna w okresie czasowym B)

* Kryteria związane z przedmiotami
	* dostępność sali z konkretnym wyposażeniem (przedmiot A wymaga rekwizytu B)
	* dostępność konkretnej sali (przedmiot A musi być prowadzony w sali B)
	* kolizje z innymi przedmiotami (przedmiot A nie może być prowadzony po przedmiocie B)
	* wymogi cykliczności (przedmiot A musi występować w planie co B dni/godzin)

* Kryteria dotyczące dni (dla każdej klasy osobno)
	* wymogi wag (w dniu A suma wag przedmiotów nie może przekroczyć B)
	* sloty zajęć (w dniu A zajęcia rozpoczynają się i kończą w przedziale czasowym B)

Dla każdego kryterium dostępne będzie kryterium odwrotne np. dla relacji musi będzie dostępna relacja nie musi itp.

Program będzie starał się spełnić wszystkie kryteria, przy czym priorytet mają te, które zostały wskazane jako pierwsze. W przypadku, gdy użytkownik nie poda żadnego kryterium, program rozpocznie generowanie planu biorąc pod uwagę jedynie kryteria logiczne (kolizje). W przypadku podania tylko kilku kryteriów, wszystkie inne będą ignorowane. Na przykład, po zdefiniowaniu przez użytkownika tylko jednego kryterium: nauczyciel A musi mieć okienko w przedziale czasowym B, jego przedział godzin pracy będzie wynikiem obliczeń mających na celu jedynie wyeliminowanie kolizji, z gwarancją wolnego czasu we wskazanym przedziale.

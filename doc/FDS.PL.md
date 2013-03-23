<center> Interaktywny generator planu lekcji </center>
=====================================================

<center> Specyfikacja funkcjonalna </center>
===========================================

***UWAGA: Ta wersja dokumentu jest wersją roboczą specyfikacji funkcjonalnej opisanego oprogramowania.***

---

**Autorzy:**

* Ariana Las
* Dagmara Siatka
* Konrad Talik
* Patryk Jaworski

**Zaktualizowano:**	2013-03-23

**Numer wersji:**	0

**Status:**	Szkic

---

Celem projektu jest opracowanie i zaimplementowanie programu komputerowego służącego do generowania planu lekcji dla szkół i uczelni. Zarówno specyfikacja techniczna, plany jak i sam program będą rozpowszechniane na zasadach GNU General Public License.

Licencja ta gwarantuje prawo do używania programu bez względu na zastosowania, prawo do analizowania działaniaprogramu, jego rozpowszechniania oraz modyfikacji. Program będzie rozpowszechniany z nadzieją, iż będzie on użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH ZASTOSOWAŃ. W celu uzyskania bliższych informacji sięgnij do Powszechnej Licencji Publicznej GNU
(http://www.gnu.org/licenses/gpl.txt).

## 1. Wprowadzenie

### 1.1. Założenia

Autorzy programu nie będą dyskryminować użytkowników korzystających z odmiennych systemów operacyjnych. Sposób projektowania oraz użyte technologie umożliwią uruchomienie programu na różnych systemach operacyjnych bez strat funkcjonalności. Korzystanie z programu ma być proste i intuicyjne, format pliku użyty do eksportu danych będzie otwarty i dobrze udokumentowany. Przewidywana jest możliwość eksportu do znany formatów kalendarza. Program nie będzie wymagał od użytkownika posiadania żadnego komercyjnego oprogramowania, druk i eksport zrzutów planów lekcji oraz rozkładów pracy nauczycieli będzie zaimplementowany z wykorzystaniem wolnych (od angielskiego słowa freedom – wolność) technologii.

### 1.2. Definicje

<dl>
  <dt>Szkoła</dt>
  <dd>Mianem Szkoły będziemy nazywać użytkownika docelowego przedstawionego w niniejszym dokumencie oprogramowania oraz jednocześnie zbiór poniżej zdefiniowanych elementów.</dd>
  <br>
  <dt>Grupa</dt>
  <dd>Grupa zajęciowa / klasa uczniów Szkoły. </dd>
  <br>
  <dt>Przedmiot</dt>
  <dd>Program nauczania obejmujący zadany materiał. Przedmiot jest nauczany przez wskazanych Nauczycieli. Niektóre przedmioty mogą wymagać odpowiedniego wyposażenia by były możliwe do realizacji.</dd>
  <br>
  <dt>Zajęcia</dt>
  <dd>Lekcje prowadzone w ramach ustalonego przedmiotu. Konkretne zajęcia prowadzone są przez konkretnego nauczyciela w konkretnej grupie lub klasie. Niektóre zajęcia mogą wymagać odpowiedniego wyposażenia by były możliwe do realizacji.</dd>
  <br>
  <dt>Nauczyciel</dt>
  <dd>Osoba posiadająca kwalifikacje do prowadzenia zajęć z danego Przedmiotu. Nauczyciel ma przydzielony zbiór zajęć (godzin), które może prowadzić.</dd>
  <br>
  <dt>Sala</dt>
  <dd>Jest miejscem odbywania się zajęć. Może udostępniać zadane wyposażenie.</dd>
  <br>
  <dt>Plan lekcji</dt>
  <dd>Zbiór uporządkowanych zajęć z konkretnych przedmiotów. Plan lekcji jest planem konkretnej grupy (klasy szkolnej) lub planem konkretnego pracownika. Plany lekcji dwóch dowolnych grup są <em>rozłączne</em>, to znaczy że zajęcia odbywające się w jednym planie nie odbywają się w drugim. To samo tyczy się planów pracowników (nauczycieli). Relacja ta nie zachodzi między planem lekcji dowolnej grupy a planem dowolnego pracownika - takie plany mogą posiadać <em> część wspólną</em>.</dd>

</dl>

## 2. Dane wejściowe

Dane wejściowe są to informacje, które użytkownik wprowadza do programu (ręcznie) i które będą używane przez wewnętrzne struktury do wygenerowania wyników.

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

Dla każdego kryterium dostępne będzie kryterium odwrotne np. dla relacji musi będzie dostępna relacja nie może itp.

Program będzie starał się spełnić wszystkie kryteria, przy czym priorytet mają te, które zostały wskazane jako pierwsze. W przypadku, gdy użytkownik nie poda żadnego kryterium, program rozpocznie generowanie planu biorąc pod uwagę jedynie kryteria logiczne (kolizje). W przypadku podania tylko kilku kryteriów, wszystkie inne będą ignorowane. Na przykład, po zdefiniowaniu przez użytkownika tylko jednego kryterium: nauczyciel A musi mieć okienko w przedziale czasowym B, jego przedział godzin pracy będzie wynikiem obliczeń mających na celu jedynie wyeliminowanie kolizji, z gwarancją wolnego czasu we wskazanym przedziale.

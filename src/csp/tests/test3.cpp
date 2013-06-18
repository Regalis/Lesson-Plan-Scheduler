/* Test code */

#include <iostream>
#include "TimetableGenerator.hpp"

int main() {

	/* Rooms */ // okresla liczbę dostępnych sal oraz ilosc miejsc w salach. W tym przypadku mamy 3 dostępne sale 001, 002, 003 pracownie chemiczna oraz informatyczna
	slimak::TimetableClassroom room001; //numer sali - 001
	room001.id = 1;
	room001.capacity = 30;              //ilosc miejsc w sali 001- 30
	slimak::TimetableClassroom room002;  //numer sali - 002
	room002.id = 2;
	room002.capacity = 30;    //ilosc miejsc w sali 002- 30
        slimak::TimetableClassroom roominformatyka;  //pracownie informatyczna
	roominformatyka.id = 3;
	roominformatyka.capacity = 30;    //ilosc miejsc w sali informatycznej- 30
	
	/* Subjects */    // lista przedmiotów
	
	// matematyka
	slimak::TimetableSubject matematyka;  // matematyka
	matematyka.id = 0;
	matematyka.classrooms.push_back(room001.id); // moze sie odbywać w salach 001, 002 oraz 003
        matematyka.classrooms.push_back(room002.id);
        //fizyka
	slimak::TimetableSubject fizyka;  // fizyka
	fizyka.id = 1;
	fizyka.classrooms.push_back(room001.id); /// moze sie odbywać w salach 001, 002 oraz 003
        fizyka.classrooms.push_back(room002.id);
        //informatyka
	slimak::TimetableSubject informatyka;  // informatyka
	informatyka.id = 2;
	informatyka.classrooms.push_back(roominformatyka.id); // może sie odbywac tylko w pracowni informatycznej
        
        

        /* Lista nauczycieli */
	/* Leszek */
	slimak::TimetableTeacher leszek;
	leszek.id = 0;
	leszek.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	// poniedzialek
	std::vector< int > leszek_poniedzialek;  // może pracowac w poniedziałek
	leszek_poniedzialek.push_back(0);     // na pierwszej
	leszek_poniedzialek.push_back(1);       //  na drugiej 
	leszek_poniedzialek.push_back(2);     // oraz na trzeciej lekcji
	// wtorek
	std::vector< int > leszek_wtorek;   // może pracowac we wtorek
	leszek_wtorek.push_back(0);     // na pierwszej
	leszek_wtorek.push_back(1);  
	leszek_wtorek.push_back(2);  // oraz 2 i 3 lekcji
	std::vector< int > leszek_sroda;
	// slots
	leszek.slots.push_back( leszek_poniedzialek );
	leszek.slots.push_back( leszek_wtorek );
	leszek.slots.push_back( leszek_sroda );
	// subjects
	leszek.subjects.push_back( matematyka.id );   // nauczyciel uczy matematyki 


	/* Gerwazy */
	slimak::TimetableTeacher gerwazy;
	gerwazy.id = 1;
	gerwazy.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	std::vector< int > gerwazy_poniedzialek;
	// wtorek
	std::vector< int > gerwazy_wtorek;  // może pracowac we wtorek
	gerwazy_wtorek.push_back(0);     // na pierwszej
	gerwazy_wtorek.push_back(1);       //  na drugiej 
	gerwazy_wtorek.push_back(2);     // oraz na trzeciej lekcji
	// sroda
	std::vector< int > gerwazy_sroda;   // może pracowac we srode
	gerwazy_sroda.push_back(0);     // na pierwszej
	gerwazy_sroda.push_back(1);   // oraz na drugiej i 3 lekcji
	gerwazy_sroda.push_back(2);
	// slots
	gerwazy.slots.push_back( gerwazy_poniedzialek );
	gerwazy.slots.push_back( gerwazy_wtorek );
	gerwazy.slots.push_back( gerwazy_sroda );
	// subjects
	gerwazy.subjects.push_back( fizyka.id );   // nauczyciel uczy fizyki

	

	/* Jerzy */
	slimak::TimetableTeacher jerzy;
	jerzy.id = 2;
	jerzy.max_slots = 10;      // ten nauczyciel moze pracowac max 10 godzin w tygodniu
	//poniedzialek
	std::vector< int > jerzy_poniedzialek;
	jerzy_poniedzialek.push_back(0);
	jerzy_poniedzialek.push_back(1);
	jerzy_poniedzialek.push_back(2);
	//wtorek
	std::vector< int > jerzy_wtorek;
	jerzy_wtorek.push_back(0);
	//sroda
	std::vector< int > jerzy_sroda;
	jerzy_sroda.push_back(0);
	jerzy_sroda.push_back(1);
	jerzy_sroda.push_back(2);
	// slots
	jerzy.slots.push_back( jerzy_poniedzialek);
	jerzy.slots.push_back( jerzy_wtorek);
	jerzy.slots.push_back( jerzy_sroda );
	
	
	// subjects
	jerzy.subjects.push_back(informatyka.id );   // nauczyciel uczy informatyki
	
	/* Groups */     //klasy
	// Ia
	slimak::TimetableGroup group_Ia;
	group_Ia.id = 0;
	group_Ia.subjects.push_back( matematyka.id ); //  matematyki
	group_Ia.subjects.push_back(fizyka.id ); //fizyki
	group_Ia.subjects.push_back( informatyka.id ); //informatyki
	group_Ia.subjects_lessons.push_back( 2 );     //2 godziny matematyki
	group_Ia.subjects_lessons.push_back( 2 );    // 2 godziny fizyki
	group_Ia.subjects_lessons.push_back( 1 );//godzine informatyki
	// Ib
	slimak::TimetableGroup group_Ib;
	group_Ib.id = 1;
	group_Ib.subjects.push_back( matematyka.id ); //  matematyki
	group_Ib.subjects.push_back(fizyka.id ); //fizyki
	group_Ib.subjects.push_back( informatyka.id ); //informatyki
	group_Ib.subjects_lessons.push_back( 2 );     // ma 2 godziny matematyki
	group_Ib.subjects_lessons.push_back( 2 );    // 2 godziny fizyki
	group_Ib.subjects_lessons.push_back( 1 );//godzine informatyki

	/* Constraints */
	std::vector< int > puste_classrooms;
	puste_classrooms.push_back(informatyka.id);
	slimak::TimetableConstraint00 puste_ograniczenie( std::vector< int > (1, jerzy.id ), puste_classrooms );

	std::map< int, slimak::TimetableGroup > given_groups;
	std::map< int, slimak::TimetableTeacher > given_teachers;
	std::map< int, slimak::TimetableSubject > given_subjects;
	std::map< int, slimak::TimetableClassroom > given_classrooms;
	std::vector< slimak::TimetableConstraint * > given_constraints;

	given_groups[0] = group_Ia;
	given_groups[1] = group_Ib;
	given_teachers[0] = leszek;
	given_teachers[1] = gerwazy;
	given_teachers[2] = jerzy;
	given_subjects[0] = matematyka;
	given_subjects[1] = fizyka;
	given_subjects[2] = informatyka;
	given_classrooms[1] = room001;
	given_classrooms[2] = room002;
	given_classrooms[3] = roominformatyka;
	given_constraints.push_back( &puste_ograniczenie );

	int liczba_dni = 3;   // liczba dni  i liczba godzin 
	int liczba_godzin  = 3;

	slimak::TimetableGenerator generator (
		 liczba_dni, liczba_godzin, 
		given_groups, given_teachers, given_subjects, given_classrooms, given_constraints
	);
	
	slimak::TimetablePlan plan_Ia = generator.generateForGroup ( group_Ia );

	slimak::TimetablePlan plan_Ib = generator.generateForGroup ( group_Ib );

	std::cerr << "Plan Ia" << std::endl;
	for (int day = 0; day < liczba_dni; ++day) {
		std::cerr << "Day " << day << ":" << std::endl;
		for (int slot = 0; slot < liczba_godzin; ++slot ) {
			std::cerr << "- Slot " << slot << ": ";
			if ( plan_Ia.slots[day][slot].isEmpty()
				|| plan_Ia.slots[day][slot].isBlank() ) {
					std::cerr << " --- " << std::endl;
					continue;
			}
			std::cerr << plan_Ia.slots[day][slot].teacher.id << " ";
			std::cerr << plan_Ia.slots[day][slot].subject.id << " ";
			std::cerr << plan_Ia.slots[day][slot].classroom.id << std::endl;
		}
	}

	std::cerr << "\nPlan Ib" << std::endl;
	for (int day = 0; day < liczba_dni; ++day) {
		std::cerr << "Day " << day << ":" << std::endl;
		for (int slot = 0; slot < liczba_godzin; ++slot ) {
			std::cerr << "- Slot " << slot << ": ";
			if ( plan_Ib.slots[day][slot].isEmpty()
				|| plan_Ib.slots[day][slot].isBlank() ) {
					std::cerr << " --- " << std::endl;
					continue;
			}
			std::cerr << plan_Ib.slots[day][slot].teacher.id << " ";
			std::cerr << plan_Ib.slots[day][slot].subject.id << " ";
			std::cerr << plan_Ib.slots[day][slot].classroom.id << std::endl;
		}
	}

	return 0;

}

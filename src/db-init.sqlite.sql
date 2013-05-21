/*
 *
 * Copyright (C) Software Liberation Maniacs Cracow
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Contributors:
 *  -> Patryk Jaworski <regalis@regalis.com.pl>
 *
 */

/**************************
 *       Core tables      *
 **************************/

create table classrooms (
	classroom_id integer not null,
	name text not null,
	capacity integer not null,
	note_id integer default null references notes on delete set null
);

create table groups (
	group_id integer primary key,
	teacher_id integer default null references teachers on delete set null,
	name text not null,
	members_no integer not null,
	note_id integer default null references notes on delete set null
);

create table intervals (
	interval_id integer primary key,
	start_date text not null,
	end_date text not null check (datetime(start_date) < datetime(end_date)),
	note_id integer default null references notes on delete set null
);

create table notes (
	note_id integer primary key,
	content text not null,
	author text,
	date text
);

create table props (
	prop_id integer primary key,
	name text not null,
	note_id integer references notes on delete set null
);

create table school_subjects (
	subject_id integer primary key,
	name text not null,
	/** subject type
	* 0 - full (2 semesters)
	* 1 - one semester
	* 2 - every now and then
	* 3 - only once
	*/
	type integer not null default 0,
	/** participants type
	* 0 - the whole group
	* 1 - split in two groups
	*/
	participants integer not null default 0,
	fatigue_level integer not null
);

create table teachers (
	teacher_id integer primary key,
	name text not null,
	surname text not null
);

/**************************
 *    Linking tables      *
 **************************/

create table classrooms_props (
	classroom_id integer references classrooms on delete cascade,
	prop_id integer references props on delete cascade,
	amount integer not null default 1 check (amount >= 0),
	primary key (classroom_id, prop_id)
);

create table groups_school_subjects (
	group_id integer references groups on delete cascade,
	subject_id integer references school_subjects on delete cascade,
	primary key (group_id, subject_id)
);

create table teachers_intervals (
	teacher_id integer references teachers on delete cascade,
	interval_id integer references intervals on delete cascade,
	/** interval type
	* 0 - available
	* 1 - unavailable
	*/
	type integer not null default 0,
	primary key (teacher_id, interval_id)
);

create table teachers_notes (
	tearcher_id integer references teachers on delete cascade,
	note_id integer references notes on delete cascade,
	primary key (tearcher_id, note_id)
);

create table teachers_props (
	teacher_id integer references teachers on delete cascade,
	prop_id integer references props on delete cascade,
	amount integer not null default 1 check (amount >= 0),
	primary key (teacher_id, prop_id)
);

create table teachers_subjects (
	teacher_id integer references teachers on delete cascade,
	subject_id integer references subjects on delete cascade,
	primary key (teacher_id, subject_id)
);

/* TODO: add trigger to notes table - auto set date */

/* vim: set ft=sql ts=4 sw=4: */

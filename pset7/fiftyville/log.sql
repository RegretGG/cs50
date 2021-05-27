--Listing all tables
.table
--to view attributes of each table
.schema
--to gather all the suspects
select * from people;
--to list all crime reports that happened on the day of the crime
select * from crime_scene_reports where year = 2020 and month = 07 and day =28;
--to see interviews of that day
select * from interviews where year = 2020 and month = 07 and day =28;
--to follow up on lead from Eugene
select * from atm_transactions where atm_location = "Fifer Street" and year = 2020 and day = 28 and month  = 7;
--to see bank accounts associated with transactions from the street during thaat time period
select * from bank_accounts where account_number in (select account_number from atm_transactions where atm_location = "Fifer Street" and year = 2020 and day = 28 and month  = 7;)
--to find people associated with the bank accounts
select license_plate from people where id in (select person_id from bank_accounts where account_number in (select account_number from atm_transactions where atm_location = "Fifer Street" and year = 2020 and day = 28 and month  = 7));
--associating license_plates with the suspect bank acounts
select * from courthouse_security_logs where year = 2020 and month = 07 and day =28 and hour = 10 and minute <26 and license_plate in (select license_plate from people where id in (select person_id from bank_accounts where account_number in (select account_number from atm_transactions where atm_location = "Fifer Street" and year = 2020 and day = 28 and month  = 7)));
--current suspects are owners of license plates:- 94KL13X,4328GD8,L93JTIZ,322W7JE . Tracking phonecalls
select phone_number from phone_calls where year = 2020 and month = 07 and day =28 and duration <60 ;
--Tracking people that fit the license_plate and the one minute call.
select * from people where license_plate in (select license_plate from courthouse_security_logs where year = 2020 and month = 07 and day =28 and hour = 10 and minute <26 and license_plate in (select license_plate from people where id in (select person_id from bank_accounts where account_number in (select account_number from atm_transactions where atm_location = "Fifer Street" and year = 2020 and day = 28 and month  = 7)))) and phone_number in (select phone_number from phone_calls where year = 2020 and month = 07 and day =28 and duration <60);
-- philip, Berthold- Accomplices Russel And Ernest -thief suspects
select * from passengers where flight_id = 36;
--common passport number with suspects is Ernest. Therefore Ernest and berthold are the likely suspects.
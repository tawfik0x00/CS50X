-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking fro crime report to get an information about the crime
SELECT description
FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2023
AND street = 'Humphrey Street';


-- Looking for interviews with witnesses
SELECT name, transcript
FROM interviews
WHERE day = 28 AND month = 7
AND year = 2023 AND transcript LIKE '%bakery%';


-- get car plates from bakery_logs

SELECT *
FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND hour = 10
AND minute BETWEEN 15 AND 25;


-- get a list of names of plates_car because Ruth see it takes a car after thef by 10 minutes
SELECT people.name FROM people
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute BETWEEN 15 AND 25;

-- get a list of atms on the stree when Eugene say it
SELECT * FROM atm_transactions
WHERE year = 2023 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street';

-- get list of all people withdraw money from atm in Legget Street in this time 10:15-10:25
SELECT people.name FROM people
JOIN bank_accounts
ON bank_accounts.person_id = people.id
JOIN atm_transactions
ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street';

-- get a list of phone calls in this time
SELECT * FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration < 60;

-- get a list of people makes this calls
SELECT people.name
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE year = 2023
AND month = 7
AND day = 28
AND duration <= 60;

-- TICKET 29 THE FIRST TICKET
SELECT * FROM flights
WHERE day = 29 AND year = 2023 AND month = 7; -- FROM airport 8 to 4 the id

-- FIND THE AIRPORT -- LaGuardia Airport | New York City
SELECT * FROM airports
WHERE id = 4;

 -- Passenger Names for the flight (bruce)
 SELECT people.name
 FROM people
 JOIN passengers
 ON people.passport_number = passengers.passport_number
 JOIN flights
 ON passengers.flight_id = flights.id
 JOIN airports
 ON flights.origin_airport_id = airports.id
 WHERE airports.city = 'Fiftyville'
 AND flights.year = 2023
 AND flights.month = 7
 AND flights.day = 29
 AND flights.hour = 8
 AND flights.minute = 20;

-- find the phone number of bruce
SELECT phone_number
FROM people
WHERE name = 'Bruce';

-- find the name of the person helped bruce

SELECT people.name FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2023
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
AND phone_calls.caller = '(367) 555-5533';



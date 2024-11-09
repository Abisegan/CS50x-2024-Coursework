-- Keep a log of any SQL queries you execute as you solve the mystery.
--Get the crime scene report description
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND year = 2023
AND street = 'Humphrey Street';



--Get the interview transcription
SELECT transcript
FROM interviews
WHERE month = 7 AND day = 28
AND year = 2023
AND transcript LIKE '%bakery%';



--Get the thief's license plate number
SELECT license_plate
FROM bakery_security_logs
WHERE month = 7 AND day = 28
AND year = 2023
AND hour = 10
AND minute > 15 AND minute < 25
AND activity = 'exit';



--Get the thief's account number
SELECT account_number
FROM atm_transactions
WHERE month = 7 AND day = 28
AND year = 2023
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';



--Get the thief's phone number
SELECT caller
FROM phone_calls
WHERE month = 7 AND day = 28
AND year = 2023
AND duration < 60;



--Get the all flights time and passenger's passport numbers at 29/07/2023 from fiftyville
SELECT passport_number, hour, minute
FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.month = 7
AND flights.day = 29
AND flights.year = 2023
AND flights.origin_airport_id IN
(
    SELECT id
    FROM airports
    WHERE city = 'Fiftyville'
)
ORDER BY hour, minute;



--Get the thief's name
SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN
(
    SELECT account_number
    FROM atm_transactions
    WHERE month = 7 AND day = 28
    AND year = 2023
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
)
AND license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7 AND day = 28
    AND year = 2023
    AND hour = 10
    AND minute > 15 AND minute < 25
    AND activity = 'exit'
)
AND phone_number IN
(
    SELECT caller
    FROM phone_calls
    WHERE month = 7 AND day = 28
    AND year = 2023
    AND duration < 60
)
AND passport_number IN
(
    SELECT passport_number
    FROM passengers
    JOIN flights ON passengers.flight_id = flights.id
    WHERE flights.year = 2023
    AND flights.month = 7
    AND flights.day = 29
    AND hour = 8 AND minute = 20
    AND flights.origin_airport_id IN
    (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    ORDER BY hour, minute

);



--Get Bruce passport_number
SELECT passport_number
FROM people
WHERE name = 'Bruce';



--TO get id of the flight he traveled
SELECT flight_id
FROM passengers
WHERE passport_number IN
(
    SELECT passport_number
    FROM people
    WHERE name = 'Bruce'
);
--To get the destination city of thief
SELECT city
FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE year = 2023
AND month = 7 AND day = 29
AND flights.id IN
(
    SELECT flight_id
    FROM passengers
    WHERE passport_number IN
    (
        SELECT passport_number
        FROM people
        WHERE name = 'Bruce'
    )
);



--To get Bruce's phone number
SELECT phone_number
FROM people
WHERE name = 'Bruce';



--To get the accomplice's phone number
SELECT receiver
FROM phone_calls
WHERE year = 2023
AND month = 7 AND daY = 28
AND duration < 60
AND caller IN
(
    SELECT phone_number
    FROM people
    WHERE name = 'Bruce'
);



--To get the accomplice's name
SELECT name
FROM people
WHERE phone_number IN
(
    SELECT receiver
    FROM phone_calls
    WHERE year = 2023
    AND month = 7 AND daY = 28
    AND duration < 60
    AND caller IN
    (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
);

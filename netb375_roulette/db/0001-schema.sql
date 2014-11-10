CREATE TABLE roulettes(
    id SERIAL PRIMARY KEY,
    name TEXT NOT NULL,
    -- Will contain any settings which will be roulette specific
    settings_json TEXT
);

CREATE TABLE board_elements(
    id SERIAL PRIMARY KEY,
    roulette_id INT REFERENCES roulettes NOT NULL,
    -- Name is a work in progress, it is the element that is shown on the board.
    -- In theory there can be roulettes with fruits instead of numbers
    sigil TEXT
);

CREATE TABLE element_types(
    id SERIAL PRIMARY KEY,
    name TEXT NOT NULL,
    multiplier NUMERIC NOT NULL DEFAULT 1
);

-- Name is a work in progress
CREATE TABLE board_elements__element_types(
    id SERIAL PRIMARY KEY,
    board_element_id INT REFERENCES board_elements,
    element_type_id INT REFERENCES element_types
);

CREATE TABLE accounts(
    id SERIAL PRIMARY KEY,
    nick_name TEXT NOT NULL,
    password TEXT NOT NULL
);

CREATE TABLE currencies(
    id SERIAL PRIMARY KEY
);

CREATE TABLE wallets(
    id SERIAL PRIMARY KEY,
    owner_id INT REFERENCES accounts,
    currency_id INT REFERENCES currencies,
    amount NUMERIC NOT NULL DEFAULT 0
);

CREATE TABLE account_transactions(
    id SERIAL PRIMARY KEY,
    roulette_id INT REFERENCES roulettes,
    account_id INT REFERENCES accounts,
    round_id INT,
    is_debit BOOLEAN,
    is_credit BOOLEAN,
    amount NUMERIC NOT NULL DEFAULT 0,
    -- elements are not a reference since we may end up deleting the game
    -- to which they belong to, but we can't delete this part of the transaction
    element_type_name TEXT NOT NULL,
    element_type_multiplier NUMERIC NOT NULL DEFAULT 1
);

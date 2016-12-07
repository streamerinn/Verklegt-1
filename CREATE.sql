--create Connections:

DROP TABLE IF EXISTS Connections;
CREATE TABLE IF NOT EXISTS "Connections" 
("scientistsID" INTEGER NOT NULL, 
"computersID" INTEGER NOT NULL, 
PRIMARY KEY ("scientistsID","computersID"),
FOREIGN KEY (scientistsID) REFERENCES Scientists (id) ON  DELETE CASCADE,
FOREIGN KEY (computersID)REFERENCES Computers(id) ON  DELETE CASCADE);

INSERT INTO Connections (scientistsID, computersID) Values (3, 3);

--create Computers:

DROP TABLE IF EXISTS Computers;
CREATE TABLE "Computers"
("id" INTEGER PRIMARY KEY AUTOINCREMENT,
"name" VARCHAR NOT NULL,
"yearBuilt" INTEGER, 
"type" VARCHAR NOT NULL, 
"built" INTEGER NOT NULL);

INSERT INTO Computers (name, type, built) VALUES ('Turing machine', 'Digital', 0);
INSERT INTO Computers (name, yearBuilt, type, built) VALUES ('Pascaline', 1645, 'Mechanical', 1);
INSERT INTO Computers (name, yearBuilt, type, built) VALUES ('Z2', 1939, 'Electromechanical', 1);


--create Scientists:

DROP TABLE IF EXISTS Scientists;
CREATE TABLE "Scientists"
("id" INTEGER PRIMARY KEY AUTOINCREMENT,
"name" VARCHAR NOT NULL,
"gender" VARCHAR NOT NULL,
"birthDate" INTEGER NOT NULL,
"deathDate" INTEGER);

INSERT INTO Scientists (name, gender, birthDate, deathDate) VALUES ('Charles Babbage', 'Male', 1791, 1871);
INSERT INTO Scientists (name, gender, birthDate, deathDate) VALUES ('Ada Locelace', 'Female', 1815, 1852);
INSERT INTO Scientists (name, gender, birthDate, deathDate) VALUES ('Konrad Zuse', 'Male', 1910, 1995);

-- Finnur tölvur sem einhver gaur bjó til:

/*SELECT b.name, b.yearBuilt, b.type, b.built
FROM Connections a, Computers b
WHERE a.scientistsID = 1 AND b.id = a.computersID;*/

-- Finnur scientistana sem bjuggu til einhverja tölvu:

/*SELECT b.name, b.gender, b.birthDate, b.deathDate
FROM Connections a, Scientists b
WHERE a.computersID = 3 AND b.id = a.scientistsID;*/
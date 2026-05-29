#include <stdio.h>

// 1. GLOBAL DATA ARRAYS
char *continents[] = {"Africa", "Antarctica", "Asia", "Australia", "Europe", "North America", "South America"};

char *countries[7][10] = {
    {"Nigeria", "Egypt", "Ethiopia", "S. Africa", "Kenya", "Morocco", "Algeria", "Ghana", "Tanzania", "Uganda"}, // Africa
    {"McMurdo", "Vostok", "Amundsen", "Showa", "Maitri", "Bharati", "Casey", "Esperanza", "Scott", "Concordia"}, // Antarctica
    {"India", "China", "Japan", "Indonesia", "Pakistan", "S. Korea", "Vietnam", "Thailand", "Turkey", "Saudi Arabia"}, // Asia
    {"Australia", "New Zealand", "Fiji", "Papua NG", "Solomon Is.", "Vanuatu", "Samoa", "Tonga", "Kiribati", "Palau"}, // Australia
    {"France", "Germany", "Italy", "UK", "Spain", "Russia", "Switzerland", "Greece", "Norway", "Netherlands"}, // Europe
    {"USA", "Canada", "Mexico", "Cuba", "Panama", "Jamaica", "Costa Rica", "Guatemala", "Bahamas", "Honduras"}, // N. America
    {"Brazil", "Argentina", "Colombia", "Peru", "Chile", "Venezuela", "Ecuador", "Bolivia", "Paraguay", "Uruguay"} // S. America
};

char *states[7][10][10] = {
    { //1. Africa
        {"LAGOS", "KANO", "KADUNA", "OYO", "RIVERS", "KATSINA", "BAUCHI", "ANAMBRA", "JIGAWA", "BENUE"}, //Nigeria
        {"CAIRO", "GIZA", "ALEXANDRIA", "DAKAHLIA", "SHARQIA", "BEHEIRA", "MINYA", "QALYUBIA", "SOHAG", "GHARBIA"}, //Egypt
        {"ADDIS ABABA", "AMHARA", "OROMIA", "TIGRAY", "SOMALI", "AFAR", "SIDAMA", "HARARI", "GAMBELA", "BENISHANGUL"}, //Ethiopia
        {"GAUTENG", "KWAZULU", "WESTERN CAPE", "EASTERN CAPE", "LIMPOPO", "MPUMALANGA", "NORTH WEST", "FREE STATE", "NORTHERN CAPE", "WILDLIFE"}, //S. Africa
        {"NAIROBI", "MOMBASA", "KIAMBU", "NAKURU", "KAKAMEGA", "BUNGOMA", "MERU", "MACHAKOS", "KISUMU", "KILIFI"}, //Kenya
        {"CASABLANCA", "RABAT", "MARRAKECH", "TANGIER", "FEZ", "SOUSS-MASSA", "MEKNES", "ORIENTAL", "KENITRA", "TETOUAN"}, //Morocco
        {"ALGIERS", "ORAN", "CONSTANTINE", "ANNABA", "BLIDA", "BATNA", "SETIF", "CHLEF", "DJELFA", "BISKRA"}, //Algeria
        {"ASHANTI", "GREATER ACCRA", "EASTERN", "CENTRAL", "WESTERN", "NORTHERN", "VOLTA", "BONO", "UPPER EAST", "UPPER WEST"}, //Ghana
        {"DAR ES SALAAM", "MWANZA", "ARUSHA", "DODOMA", "MBEYA", "MOROGORO", "TANGA", "KAHAMA", "TABORA", "ZANZIBAR"}, //Tanzania
        {"KAMPALA", "WAKISO", "MBARARA", "JINJA", "GULU", "MUKONO", "KASESE", "MASAKA", "LIRA", "MBALE"}, //Uganda
    },
    { //2. Antarctica
        {"MCMURDO (USA)", "Largest community", "Has an airport", "Observation Tube", "Pop reaches 1000", "Ross Island", "NSF Operated", "Williams Field", "Volcano Erebus", "Crary Lab"}, // McMurdo
        {"VOSTOK (Russia)", "Pole of Cold", "Lowest Temps", "Lake Vostok", "Ice core drilling", "Magnetic Pole", "Ice Core Lab", "Record -89.2C", "Solar Research", "Remote Area"}, // Vostok
        {"AMUNDSEN (USA)", "Geographic S.Pole", "High altitude", "6 mo dark/light", "South Pole Tele", "IceCube Array", "Skiway Runway", "Elevated Stn", "Dark Sector", "BICEP Tele"}, // Amundsen
        {"SHOWA (Japan)", "East Ongul Island", "Atmos physics", "Aurora observation", "Since 1957", "Lutzow-Holm", "Upper Atmos", "Cosmic Rays", "Geology Lab", "Seismic Stn"}, // Showa
        {"MAITRI (India)", "2nd permanent stn", "Schirmacher Oasis", "Steel foundation", "Lake Priyadarshini", "Indian Base", "Winter Team", "Summer Lab", "Clean Water", "Rocky Terrain"}, // Maitri
        {"BHARATI (India)", "Newest facility", "134 containers", "Larsemann Hills", "Oceanic research", "Modern Tech", "Modular Design", "Wind Turbines", "Eco-Friendly", "Ship Mooring"}, // Bharati
        {"CASEY (Australia)", "Vincennes Bay", "Built on stilts", "Antarctic flights", "Red Shed quarters", "Wilkes Land", "Penguin Colony", "Waste Plant", "Snow Clearance", "Yellow Shed"}, // Casey
        {"ESPERANZA (Arg)", "Civilian settle.", "School/Radio stn", "First human birth", "Antarctic Penin.", "Hope Bay", "Army Base", "Glacier View", "Historic Hut", "Tourist Stop"}, // Esperanza
        {"SCOTT BASE (NZ)", "Pram Point", "Bright green color", "Ross Ice Shelf", "Near McMurdo", "Hillary Field", "Telecom Hut", "Pressure Ridge", "Skua Colony", "Seal Tagging"}, // Scott Base
        {"CONCORDIA (FR/IT)", "Shared station", "White Mars", "Dry/thin air", "Space simulation", "Dome C Ice", "NASA Analog", "Glaciology", "European Lab", "Deep Freeze"}  // Concordia
    },
    { //3. Asia
        {"UTTAR PRADESH", "MAHARASHTRA", "BIHAR", "WEST BENGAL", "MADHYA PRADESH", "TAMIL NADU", "RAJASTHAN", "KARNATAKA", "GUJARAT", "DELHI"}, // INDIA (Country 0)
        {"GUANGDONG", "SHANDONG", "HENAN", "SICHUAN", "JIANGSU", "HEBEI", "HUNAN", "ZHEJIANG", "ANHUI", "HUBEI"}, // CHINA (Country 1)
        {"TOKYO", "KANAGAWA", "OSAKA", "AICHI", "SAITAMA", "CHIBA", "HYOGO", "HOKKAIDO", "FUKUOKA", "SHIZUOKA"}, // JAPAN (Country 2)
        {"WEST JAVA", "EAST JAVA", "CENTRAL JAVA", "NORTH SUMATRA", "BANTEN", "JAKARTA", "SOUTH SULAWESI", "LAMPUNG", "SOUTH SUMATRA", "RIAU"}, // INDONESIA (Country 3)
        {"PUNJAB", "SINDH", "KPK", "BALOCHISTAN", "ISLAMABAD", "AZAD KASHMIR", "GILGIT-BALTISTAN", "N/A", "N/A", "N/A"}, // PAKISTAN (Country 4)
        {"SEOUL", "GYEONGGI", "BUSAN", "GYEONGNAM", "INCHEON", "GYEONGBUK", "DAEGU", "CHUNGNAM", "JEONNAM", "JEONBUK"}, // SOUTH KOREA (Country 5)
        {"HO CHI MINH", "HANOI", "THANH HOA", "NGHE AN", "DONG NAI", "BINH DUONG", "HAI PHONG", "AN GIANG", "DAK LAK", "THAI BINH"}, // VIETNAM (Country 6)
        {"BANGKOK", "NAKHON RATCH.", "SAMUT PRAKAN", "CHIANG MAI", "KHON KAEN", "CHONBURI", "UBON RATCH.", "NAKHON SI THAM.", "BURIRAM", "SURAT THANI"}, // THAILAND (Country 7)
        {"ISTANBUL", "ANKARA", "IZMIR", "BURSA", "ANTALYA", "ADANA", "KONYA", "SANLIURFA", "GAZIANTEP", "MERSIN"}, // TURKEY (Country 8)
        {"RIYADH", "MAKKAH", "EASTERN PROV.", "ASIR", "MADINAH", "JIZAN", "QASSIM", "TABUK", "HAIL", "NAJRAN"}  // SAUDI ARABIA (Country 9)
    },
    { //4. Australia
        {"NEW SOUTH WALES", "VICTORIA", "QUEENSLAND", "W. AUSTRALIA", "S. AUSTRALIA", "TASMANIA", "ACT", "NORTHERN TERR.", "Jervis Bay", "Norfolk Island"}, // Australia
        {"AUCKLAND", "CANTERBURY", "WELLINGTON", "WAIKATO", "BAY OF PLENTY", "MANAWATU", "OTAGO", "NORTHLAND", "HAWKE'S BAY", "TARANAKI"}, // New Zealand
        {"BA", "NAITASIRI", "REWA", "TAILEVU", "MACUATA", "NADROGA", "CAKAUDROVE", "NAMOSI", "SERUA", "RA"}, // Fiji
        {"MOROBE", "W. HIGHLANDS", "E. HIGHLANDS", "MADANG", "E. SEPIK", "ENGA", "S. HIGHLANDS", "NCD", "MILNE BAY", "W. NEW BRITAIN"}, // Papua NG
        {"MALAITA", "GUADALCANAL", "WESTERN", "MAKIRA", "CHOISEUL", "CENTRAL", "ISABEL", "TEMOTU", "RENNELL", "HONIARA"}, // Solomon Is.
        {"MALAMPA", "PENAMA", "SANMA", "SHEFA", "TAFEA", "TORBA", "Efate Island", "Espiritu Santo", "Tanna Island", "Ambrym"}, // Vanuatu
        {"TUAMASAGA", "ANA", "AIGA-I-LE-TAI", "ATUA", "VAA-O-FONO", "FAASALELEAGA", "GAGAEMAUGA", "GAGAFOOMAUGA", "PALAULI", "SATUPAITEA"}, // Samoa
        {"TONGATAPU", "VAVA'U", "HA'APAI", "EUA", "ONGO NIUA", "Niuas", "Nomuka", "Lifuka", "Foa", "Ha'ano"}, // Tonga
        {"GILBERT ISLANDS", "LINE ISLANDS", "PHOENIX ISLANDS", "Tarawa", "Kiritimati", "Tabuaeran", "Teraina", "Banaba", "Butaritari", "Abemama"}, // Kiribati
        {"AIRAI", "KOROR", "AIMELIIK", "MELEKEOK", "NGARAARD", "NGARCHELONG", "NGARDMAU", "NGATPANG", "NGCHESAR", "NGIWAL"} // Palau
    },
    { //5. Europe
        {"PARIS", "NORD", "BOUCHES-DU-RHONE", "RHONE", "GIRONDE", "PAS-DE-CALAIS", "YVELINES", "H-GARONNE", "L-ATLANTIQUE", "S-SAINT-DENIS"}, // France
        {"BAVARIA", "BERLIN", "HAMBURG", "SAXONY", "HESSE", "B-WURTTEMBERG", "NRW", "L. SAXONY", "BREMEN", "THURINGIA"}, // Germany
        {"LOMBARDY", "LAZIO", "CAMPANIA", "SICILY", "VENETO", "PIEDMONT", "E-ROMAGNA", "TUSCANY", "PUGLIA", "LIGURIA"}, // Italy
        {"ENGLAND", "SCOTLAND", "WALES", "N. IRELAND", "LONDON", "MANCHESTER", "BIRMINGHAM", "GLASGOW", "LIVERPOOL", "EDINBURGH"}, // UK
        {"ANDALUSIA", "CATALONIA", "MADRID", "VALENCIA", "GALICIA", "CASTILE & LEON", "BASQUE COUNTRY", "CANARY IS.", "MURCIA", "ARAGON"}, // Spain
        {"MOSCOW CITY", "ST. PETERSBURG", "TATARSTAN", "KRASNODAR", "SVERDLOVSK", "ROSTOV", "BASHKORTOSTAN", "MOSCOW OBLAST", "SAMARA", "CHELYABINSK"}, // Russia
        {"ZURICH", "BERN", "VAUD", "AARGAU", "ST. GALLEN", "GENEVA", "LUCERNE", "TICINO", "VALAIS", "BASEL-STADT"}, // Switzerland
        {"ATTICA", "C. MACEDONIA", "THESSALY", "W. GREECE", "CRETE", "PELOPONNESE", "EPIRUS", "S. AEGEAN", "N. AEGEAN", "C. GREECE"}, // Greece
        {"OSLO", "VIKEN", "VESTLAND", "ROGALAND", "VESTFOLD", "INNLANDET", "AGDER", "NORDLAND", "TROMS", "FINNMARK"}, // Norway
        {"S. HOLLAND", "N. HOLLAND", "N. BRABANT", "UTRECHT", "GELDERLAND", "OVERIJSSEL", "LIMBURG", "FRIESLAND", "GRONINGEN", "DRENTHE"} // Netherlands
    },
    { //6. North America
        {"CALIFORNIA", "TEXAS", "FLORIDA", "NEW YORK", "ILLINOIS", "PENNSYLVANIA", "OHIO", "GEORGIA", "NORTH CAROLINA", "MICHIGAN"}, // USA
        {"ONTARIO", "QUEBEC", "BRITISH COLUMBIA", "ALBERTA", "MANITOBA", "SASKATCHEWAN", "NOVA SCOTIA", "NEW BRUNSWICK", "NEWFOUNDLAND", "PRINCE EDWARD IS."}, // Canada
        {"MEXICO CITY", "JALISCO", "VERACRUZ", "PUEBLA", "GUANAJUATO", "NUEVO LEON", "CHIAPAS", "MICHOACAN", "OAXACA", "GUERRERO"}, // Mexico
        {"HAVANA", "SANTIAGO DE CUBA", "HOLGUIN", "VILLA CLARA", "CAMAGUEY", "MATANZAS", "PINAR DEL RIO", "LAS TUNAS", "ARTEMISA", "GRANMA"}, // Cuba
        {"PANAMA", "CHIRIQUI", "WEST PANAMA", "COLON", "COCLE", "VERAGUAS", "HERRERA", "LOS SANTOS", "BOCAS DEL TORO", "DARIEN"}, // Panama
        {"ST. ANDREW", "ST. CATHERINE", "CLARENDON", "ST. JAMES", "ST. ANN", "ST. ELIZABETH", "MANCHESTER", "WESTMORELAND", "ST. MARY", "PORTLAND"}, // Jamaica
        {"SAN JOSE", "ALAJUELA", "CARTAGO", "HEREDIA", "GUANACASTE", "PUNTARENAS", "LIMON", "San Carlos", "Perez Zeledon", "Liberia"}, // Costa Rica
        {"GUATEMALA", "HUEHUETENANGO", "ALTA VERAPAZ", "SAN MARCOS", "QUICHE", "QUETZALTENANGO", "ESCUINTLA", "SUCHITEPEQUEZ", "TOTONICAPAN", "SOLOLA"}, // Guatemala
        {"NEW PROVIDENCE", "GRAND BAHAMA", "ABACO", "ELEUTHERA", "ANDROS", "EXUMA", "LONG ISLAND", "BIMINI", "CAT ISLAND", "INAGUA"}, // Bahamas
        {"FRANCISCO MORAZAN", "CORTES", "CHOLUTECA", "COMAYAGUA", "EL PARAISO", "ATLANTIDA", "YORO", "OLANCHO", "SANTA BARBARA", "COPAN"} // Honduras
    },
    { // South America
        {"SAO PAULO", "MINAS GERAIS", "RIO DE JANEIRO", "BAHIA", "PARANA", "R.G. DO SUL", "PERNAMBUCO", "CEARA", "PARA", "S. CATARINA"}, // Brazil
        {"BUENOS AIRES", "CORDOBA", "SANTA FE", "MENDOZA", "TUCUMAN", "ENTRE RIOS", "SALTA", "CHACO", "CORRIENTES", "MISIONES"}, // Argentina
        {"ANTIOQUIA", "VALLE DEL CAUCA", "CUNDINAMARCA", "SANTANDER", "ATLANTICO", "BOLIVAR", "CORDOBA", "NARINO", "TOLIMA", "BOYACA"}, // Colombia
        {"LIMA", "AREQUIPA", "LA LIBERTAD", "PIURA", "CAJAMARCA", "PUNO", "JUNIN", "CUSCO", "LAMBAYEQUE", "ANCASH"}, // Peru
        {"METROPOLITANA", "VALPARAISO", "BIOBIO", "MAULE", "ARAUCANIA", "O'HIGGINS", "LOS LAGOS", "COQUIMBO", "ANTOFAGASTA", "LOS RIOS"}, // Chile
        {"ZULIA", "MIRANDA", "CARABOBO", "DIST. CAPITAL", "LARA", "ARAGUA", "BOLIVAR", "ANZOATEGUI", "TACHIRA", "SUCRE"}, // Venezuela
        {"GUAYAS", "PICHINCHA", "MANABI", "AZUAY", "LOS RIOS", "EL ORO", "TUNGURAHUA", "LOJA", "CHIMBORAZO", "IMBABURA"}, // Ecuador
        {"LA PAZ", "SANTA CRUZ", "COCHABAMBA", "POTOSI", "CHUQUISACA", "ORURO", "TARIJA", "BENI", "PANDO", "Gran Chaco"}, // Bolivia
        {"CENTRAL", "ALTO PARANA", "ITAPUA", "CAAGUAZU", "SAN PEDRO", "CORDILLERA", "PARAGUARI", "CONCEPCION", "GUAIRA", "CAAZAPA"}, // Paraguay
        {"MONTEVIDEO", "CANELONES", "MALDONADO", "SALTO", "COLONIA", "PAYSANDU", "SAN JOSE", "RIVERA", "TACUAREMBO", "FLORIDA"} // Uruguay
    }
};

char *cities[7][10][10][10] = {
    { // AFRICA
        { // 1. NIGERIA
            {"Ikeja", "Lekki", "Ikorodu", "Epe", "Badagry", "Surulere", "Ajah", "Victoria Is.", "Yaba", "Mushin"}, // LAGOS
            {"Fagge", "Gwale", "Tarauni", "Dala", "Nasarawa", "Kumbotso", "Ungogo", "Wudil", "Gaya", "Bebeji"}, // KANO
            {"Kaduna", "Zaria", "Kafanchan", "Kagoro", "Zonkwa", "Kachia", "Makarfi", "B.Gwari", "Saminaka", "Jere"}, // KADUNA
            {"Ibadan", "Ogbomosho", "Oyo", "Iseyin", "Saki", "Igboho", "Kisi", "Okeho", "Lalupo", "Eruwa"}, // OYO
            {"Port Harcourt", "Obio-Akpor", "Bonny", "Okrika", "Onne", "Eleme", "Degema", "Opobo", "Ahoada", "Omoku"}, // RIVERS
            {"Katsina", "Daura", "Funtua", "Malumfashi", "Bakori", "Kankia", "Dutsin-Ma", "Mani", "Jibia", "Danja"}, // KATSINA
            {"Bauchi", "Azare", "Misau", "Jama'are", "Ningi", "Dass", "Toro", "Alkaleri", "Tafawa Balewa", "Darazo"}, // BAUCHI
            {"Awka", "Onitsha", "Nnewi", "Ekwulobia", "Aguata", "Ihiala", "Nkpor", "Obosi", "Umuoji", "Atani"}, // ANAMBRA
            {"Dutse", "Hadejia", "Gumel", "Birnin Kudu", "Ringim", "Kazaure", "Babura", "Mallam Madori", "Gwaram", "Kiyawa"}, // JIGAWA
            {"Makurdi", "Gboko", "Otukpo", "Katsina-Ala", "Adoka", "Lobi", "Vandeikya", "Ugbokolo", "Agatu", "Oju"} // BENUE
        },
        { // 2. EGYPT
            {"Heliopolis", "Maadi", "Nasr", "Zamalek", "Garden City", "Shoubra", "Helwan", "Abbassia", "Marg", "New Cairo"}, // CAIRO
            {"6 Oct", "Sh.Zayed", "Haram", "Dokki", "Agouza", "Imbaba", "Faisal", "Hawamdia", "Badrasheen", "Atfih"}, // GIZA
            {"Montaza", "Maamoura", "Smouha", "Agami", "Borg El Arab", "San Stefano", "Stanley", "Roushdy", "Glim", "Sidi Gaber"}, // ALEXANDRIA
            {"Mansoura", "Talkha", "Mit Ghamr", "Dekernes", "Belqas", "Manzala", "Sherbin", "Aga", "Minat El Nasr", "Simbillawein"}, // DAKAHLIA
            {"Zagazig", "Bilbeis", "Abu Hammad", "Faqus", "Abu Kebir", "Hehia", "Minat El Qamh", "Kafr Saqr", "Awlad Saqr", "Diyarb Negm"}, // SHARQIA
            {"Damanhur", "Kafr El Dawar", "Rashid", "Edko", "Abu Hummus", "Etay El Baroud", "Kom Hamada", "Hosh Issa", "Shubrakhit", "Mahmoudia"}, // BEHEIRA
            {"Minya City", "Mallawi", "Maghagha", "Beni Mazar", "Samalut", "Abu Qurqas", "Deir Mawas", "Matay", "El Idwa", "Beni Ahmed"}, // MINYA
            {"Banha", "Shubra El Kheima", "Obour", "Khanka", "Qalyub", "Qanater", "Shebin El Qanater", "Tukh", "Kafr Shukr", "Qaha"}, // QALYUBIA
            {"Sohag City", "Girga", "Akhmim", "Tahta", "Tima", "Monsha'a", "Sakulta", "Maragha", "Juhayna", "Dar El Salam"}, // SOHAG
            {"Tanta", "Mahalla El Kubra", "Kafr El Zayat", "Zefta", "Samanoud", "Qutour", "Basyoun", "Al Santa", "Kafr El Zayyat", "Qutur"} // GHARBIA
        },
        { // 3. ETHIOPIA
            {"Arada", "Bole", "Kirkos", "Gullele", "Yeka", "Nifas Silk", "Akaki Kality", "Lideta", "Kolfe Keranio", "Addis Ketema"}, // ADDIS ABABA
            {"Bahir Dar", "Gondar", "Dessie", "Debre Markos", "Debre Tabor", "Kombolcha", "Lalibela", "Weldiya", "Debre Birhan", "Motta"}, // AMHARA
            {"Adama", "Jimma", "Bishoftu", "Shashemene", "Nekemte", "Asella", "Robe", "Ambo", "Burayu", "Waliso"}, // OROMIA
            {"Mekelle", "Adigrat", "Aksum", "Shire", "Humera", "Adwa", "Alamata", "Wukro", "Maychew", "Sheraro"}, // TIGRAY
            {"Jijiga", "Gode", "Kebri Dahar", "Degehabur", "Warder", "Dollo Ado", "Shilabo", "Kebridehar", "Ferfer", "Danot"}, // SOMALI
            {"Semera", "Asaita", "Logia", "Dubti", "Det Bahri", "Abala", "Berhale", "Konaba", "Dallol", "Erebti"}, // AFAR
            {"Hawassa", "Yirgalem", "Aleta Wendo", "Leku", "Dilla", "Irgalem", "Bansa", "Aroresa", "Chuko", "Wensho"}, // SIDAMA
            {"Harar City", "Dire Dawa", "Babile", "Hundane", "Jarso", "Fedis", "Meyumuluke", "Kersa", "Metta", "Gursum"}, // HARARI
            {"Gambela City", "Itang", "Pugnido", "Lare", "Abobo", "Jikau", "Akobo", "Wanthoa", "Gorgora", "Jikawo"}, // GAMBELA
            {"Assosa", "Kamashi", "Gilgel Beles", "Mandi", "Bambasi", "Kurmuk", "Guba", "Sherkole", "Wonbera", "Bulladen"} // BENISHANGUL
        },
        { // 4. SOUTH AFRICA
            {"Johannesburg", "Pretoria", "Soweto", "Sandton", "Centurion", "Midrand", "Roodepoort", "Benoni", "Germiston", "Alberton"}, // GAUTENG
            {"Durban", "Pietermaritzburg", "Umhlanga", "Newcastle", "Amanzimtoti", "Ballito", "Richards Bay", "Ladysmith", "Dundee", "Estcourt"}, // KWAZULU
            {"Cape Town", "Stellenbosch", "George", "Paarl", "Worcester", "Mossel Bay", "Knysna", "Oudtshoorn", "Beaufort West", "Saldanha"}, // WESTERN CAPE
            {"Gqeberha", "East London", "Mthatha", "Bhisho", "Uitenhage", "Grahamstown", "Queenstown", "Cradock", "Butterworth", "Aliwal North"}, // EASTERN CAPE
            {"Polokwane", "Mokopane", "Thohoyandou", "Tzaneen", "Musina", "Phalaborwa", "Giyani", "Lebowakgomo", "Bela-Bela", "Modimolle"}, // LIMPOPO
            {"Mbombela", "Emalahleni", "Secunda", "Ermelo", "Standerton", "Barberton", "Middelburg", "White River", "Lydenburg", "Bethal"}, // MPUMALANGA
            {"Mahikeng", "Klerksdorp", "Rustenburg", "Potchefstroom", "Brits", "Vryburg", "Lichtenburg", "Orkney", "Stilfontein", "Zeerust"}, // NORTH WEST
            {"Bloemfontein", "Welkom", "Sasolburg", "Kroonstad", "Bethlehem", "Botshabelo", "Phuthaditjhaba", "Harrismith", "Parys", "Senekal"}, // FREE STATE
            {"Kimberley", "Upington", "De Aar", "Kuruman", "Springbok", "Kathu", "Postmasburg", "Colesberg", "Barkly West", "Calvinia"}, // NORTHERN CAPE
            {"Kruger Park", "Table Mountain", "Garden Route", "Drakensberg", "Sun City", "Pilanesberg", "Addo Elephant", "Hluhluwe", "Sabi Sands", "Madikwe"} // WILDLIFE
        },
        { // 5. KENYA
            {"Westlands", "Kibera", "Langata", "Dagoretti", "Embakasi", "Kasaran", "Makadara", "Kamukunji", "Starehe", "Pumwani"}, // NAIROBI
            {"Nyali", "Likoni", "Kisauni", "Changamwe", "Jomvu", "Mvita", "Bamburi", "Tudor", "Majengo", "Shimanzi"}, // MOMBASA
            {"Thika", "Ruiru", "Kiambu City", "Limuru", "Kikuyu", "Karuri", "Gatundu", "Githunguri", "Juja", "Lari"}, // KIAMBU
            {"Nakuru City", "Naivasha", "Molo", "Gilgil", "Njoro", "Rongai", "Subukia", "Kuresoi", "Bahati", "Mai Mahiu"}, // NAKURU
            {"Kakamega Town", "Mumias", "Butere", "Lugari", "Likuyani", "Malava", "Navakholo", "Shinyalu", "Ikolomani", "Khwisero"}, // KAKAMEGA
            {"Bungoma Town", "Webuye", "Chwele", "Kimilili", "Sirisia", "Malakisi", "Bokoli", "Kanduyi", "Tongaren", "Mt. Elgon"}, // BUNGOMA
            {"Meru Town", "Maua", "Nanyuki", "Timau", "Nkubu", "Imenti", "Tigania", "Igembe", "Lare", "Muthara"}, // MERU
            {"Machakos Town", "Athi River", "Kangundo", "Matungulu", "Mwala", "Yatta", "Kathiani", "Masinga", "Tala", "Syokimau"}, // MACHAKOS
            {"Kisumu City", "Ahero", "Muhoroni", "Maseno", "Kombewa", "Sondu", "Koru", "Katito", "Chiga", "Nyangande"}, // KISUMU
            {"Kilifi Town", "Malindi", "Mtwapa", "Watamu", "Mariakani", "Kaloleni", "Garsen", "Magarini", "Gede", "Marafa"} // KILIFI
        },
        { // 6. MOROCCO
            {"Casablanca", "Mohammedia", "El Jadida", "Settat", "Berrechid", "Benslimane", "Sidi Bennour", "Azemmour", "Bouznika", "Oulad Teima"}, // CASABLANCA
            {"Rabat", "Sale", "Kenitra", "Skhirat", "Temara", "Khemisset", "Sidi Slimane", "Sidi Kacem", "Tiflet", "Souk El Arba"}, // RABAT
            {"Marrakech", "Safi", "Essaouira", "El Kelaa", "Youssoufia", "Tahannaout", "Benguerir", "Chichaoua", "Imintanoute", "Ait Ourir"}, // MARRAKECH
            {"Tangier", "Tetouan", "Al Hoceima", "Larache", "Chefchaouen", "Ksar El Kebir", "Ouazzane", "Fnideq", "M'diq", "Asilah"}, // TANGIER
            {"Fez", "Meknes", "Taza", "Sefrou", "Taounate", "Boulemane", "Missour", "Moulay Idriss", "Ifrane", "Azrou"}, // FEZ
            {"Agadir", "Inezgane", "Ait Melloul", "Taroudant", "Tiznit", "Tata", "Chtouka", "Biougra", "Massa", "Taliouine"}, // SOUSS-MASSA
            {"Meknes City", "El Hajeb", "Ifrane", "Azrou", "Khenifra", "Midelt", "Boufekrane", "Sabaa Aiyoun", "Ain Taoujdate", "Agourai"}, // MEKNES
            {"Oujda", "Nador", "Berkane", "Taourirt", "Guercif", "Jerada", "Figuig", "Bouarfa", "Saidia", "Ahfir"}, // ORIENTAL
            {"Kenitra City", "Sidi Yahya", "Souk El Arba", "Mehdya", "Mnasra", "Mograne", "Arbaoua", "Lalla Mimouna", "Souk Tlet", "Ben Mansour"}, // KENITRA
            {"Tetouan City", "Martil", "M'diq", "Fnideq", "Oued Laou", "Bab Taza", "Chefchaouen", "Bni Bouayach", "Imzouren", "Targuist"} // TETOUAN
        },
        { // 7. ALGERIA
            {"Algiers", "Sidi M'Hamed", "Bab El Oued", "Zeralda", "Cheraga", "Dar El Beida", "Baraki", "Birtouta", "Rouiba", "Boucheba"}, // ALGIERS
            {"Oran", "Bir El Djir", "Es Senia", "Arzew", "Gdyel", "Bethioua", "Mers El Kebir", "Boutlelis", "Ain El Turk", "Misserghin"}, // ORAN
            {"Constantine", "El Khroub", "Hamma Bouziane", "Zighoud Youcef", "Didouche Mourad", "Ben Zied", "Ibn Ziad", "Ain Smara", "Ouled Rahmoune", "Ali Mendjeli"}, // CONSTANTINE
            {"Annaba", "El Bouni", "Sidi Amar", "Berrahal", "El Hadjar", "Chetaibi", "Seraidi", "Trézel", "Drean", "El Kala"}, // ANNABA
            {"Blida", "Boufarik", "Ouled Yaich", "Beni Mered", "Beni Tamou", "Chiffa", "Mouzaia", "El Affroun", "Meftah", "Larbaa"}, // BLIDA
            {"Batna", "Arris", "Barika", "Merouana", "Ain Touta", "N'Gaous", "Timgad", "Tazoult", "Chemora", "Khenchela"}, // BATNA
            {"Setif", "El Eulma", "Ain Arnat", "Ain Oulmene", "Guenzet", "Bouandas", "Beni Aziz", "Hammam Guergour", "Salah Bey", "El Ouricia"}, // SETIF
            {"Chlef", "Oued Fodda", "Boukadir", "Tenes", "Ouled Fares", "Chettia", "El Karimia", "Zeboudja", "Sobha", "Sendjas"}, // CHLEF
            {"Djelfa", "Ain Oussera", "Hassi Bahbah", "Messaad", "Dar Chioukh", "Birine", "Idrissia", "Faid el Botma", "Had-Sahary", "Zaccar"}, // DJELFA
            {"Biskra", "Tolga", "Ouled Djellal", "Sidi Okba", "El Kantara", "Zeribet El Oued", "M'Chouneche", "Lichana", "Ourlal", "Sidi Khaled"} // BISKRA
        },
        { // 8. GHANA
            {"Kumasi", "Obuasi", "Ejisu", "Konongo", "Mampong", "Bekwai", "Nkawie", "Offinso", "Tepa", "Agogo"}, // ASHANTI
            {"Accra", "Tema", "Madina", "Ashaiman", "Adenta", "Teshie", "Nungua", "Lapaz", "Dansoman", "Achimota"}, // GREATER ACCRA
            {"Koforidua", "Nkawkaw", "Nsawam", "Akim Oda", "Somanya", "Asamankese", "Manya Krobo", "Suhum", "Kibi", "Aburi"}, // EASTERN
            {"Cape Coast", "Winneba", "Kasoa", "Mfantseman", "Elmina", "Agona Swedru", "Dunkwa-on-Offin", "Apam", "Saltpond", "Buduburam"}, // CENTRAL
            {"Sekondi-Takoradi", "Tarkwa", "Axim", "Elubo", "Prestea", "Bibiani", "Sefwi Wiawso", "Enchi", "Shama", "Dixcove"}, // WESTERN
            {"Tamale", "Yendi", "Savelugu", "Damongo", "Buipe", "Walewale", "Gambaga", "Salaga", "Bimbilla", "Nalerigu"}, // NORTHERN
            {"Ho", "Hohoe", "Kpando", "Aflao", "Anloga", "Keta", "Sogakope", "Denu", "Dzodze", "Adidome"}, // VOLTA
            {"Sunyani", "Techiman", "Berekum", "Wenchi", "Dormaa Ahenkro", "Kintampo", "Nkoranza", "Bechem", "Goaso", "Duayaw Nkwanta"}, // BONO
            {"Bolgatanga", "Bawku", "Navrongo", "Paga", "Sandema", "Tongo", "Zuarungu", "Garu", "Pusiga", "Bongo"}, // UPPER EAST
            {"Wa", "Tumu", "Jirapa", "Lambussie", "Lawra", "Nandom", "Hamile", "Nadowli", "Funsi", "Kaleo"} // UPPER WEST
        },
        { // 9. TANZANIA
            {"Ilala", "Kinondoni", "Temeke", "Ubungo", "Kigamboni", "Mbagala", "Tegeta", "Posta", "Kariakoo", "Mikocheni"}, // DAR ES SALAAM
            {"Ilemela", "Nyamagana", "Misungwi", "Magu", "Sengerema", "Geita", "Buswelu", "Nansio", "Kamanga", "Kisesa"}, // MWANZA
            {"Arusha City", "Meru", "Musa", "Usa River", "Monduli", "Longido", "Karatu", "Ngorongoro", "Tengeru", "Ngaramtoni"}, // ARUSHA
            {"Dodoma City", "Kondoa", "Kongwa", "Mpwapwa", "Bahi", "Chamwino", "Chemba", "Kibaigwa", "Mlowa", "Makutopora"}, // DODOMA
            {"Mbeya City", "Tunduma", "Chunya", "Mbarali", "Kyela", "Rungwe", "Busokelo", "Uyole", "Mbalizi", "Songwe"}, // MBEYA
            {"Morogoro Town", "Kilombero", "Kilosa", "Ulanga", "Gairo", "Mvomero", "Mikumi", "Ifakara", "Mahenge", "Kidatu"}, // MOROGORO
            {"Tanga City", "Muheza", "Korogwe", "Lushoto", "Handeni", "Pangani", "Mkinga", "Kilindi", "Bumbuli", "Soni"}, // TANGA
            {"Kahama Town", "Shinyanga", "Kishapu", "Ushetu", "Msalala", "Isaka", "Tinde", "Bulyanhulu", "Lohumbo", "Songwa"}, // KAHAMA
            {"Tabora Town", "Nzega", "Igunga", "Uyui", "Urambo", "Kaliua", "Sikonge", "Pangale", "Bukene", "Isevya"}, // TABORA
            {"Stone Town", "Bububu", "Nungwi", "Paje", "Chwaka", "Mkokotoni", "Koani", "Chake Chake", "Mkoani", "Wete"} // ZANZIBAR
        },
        { // 10. UGANDA
            {"Kampala Central", "Nakawa", "Makindye", "Kawempe", "Rubaga", "Kiswa", "Kiwatule", "Buziga", "Muyenga", "Kololo"}, // KAMPALA
            {"Entebbe", "Kira", "Nansana", "Makindye Ssabagabo", "Kasangati", "Gayaza", "Kasanje", "Wakiso Town", "Bulenga", "Kyengera"}, // WAKISO
            {"Mbarara City", "Kamukuzi", "Kakoba", "Nyamitanga", "Biharwe", "Bwizibwera", "Ruti", "Kashanyarazi", "Katete", "Nyamitanga"}, // MBARARA
            {"Jinja City", "Bugembe", "Mafubira", "Walukuba", "Mpumudde", "Kakira", "Namulesa", "Buwenge", "Kyabirwa", "Masese"}, // JINJA
            {"Gulu City", "Pece", "Layibi", "Laroo", "Bardege", "Omoro", "Bobi", "Koro", "Koch Goma", "Patiko"}, // GULU
            {"Mukono Town", "Seeta", "Mityana", "Lugazi", "Kayunga", "Njeru", "Gaba", "Kome", "Katosi", "Nakifuma"}, // MUKONO
            {"Kasese Town", "Mpondwe", "Bwera", "Katwe", "Hima", "Muhokya", "Kikorongo", "Mubuku", "Ibanda", "Katunguru"}, // KASES
            {"Masaka City", "Nyendo", "Kiwangala", "Kyotera", "Rakai", "Lwengo", "Kalungu", "Bukomansimbi", "Lyantonde", "Mutukula"}, // MASAKA
            {"Lira City", "Aduku", "Apac", "Oyam", "Dokolo", "Kyoga", "Amolatar", "Alebtong", "Otuke", "Kole"}, // LIRA
            {"Mbale City", "Wanale", "Nkoma", "Namakwekwe", "Busiu", "Sironko", "Bududa", "Manafwa", "Bulambuli", "Bubulo"} // MBALE
        }
    },

    { // ANTARCTICA
        { // 1. Major Stations
            {"Ross Island", "NSF Operated", "Williams Field", "Pegasus White", "Winter Pop 250", "Volcano Erebus", "Crary Lab", "Under-ice Cam", "Dry Valleys", "Helicopters"}, // MCMURDO
            {"Magnetic Pole", "Subglacial Lake", "Ice Core Lab", "Record -89.2C", "Solar Radiation", "Snow Crust", "Remote Area", "Russian Base", "Drilling Rig", "High Plateau"}, // VOSTOK
            {"90 Degrees S", "Dark Sector", "Skiway Runway", "Elevated Stn", "IceCube Array", "South Pole Map", "Ceremonial Pole", "Geographic Pole", "BICEP Tele", "Cargo Planes"}, // AMUNDSEN
            {"Ongul Sound", "Lutzow-Holm", "Upper Atmos", "Cosmic Rays", "Geology Lab", "Seismic Stn", "Biological Lab", "Japanese Tech", "Inland Routes", "Coastal Ice"}, // SHOWA
            {"Rock Oasis", "Steel Modules", "Winter Team", "Summer Lab", "Clean Water", "Dakshin Gangotri", "Satellite Link", "Microbiology", "Rocky Terrain", "Supply Port"}, // MAITRI
            {"Larsemann Hills", "Modular Design", "High Speed Net", "Seawater Plant", "Wind Turbines", "Eco-Friendly", "Geophysics", "Coastal Research", "Ship Mooring", "Modern Tech"}, // BHARATI
            {"Wilkes Land", "Bailey Penin.", "Automatic Stn", "Penguin Colony", "Petrels Nest", "Marine Science", "Waste Plant", "Stilts Design", "Snow Clearance", "Yellow Shed"}, // CASEY
            {"Hope Bay", "Civilian Homes", "Radio LRA36", "School No 38", "Army Base", "Glacier View", "Historic Hut", "Tourist Stop", "Birth Record", "Peninsula Tip"}, // ESPERANZA
            {"Hillary Field", "Green Complex", "Telecom Hut", "Pressure Ridge", "Arrival Heights", "Crater Hill", "Skua Colony", "Seal Tagging", "Diving Hole", "Trans-Antarctic"}, // SCOTT BASE
            {"Dome C Ice", "No Bacteria", "Pure Air", "NASA Analog", "Glaciology", "Space Science", "European Lab", "Deep Freeze", "High Plateau", "Isolation Test"}  // CONCORDIA
        },
        { // 2. Supplementary Bases
            {"Zhongshan", "Great Wall", "Kunlun", "Taishan", "Progress", "Novolazarevskaya", "Mirny", "Bellingshausen", "Molodezhnaya", "Leningradskaya"}, // Base Group A
            {"Halley VI", "Rothera", "Signy", "Fossil Bluff", "Sky Blu", "Bird Island", "King Edward", "Grytviken", "Coronation", "South Georgia"}, // Base Group B
            {"Dumont d'Urville", "Robert Guillard", "Cap Prud'homme", "Port-aux-Francais", "Martin-de-Vivies", "Alfred Faure", "Kerguelen", "Crozet", "Amsterdam Is", "Saint-Paul"}, // Base Group C
            {"Palmer Station", "Copacabana", "Pieter Lenie", "Old Base", "Glacier Point", "Arthur Harbor", "Torgersen", "Litchfield", "Loudwater", "Joubin"}, // Base Group D
            {"San Martin", "Belgrano II", "Orcadas", "Marambio", "Carlini", "Brown", "Primavera", "Decepcion", "Melchior", "Camara"}, // Base Group E
            {"Arturo Prat", "O'Higgins", "Frei Montalva", "Escudero", "Gabriel Videla", "Carvajal", "Risopatron", "Shirreff", "Yelcho", "Guesalaga"}, // Base Group F
            {"Neumayer III", "Kohnen", "Gondwana", "Dallmann", "O'Higgins", "Drescher", "Filchner", "Georg von Neu", "Ekstrom", "Atka Ice"}, // Base Group G
            {"King Sejong", "Jang Bogo", "Tor", "Troll", "Aboa", "Wasa", "Svea", "Nordenskiold", "Pueblo", "Villa Las Estrellas"}, // Base Group H
            {"Orcadas Base", "Laurie Island", "Scotia Sea", "South Orkney", "Gourlay", "Signy Island", "Moe Island", "Lynch Island", "Powell Is", "Fredriksen"}, // Base Group I
            {"Artigas Base", "Machu Picchu", "Maldonado", "Juan Carlos I", "Gabriel de Castilla", "St. Kliment", "Jinnah", "Maitri Ext", "Dakshin", "Law-Racovita"} // Base Group J
        },
        // Index 2 to 9: Geographic Landmarks
        {{"Mt Vinson", "Tyree", "Shinn", "Gardner", "Epperly", "Rutford", "Ice Stream", "Ellsworth Mt", "Saba", "Sentinel"}},
        {{"Ross Sea", "McMurdo Sound", "Terra Nova", "Granite Harbor", "Franklin Is", "Beaufort Is", "Coulman Is", "Adare", "Wood Bay", "Terra Nova"}},
        {{"Weddell Sea", "Berkner Is", "Ron Ice Shelf", "Filchner", "Larsen A", "Larsen B", "Larsen C", "Larsen D", "Vahsel", "Gould Bay"}},
        {{"Trans-Antarctic", "Queen Maud", "Beardmore", "Axel Heiberg", "Nimrod", "Scott Glacier", "Amundsen Gl", "Reedy", "Leverett", "Shackleton"}},
        {{"Palmer Land", "Graham Land", "Trinity Penin", "Larsen", "Wilkins", "Alexander Is", "Adelaide Is", "Biscoe", "Palmer", "Anvers"}},
        {{"Victoria Land", "Wilkes Land", "Adelie Land", "George V Land", "Oates Land", "Banzare", "Sabrina", "Budd Land", "Knox Land", "Queen Mary"}},
        {{"Mac Robertson", "Princess Elizabeth", "Enderby Land", "Kemp Land", "Wilhelm II", "Prydz Bay", "Amery", "Lars Christensen", "Ingrid", "Leopold"}},
        {{"Queen Maud Land", "Princess Astrid", "Princess Ragnhild", "Prince Harald", "Prince Olav", "Mizuho", "Asuka", "Svarthamaren", "Tor", "Troll"}}
    },

    { // ASIA
        { // 1. INDIA
            {"Lucknow", "Kanpur", "Ghaziabad", "Agra", "Varanasi", "Meerut", "Prayagraj", "Bareilly", "Aligarh", "Noida"}, // UP
            {"Mumbai", "Pune", "Nagpur", "Thane", "Pimpri", "Nashik", "Kalyan", "Vasai", "Aurangabad", "Navi Mum."}, // Maharashtra
            {"Patna", "Gaya", "Bhagalpur", "Muzaffarpur", "Purnia", "Darbhanga", "Arrah", "Begusarai", "Katihar", "Munger"}, // Bihar
            {"Kolkata", "Howrah", "Durgapur", "Asansol", "Siliguri", "Maheshtala", "Rajpur", "Haldia", "Habra", "Kharagpur"}, // WB
            {"Indore", "Bhopal", "Jabalpur", "Gwalior", "Ujjain", "Sagar", "Dewas", "Satna", "Ratlam", "Rewa"}, // MP
            {"Chennai", "Coimbatore", "Madurai", "Trichy", "Salem", "Tiruppur", "Erode", "Vellore", "Thoothukudi", "Nagercoil"}, // TN
            {"Jaipur", "Jodhpur", "Kota", "Bikaner", "Ajmer", "Udaipur", "Bhilwara", "Alwar", "Bharatpur", "Sikar"}, // Rajasthan
            {"Bengaluru", "Hubballi", "Mysuru", "Belagavi", "Mangaluru", "Gulbarga", "Davanagere", "Ballari", "Bijapur", "Shimoga"}, // Karnataka
            {"Ahmedabad", "Surat", "Vadodara", "Rajkot", "Bhavnagar", "Jamnagar", "Junagadh", "Gandhinagar", "Anand", "Morbi"}, // Gujarat
            {"Connaught Place", "Dwarka", "Saket", "Rohini", "Janakpuri", "Vasant Kunj", "Mayur Vihar", "Lajpat Nagar", "Karol Bagh", "Chandni Chowk"} // Delhi
        },
        { // 2. CHINA
            {"Guangzhou", "Shenzhen", "Dongguan", "Foshan", "Huizhou", "Zhanjiang", "Shantou", "Zhongshan", "Jiangmen", "Maoming"}, // Guangdong
            {"Jinan", "Qingdao", "Yantai", "Weifang", "Linyi", "Jining", "Zibo", "Heze", "Tai'an", "Dezhou"}, // Shandong
            {"Zhengzhou", "Luoyang", "Nanyang", "Xinxiang", "Anyang", "Zhumadian", "Xinyang", "Zhoukou", "Shangqiu", "Kaifeng"}, // Henan
            {"Chengdu", "Mianyang", "Nanchong", "Luzhou", "Yibin", "Leshun", "Zigong", "Panzhihua", "Guangyuan", "Suining"}, // Sichuan
            {"Nanjing", "Suzhou", "Wuxi", "Changzhou", "Xuzhou", "Nantong", "Yangzhou", "Taizhou", "Yancheng", "Huai'an"}, // Jiangsu
            {"Shijiazhuang", "Tangshan", "Baoding", "Handan", "Langfang", "Cangzhou", "Xingtai", "Hengshui", "Zhangjiakou", "Chengde"}, // Hebei
            {"Changsha", "Zhuzhou", "Xiangtan", "Hengyang", "Shaoyang", "Yueyang", "Changde", "Yiyang", "Chenzhou", "Yongzhou"}, // Hunan
            {"Hangzhou", "Ningbo", "Wenzhou", "Shaoxing", "Jiaxing", "Jinhua", "Taizhou", "Quzhou", "Lishui", "Zhoushan"}, // Zhejiang
            {"Hefei", "Wuhu", "Bengbu", "Huainan", "Ma'anshan", "Huaibei", "Anqing", "Huangshan", "Chuzhou", "Fuyang"}, // Anhui
            {"Wuhan", "Xiangyang", "Yichang", "Jingzhou", "Xiaogan", "Huanggang", "Suizhou", "Ezhou", "Jingmen", "Xianning"} // Hubei
        },
        { // 3. JAPAN
            {"Shinjuku", "Shibuya", "Setagaya", "Nerima", "Edogawa", "Adachi", "Itabashi", "Koto", "Shinagawa", "Chuo"}, // Tokyo
            {"Yokohama", "Kawasaki", "Sagamihara", "Fujisawa", "Yokosuka", "Hiratsuka", "Chigasaki", "Atsugi", "Yamato", "Oda"}, // Kanagawa
            {"Sakai", "Higashiosaka", "Hirakata", "Toyonaka", "Suita", "Takatsuki", "Ibaraki", "Yao", "Neyagawa", "Izumi"}, // Osaka
            {"Nagoya", "Toyota", "Okazaki", "Ichinomiya", "Toyohashi", "Kasugai", "Anjo", "Nishio", "Komaki", "Inazawa"}, // Aichi
            {"Saitama City", "Kawaguchi", "Tokorozawa", "Koshigaya", "Kasukabe", "Ageo", "Kumagaya", "Soka", "Niiza", "Sayama"}, // Saitama
            {"Chiba City", "Funabashi", "Matsudo", "Ichikawa", "Kashiwa", "Ichihara", "Yachiyo", "Nagareyama", "Narita", "Noda"}, // Chiba
            {"Kobe", "Himeji", "Nishinomiya", "Amagasaki", "Akashi", "Kakogawa", "Takarazuka", "Itami", "Kawanishi", "Sanda"}, // Hyogo
            {"Sapporo", "Asahikawa", "Hakodate", "Kushiro", "Tomakomai", "Obihiro", "Otaru", "Kitami", "Ebetsu", "Muroran"}, // Hokkaido
            {"Fukuoka City", "Kitakyushu", "Kurume", "Iizuka", "Omuta", "Kasuga", "Chikushino", "Onojo", "Munakata", "Itoshima"}, // Fukuoka
            {"Shizuoka City", "Hamamatsu", "Fuji", "Numazu", "Iwata", "Yaizu", "Fujieda", "Mishima", "Fujinomiya", "Shimada"} // Shizuoka
        },
        { // 4. PAKISTAN
            {"Lahore", "Faisalabad", "Rawalpindi", "Gujranwala", "Multan", "Sialkot", "Bahawalpur", "Sargodha", "Gujrat", "Sheikhupura"}, // Punjab
            {"Karachi", "Hyderabad", "Sukkur", "Larkana", "Nawabshah", "Mirpur Khas", "Jacobabad", "Shikarpur", "Khairpur", "Dadu"}, // Sindh
            {"Peshawar", "Mardan", "Abbottabad", "Mingora", "Kohat", "Bannu", "Swabi", "Dera Ismail Khan", "Charsadda", "Nowshera"}, // KPK
            {"Quetta", "Turbat", "Khuzdar", "Hub", "Chaman", "Gwadar", "Sibi", "Zhob", "Loralai", "Dera Murad Jamali"}, // Balochistan
            {"Blue Area", "F-6", "F-7", "F-8", "G-6", "G-7", "G-8", "G-9", "G-10", "I-8"}, // Islamabad
            {"Muzaffarabad", "Mirpur", "Rawalakot", "Kotli", "Bhimber", "Bagh", "Sudhanoti", "Hattian Bala", "Haveli", "Neelum"}, // Azad Kashmir
            {"Gilgit", "Skardu", "Ghanche", "Kharmang", "Shigar", "Astore", "Diamer", "Ghizer", "Hunza", "Nagar"}, // Gilgit-Baltistan
            {"Karachi Coast", "Gwadar Port", "Ormara", "Pasni", "Jiwni", "Gadani", "Sonmiani", "Keti Bandar", "Sir Creek", "Bundal Is."}, // Extra Coast
            {"Taxila", "Wah Cantt", "Murree", "Nathia Gali", "Taxila City", "Hasan Abdal", "Topi", "Attock", "Sawabi", "Tarbela"}, // Extra North
            {"Ziarat", "Pishin", "Noshki", "Kharan", "Sui", "Dera Bugti", "Kohlu", "Zhob City", "Kalat", "Mastung"} // Extra West
        },
        { // 5. INDONESIA
            {"Bandung", "Bekasi", "Depok", "Bogor", "Tasikmalaya", "Cimahi", "Sukabumi", "Banjar", "Ciamis", "Cianjur"}, // West Java
            {"Surabaya", "Malang", "Kediri", "Probolinggo", "Pasuruan", "Madiun", "Blitar", "Batu", "Mojokerto", "Jember"}, // East Java
            {"Semarang", "Surakarta", "Magelang", "Pekalongan", "Salatiga", "Tegal", "Cilacap", "Banyumas", "Kudus", "Pati"}, // Central Java
            {"Medan", "Binjai", "Pematangsiantar", "Tanjungbalai", "Tebing Tinggi", "Sibolga", "Padangsidimpuan", "Gunungsitoli", "Karo", "Deli"}, // North Sumatra
            {"Tangerang", "South Tangerang", "Serang", "Cilegon", "Pandeglang", "Lebak", "Anyer", "Merak", "Balaraja", "Cikupa"}, // Banten
            {"Central Jakarta", "West Jakarta", "South Jakarta", "East Jakarta", "North Jakarta", "Kepulauan Seribu", "Gambir", "Menteng", "Senayan", "Kemang"}, // Jakarta
            {"Makassar", "Parepare", "Palopo", "Gowa", "Maros", "Bone", "Bulukumba", "Toraja", "Selayar", "Bantaeng"}, // South Sulawesi
            {"Bandar Lampung", "Metro", "South Lampung", "Central Lampung", "East Lampung", "Pringsewu", "Pesawaran", "Tanggamus", "Tulang Bawang", "Mesuji"}, // Lampung
            {"Palembang", "Lubuklinggau", "Pagar Alam", "Prabumulih", "Banyuasin", "Ogan Ilir", "Ogan Komering", "Musi Banyuasin", "Musi Rawas", "Lahat"}, // South Sumatra
            {"Pekanbaru", "Dumai", "Bengkalis", "Indragiri Hilir", "Indragiri Hulu", "Kampar", "Kuantan Singingi", "Pelalawan", "Rokan Hilir", "Rokan Hulu"} // Riau
        },
        { // 6. SOUTH KOREA
            {"Gangnam", "Hongdae", "Myeongdong", "Itaewon", "Jongno", "Songpa", "Gangseo", "Nowon", "Guro", "Yeongdeungpo"}, // Seoul
            {"Suwon", "Goyang", "Yongin", "Seongnam", "Bucheon", "Ansan", "Hwaseong", "Anyang", "Pyeongtaek", "Siheung"}, // Gyeonggi
            {"Haeundae", "Seomyeon", "Saha", "Dongnae", "Nam-gu", "Buk-gu", "Sasang", "Geumjeong", "Yeonje", "Suyeong"}, // Busan
            {"Changwon", "Gimhae", "Yangsan", "Jinju", "Geoje", "Tongyeong", "Sacheon", "Miryang", "Haman", "Changnyeong"}, // Gyeongnam
            {"Bupyeong", "Namdong", "Yeonsu", "Michuhol", "Seo-gu", "Gyeyang", "Jung-gu", "Dong-gu", "Ganghwa", "Ongjin"}, // Incheon
            {"Pohang", "Gumi", "Gyeongju", "Gyeongsan", "Andong", "Gimcheon", "Yeongju", "Sangju", "Yeongcheon", "Mungyeong"}, // Gyeongbuk
            {"Dalseo", "Buk-gu", "Suseong", "Dong-gu", "Seo-gu", "Nam-gu", "Jung-gu", "Dalseong", "Gunwi", "Chilgok"}, // Daegu
            {"Cheonan", "Asan", "Seosan", "Dangjin", "Gongju", "Nonsan", "Boryeong", "Gyeryong", "Buyeo", "Seocheon"}, // Chungnam
            {"Yeosu", "Suncheon", "Mokpo", "Gwangyang", "Naju", "Muan", "Haenam", "Goheung", "Hwasun", "Yeongam"}, // Jeonnam
            {"Jeonju", "Iksan", "Gunsan", "Jeongeup", "Gimje", "Namwon", "Wanju", "Gochang", "Buan", "Sunchang"} // Jeonbuk
        },
        { // 7. VIETNAM
            {"District 1", "District 2", "District 3", "Thu Duc", "Go Vap", "Binh Thanh", "Tan Binh", "District 7", "District 10", "Cu Chi"}, // Ho Chi Minh
            {"Ba Dinh", "Hoan Kiem", "Tay Ho", "Long Bien", "Cau Giay", "Dong Da", "Hai Ba Trung", "Hoang Mai", "Thanh Xuan", "Ha Dong"}, // Hanoi
            {"Thanh Hoa City", "Sam Son", "Bim Son", "Muong Lat", "Quan Hoa", "Ba Thuoc", "Lang Chanh", "Ngoc Lac", "Cam Thuy", "Thach Thanh"}, // Thanh Hoa
            {"Vinh", "Cua Lo", "Thai Hoa", "Hoang Mai", "Ky Son", "Tuong Duong", "Con Cuong", "Tan Ky", "Anh Son", "Nghia Dan"}, // Nghe An
            {"Bien Hoa", "Long Khanh", "Long Thanh", "Nhon Trach", "Vinh Cuu", "Trang Bom", "Thong Nhat", "Dinh Quan", "Tan Phu", "Xuan Loc"}, // Dong Nai
            {"Thu Dau Mot", "Thuan An", "Di An", "Tan Uyen", "Ben Cat", "Dau Tieng", "Phu Giao", "Bac Tan Uyen", "Bau Bang", "N/A City"}, // Binh Duong
            {"Hong Bang", "Le Chan", "Ngo Quyen", "Kien An", "Hai An", "Do Son", "Duong Kinh", "An Duong", "An Lao", "Bach Long Vi"}, // Hai Phong
            {"Long Xuyen", "Chau Doc", "Tan Chau", "An Phu", "Chau Phu", "Chau Thanh", "Cho Moi", "Phu Tan", "Thoai Son", "Tri Ton"}, // An Giang
            {"Buon Ma Thuot", "Buon Ho", "Ea H'leo", "Ea Kar", "Ea Súp", "Krông Ana", "Krông Bông", "Krông Búk", "Krông Năng", "Krông Pắc"}, // Dak Lak
            {"Thai Binh City", "Dông Hung", "Hung Hà", "Kiên Xuong", "Quynh Phu", "Thái Thuy", "Tiên Hai", "Vu Thu", "N/A", "N/A"} // Thai Binh
        },
        { // 8. THAILAND
            {"Siam", "Sukhumvit", "Silom", "Chatuchak", "Bang Na", "Thon Buri", "Min Buri", "Lat Krabang", "Pathum Wan", "Dusit"}, // Bangkok
            {"Mueang Korat", "Pak Chong", "Sikhio", "Phimai", "Sung Noen", "Chok Chai", "Dan Khun Thot", "Non Thai", "Non Sung", "Bua Yai"}, // Nakhon Ratch.
            {"Mueang Samut", "Phra Pradaeng", "Phra Samut", "Bang Phli", "Bang Bo", "Bang Sao Thong", "Pu Chao", "Bang Na Ext", "Samrong", "Tamru"}, // Samut Prakan
            {"Old City", "Nimman", "Mae Rim", "Hang Dong", "San Sai", "Doi Saket", "Sankamphaeng", "Mae Taeng", "Fang", "Chom Thong"}, // Chiang Mai
            {"Mueang Khon Kaen", "Chum Phae", "Ban Phai", "Phon", "Nong Ruea", "Nong Song Hong", "Phu Wiang", "Mancha Khiri", "Kranuan", "Ubolratana"}, // Khon Kaen
            {"Pattaya", "Chonburi City", "Si Racha", "Bang Lamung", "Sattahip", "Ban Bueng", "Phan Thong", "Phanat Nikhom", "Ko Sichang", "Ko Lan"}, // Chonburi
            {"Mueang Ubon", "Warit Chamrap", "Det Udom", "Phibun Mangsahan", "Trakan Phuet Phon", "Khemarat", "Buntharik", "Nam Yuen", "Na Chaluai", "Don Tan"}, // Ubon Ratch.
            {"Mueang Nakhon", "Thung Song", "Pak Phanang", "Sichon", "Tha Sala", "Ron Phibun", "Lan Saka", "Chawang", "Hua Sai", "Khanom"}, // Nakhon Si Tham.
            {"Mueang Buriram", "Nang Rong", "Prakhon Chai", "Satuek", "Lahan Sai", "Ban Kruat", "Putthaisong", "Lam Plai Mat", "Khu Mueang", "Non Suwan"}, // Buriram
            {"Ko Samui", "Ko Pha Ngan", "Ko Tao", "Mueang Surat Thani", "Kanchanadit", "Don Sak", "Chaiya", "Phunphin", "Wiang Sa", "Phanom"} // Surat Thani
        },
        { // 9. TURKEY
            {"Fatih", "Besiktas", "Uskudar", "Kadikoy", "Beyoglu", "Sisli", "Bakirkoy", "Maltepe", "Esenyurt", "Pendik"}, // Istanbul
            {"Cankaya", "Kecioren", "Yenimahalle", "Mamah", "Etimesgut", "Sincan", "Altindag", "Gokbasi", "Pursaklar", "Elmadag"}, // Ankara
            {"Konak", "Karsiyaka", "Bornova", "Buca", "Cigli", "Gaziemir", "Bayrakli", "Balcova", "Narlidere", "Urla"}, // Izmir
            {"Osmangazi", "Yildirim", "Nilufer", "Inegyol", "Gemlik", "Mudanya", "Gursu", "Kestel", "Mustafakemalpasa", "Karacabey"}, // Bursa
            {"Muratpasa", "Kepez", "Konyaalti", "Alanya", "Manavgat", "Serik", "Aksu", "Dosemealti", "Kemer", "Korkuteli"}, // Antalya
            {"Seyhan", "Cukurova", "Yuregir", "Saricam", "Ceyhan", "Kozan", "Imamoğlu", "Karataş", "Pozantı", "Aladağ"}, // Adana
            {"Selcuklu", "Meram", "Karatay", "Ereğli", "Akşehir", "Beyşehir", "Seydişehir", "Ilgın", "Cihanbeyli", "Kulu"}, // Konya
            {"Eyyübiye", "Haliliye", "Karaköprü", "Siverek", "Viranşehir", "Suruç", "Birecik", "Akçakale", "Ceylanpınar", "Harran"}, // Sanliurfa
            {"Şahinbey", "Şehitkamil", "Nizip", "Islahiye", "Nurdağı", "Araban", "Yavuzeli", "Karkamış", "Oğuzeli", "N/A"}, // Gaziantep
            {"Akdeniz", "Mezitli", "Yenişehir", "Toroslar", "Tarsus", "Silifke", "Erdemli", "Anamur", "Mut", "Bozyazı"} // Mersin
        },
        { // 10. SAUDI ARABIA
            {"Olaya", "Malaz", "Batha", "Diplomatic Qtr", "Diriyah", "Al-Naseem", "Al-Shifa", "Al-Uraya", "Al-Mursalat", "Rawdah"}, // Riyadh
            {"Al-Balad", "Al-Hamra", "Al-Safa", "Al-Rawdah", "Al-Nahda", "Al-Basateen", "Obhur", "Al-Marwah", "Al-Waha", "Al-Nuzhah"}, // Makkah (Jeddah)
            {"Dammam", "Khobar", "Dhahran", "Jubail", "Hofuf", "Al-Ahsa", "Qatif", "Khafji", "Hafr Al-Batin", "Ras Tanura"}, // Eastern Prov.
            {"Abha", "Khamis Mushait", "Bisha", "Bareq", "Mahayel", "Al-Namas", "Sarat Abidah", "Majardah", "Ahad Rafidah", "Dahran Al-Janub"}, // Asir
            {"Al-Haram", "Yanbu", "Al-Ula", "Badr", "Khaybar", "Al-Hanakiyah", "Mahd Al-Dahab", "Al-Eis", "Wadi Al-Fara", "Yanbu Al-Sinaiyah"}, // Madinah
            {"Jizan City", "Sabya", "Abu Arish", "Samtah", "Al-Darb", "Al-Ardah", "Damat", "Al-Edabi", "Al-Reeth", "Farasan Is."}, // Jizan
            {"Buraydah", "Unaizah", "Ar Rass", "Al Mithnab", "Al Bukayriyah", "Al Badayea", "Riyadh Al Khabra", "Al Khabra", "Uyun Al-Jiwa", "Asyah"}, // Qassim
            {"Tabuk City", "Al-Wajh", "Duba", "Tayma", "Umluj", "Haql", "Al-Bada'a", "Sharma", "Neom City", "Magna"}, // Tabuk
            {"Hail City", "Baqa'a", "Al-Ghazalah", "Al-Shanan", "Al-Hait", "Al-Sulaymi", "Al-Shamli", "Mawqaq", "Al-Kharkhir", "Al-Ajfar"}, // Hail
            {"Najran City", "Sharurah", "Hubuna", "Badr Al-Janub", "Yadamah", "Thar", "Khabbash", "Al-Wadiah", "N/A", "N/A"} // Najran
        }    
    },

    { // AUSTRALIA
        { // 1. AUSTRALIA
            {"Sydney", "Newcastle", "Wollongong", "Maitland", "Blue Mountains", "Cessnock", "Orange", "Dubbo", "Tamworth", "Albury"}, // NEW SOUTH WALES
            {"Melbourne", "Geelong", "Ballarat", "Bendigo", "Shepparton", "Melton", "Mildura", "Warrnambool", "Sunbury", "Traralgon"}, // VICTORIA
            {"Brisbane", "Gold Coast", "Sunshine Coast", "Townsville", "Cairns", "Toowoomba", "Mackay", "Rockhampton", "Bundaberg", "Hervey Bay"}, // QUEENSLAND
            {"Perth", "Rockingham", "Mandurah", "Bunbury", "Kalgoorlie", "Geraldton", "Albany", "Karratha", "Broome", "Port Hedland"}, // W. AUSTRALIA
            {"Adelaide", "Mount Gambier", "Whyalla", "Gawler", "Port Pirie", "Bridgewater", "Port Lincoln", "Murray Bridge", "Victor Harbor", "Mount Barker"}, // S. AUSTRALIA
            {"Hobart", "Launceston", "Devonport", "Burnie", "Ulverstone", "Kingston", "New Norfolk", "Wynyard", "George Town", "Sorell"}, // TASMANIA
            {"Canberra", "Belconnen", "Gungahlin", "Tuggeranong", "Woden Valley", "Weston Creek", "Molonglo", "North Canberra", "South Canberra", "Hall"}, // ACT
            {"Darwin", "Palmerston", "Alice Springs", "Katherine", "Nhulunbuy", "Howard Springs", "Tennant Creek", "Yulara", "Jabiru", "Batchelor"}, // NORTHERN TERR.
            {"Sussex Inlet", "Huskisson", "Vincentia", "Hyams Beach", "Booderee", "Wreck Bay", "Currarong", "Callala Bay", "Erowal Bay", "Sanctuary Pt"}, // Jervis Bay
            {"Kingston", "Burnt Pine", "Cascade", "Middlegate", "Longridge", "Anson Bay", "Steeles Point", "Bumbora", "Rocky Point", "Ball Bay"} // Norfolk Island
        },
        { // 2. NEW ZEALAND
            {"Auckland City", "Manukau", "North Shore", "Waitakere", "Pukekohe", "Waiheke", "Wellsford", "Warkworth", "Helensville", "Orewa"}, // AUCKLAND
            {"Christchurch", "Timaru", "Ashburton", "Rangiora", "Rolleston", "Kaiapoi", "Lincoln", "Temuka", "Geraldine", "Waimate"}, // CANTERBURY
            {"Wellington City", "Lower Hutt", "Upper Hutt", "Porirua", "Kapiti", "Masterton", "Levin", "Paraparaumu", "Otaki", "Waikanae"}, // WELLINGTON
            {"Hamilton", "Taupo", "Cambridge", "Te Awamutu", "Tokoroa", "Huntly", "Matamata", "Morrinsville", "Thames", "Waitomo"}, // WAIKATO
            {"Tauranga", "Rotorua", "Whakatane", "Kawerau", "Te Puke", "Opotiki", "Katikati", "Murupara", "Maketu", "Omokoroa"}, // BAY OF PLENTY
            {"Palmerston North", "Whanganui", "Levin", "Feilding", "Dannevirke", "Marton", "Pahiatua", "Bulls", "Taihape", "Foxton"}, // MANAWATU
            {"Dunedin", "Queenstown", "Oamaru", "Wanaka", "Alexandra", "Cromwell", "Balclutha", "Milton", "Mosgiel", "Arrowtown"}, // OTAGO
            {"Whangarei", "Kerikeri", "Kaitaia", "Dargaville", "Kaikohe", "Paihia", "Maungaturoto", "Kawakawa", "Ruakaka", "Mangawhai"}, // NORTHLAND
            {"Napier", "Hastings", "Havelock North", "Wairoa", "Waipukurau", "Waipawa", "Tikokino", "Otane", "Takapau", "Porangahau"}, // HAWKE'S BAY
            {"New Plymouth", "Hawera", "Stratford", "Eltham", "Opunake", "Patea", "Waitara", "Inglewood", "Manaia", "Okato"} // TARANAKI
        },
        { // 3. FIJI
            {"Ba Town", "Lautoka City", "Tavua", "Nadi", "Vatukoula", "Yavuna", "Koroivolu", "Sabeto", "Vuda", "Natabua"}, // BA
            {"Nasinu", "Nausori", "Tamavua", "Lami", "Colo-i-Suva", "Wainibuku", "Nakasi", "Davuilevu", "Kalabo", "Vunidawa"}, // NAITASIRI
            {"Suva City", "Rewa Town", "Laucala", "Vunivalu", "Nokia", "Lomanikoro", "Tokatoka", "Burebasaga", "Tavuya", "Waivou"}, // REWA
            {"Korovou", "Bau", "Nausori North", "Wainibokasi", "Lodoni", "Namatakula", "Sawakasa", "Namata", "Viwa", "Dromuna"}, // TAILEVU
            {"Labasa", "Seaqaqa", "Waiqele", "Bulileka", "Batinikama", "Malau", "Vunimoli", "Soasoa", "Coqeloa", "Dreketilailai"}, // MACUATA
            {"Sigatoka", "Cuvu", "Lawaqa", "Korotogo", "Nadroga Central", "Valley Road", "Lomawai", "Malomalo", "Natadola", "Kavanagasau"}, // NADROGA
            {"Savusavu", "Nabouwalu", "Taveuni", "Bua", "Lekutu", "Wairiki", "Somosomo", "Matei", "Navaca", "Yaqeta"}, // CAKAUDROVE
            {"Navua", "Namuka", "Veivatuloa", "Mau", "Waidradra", "Galoa", "Deuba", "Beqa", "Yanuca", "Rovadrau"}, // NAMOSI
            {"Pacific Harbour", "Korovisilou", "Navua East", "Naboutini", "Serua Island", "Vunaniu", "Yarawa", "Talivakola", "Namaqumaqua", "Galoa Town"}, // SERUA
            {"Rakiraki", "Vaileka", "Nananu-i-Ra", "Ellington", "Wananavu", "Togovere", "Naria", "Namarai", "Barotu", "Navolau"} // RA
        },
        { // 4. PAPUA NEW GUINEA
            {"Lae", "Bulolo", "Wau", "Finschhafen", "Kaiapit", "Menyamya", "Mumeng", "Mutzing", "Sialum", "Wasu"}, // MOROBE
            {"Mount Hagen", "Mul", "Baiyer", "Nebilyer", "Hagen Central", "Togoba", "Kuta", "Bukapena", "Alimp", "Kagamuga"}, // W. HIGHLANDS
            {"Goroka", "Kainantu", "Henganofi", "Lufa", "Okapa", "Obura", "Wonenara", "Daulo", "Watabung", "Bena"}, // E. HIGHLANDS
            {"Madang Town", "Alexishafen", "Bogia", "Simbai", "Bundi", "Saidor", "Karkar", "Aiome", "Usino", "Walium"}, // MADANG
            {"Wewak", "Angoram", "Maprik", "Yangoru", "Aitape", "Lumi", "Nuku", "Dreikikir", "Ambunti", "Pagwi"}, // E. SEPIK
            {"Wabag", "Wapenamanda", "Lagaip", "Porgera", "Laiagam", "Kandep", "Ambum", "Kompiam", "Sirunki", "Surinki"}, // ENGA
            {"Mendi", "Tari", "Ialibu", "Pangia", "Koroba", "Kopiago", "Nipa", "Kutubu", "Erave", "Kagua"}, // S. HIGHLANDS
            {"Port Moresby", "Waigani", "Boroko", "Gerehu", "Hanuabada", "Koki", "Badili", "Hohola", "Tokarara", "June Valley"}, // NCD
            {"Alotau", "Samarai", "Esa'ala", "Misima", "Losuia", "Kiriwina", "Woodlark", "Rabaraba", "Baniara", "Bolubolu"}, // MILNE BAY
            {"Kimbe", "Bialla", "Hoskins", "Talasea", "Gloucester", "Kandrian", "Gasmata", "Mosa", "Nakanai", "Bali-Vitu"} // W. NEW BRITAIN
        },
        { // 5. SOLOMON ISLANDS
            {"Auki", "Maluu", "Atori", "Akwani", "Dala", "Buma", "Rohinari", "Afio", "Foula", "Onepusu"}, // MALAITA
            {"Honiara West", "Henderson", "Lunga", "Tenaru", "GPPOL", "Ruavatu", "Aola", "Marau", "Avu Avu", "Visale"}, // GUADALCANAL
            {"Gizo", "Munda", "Noro", "Seghe", "Ringgi", "Poitete", "Vella Lavella", "Kolombangara", "Ranongga", "Simbo"}, // WESTERN
            {"Kirakira", "Pamua", "Bauro", "Wainoni", "Santa Ana", "Santa Catalina", "Star Harbour", "Namuga", "Ugi", "Three Sisters"}, // MAKIRA
            {"Taro Island", "Choiseul Bay", "Panggoe", "Moli", "Sasamungga", "Vavudu", "Nuatabu", "Voza", "Nanango", "Sepa"}, // CHOISEUL
            {"Tulagi", "Savo", "Ngella", "Yandina", "Pavuvu", "Banika", "Mborokua", "Russell Is.", "Sandfly", "Buena Vista"}, // CENTRAL
            {"Buala", "Maringe", "Kia", "Tataba", "Sigana", "Gao", "Bugotu", "Hograno", "Zabana", "Kokota"}, // ISABEL
            {"Lata", "Nendo", "Reef Islands", "Duff Islands", "Utupua", "Vanikoro", "Tikopia", "Anuta", "Fatutaka", "Graciosa Bay"}, // TEMOTU
            {"Tigoa", "Lavangu", "Niupani", "Bellona", "Mungiki", "Kangava", "Matangi", "East Rennell", "West Rennell", "Lake Te Ngano"}, // RENNELL
            {"Town Ground", "Point Cruz", "Kukum", "Vura", "Panatina", "Naha", "Mbokonavera", "White River", "Rove", "Skyline"} // HONIARA
        },
        { // 6. VANUATU
            {"Lakatoro", "Norsup", "Lamap", "South West Bay", "Ahamb", "Maskelynes", "Paama", "Lopevi", "Ambrym", "Craig Cove"}, // MALAMPA
            {"Saratamata", "Longana", "Lolowai", "Bwatnapni", "Melsisi", "Waterfall", "Abwatuntora", "Loltong", "Navenevene", "Quatneune"}, // PENAMA
            {"Luganville", "Hog Harbour", "Port Olry", "Aore", "Malo", "Tutuva", "Bokissa", "Aese", "Ratua", "Mafia"}, // SANMA
            {"Port Vila", "Bauerfield", "Mele", "Pango", "Eton", "Epi", "Tongoa", "Emae", "Nguna", "Pele"}, // SHEFA
            {"Isangel", "Lenakel", "Louniel", "White Grass", "Aniwa", "Futuna", "Aneityum", "Erromango", "Ipota", "Dillon's Bay"}, // TAFEA
            {"Sola", "Mota Lava", "Vanua Lava", "Gaua", "Ureparapara", "Merig", "Mere Lava", "Hiw", "Loh", "Toga"}, // TORBA
            {"Pango Pt", "Teouma", "Montmartre", "Erakor", "Eratap", "Forari", "Siviri", "Paunangisu", "Epau", "Moso"}, // Efate Island
            {"Champagne Beach", "Lonnoc", "Aird Hill", "Big Bay", "Vatthe", "Shark Bay", "Turtle Bay", "Matevulu", "Loru", "Million Dollar Pt"}, // Espiritu Santo
            {"Yasur", "Lamak", "Iguana", "Port Resolution", "Sulphur Bay", "Yaneumel", "Yakir", "Kwamera", "Green Hill", "Enpuka"}, // Tanna Island
            {"Dip Point", "Fanla", "Ranon", "Magam", "Endu", "Eas", "Port Vato", "Lalinda", "Baiap", "Sesivi"} // Ambrym
        },
        { // 7. SAMOA
            {"Apia", "Vaitele", "Faleata", "Vaimauga", "Letogo", "Laulii", "Fagalii", "Moata'a", "Magiagi", "Tanugamanono"}, // TUAMASAGA
            {"Faleasiu", "Fasito'o Uta", "Leulumoega", "Nofoalii", "Fasito'o Tai", "Vailuutai", "Magia", "Satuimalufilufi", "Fuailalo", "Siufaga"}, // ANA
            {"Mulifanua", "Manono Utu", "Apolima Tai", "Fuailolo'o", "Salua", "Saluafata", "Lepa", "Lotofaga", "Aufaga", "Vavau"}, // AIGA-I-LE-TAI
            {"Aleipata", "Lufilufi", "Falefa", "Faleapuna", "Musumusu", "Salimu", "Samamea", "Lalomano", "Ti'avea", "Amaile"}, // ATUA
            {"Maasina", "Lona", "Faleapuna Tai", "Uafato", "Samamea Tai", "Taelefaga", "Saletele", "Musumusu Tai", "Leva", "Falevao"}, // VAA-O-FONO
            {"Salelologa", "Safotulafai", "Sapapalii", "Lano", "Asau", "Vaisala", "Aopo", "Sasina", "Safotu", "Manase"}, // FAASALELEAGA
            {"Saleaula", "Sato'alepai", "Fagamalo", "Lelepa", "Avao", "Vaipua", "Sasina Tai", "Letui", "Aopo Tai", "Samalaeulu"}, // GAGAEMAUGA
            {"Aopo North", "Sasina North", "Safotu North", "Manase North", "Safai", "Satu'atua", "Salailua", "Siutu", "Taga", "Gataivai"}, // GAGAFOOMAUGA
            {"Vailoa", "Gataivai", "Gautavai", "Sili", "Puleia", "Taga", "Satuiatua", "Salailua", "Siutu", "Fatuvalu"}, // PALAULI
            {"Satupaitea Town", "Vailoa South", "Gataivai South", "Pitote", "Satufia", "Vaega", "Mosula", "Tafua", "Siaia", "Fogasavaii"} // SATUPAITEA
        },
        { // 8. TONGA
            {"Nuku'alofa", "Mu'a", "Haveluloto", "Vaini", "Kolonga", "Houma", "Pea", "Tatakamotonga", "Fua'amotu", "Nukunuku"}, // TONGATAPU
            {"Neiafu", "Leimatua", "Hihifo", "Pangaimotu", "Hunga", "Kapa", "Koloa", "Nuapapu", "Ovaka", "Taunga"}, // VAVA'U
            {"Pangai", "Ha'ano", "Foa", "Lifuka", "Uiha", "Nomuka", "Tofua", "Lofanga", "Mango", "Fonoi"}, // HA'APAI
            {"Ohonua", "Houma", "Tufuvai", "Angaha", "Pangai South", "Futuna", "Esia", "Sapa'ata", "Fata'ulua", "Mu'a"}, // EUA
            {"Hihifo", "Angaha", "Niuatoputapu", "Niuafo'ou", "Falehau", "Vaipoa", "Angaha South", "Petani", "Kolofo'ou", "Tafahi"}, // ONGO NIUA
            {"Tafahi", "Niuas North", "Angaha North", "Vaipoa Village", "Hihifo Town", "Falehau Bay", "Niuatoputapu Is", "Mata'aho", "Vaikona", "Hala'ovave"}, // Niuas
            {"Nomuka South", "Mango South", "Fonoi South", "O'ua", "Lekeleka", "Tungua", "Kotu", "Matuku", "Fotuha'a", "Teaupa"}, // Nomuka
            {"Lifuka North", "Pangai North", "Hihifo North", "Kolo", "Holopeka", "Koulo", "Pangai Central", "Hihifo West", "Lifuka South", "Lotofoa"}, // Lifuka
            {"Foa North", "Lotofoa North", "Ha'ateiho", "Fangale'ounga", "Fotua", "Faleloa", "Ha'afuva", "Lotofoa East", "Foa West", "Ha'alaufuli"}, // Foa
            {"Ha'ano North", "Fakakai North", "Pukotala", "Ha'ano Village", "Muitoa", "Fakakai South", "Ha'ano West", "Niu'ui", "Koulo", "Holopeka"} // Ha'ano
        },
        { // 9. KIRIBATI
            {"Bairiki", "Betio", "Bikenibeu", "Teaoraereke", "Eita", "Nanikai", "Ambo", "Banraeaba", "Tanaea", "Bonriki"}, // GILBERT ISLANDS
            {"London", "Poland", "Banana", "Tabwakea", "Paris", "Cassidy", "Fanning", "Washington", "Christmas Is.", "Teraina"}, // LINE ISLANDS
            {"Kanton", "Enderbury", "Birnie", "McKean", "Rawaki", "Manra", "Orona", "Nikumaroro", "Winslow", "Phoenix Is."}, // PHOENIX ISLANDS
            {"South Tarawa", "North Tarawa", "Abaiang", "Marakei", "Maiana", "Kuria", "Aranuka", "Abemama", "Nonouti", "Tabiteuea"}, // Tarawa
            {"Main Camp", "Bay of Wrecks", "Cook Island", "Motu Upua", "Nora's Is.", "Vaskess Is.", "Joe's Hill", "Bridges", "Y-Site", "Aeon"}, // Kiritimati
            {"Paelau", "Aitari", "Tenenebo", "Tereitaki", "English Harbour", "Napari", "Mauri Town", "Tabuaeran Pt", "Fanning Is", "Aitari East"}, // Tabuaeran
            {"Tangore", "Abaiang East", "Aranuka East", "Teraina South", "Teraina North", "Matu", "Buariki", "Tebunginako", "Taburao", "Nuariki"}, // Teraina
            {"Antereen", "Tabwewa", "Uma", "Tabiang", "Banaba Town", "Ocean Island", "Buakonikai", "Banaba West", "Cantilever", "Home Bay"}, // Banaba
            {"Butaritari Town", "Ukiangang", "Kuma", "Buariki", "Tanimaiaki", "Tabonuea", "Tanimaiaki North", "Kuuma", "Buariki South", "Butaritari East"}, // Butaritari
            {"Abemama Town", "Kariatebike", "Tanimainiku", "Tebanga", "Manoku", "Kabangaki", "Baretoa", "Biiti", "Bangotantebae", "Tabiang"} // Abemama
        },
        { // 10. PALAU
            {"Ngeruluobel", "Ngerusar", "Ordomel", "Oikull", "Airai Village", "Ngetkib", "Ngeruluobel Tai", "Ngerikiil", "Desekel", "Ngchesechang"}, // AIRAI
            {"Koror City", "Meyuns", "Ngermid", "Ngerbeched", "Ngerkesoaol", "Ngerchemai", "Iyebukel", "Idid", "Meketii", "Dngeronger"}, // KOROR
            {"Imul", "Ngerkeai", "Ngerutil", "Medeorm", "Ngerkeai Village", "Ngereklmadel", "Aimeliik Port", "Elechui", "Ngardmau Pt", "Ngulu"}, // AIMELIIK
            {"Melekeok Village", "Ngeruhel", "Ngermelech", "Ngerubesang", "Capitol Hill", "Melekeok East", "Ngeruhel South", "Melekeok West", "Beach Side", "Lake Ngardok"}, // MELEKEOK
            {"Ngermechau", "Ngeburch", "Ngardmau", "Ulimang", "Ngiwal Village", "Ngiwal Beach", "Ngaraard Pt", "Choll", "Elab", "Ngebei"}, // NGARAARD
            {"Ollei", "Mengellang", "Ngibiil", "Ngerbau", "Ngarchar", "Ngerechur", "Ngerkeklau", "Desekel", "Babeldaob", "Ngarchar North"}, // NGARCHELONG
            {"Ngetpang Village", "Ngatpang Tai", "Ngatpang Beach", "Ibobang", "Ngatpang Port", "Ngatpang West", "Ngatpang East", "Ngetpang North", "Hill Side", "Old Town"}, // NGARDMAU
            {"Ngatpang West", "Ngatpang East", "Ngatpang South", "Ngatpang Central", "Ngatpang North", "Ibobang Village", "Ngatpang Bay", "Ngatpang Road", "Jungle Side", "Dock Area"}, // NGATPANG
            {"Ngchesar Village", "Ngchesar Tai", "Ngchesar North", "Ngchesar South", "Ngerngesang", "Ngerikuul", "Ngchesar East", "Ngchesar West", "Forest View", "River Side"}, // NGCHESAR
            {"Ngiwal Village", "Ngiwal Tai", "Ngiwal North", "Ngiwal South", "Ngiwal East", "Ngiwal West", "Ngiwal Beach", "Ngiwal Port", "Ngiwal Hill", "Old Ngiwal"} // NGIWAL
        }
    },
    { // EUROPE
        { // 1. FRANCE
            {"Paris City", "Boulogne", "Saint-Denis", "Argenteuil", "Nanterre", "Creteil", "Versailles", "Courbevoie", "Vitry", "Colombes"}, // PARIS
            {"Lille", "Roubaix", "Tourcoing", "Dunkerque", "Villeneuve", "Valenciennes", "Douai", "Wattrelos", "Marcq", "Maubeuge"}, // NORD
            {"Marseille", "Aix-en-Provence", "Arles", "Martigues", "Aubagne", "Istres", "Salon", "Vitrolles", "Marignane", "La Ciotat"}, // BOUCHES-DU-RHONE
            {"Lyon", "Villeurbanne", "Venissieux", "Caluire", "Saint-Priest", "Vaulx-en-Velin", "Bron", "Villefranche", "Meyzieu", "Rillieux"}, // RHONE
            {"Bordeaux", "Merignac", "Pessac", "Talence", "Villenave", "Saint-Medard", "Begles", "Gradignan", "Cenon", "Libourne"}, // GIRONDE
            {"Calais", "Boulogne-sur-Mer", "Arras", "Lens", "Lievin", "Henin-Beaumont", "Bethune", "Bruay", "Avion", "Carvin"}, // PAS-DE-CALAIS
            {"Versailles City", "Sartrouville", "Mantes-la-Jolie", "Saint-Germain", "Poissy", "Conflans", "Trappes", "Les Mureaux", "Houilles", "Pluiseux"}, // YVELINES
            {"Toulouse", "Colomiers", "Tournefeuille", "Blagnac", "Muret", "Cugnaux", "Plaisance", "Balma", "L'Union", "Ramonville"}, // H-GARONNE
            {"Nantes", "Saint-Nazaire", "Saint-Herblain", "Reze", "Saint-Sebastien", "Orvault", "Vertou", "Coueron", "Carquefou", "Bouguenais"}, // L-ATLANTIQUE
            {"Saint-Denis City", "Montreuil", "Aulnay", "Aubervilliers", "Drancy", "Noisy-le-Grand", "Pantin", "Bondy", "Epinay", "Sevran"} // S-SAINT-DENIS
        },
        { // 2. GERMANY
            {"Munich", "Nuremberg", "Augsburg", "Regensburg", "Ingolstadt", "Wurzburg", "Furth", "Erlangen", "Bamberg", "Bayreuth"}, // BAVARIA
            {"Mitte", "Pankow", "Charlottenburg", "Neukolln", "Lichtenberg", "Reinickendorf", "Steglitz", "Spandau", "Treptow", "Marzahn"}, // BERLIN
            {"Altona", "Bergedorf", "Eimsbuttel", "Hamburg-Mitte", "Hamburg-Nord", "Harburg", "Wandsbek", "Wilhelmsburg", "St. Pauli", "Blankenese"}, // HAMBURG
            {"Leipzig", "Dresden", "Chemnitz", "Zwickau", "Plauen", "Gorlitz", "Freiberg", "Bautzen", "Pirna", "Hoyerswerda"}, // SAXONY
            {"Frankfurt", "Wiesbaden", "Kassel", "Darmstadt", "Offenbach", "Hanau", "Giessen", "Marburg", "Fulda", "Wetzlar"}, // HESSE
            {"Stuttgart", "Mannheim", "Karlsruhe", "Freiburg", "Heidelberg", "Heilbronn", "Pforzheim", "Ulm", "Ludwigsburg", "Esslingen"}, // B-WURTTEMBERG
            {"Cologne", "Dusseldorf", "Dortmund", "Essen", "Duisburg", "Bochum", "Wuppertal", "Bielefeld", "Bonn", "Munster"}, // NRW
            {"Hanover", "Braunschweig", "Oldenburg", "Osnabruck", "Wolfsburg", "Gottingen", "Salzgitter", "Hildesheim", "Delmenhorst", "Wilhelmshaven"}, // L. SAXONY
            {"Bremen City", "Bremerhaven", "Vegesack", "Blumenthal", "Burglesum", "Hemelingen", "Obervieland", "Huchting", "Findorff", "Walle"}, // BREMEN
            {"Erfurt", "Jena", "Gera", "Weimar", "Gotha", "Eisenach", "Nordhausen", "Suhl", "Altenburg", "Muhlhausen"} // THURINGIA
        },
        { // 3. ITALY
            {"Milan", "Brescia", "Monza", "Bergamo", "Busto Arsizio", "Sesto San G.", "Como", "Varese", "Ciniseall", "Pavia"}, // LOMBARDY
            {"Rome", "Latina", "Guidonia", "Fiumicino", "Aprilia", "Viterbo", "Pomezia", "Tivoli", "Anzio", "Velletri"}, // LAZIO
            {"Naples", "Salerno", "Giugliano", "Torre del Greco", "Pozzuoli", "Casoria", "Castellammare", "Afragola", "Marano", "Acerra"}, // CAMPANIA
            {"Palermo", "Catania", "Messina", "Siracusa", "Marsala", "Gela", "Ragusa", "Trapani", "Caltanissetta", "Agrigento"}, // SICILY
            {"Venice", "Verona", "Padua", "Vicenza", "Treviso", "Rovigo", "Chioggia", "Bassano", "San Dona", "Schio"}, // VENETO
            {"Turin", "Novara", "Alessandria", "Asti", "Moncalieri", "Cuneo", "Collegno", "Rivoli", "Vercelli", "Biella"}, // PIEDMONT
            {"Bologna", "Parma", "Modena", "Reggio Emilia", "Ravenna", "Rimini", "Ferrara", "Forli", "Piacenza", "Cesena"}, // E-ROMAGNA
            {"Florence", "Prato", "Livorno", "Arezzo", "Pistoia", "Lucca", "Pisa", "Grosseto", "Massa", "Carrara"}, // TUSCANY
            {"Bari", "Taranto", "Foggia", "Andria", "Lecce", "Barletta", "Brindisi", "Altamura", "Molfetta", "Manfredonia"}, // PUGLIA
            {"Genoa", "La Spezia", "Savona", "Sanremo", "Imperia", "Rapallo", "Chiavari", "Ventimiglia", "Albenga", "Sarzana"} // LIGURIA
        },
        { // 4. UNITED KINGDOM
            {"Manchester", "Birmingham", "Leeds", "Liverpool", "Sheffield", "Bristol", "Leicester", "Nottingham", "Newcastle", "Southampton"}, // ENGLAND
            {"Glasgow City", "Edinburgh City", "Aberdeen", "Dundee", "Paisley", "East Kilbride", "Livingston", "Hamilton", "Dunfermline", "Cumbernauld"}, // SCOTLAND
            {"Cardiff", "Swansea", "Newport", "Wrexham", "Barry", "Neath", "Bridgend", "Cwmbran", "Llanelli", "Pontypridd"}, // WALES
            {"Belfast", "Derry", "Lisburn", "Newry", "Armagh", "Bangor", "Ballymena", "Coleraine", "Carrickfergus", "Antrim"}, // N. IRELAND
            {"Westminster", "Camden", "Greenwich", "Hackney", "Islington", "Chelsea", "Southwark", "Tower Hamlets", "Lambeth", "Wandsworth"}, // LONDON
            {"Salford", "Bolton", "Oldham", "Rochdale", "Stockport", "Tameside", "Trafford", "Wigan", "Bury", "Stretford"}, // MANCHESTER
            {"Solihull", "Sutton Coldfield", "Halesowen", "Dudley", "Walsall", "West Bromwich", "Stourbridge", "Erdington", "Edgbaston", "Handsworth"}, // BIRMINGHAM
            {"Govan", "Partick", "Hillhead", "Maryhill", "Pollokshields", "Shawlands", "Cathcart", "Castlemilk", "Drumchapel", "Easterhouse"}, // GLASGOW
            {"Birkenhead", "St Helens", "Wallasey", "Crosby", "Bootle", "Kirkby", "Southport", "Bebington", "Prescot", "Formby"}, // LIVERPOOL
            {"Leith", "Corstorphine", "Portobello", "Morningside", "Gorgie", "Newington", "Liberton", "Colinton", "Granton", "Stockbridge"} // EDINBURGH
        },
        { // 5. SPAIN
            {"Seville", "Malaga", "Cordoba", "Granada", "Jerez", "Almeria", "Huelva", "Cadiz", "Marbella", "Dos Hermanas"}, // ANDALUSIA
            {"Barcelona", "L'Hospitalet", "Badalona", "Terrassa", "Sabadell", "Tarragona", "Mataro", "Santa Coloma", "Reus", "Girona"}, // CATALONIA
            {"Madrid City", "Mostoles", "Alcala", "Fuenlabrada", "Leganes", "Getafe", "Alcorcon", "Parla", "Alcobendas", "Coslada"}, // MADRID
            {"Valencia City", "Alicante", "Elche", "Castellon", "Torrevieja", "Torrent", "Orihuela", "Gandia", "Paterna", "Sagunto"}, // VALENCIA
            {"Vigo", "A Coruna", "Ourense", "Lugo", "Santiago", "Pontevedra", "Ferrol", "Narón", "Oleiros", "Carballo"}, // GALICIA
            {"Valladolid", "Burgos", "Salamanca", "Leon", "Palencia", "Ponferrada", "Zamora", "Avila", "Segovia", "Soria"}, // CASTILE & LEON
            {"Bilbao", "Vitoria-Gasteiz", "San Sebastian", "Barakaldo", "Getxo", "Irun", "Portugalete", "Santurtzi", "Basauri", "Errenteria"}, // BASQUE COUNTRY
            {"Las Palmas", "Santa Cruz", "San Cristobal", "Telde", "Arona", "Santa Lucia", "Arrecife", "San Bartolome", "Adeje", "Puerto del Rosario"}, // CANARY IS.
            {"Murcia City", "Cartagena", "Lorca", "Molina de Segura", "Alcantarilla", "Mazarron", "Cieza", "Yecla", "Aguilas", "Torre-Pacheco"}, // MURCIA
            {"Zaragoza", "Huesca", "Teruel", "Calatayud", "Utebo", "Monzon", "Barbastro", "Ejea", "Alcañiz", "Fraga"} // ARAGON
        },
        { // 6. RUSSIA
            {"Central Dist", "Arbat", "Tverskoy", "Basmanny", "Khamovniki", "Tagansky", "Presnensky", "Meshchansky", "Zamoskvorechye", "Yakimanka"}, // MOSCOW CITY
            {"Vasileostrovsky", "Vyborgsky", "Kalininsky", "Kirovsky", "Kolpinsky", "Krasnogvardeysky", "Krasnoselsky", "Kronstadtsky", "Kurortny", "Moskovsky"}, // ST. PETERSBURG
            {"Kazan", "Naberezhnye", "Almetyevsk", "Zelenodolsk", "Nizhnekamsk", "Bugulma", "Yelabuga", "Leninogorsk", "Chistopol", "Zainsk"}, // TATARSTAN
            {"Krasnodar City", "Sochi", "Novorossiysk", "Armavir", "Yeysk", "Kropotkin", "Slavyansk", "Tuapse", "Labinsk", "Tikhoretsk"}, // KRASNODAR
            {"Yekaterinburg", "Nizhny Tagil", "Kamensk-Uralsky", "Pervouralsk", "Serov", "Novouralsk", "Asbest", "Polevskoy", "Revda", "Verkhnyaya Pyshma"}, // SVERDLOVSK
            {"Rostov-on-Don", "Taganrog", "Shakhty", "Novocherkassk", "Volgodonsk", "Bataysk", "Novoshakhtinsk", "Azov", "Kamensk-Shakhtinsky", "Gukovo"}, // ROSTOV
            {"Ufa", "Sterlitamak", "Salavat", "Neftekamsk", "Oktyabrsky", "Beloretsk", "Tuymazy", "Ishimbay", "Kumertau", "Meleuz"}, // BASHKORTOSTAN
            {"Balashikha", "Podolsk", "Khimki", "Mytishchi", "Korolyov", "Lyubertsy", "Krasnogorsk", "Elektrostal", "Kolomna", "Odintsovo"}, // MOSCOW OBLAST
            {"Samara City", "Tolyatti", "Syzran", "Novokuybyshevsk", "Chapayevsk", "Zhigulyovsk", "Otradny", "Kinél", "Pokhvistnevo", "Oktyabrsk"}, // SAMARA
            {"Chelyabinsk City", "Magnitogorsk", "Zlatoust", "Miass", "Kopeysk", "Ozyorsk", "Troitsk", "Snezhinsk", "Satka", "Chebarkul"} // CHELYABINSK
        },
        { // 7. SWITZERLAND
            {"Zurich City", "Winterthur", "Uster", "Dubendorf", "Dietikon", "Wetzikon", "Wadenswil", "Horgen", "Kloten", "Adliswil"}, // ZURICH
            {"Bern City", "Thun", "Koniz", "Ostermundigen", "Burgdorf", "Steffisburg", "Langenthal", "Muri", "Spiez", "Worb"}, // BERN
            {"Lausanne", "Yverdon", "Montreux", "Morges", "Nyon", "Renens", "Vevey", "Pully", "Gland", "Ecublens"}, // VAUD
            {"Aarau", "Wettingen", "Baden", "Wohlen", "Ofstringen", "Rheinfelden", "Spreitenbach", "Zofingen", "Brugg", "Mohlis"}, // AARGAU
            {"St. Gallen City", "Rapperswil-Jona", "Wil", "Gossau", "Wattwil", "Uzwil", "Altstatten", "Buchs", "Flawil", "Rorschach"}, // ST. GALLEN
            {"Geneva City", "Vernier", "Lancy", "Meyrin", "Carouge", "Onex", "Thonex", "Versoix", "Chenit", "Veyrier"}, // GENEVA
            {"Lucerne City", "Emmen", "Kriens", "Ebikon", "Horw", "Sursee", "Hochdorf", "Dagmersellen", "Ruswil", "Willisau"}, // LUCERNE
            {"Lugano", "Bellinzona", "Locarno", "Mendrisio", "Chiasso", "Giubiasco", "Minusio", "Losone", "Riva", "Biasca"}, // TICINO
            {"Sion", "Martigny", "Monthey", "Sierre", "Brig-Glis", "Visp", "Naters", "Vionnaz", "St-Maurice", "Bagnes"}, // VALAIS
            {"Basel City", "Riehen", "Bettingen", "St. Johann", "Gundeldingen", "Bachletten", "Matthaus", "Klybeck", "Wettstein", "Hirzbrunnen"} // BASEL-STADT
        },
        { // 8. GREECE
            {"Athens", "Piraeus", "Peristeri", "Kallithea", "Acharnes", "Nikaia", "Glyfada", "Ilio", "Zografou", "Egaleo"}, // ATTICA
            {"Thessaloniki", "Kalamaria", "Katerini", "Serres", "Veria", "Giannitsa", "Kilkis", "Oreokastro", "Pylaia", "Thermi"}, // C. MACEDONIA
            {"Larissa", "Volos", "Trikala", "Karditsa", "Elassona", "Tirnavos", "Farsala", "Almyros", "Kalampaka", "Palamas"}, // THESSALY
            {"Patras", "Agrinio", "Aigio", "Pyrgos", "Mesolonghi", "Nafpaktos", "Amaliada", "Kato Achaia", "Ovrya", "Rio"}, // W. GREECE
            {"Heraklion", "Chania", "Rethymno", "Ierapetra", "Agios Nikolaos", "Sitia", "Gazi", "Kissamos", "Arkalochori", "Malia"}, // CRETE
            {"Kalamata", "Tripoli", "Corinth", "Argos", "Sparta", "Nafplio", "Loutraki", "Kiato", "Messini", "Gargalianoi"}, // PELOPONNESE
            {"Ioannina", "Arta", "Preveza", "Igoumenitsa", "Anatoli", "Konitsa", "Metsovo", "Paramythia", "Filippiada", "Parga"}, // EPIRUS
            {"Rhodes", "Kos", "Kalymnos", "Naxos", "Mykonos", "Santorini", "Paros", "Syros", "Leros", "Patmos"}, // S. AEGEAN
            {"Mytilene", "Chios", "Samos", "Myrina", "Plomari", "Karlovasi", "Vathy", "Molyvos", "Pyrgi", "Olympoi"}, // N. AEGEAN
            {"Chalcis", "Lamia", "Thebes", "Livadeia", "Amfissa", "Karpenisi", "Istiaia", "Eretria", "Aliartos", "Psachna"} // C. GREECE
        },
        { // 9. NORWAY
            {"Oslo City", "Sentrum", "Frogner", "Grünerløkka", "Gamle Oslo", "St. Hanshaugen", "Ullern", "Vestre Aker", "Nordre Aker", "Bjerke"}, // OSLO
            {"Sandvika", "Asker", "Lillestrøm", "Drammen", "Fredrikstad", "Sarpsborg", "Moss", "Hønefoss", "Jessheim", "Ski"}, // VIKEN
            {"Bergen", "Stavanger", "Sandnes", "Haugesund", "Sotra", "Askøy", "Osøyro", "Leirvik", "Knarvik", "Odda"}, // VESTLAND
            {"Stavanger City", "Sandnes", "Bryne", "Egersund", "Kopervik", "Åkrehamn", "Jørpeland", "Sauda", "Skudeneshavn", "Tananger"}, // ROGALAND
            {"Tønsberg", "Sandefjord", "Larvik", "Horten", "Porsgrunn", "Skien", "Notodden", "Rjukan", "Stathelle", "Langesund"}, // VESTFOLD
            {"Hamar", "Lillehammer", "Gjøvik", "Kongsvinger", "Elverum", "Brumunddal", "Bekkelaget", "Raufoss", "Moelv", "Tynset"}, // INNLANDET
            {"Kristiansand", "Arendal", "Grimstad", "Mandal", "Vennesla", "Farsund", "Flekkefjord", "Lillesand", "Risør", "Tvedestrand"}, // AGDER
            {"Bodø", "Narvik", "Mo i Rana", "Mosjøen", "Sandnessjøen", "Fauske", "Sortland", "Brønnøysund", "Leknes", "Svolvær"}, // NORDLAND
            {"Tromsø", "Harstad", "Finnsnes", "Setermoen", "Skjervøy", "Storslett", "Silsand", "Bardu", "Målselv", "Lyngen"}, // TROMS
            {"Alta", "Hammerfest", "Vadsø", "Kirkenes", "Vardø", "Honningsvåg", "Lakselv", "Karasjok", "Kautokeino", "Båtsfjord"} // FINNMARK
        },
        { // 10. NETHERLANDS
            {"Rotterdam", "The Hague", "Zoetermeer", "Leiden", "Dordrecht", "Alphen", "Westland", "Delft", "Schiedam", "Spijkenisse"}, // S. HOLLAND
            {"Amsterdam", "Haarlem", "Zaanstad", "Haarlemmermeer", "Alkmaar", "Amstelveen", "Hilversum", "Purmerend", "Hoorn", "Velsen"}, // N. HOLLAND
            {"Eindhoven", "Tilburg", "Breda", "Den Bosch", "Helmond", "Roosendaal", "Oss", "Bergen op Zoom", "Oosterhout", "Waalwijk"}, // N. BRABANT
            {"Utrecht City", "Amersfoort", "Veenendaal", "Zeist", "Nieuwegein", "Woerden", "Houten", "IJsselstein", "Soest", "De Bilt"}, // UTRECHT
            {"Nijmegen", "Arnhem", "Apeldoorn", "Ede", "Doetinchem", "Barneveld", "Zutphen", "Harderwijk", "Overbetuwe", "Wageningen"}, // GELDERLAND
            {"Enschede", "Zwolle", "Deventer", "Hengelo", "Almelo", "Kampen", "Hardenberg", "Oldenzaal", "Raalte", "Steenwijkerland"}, // OVERIJSSEL
            {"Maastricht", "Venlo", "Sittard-Geleen", "Heerlen", "Roermond", "Weert", "Kerkrade", "Landgraaf", "Brunssum", "Stein"}, // LIMPOPO (LIMBURG)
            {"Leeuwarden", "Drachten", "Sneek", "Heerenveen", "Harlingen", "Franeker", "Joure", "Wolvega", "Lemmer", "Dokkum"}, // FRIESLAND
            {"Groningen City", "Delfzijl", "Hoogezand", "Stadskanaal", "Veendam", "Winschoten", "Haren", "Appingedam", "Leek", "Ter Apel"}, // GRONINGEN
            {"Assen", "Emmen", "Hoogeveen", "Meppel", "Coevorden", "Beilen", "Roden", "Klazienaveen", "Zuidlaren", "Eelde"} // DRENTHE
        }
    },
    { // NORTH AMERICA
        { // 1. USA
            {"Los Angeles", "San Diego", "San Jose", "San Francisco", "Fresno", "Sacramento", "Long Beach", "Oakland", "Bakersfield", "Anaheim"}, // CALIFORNIA
            {"Houston", "San Antonio", "Dallas", "Austin", "Fort Worth", "El Paso", "Arlington", "Corpus Christi", "Plano", "Lubbock"}, // TEXAS
            {"Miami", "Tampa", "Orlando", "Jacksonville", "St. Petersburg", "Hialeah", "Tallahassee", "Fort Lauderdale", "Port St. Lucie", "Cape Coral"}, // FLORIDA
            {"New York City", "Buffalo", "Rochester", "Yonkers", "Syracuse", "Albany", "New Rochelle", "Mount Vernon", "Schenectady", "Utica"}, // NEW YORK
            {"Chicago", "Aurora", "Rockford", "Joliet", "Naperville", "Springfield", "Peoria", "Elgin", "Waukegan", "Cicero"}, // ILLINOIS
            {"Philadelphia", "Pittsburgh", "Allentown", "Erie", "Reading", "Scranton", "Bethlehem", "Lancaster", "Harrisburg", "Altoona"}, // PENNSYLVANIA
            {"Columbus", "Cleveland", "Cincinnati", "Toledo", "Akron", "Dayton", "Parma", "Canton", "Youngstown", "Lorain"}, // OHIO
            {"Atlanta", "Augusta", "Columbus", "Macon", "Savannah", "Athens", "Sandy Springs", "Roswell", "Johns Creek", "Warner Robins"}, // GEORGIA
            {"Charlotte", "Raleigh", "Greensboro", "Durham", "Winston-Salem", "Fayetteville", "Cary", "Wilmington", "High Point", "Concord"}, // NORTH CAROLINA
            {"Detroit", "Grand Rapids", "Warren", "Sterling Heights", "Ann Arbor", "Lansing", "Flint", "Dearborn", "Livonia", "Westland"} // MICHIGAN
        },
        { // 2. CANADA
            {"Toronto", "Ottawa", "Mississauga", "Brampton", "Hamilton", "London", "Markham", "Vaughan", "Kitchener", "Windsor"}, // ONTARIO
            {"Montreal", "Quebec City", "Laval", "Gatineau", "Longueuil", "Sherbrooke", "Levis", "Saguenay", "Trois-Rivieres", "Terrebonne"}, // QUEBEC
            {"Vancouver", "Surrey", "Burnaby", "Richmond", "Abbotsford", "Coquitlam", "Kelowna", "Nanaimo", "Kamloops", "Victoria"}, // BRITISH COLUMBIA
            {"Calgary", "Edmonton", "Red Deer", "Lethbridge", "St. Albert", "Medicine Hat", "Grande Prairie", "Airdrie", "Spruce Grove", "Leduc"}, // ALBERTA
            {"Winnipeg", "Brandon", "Steinbach", "Thompson", "Portage la Prairie", "Selkirk", "Winkler", "Dauphin", "Morden", "The Pas"}, // MANITOBA
            {"Saskatoon", "Regina", "Prince Albert", "Moose Jaw", "Swift Current", "Yorkton", "North Battleford", "Estevan", "Weyburn", "Martensville"}, // SASKATCHEWAN
            {"Halifax", "Sydney", "Dartmouth", "Truro", "New Glasgow", "Glace Bay", "Kentville", "Amherst", "Bridgewater", "Yarmouth"}, // NOVA SCOTIA
            {"Moncton", "Saint John", "Fredericton", "Dieppe", "Riverview", "Quispamsis", "Miramichi", "Edmundston", "Bathurst", "Rothesay"}, // NEW BRUNSWICK
            {"St. John's", "Mount Pearl", "Corner Brook", "Conception Bay", "Paradise", "Gander", "Grand Falls", "Torbay", "Labrador City", "Happy Valley"}, // NEWFOUNDLAND
            {"Charlottetown", "Summerside", "Stratford", "Cornwall", "Three Rivers", "Kensington", "Souris", "Alberton", "Tignish", "Borden-Carleton"} // PRINCE EDWARD IS.
        },
        { // 3. MEXICO
            {"Iztapalapa", "Gustavo Madero", "Alvaro Obregon", "Tlalpan", "Coyoacan", "Cuauhtemoc", "Venustiano Carranza", "Xochimilco", "Benito Juarez", "Azcapotzalco"}, // MEXICO CITY
            {"Guadalajara", "Zapopan", "Tlaquepaque", "Tonala", "Puerto Vallarta", "Tlajomulco", "Lagos de Moreno", "Tepatitlan", "Ciudad Guzman", "Ocotlan"}, // JALISCO
            {"Veracruz City", "Xalapa", "Coatzacoalcos", "Minatitlan", "Orizaba", "Cordoba", "Poza Rica", "Tuxpan", "Boca del Rio", "Cosoleacaque"}, // VERACRUZ
            {"Puebla City", "Tehuacan", "San Martin", "Cholula", "Atlixco", "Amozoc", "Huauchinango", "San Pedro", "Zacatlan", "Izucar"}, // PUEBLA
            {"Leon", "Irapuato", "Celaya", "Salamanca", "Silao", "Guanajuato City", "San Miguel de Allende", "Valle de Santiago", "Dolores Hidalgo", "Acambaro"}, // GUANAJUATO
            {"Monterrey", "Guadalupe", "Apodaca", "San Nicolas", "General Escobedo", "Santa Catarina", "Juarez", "San Pedro Garza", "Garcia", "Cadereyta"}, // NUEVO LEON
            {"Tuxtla Gutierrez", "Tapachula", "San Cristobal", "Comitan", "Chiapa de Corzo", "Palenque", "Tonala", "Cintalapa", "Huixtla", "Ocosingo"}, // CHIAPAS
            {"Morelia", "Uruapan", "Zamora", "Lazaro Cardenas", "Apatzingan", "Zitacuaro", "La Piedad", "Sahuayo", "Hidalgo", "Jacona"}, // MICHOACAN
            {"Oaxaca City", "San Juan Bautista", "Salina Cruz", "Juchitan", "Huajuapan", "Tehuantepec", "Loma Bonita", "Puerto Escondido", "Miahuatlan", "Tlacolula"}, // OAXACA
            {"Acapulco", "Chilpancingo", "Iguala", "Taxco", "Zihuatanejo", "Chilapa", "Tlapa", "Pungarabato", "Tixtla", "Ometepec"} // GUERRERO
        },
        { // 4. CUBA
            {"Old Havana", "Vedado", "Miramar", "Centro Habana", "Playa", "Marianao", "Boyeros", "Guanabacoa", "San Miguel", "Cotorro"}, // HAVANA
            {"Santiago City", "Palma Soriano", "Contramaestre", "San Luis", "Songo-La Maya", "Guama", "Mella", "Tercer Frente", "Segundo Frente", "Cruces"}, // SANTIAGO DE CUBA
            {"Holguin City", "Banes", "Mayari", "Moa", "Sagua de Tanamo", "Gibara", "Calixto Garcia", "Cueto", "Urbano Noris", "Baguanos"}, // HOLGUIN
            {"Santa Clara", "Sagua la Grande", "Placetas", "Caibarien", "Remedios", "Camajuani", "Santo Domingo", "Ranchuelo", "Manicaragua", "Corralillo"}, // VILLA CLARA
            {"Camaguey City", "Florida", "Nuevitas", "Vertientes", "Guaimaro", "Santa Cruz del Sur", "Sibanicu", "Esmeralda", "Jimaguayu", "Minas"}, // CAMAGUEY
            {"Matanzas City", "Cardenas", "Varadero", "Colon", "Jaguey Grande", "Jovellanos", "Pedro Betancourt", "Perico", "Union de Reyes", "Limonar"}, // MATANZAS
            {"Pinar del Rio City", "Consolacion del Sur", "San Juan y Martinez", "Vinales", "Sandino", "Mantua", "Guane", "Los Palacios", "La Palma", "Minas de Matahambre"}, // PINAR DEL RIO
            {"Las Tunas City", "Puerto Padre", "Jobabo", "Colombia", "Majibacoa", "Manati", "Amancio", "Jesus Menendez", "Vazquez", "Bartle"}, // LAS TUNAS
            {"Artemisa City", "Bauta", "Mariel", "San Antonio", "Guanajay", "Bahia Honda", "Candelaria", "San Cristobal", "Alquizar", "Guira de Melena"}, // ARTEMISA
            {"Bayamo", "Manzanillo", "Jiguani", "Niquero", "Campechuela", "Bartolome Maso", "Yara", "Guisa", "Buey Arriba", "Rio Cauto"} // GRANMA
        },
        { // 5. PANAMA
            {"Panama City", "San Miguelito", "Tocumen", "Juan Diaz", "Pacora", "Chorrera", "Arraijan", "Ancon", "Bella Vista", "Betania"}, // PANAMA
            {"David", "Boquete", "Bugaba", "Alanje", "Baru", "Dolega", "Gualaca", "Remedios", "Renacimiento", "San Lorenzo"}, // CHIRIQUI
            {"La Chorrera City", "Arraijan City", "Capira", "Chame", "San Carlos", "Puerto Caimito", "Guadalupe", "Playa Leona", "Santa Rita", "Lidice"}, // WEST PANAMA
            {"Colon City", "Chagres", "Donoso", "Portobelo", "Santa Isabel", "Sabanitas", "Cativa", "Buena Vista", "Salamanca", "Limón"}, // COLON
            {"Penonome", "Aguadulce", "Antón", "La Pintada", "Ola", "Nata", "El Valle", "Rio Hato", "Cocle City", "Pocrí"}, // COCLE
            {"Santiago City", "Atalaya", "Calobre", "Cañazas", "La Mesa", "Las Palmas", "Montijo", "Río de Jesús", "Santa Fe", "Soná"}, // VERAGUAS
            {"Chitré", "Las Minas", "Los Pozos", "Ocú", "Parita", "Pesé", "Santa María", "La Arena", "Monagrillo", "San Juan"}, // HERRERA
            {"Las Tablas", "Guararé", "Los Santos City", "Macaracas", "Pedasí", "Pocrí", "Tonosí", "La Espigadilla", "Sabana Grande", "Vallerriquito"}, // LOS SANTOS
            {"Bocas del Toro City", "Changuinola", "Chiriquí Grande", "Almirante", "Bastimentos", "Cauchero", "Punta Laurel", "Tierra Oscura", "Guabito", "El Teribe"}, // BOCAS DEL TORO
            {"La Palma", "El Real de Santa Maria", "Garachiné", "Jaqué", "Yaviza", "Metetí", "Puerto Piña", "Taimatí", "Canglón", "Santa Fé"} // DARIEN
        },
        { // 6. JAMAICA
            {"Kingston City", "Half Way Tree", "Stony Hill", "Trench Town", "Harbour View", "Gordon Town", "Mavis Bank", "August Town", "Cross Roads", "Vineyard Town"}, // ST. ANDREW
            {"Spanish Town", "Portmore", "Old Harbour", "Linstead", "Bog Walk", "Ewarton", "Lannibes", "Guy's Hill", "Gregory Park", "Waterford"}, // ST. CATHERINE
            {"May Pen", "Lionel Town", "Hayes", "Chapelton", "Frankfield", "Spaldings", "Kellits", "Race Course", "Rocky Point", "Mocho"}, // CLARENDON
            {"Montego Bay", "Anchovy", "Cambridge", "Montpelier", "Reading", "Somerton", "Rose Hall", "Adelphi", "Spring Mount", "Maroon Town"}, // ST. JAMES
            {"Ocho Rios", "St. Ann's Bay", "Brown's Town", "Discovery Bay", "Runaway Bay", "Claremont", "Moneague", "Watt Town", "Bamboo", "Alexandria"}, // ST. ANN
            {"Black River", "Santa Cruz", "Junction", "Malvern", "Nain", "Lacovia", "Maggotty", "Bull Savanna", "Newmarket", "Balaclava"}, // ST. ELIZABETH
            {"Mandeville", "Christiana", "Porus", "Williamsfield", "Mile Gully", "Newport", "Royal Flat", "Hatfield", "Knockpatrick", "Old England"}, // MANCHESTER
            {"Savanna-la-Mar", "Grange Hill", "Negril", "Little London", "Petersfield", "Whitehouse", "Darliston", "Bethel Town", "Bluefields", "Sheffield"}, // WESTMORELAND
            {"Port Maria", "Annotto Bay", "Oracabessa", "Highgate", "Gayle", "Richmond", "Islington", "Guys Hill", "Castleaton", "Boscobel"}, // ST. MARY
            {"Port Antonio", "Buff Bay", "Hope Bay", "Manchioneal", "Fairy Hill", "St. Margaret's Bay", "Long Bay", "Moore Town", "Fruitful Vale", "Swift River"} // PORTLAND
        },
        { // 7. COSTA RICA
            {"San Jose City", "Escazu", "Desamparados", "Puriscal", "Tarrazu", "Aserrí", "Mora", "Goicoechea", "Santa Ana", "Alajuelita"}, // SAN JOSE
            {"Alajuela City", "San Ramon", "Grecia", "San Mateo", "Atenas", "Naranjo", "Palmares", "Poas", "Orotina", "San Carlos"}, // ALAJUELA
            {"Cartago City", "Paraiso", "La Union", "Jimenez", "Turrialba", "Alvarado", "Oreamuno", "El Guarco", "Pacayas", "Tierra Blanca"}, // CARTAGO
            {"Heredia City", "Barva", "Santo Domingo", "Santa Barbara", "San Rafael", "San Isidro", "Belen", "Flores", "San Pablo", "Sarapiqui"}, // HEREDIA
            {"Liberia", "Nicoya", "Santa Cruz", "Bagaces", "Cañas", "Abangares", "Tilaran", "Nandayure", "La Cruz", "Hojancha"}, // GUANACASTE
            {"Puntarenas City", "Esparza", "Buenos Aires", "Montes de Oro", "Osa", "Quepos", "Golfito", "Coto Brus", "Parrita", "Corredores"}, // PUNTARENAS
            {"Limon City", "Pococi", "Siquirres", "Talamanca", "Matina", "Guacimo", "Cahuita", "Puerto Viejo", "Bribri", "Tortuguero"}, // LIMON
            {"Quesada", "Aguas Zarcas", "Pital", "La Fortuna", "Florencia", "Pocosol", "Venecia", "Monterrey", "Cutris", "La Tigra"}, // San Carlos
            {"San Isidro", "General", "Daniel Flores", "Cajon", "Baru", "Rio Nuevo", "Platanares", "Pejibaye", "Paramo", "La Amistad"}, // Perez Zeledon
            {"Liberia City", "Cañas Dulces", "Mayorga", "Nacascolo", "Curubande", "Blanca", "Dos Rios", "Guayabo", "Aguas Claras", "Zapote"} // Liberia
        },
        { // 8. GUATEMALA
            {"Guatemala City", "Mixco", "Villa Nueva", "Petapa", "Amatitlan", "Villa Canales", "Chinautla", "Fraijanes", "Santa Catarina", "San Jose Pinula"}, // GUATEMALA
            {"Huehuetenango City", "Chiantla", "Malacatancito", "Cuilco", "Nenton", "San Pedro Necta", "Jacaltenango", "Soloma", "Ixtahuacan", "Libertad"}, // HUEHUETENANGO
            {"Coban", "Santa Cruz Verapaz", "San Cristobal", "Tactic", "Tamahu", "Tucuru", "Panzos", "Senahu", "Chahal", "Lanquín"}, // ALTA VERAPAZ
            {"San Marcos City", "San Pedro Sac.", "Comitancillo", "San Antonio Sac.", "San Miguel Ixt.", "Concepcion Tut.", "Tacaná", "Sibinal", "Tajumulco", "Tejutla"}, // SAN MARCOS
            {"Santa Cruz del Quiche", "Chichicastenango", "Chinique", "Zacualpa", "Chajul", "Chicaman", "Ixcán", "Joyabaj", "Nebaj", "Cunén"}, // QUICHE
            {"Quetzaltenango City", "Salcaja", "Olintepeque", "San Carlos Sija", "Sibilia", "Cabrican", "Cajola", "Almolonga", "Cantel", "Zunil"}, // QUETZALTENANGO
            {"Escuintla City", "Santa Lucia Cotz.", "La Democracia", "Siquinala", "Masagua", "Tiquisate", "La Gomera", "Guanagazapa", "San Jose", "Iztapa"}, // ESCUINTLA
            {"Mazatenango", "Cuyotenango", "San Francisco Zapotitlan", "San Bernardino", "Samayac", "San Pablo Jocopilas", "San Antonio", "San Miguel Panan", "Chicacao", "Patulul"}, // SUCHITEPEQUEZ
            {"Totonicapan City", "San Cristobal Tot.", "San Francisco El Alto", "Santa Maria Chiquimula", "Momostenango", "Santa Lucia La Reforma", "San Bartolo", "San Andres Xecul", "N/A-1", "N/A-2"}, // TOTONICAPAN
            {"Solola City", "San Jose Chacaya", "Santa Maria Vis.", "Santa Lucia Ut.", "Nahuala", "Santa Catarina Ixt.", "Santa Clara La Laguna", "Concepcion", "Panajachel", "San Andres Semetabaj"} // SOLOLA
        },
        { // 9. BAHAMAS
            {"Nassau", "Lyford Cay", "Paradise Island", "Cable Beach", "Adelaide", "Fox Hill", "Gambier", "Carmichael", "South Beach", "Sea Breeze"}, // NEW PROVIDENCE
            {"Freeport", "Lucaya", "West End", "Eight Mile Rock", "High Rock", "McLeans Town", "Pinder's Point", "Williams Town", "Hunters", "Lewis Yard"}, // GRAND BAHAMA
            {"Marsh Harbour", "Hope Town", "Treasure Cay", "Green Turtle Cay", "Sandy Point", "Man-O-War Cay", "Guana Cay", "Dundas Town", "Murphy Town", "Cherokee"}, // ABACO
            {"Governor's Harbour", "Rock Sound", "Harbour Island", "Spanish Wells", "Gregory Town", "Alice Town", "Tarpum Bay", "Bannerman Town", "Deep Creek", "Green Castle"}, // ELEUTHERA
            {"Nicholls Town", "Andros Town", "Congo Town", "Kemps Bay", "Mastic Point", "Staniard Creek", "Fresh Creek", "Blanket Sound", "Love Hill", "Behring Point"}, // ANDROS
            {"George Town", "Staniel Cay", "Black Point", "Farmers Cay", "Little Exuma", "Rolleville", "Steventon", "Forbes Hill", "Williams Town", "Harts"}, // EXUMA
            {"Clarence Town", "Deadman's Cay", "Simms", "Salt Pond", "Buckleys", "Burnt Ground", "Hamiltons", "Mangled Cay", "Petty's", "Roses"}, // LONG ISLAND
            {"Alice Town", "Bailey Town", "Porgy Bay", "South Bimini", "Gun Cay", "Cat Cay", "Ocean Cay", "N/A-1", "N/A-2", "N/A-3"}, // BIMINI
            {"Arthur's Town", "New Bight", "Old Bight", "Port Howe", "Devil's Point", "Orange Creek", "Dumfries", "Wilson's Bay", "Knowles", "Zonicle's"}, // CAT ISLAND
            {"Matthew Town", "Great Inagua", "Little Inagua", "Lantern Head", "Mortimer's", "N/A-1", "N/A-2", "N/A-3", "N/A-4", "N/A-5"} // INAGUA
        },
        { // 10. HONDURAS
            {"Tegucigalpa", "Comayaguela", "Santa Lucia", "Valle de Angeles", "Ojojona", "San Buenaventura", "Tatumbla", "Sabanagrande", "Cantarranas", "Villa de San Francisco"}, // FRANCISCO MORAZAN
            {"San Pedro Sula", "Choloma", "Puerto Cortes", "Villanueva", "La Lima", "San Manuel", "Pimienta", "Potrerillos", "Omoa", "Santa Cruz de Yojoa"}, // CORTES
            {"Choluteca City", "San Marcos de Colon", "Pespire", "El Corpus", "Namasigue", "Marcovia", "Orocuina", "Duyure", "Apacilagua", "Concepcion de Maria"}, // CHOLUTECA
            {"Comayagua City", "Siguatepeque", "La Libertad", "Ajuterique", "Lejamani", "El Rosario", "Taulabe", "San Jeronimo", "Meambar", "Ojos de Agua"}, // COMAYAGUA
            {"Danli", "El Paraiso City", "Yuscaran", "Teupasenti", "Moroceli", "Jacaleapa", "Liure", "Soledad", "Texiguat", "Vado Ancho"}, // EL PARAISO
            {"La Ceiba", "Tela", "Jutiapa", "La Masica", "Esparta", "San Francisco", "El Porvenir", "Arizona", "N/A-1", "N/A-2"}, // ATLANTIDA
            {"El Progreso", "Yoro City", "Olanchito", "Santa Rita", "Sulaco", "Morazan", "Victoria", "Yorito", "Jocón", "Arenal"}, // YORO
            {"Juticalpa", "Catacamas", "Campamento", "Dulce Nombre", "San Esteban", "Salamá", "Manto", "Guarizama", "Concordia", "Gualaco"}, // OLANCHO
            {"Santa Barbara City", "Trinidad", "Quimistan", "Azacualpa", "Macuelizo", "Petoa", "San Marcos", "Santa Rita", "Ceguaca", "Naranjito"}, // SANTA BARBARA
            {"Santa Rosa de Copan", "Copan Ruinas", "La Entrada", "Cucuyagua", "Florida", "Dulce Nombre", "San Agustin", "San Juan de Opoa", "N/A-1", "N/A-2"} // COPAN
        }
    },
    { // SOUTH AMERICA
        { // 1. BRAZIL
            {"Sao Paulo City", "Guarulhos", "Campinas", "Sao Bernardo", "Santo Andre", "Osasco", "Sorocaba", "Ribeirao Preto", "Santos", "Maua"}, // SAO PAULO
            {"Belo Horizonte", "Uberlandia", "Contagem", "Juiz de Fora", "Betim", "Montes Claros", "Ribeirao Neves", "Uberaba", "Governador", "Ipatinga"}, // MINAS GERAIS
            {"Rio City", "Sao Goncalo", "Duque de Caxias", "Nova Iguacu", "Niteroi", "Belford Roxo", "Campos", "Sao Joao", "Petropolis", "Volta Redonda"}, // RIO DE JANEIRO
            {"Salvador", "Feira de Santana", "Vitoria da Conquista", "Camacari", "Itabuna", "Juazeiro", "Ilheus", "Lauro de Freitas", "Jequie", "Alagoinhas"}, // BAHIA
            {"Curitiba", "Londrina", "Maringa", "Ponta Grossa", "Cascavel", "Sao Jose", "Foz do Iguacu", "Colombo", "Guarapuava", "Paranagua"}, // PARANA
            {"Porto Alegre", "Caxias do Sul", "Canoas", "Pelotas", "Santa Maria", "Gravatai", "Viamao", "Novo Hamburgo", "Sao Leopoldo", "Rio Grande"}, // R.G. DO SUL
            {"Recife", "Jaboatao", "Olinda", "Caruaru", "Petrolina", "Paulista", "Cabo de Santo", "Camaragibe", "Garanhuns", "Vitoria"}, // PERNAMBUCO
            {"Fortaleza", "Caucaia", "Juazeiro do Norte", "Maracanau", "Sobral", "Crato", "Itapipoca", "Maranguape", "Quixada", "Iguatu"}, // CEARA
            {"Belem", "Ananindeua", "Santarem", "Maraba", "Castanhal", "Parauapebas", "Abaetetuba", "Cameta", "Marituba", "Braganca"}, // PARA
            {"Joinville", "Florianopolis", "Blumenau", "Sao Jose", "Itajai", "Chapeco", "Criciuma", "Lages", "Jaragua do Sul", "Palhoca"} // S. CATARINA
        },
        { // 2. ARGENTINA
            {"La Plata", "Mar del Plata", "Bahia Blanca", "Lanus", "Pilar", "Quilmes", "Lujan", "Tandil", "Zarate", "Olavarria"}, // BUENOS AIRES
            {"Cordoba City", "Rio Cuarto", "Villa Maria", "Carlos Paz", "San Francisco", "Alta Gracia", "Rio Tercero", "Bell Ville", "La Falda", "Cosquin"}, // CORDOBA
            {"Rosario", "Santa Fe City", "Rafaela", "Reconquista", "Santo Tome", "Venado Tuerto", "Villa Constitucion", "Esperanza", "Gálvez", "San Jorge"}, // SANTA FE
            {"Mendoza City", "San Rafael", "Godoy Cruz", "Las Heras", "Guaymallen", "Maipu", "Lujan de Cuyo", "Tunuyan", "General Alvear", "Rivadavia"}, // MENDOZA
            {"San Miguel", "Yerba Buena", "Tafi Viejo", "Concepcion", "Aguilares", "Monteros", "Famailla", "Lules", "Banda del Rio", "Trancas"}, // TUCUMAN
            {"Parana City", "Concordia", "Gualeguaychu", "Concepcion", "Gualeguay", "Villaguay", "Chajari", "Victoria", "La Paz", "Diamante"}, // ENTRE RIOS
            {"Salta City", "Oran", "Tartagal", "Metan", "Rosario de Lerma", "General Guemes", "Joaquin V. Gonzalez", "Cafayate", "Cerrillos", "Embarcacion"}, // SALTA
            {"Resistencia", "Sáenz Peña", "Villa Ángela", "Charata", "Las Breñas", "Castelli", "Machagai", "Quitilipi", "Fontana", "Barranqueras"}, // CHACO
            {"Corrientes City", "Goya", "Paso de los Libres", "Curuzu Cuatia", "Mercedes", "Bella Vista", "Santo Tome", "Monte Caseros", "Ituzaingo", "Esquina"}, // CORRIENTES
            {"Posadas", "Oberá", "Eldorado", "Puerto Iguazú", "Apóstoles", "Leandro N. Alem", "Jardín América", "San Vicente", "Montecarlo", "Aristóbulo"} // MISIONES
        },
        { // 3. COLOMBIA
            {"Medellin", "Bello", "Itagui", "Envigado", "Apartado", "Rionegro", "Caucasia", "Turbo", "Chigorodo", "La Estrella"}, // ANTIOQUIA
            {"Cali", "Buenaventura", "Palmira", "Tulua", "Cartago", "Jamundi", "Buga", "Yumbo", "Florida", "Pradera"}, // VALLE DEL CAUCA
            {"Bogota North", "Soacha", "Facatativa", "Zipaquira", "Chia", "Girardot", "Fusagasuga", "Mosquera", "Madrid", "Funza"}, // CUNDINAMARCA
            {"Bucaramanga", "Floridablanca", "Giron", "Piedecuesta", "Barrancabermeja", "San Gil", "Socorro", "Barbosa", "Lebrija", "Cimitarra"}, // SANTANDER
            {"Barranquilla", "Soledad", "Malambo", "Sabanalarga", "Baranoa", "Galapa", "Puerto Colombia", "Santo Tomas", "Luruaco", "Polonuevo"}, // ATLANTICO
            {"Cartagena City", "Magangué", "Turbaco", "Arjona", "Carmen de Bolivar", "Maria La Baja", "Mompós", "Tiquisio", "Santa Rosa", "Villanueva"}, // BOLIVAR
            {"Montería", "Cereté", "Sahagún", "Lorica", "Montelíbano", "Planeta Rica", "Tierralta", "Ciénaga de Oro", "Chinu", "Cotorra"}, // CORDOBA
            {"Pasto", "Tumaco", "Ipiales", "Tuquerres", "La Union", "Samaniego", "Barbacoas", "Cumbal", "Sandoná", "El Charco"}, // NARINO
            {"Ibagué", "Espinal", "Chaparral", "Líbano", "Guamo", "Mariquita", "Melgar", "Flandes", "Fresno", "Cajamarca"}, // TOLIMA
            {"Tunja", "Duitama", "Sogamoso", "Chiquinquirá", "Puerto Boyacá", "Paipa", "Moniquirá", "Samacá", "Villa de Leyva", "Guateque"} // BOYACA
        },
        { // 4. PERU
            {"Miraflores", "San Isidro", "Barranco", "Surco", "La Molina", "San Miguel", "Callao", "Ate", "Comas", "Lurín"}, // LIMA
            {"Arequipa City", "Cerro Colorado", "Paucarpata", "Cayma", "Mariano Melgar", "Majes", "Mollendo", "Camaná", "Aplao", "Chuquibamba"}, // AREQUIPA
            {"Trujillo City", "Huanchaco", "El Porvenir", "La Esperanza", "Víctor Larco", "Chepén", "Pacasmayo", "Huamachuco", "Otuzco", "Virú"}, // LA LIBERTAD
            {"Piura City", "Sullana", "Talara", "Paita", "Chulucanas", "Sechura", "Catacaos", "Castilla", "Tambogrande", "Ayabaca"}, // PIURA
            {"Cajamarca City", "Jaén", "Chota", "Celendín", "Cajabamba", "Bambamarca", "San Ignacio", "Hualgayoc", "Contumazá", "Cutervo"}, // CAJAMARCA
            {"Puno City", "Juliaca", "Ayaviri", "Azángaro", "Huancané", "Ilave", "Putina", "Lampa", "Yunguyo", "Desaguadero"}, // PUNO
            {"Huancayo", "Tarma", "Jauja", "La Oroya", "Concepción", "Chanchamayo", "Satipo", "Chupaca", "Junín City", "Pichanaqui"}, // JUNIN
            {"Cusco City", "Sicuani", "Quillabamba", "Urubamba", "Calca", "Pisac", "Ollantaytambo", "Chinchero", "Espinar", "Anta"}, // CUSCO
            {"Chiclayo City", "Lambayeque City", "Ferreñafe", "Olmos", "Motupe", "Pimentel", "Tumán", "Monsefú", "Chongoyape", "Jayanca"}, // LAMBAYEQUE
            {"Huaraz", "Chimbote", "Nuevo Chimbote", "Caraz", "Casma", "Huarmey", "Carhuaz", "Pomabamba", "Yungay", "Huari"} // ANCASH
        },
        { // 5. CHILE
            {"Santiago City", "Puente Alto", "Maipú", "La Florida", "San Bernardo", "Las Condes", "Peñalolén", "Pudahuel", "Quilicura", "Ñuñoa"}, // METROPOLITANA
            {"Valparaíso City", "Viña del Mar", "Quilpué", "Villa Alemana", "San Antonio", "Quillota", "San Felipe", "Los Andes", "Limache", "Concón"}, // VALPARAISO
            {"Concepción City", "Talcahuano", "San Pedro", "Chiguayante", "Coronel", "Lota", "Penco", "Tomé", "Los Ángeles", "Chillán"}, // BIOBIO
            {"Talca", "Curicó", "Linares", "Cauquenes", "Constitución", "Molina", "Parral", "San Javier", "San Clemente", "Teno"}, // MAULE
            {"Temuco", "Padre Las Casas", "Villarrica", "Angol", "Pucón", "Victoria", "Lautaro", "Nueva Imperial", "Collipulli", "Traiguén"}, // ARAUCANIA
            {"Rancagua", "San Fernando", "Pichilemu", "Machalí", "Rengo", "San Vicente", "Santa Cruz", "Chimbarongo", "Graneros", "Mostazal"}, // O'HIGGINS
            {"Puerto Montt", "Osorno", "Castro", "Ancud", "Puerto Varas", "Quellón", "Llanquihue", "Frutillar", "Purranque", "Calbuco"}, // LOS LAGOS
            {"La Serena", "Coquimbo", "Ovalle", "Illapel", "Vicuña", "Salamanca", "Los Vilos", "Andacollo", "Combarbalá", "Monte Patria"}, // COQUIMBO
            {"Antofagasta City", "Calama", "Tocopilla", "Taltal", "Mejillones", "María Elena", "San Pedro Atacama", "Baquedano", "Sierra Gorda", "Ollagüe"}, // ANTOFAGASTA
            {"Valdivia", "La Unión", "Río Bueno", "Paillaco", "Panguipulli", "Los Lagos City", "Mariquina", "Lanco", "Futrono", "Corral"} // LOS RIOS
        },
        { // 6. VENEZUELA
            {"Maracaibo", "Cabimas", "Ciudad Ojeda", "Lagunillas", "Machiques", "La Villa", "Mara", "San Francisco", "Santa Rita", "Miranda"}, // ZULIA
            {"Caracas East", "Petare", "Baruta", "Chacao", "El Hatillo", "Guarenas", "Guatire", "Los Teques", "Ocumare", "Cua"}, // MIRANDA
            {"Valencia", "Puerto Cabello", "Guacara", "Naguanagua", "San Diego", "Mariara", "Bejuma", "Moron", "San Joaquin", "Los Guayos"}, // CARABOBO
            {"Caracas City", "Libertador", "El Valle", "Catia", "Coche", "Antimano", "Caricuao", "La Vega", "San Juan", "23 de Enero"}, // DIST. CAPITAL
            {"Barquisimeto", "Cabudare", "Carora", "El Tocuyo", "Quibor", "Duaca", "Sarare", "Sanare", "Siquisique", "Aguada Grande"}, // LARA
            {"Maracay", "Turmero", "El Limon", "La Victoria", "Cagua", "Villa de Cura", "Santa Rita", "Palo Negro", "San Mateo", "Ocumare Coast"}, // ARAGUA
            {"Ciudad Bolivar", "Ciudad Guayana", "Upata", "Caicara", "Tumeremo", "Guasipati", "El Callao", "Santa Elena", "El Pao", "Maripa"}, // BOLIVAR
            {"Barcelona", "Puerto La Cruz", "El Tigre", "Anaco", "Lecheria", "Guanta", "Cantaura", "San Jose", "El Tigrito", "Pariaguan"}, // ANZOATEGUI
            {"San Cristobal", "Rubio", "San Antonio", "Tariba", "Colon", "La Fria", "Palmira", "Capacho", "Michelena", "Urena"}, // TACHIRA
            {"Cumana", "Carupano", "Cumanacoa", "Cariaco", "Rio Caribe", "Guiria", "Casanay", "Araya", "Irapa", "San Antonio"} // SUCRE
        },
        { // 7. ECUADOR
            {"Guayaquil City", "Duran", "Milagro", "Samborondon", "Daule", "Playas", "El Empalme", "Naranjal", "Balzar", "Yaguachi"}, // GUAYAS
            {"Quito City", "Sangolqui", "Machachi", "Cayambe", "Tabacundo", "Puerto Quito", "Pedro Vicente", "Conocoto", "Cumbaya", "Tumbaco"}, // PICHINCHA
            {"Portoviejo", "Manta", "Chone", "El Carmen", "Bahia", "Jipijapa", "Calceta", "Montecristi", "Paján", "Rocafuerte"}, // MANABI
            {"Cuenca", "Gualaceo", "Paute", "Sigsig", "Giron", "Santa Isabel", "Chordeleg", "Camilo Ponce", "Nabón", "Oña"}, // AZUAY
            {"Babahoyo", "Quevedo", "Ventanas", "Vinces", "Buena Fe", "Valencia", "Puebloviejo", "Mocache", "Baba", "Montalvo"}, // LOS RIOS
            {"Machala", "Pasaje", "Santa Rosa", "Huaquillas", "Arenillas", "Piñas", "Zaruma", "Portovelo", "El Guabo", "Balsas"}, // EL ORO
            {"Ambato", "Baños", "Pelileo", "Pillaro", "Quero", "Cevallos", "Mocha", "Tisaleo", "Patate", "Izamba"}, // TUNGURAHUA
            {"Loja City", "Catamayo", "Cariamanga", "Macara", "Saraguro", "Zapotillo", "Celica", "Chaguarpamba", "Puyango", "Espindola"}, // LOJA
            {"Riobamba", "Guano", "Chambo", "Alausí", "Guamote", "Pallatanga", "Chunchi", "Cumandá", "Colta", "Penipe"}, // CHIMBORAZO
            {"Ibarra", "Otavalo", "Cotacachi", "Atuntaqui", "Atuqui", "Pimampiro", "Urcuqui", "San Antonio", "Natabuela", "Mira"} // IMBABURA
        },
        { // 8. BOLIVIA
            {"La Paz City", "El Alto", "Viacha", "Achacachi", "Caranavi", "Patacamaya", "Copacabana", "Coroico", "Laja", "Palca"}, // LA PAZ
            {"Santa Cruz City", "Montero", "Warnes", "La Guardia", "El Carmen", "Camiri", "San Ignacio", "Roboré", "Cotoca", "Mineros"}, // SANTA CRUZ
            {"Cochabamba City", "Quillacollo", "Sacaba", "Tiquipaya", "Colcapirhua", "Vinto", "Punata", "Cliza", "Aiquile", "Mizque"}, // COCHABAMBA
            {"Potosi City", "Uyuni", "Llallagua", "Tupiza", "Villazon", "Uncia", "Betanzos", "Cotagaita", "Puna", "Colquechaka"}, // POTOSI
            {"Sucre City", "Monteagudo", "Camargo", "Padilla", "Tarabuco", "Zudáñez", "Serrano", "Yamparáez", "Presto", "Mojocoya"}, // CHUQUISACA
            {"Oruro City", "Challapata", "Huanuni", "Caracollo", "Eucaliptus", "Sabaya", "Toledo", "Machacamarca", "Poopó", "Salinas"}, // ORURO
            {"Tarija City", "Yacuiba", "Bermejo", "Villamontes", "Entre Rios", "San Lorenzo", "Carapari", "Padcaya", "Iscayachi", "Uriondo"}, // TARIJA
            {"Trinidad", "Riberalta", "Guayaramerin", "San Borja", "Rurrenabaque", "Santa Ana", "San Ignacio", "Reyes", "Magdalena", "Baures"}, // BENI
            {"Cobija", "Porvenir", "Puerto Rico", "Sena", "Filadelfia", "Puerto Gonzalo", "San Lorenzo", "Bella Flor", "Bolivia City", "Santos Mercado"}, // PANDO
            {"Villamontes", "Yacuiba", "Caraparí", "Ibibobo", "Caiza", "Crevaux", "D'Orbigny", "Palo Marcado", "Tiguipa", "Hito BR"} // Gran Chaco
        },
        { // 9. PARAGUAY
            {"Luque", "Lambare", "San Lorenzo", "Capiata", "Fernando", "Mariano", "Limpio", "Nemby", "Ita", "Itaugua"}, // CENTRAL
            {"Ciudad del Este", "Presidente Franco", "Hernandarias", "Minga Guazu", "Iruña", "Santa Rita", "Minga Pora", "Naranjal", "Mallorquin", "Yguazu"}, // ALTO PARANA
            {"Encarnacion", "Cambyreta", "Hohenau", "Obligado", "Bella Vista", "Natalio", "Fram", "Pirapo", "Carmen", "San Cosme"}, // ITAPUA
            {"Caaguazu City", "Coronel Oviedo", "Caaguazu Town", "J.E. Estigarribia", "Repatriacion", "Yhu", "Pastoreo", "San Jose", "Vaquería", "Cecilio Báez"}, // CAAGUAZU
            {"San Pedro City", "Santa Rosa", "San Estanislao", "Guayaibi", "Chore", "Tacuati", "General Resquin", "Lima", "Antequera", "Capiibary"}, // SAN PEDRO
            {"Caacupe", "Piribebuy", "Itacurubi", "Arroyos", "Eusebio Ayala", "Emboscada", "Altos", "San Bernardino", "Tobati", "Caraguatay"}, // CORDILLERA
            {"Paraguari City", "Carapegua", "Quiindy", "Ybycui", "Pirayu", "Acahay", "Sapucai", "Mbuyapey", "Yaguarón", "Escobar"}, // PARAGUARI
            {"Concepcion City", "Horqueta", "Yby Yau", "Vallemi", "Loreto", "Belén", "San Lazaro", "Azotey", "Sargento Felix", "Paso Barreto"}, // CONCEPCION
            {"Villarrica", "Colonia Independencia", "Paso Yobai", "Iturbe", "Mbocayaty", "Natalicio", "Troche", "Fassardi", "Borja", "Itape"}, // GUAIRA
            {"Caazapa City", "San Juan Nepomuceno", "Yuty", "Tava'i", "Aba'i", "Buena Vista", "Fulgencio Yegros", "Maciel", "Bertoni", "Yegros"} // CAAZAPA
        },
        { // 10. URUGUAY
            {"Montevideo City", "Ciudad Vieja", "Pocitos", "Carrasco", "Prado", "Buceo", "Malvin", "Sayago", "Cerro", "Aguada"}, // MONTEVIDEO
            {"Ciudad de la Costa", "Las Piedras", "Pando", "Canelones City", "La Paz", "Santa Lucia", "Progreso", "Sauce", "Tala", "San Ramon"}, // CANELONES
            {"Maldonado City", "Punta del Este", "San Carlos", "Piriapolis", "Pan de Azucar", "Aigua", "Punta Ballena", "Solís", "Garzón", "José Ignacio"}, // MALDONADO
            {"Salto City", "Dayman", "San Antonio", "Constitucion", "Belen", "Colonia Lavalleja", "Biassini", "Puntas de Valentin", "Toro Negro", "Veras"}, // SALTO
            {"Colonia del Sacramento", "Carmelo", "Juan Lacaze", "Nueva Helvecia", "Rosario", "Tarariras", "Nueva Palmira", "Ombués de Lavalle", "Florencio Sánchez", "Conchillas"}, // COLONIA
            {"Paysandú City", "Guichón", "Quebracho", "Lorenzo Geyres", "Piedras Coloradas", "Porvenir", "Tambores", "Chapicuy", "Orgoroso", "Casablanca"}, // PAYSANDU
            {"San José de Mayo", "Ciudad del Plata", "Libertad", "Rodríguez", "Ecilda Paullier", "Rafael Perazza", "Capurro", "Puntas de Valdéz", "Mal Abrigo", "Ituzaingó"}, // SAN JOSE
            {"Rivera City", "Vichadero", "Tranqueras", "Minas de Corrales", "Lagos del Norte", "Masoller", "Ataques", "Cerro Pelado", "Moirones", "Lapuente"}, // RIVERA
            {"Tacuarembó City", "Paso de los Toros", "San Gregorio", "Ansina", "Curtina", "Achar", "Caraguatá", "Tambores South", "Paso Bonilla", "Punta de Carretera"}, // TACUAREMBO
            {"Florida City", "Sarandí Grande", "Casupá", "Fray Marcos", "25 de Mayo", "Cardal", "Nico Pérez", "Capilla del Sauce", "Mendoza", "Cerro Colorado"} // FLORIDA
        }
    }
};

// Function to handle selection
int getSelection(char *title, char *items[], int count) {
    int choice;
    printf("\n==================================================\n");
    printf("        🌍 %s 🌍\n", title);
    printf("==================================================\n");
    for (int i = 0; i < count; i++) {
        printf("  [%2d] %-18s", i + 1, items[i]);
        if ((i + 1) % 2 == 0) printf("\n");
    }
    printf("\n--------------------------------------------------\n");
    printf("SELECT (1-%d): ", count);
    if (scanf("%d", &choice) != 1) return -1;
    if (choice < 1 || choice > count) return -1;
    return choice - 1;
}

int main() {
    int c_idx, co_idx, s_idx, ci_idx;

    printf("==================================================\n");
    printf("        🌍  ELITE WORLD EXPLORER TERMINAL  🌍       \n");
    printf("==================================================\n");

    // 1. Continent
    c_idx = getSelection("SELECT YOUR CONTINENT", continents, 7);
    if (c_idx == -1) { printf("Invalid!\n"); return 0; }

    // 2. Country
    char *countryTitle = (c_idx == 1) ? "SELECT RESEARCH STATION" : "SELECT YOUR COUNTRY";
    co_idx = getSelection(countryTitle, countries[c_idx], 10);
    if (co_idx == -1) return 0;

    // Antarctica special case (No states/cities needed)
    if (c_idx == 1) {
        printf("\n✅ SUCCESS: DESTINATION LOCKED!\n");
        printf(">> Continent: %s\n", continents[c_idx]);
        printf(">> Station:   %s\n", countries[c_idx][co_idx]);
        return 0;
    }

    // 3. State
    s_idx = getSelection("SELECT STATE / REGION", states[c_idx][co_idx], 10);
    if (s_idx == -1) return 0;

    // 4. City
    ci_idx = getSelection("SELECT CITY / AREA", cities[c_idx][co_idx][s_idx], 10);
    if (ci_idx == -1) return 0;

    // FINAL OUTPUT (Sab kuch print karne ke liye)
    printf("\n✅ SUCCESS: DESTINATION LOCKED!\n");
    printf("--------------------------------------------------\n");
    printf("🗺️  TRAVEL DETAILS:\n");
    printf(">> Continent : %s\n", continents[c_idx]);
    printf(">> Country   : %s\n", countries[c_idx][co_idx]);
    printf(">> State     : %s\n", states[c_idx][co_idx][s_idx]);
    printf(">> City      : %s\n", cities[c_idx][co_idx][s_idx][ci_idx]);
    printf("--------------------------------------------------\n");
    printf("         STAY SAFE AND HAPPY TRAVELS!            \n");
    printf("==================================================\n");

    return 0;
}
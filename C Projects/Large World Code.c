#include <stdio.h>

int main() {
    int choice;

    printf("==================================================\n");
    printf("        🌍  ELITE WORLD EXPLORER TERMINAL  🌍       \n");
    printf("==================================================\n");
    printf("  [1] Africa          [5] Europe\n");
    printf("  [2] Antarctica      [6] North America\n");
    printf("  [3] Asia            [7] South America\n");
    printf("  [4] Australia\n");
    printf("==================================================\n");
    printf("SELECT YOUR DESTINATION (1-7): ");
    
    scanf("%d", &choice);
    printf("\n--------------------------------------------------\n");


    if (choice == 1) {
        int country_choice; 
        
        printf("📍 CONTINENT: AFRICA\n");
        printf("TOP 10 COUNTRIES:\n");
        printf("1. Nigeria    2. Egypt      3. Ethiopia\n");
        printf("4. S. Africa  5. Kenya      6. Morocco\n");
        printf("7. Algeria    8. Ghana      9. Tanzania\n");
        printf("10. Uganda\n");
        
        printf("\nCHOOSE A COUNTRY (1-10): ");
        scanf("%d", &country_choice);
        printf("------------------------------\n");

        if (country_choice == 1) { // NIGERIA
            int state_choice, city_choice;
            
            printf(">> NIGERIA: Select a State (1-10)\n");
            printf("1. Lagos      2. Kano       3. Kaduna\n");
            printf("4. Oyo        5. Rivers     6. Katsina\n");
            printf("7. Bauchi     8. Anambra    9. Jigawa\n");
            printf("10. Benue\n");
            
            printf("\nENTER STATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // LAGOS
                printf("🏙️  Top 10 Cities in LAGOS:\n");
                printf("1. Ikeja    2. Lekki    3. Ikorodu    4. Epe       5. Badagry\n");
                printf("6. Surulere 7. Ajah     8. Victoria Is. 9. Yaba     10. Mushin\n");
            } 
            else if (state_choice == 2) { // KANO
                printf("🏙️  Top 10 Cities in KANO:\n");
                printf("1. Fagge    2. Gwale    3. Tarauni    4. Dala      5. Nasarawa\n");
                printf("6. Kumbotso 7. Ungogo   8. Wudil      9. Gaya      10. Bebeji\n");
            }
            else if (state_choice == 3) { // KADUNA
                printf("🏙️  Top 10 Cities in KADUNA:\n");
                printf("1. Kaduna   2. Zaria    3. Kafanchan  4. Kagoro    5. Zonkwa\n");
                printf("6. Kachia   7. Makarfi  8. Birnin Gwari 9. Saminaka 10. Jere\n");
            }
            else if (state_choice == 4) { // OYO
                printf("🏙️  Top 10 Cities in OYO:\n");
                printf("1. Ibadan   2. Ogbomosho 3. Oyo       4. Seyin     5. Iseyin\n");
                printf("6. Saki     7. Igboho    8. Kisi      9. Okeho     10. Lalupo\n");
            }
            else if (state_choice == 5) { // RIVERS
                printf("🏙️  Top 10 Cities in RIVERS:\n");
                printf("1. Port Harcourt 2. Obio-Akpor 3. Bonny 4. Okrika   5. Onne\n");
                printf("6. Eleme    7. Degema   8. Opobo     9. Ahoada    10. Omoku\n");
            }
            else if (state_choice == 6) { // KATSINA
                printf("🏙️  Top 10 Cities in KATSINA:\n");
                printf("1. Katsina  2. Daura    3. Funtua    4. Malumfashi 5. Bakori\n");
                printf("6. Kankia   7. Dutsin-Ma 8. Mani     9. Jibia     10. Danja\n");
            }
            else if (state_choice == 7) { // BAUCHI
                printf("🏙️  Top 10 Cities in BAUCHI:\n");
                printf("1. Bauchi   2. Azare    3. Misau     4. Jama'are   5. Ningi\n");
                printf("6. Dass     7. Toro     8. Alkaleri  9. Tafawa Balewa 10. Darazo\n");
            }
            else if (state_choice == 8) { // ANAMBRA
                printf("🏙️  Top 10 Cities in ANAMBRA:\n");
                printf("1. Awka     2. Onitsha  3. Nnewi     4. Ekwulobia  5. Aguata\n");
                printf("6. Ihiala   7. Nkpor    8. Obosi     9. Umuoji    10. Atani\n");
            }
            else if (state_choice == 9) { // JIGAWA
                printf("🏙️  Top 10 Cities in JIGAWA:\n");
                printf("1. Dutse    2. Hadejia  3. Gumel     4. Birnin Kudu 5. Ringim\n");
                printf("6. Kazaure  7. Babura   8. Mallam Madori 9. Gwaram 10. Kiyawa\n");
            }
            else if (state_choice == 10) { // BENUE
                printf("🏙️  Top 10 Cities in BENUE:\n");
                printf("1. Makurdi  2. Gboko    3. Otukpo    4. Katsina-Ala 5. Adikpo\n");
                printf("6. Vandeikya 7. Zaki Biam 8. Aliade  9. Okpoga    10. Oju\n");
            }
            else {
                printf("⚠️ Invalid State Selection.\n");
                return 0; // Exit or handle error
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Nigeria\n");
                printf(">> State Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid City Number.\n");
            }
        }
        
        else if (country_choice == 2) { // EGYPT
            int state_choice, city_choice;
            
            printf(">> EGYPT: Select a Governorate (1-10)\n");
            printf("1. Cairo      2. Giza       3. Alexandria\n");
            printf("4. Dakahlia   5. Sharqia    6. Beheira\n");
            printf("7. Minya      8. Qalyubia   9. Sohag\n");
            printf("10. Gharbia\n");
            
            printf("\nENTER GOVERNORATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // CAIRO
                printf("🏙️  Top 10 Cities/Districts in CAIRO:\n");
                printf("1. Heliopolis 2. Maadi      3. Nasr City  4. Zamalek    5. Garden City\n");
                printf("6. Shoubra    7. Helwan     8. Abbassia   9. El-Marg    10. New Cairo\n");
            } 
            else if (state_choice == 2) { // GIZA
                printf("🏙️  Top 10 Cities/Districts in GIZA:\n");
                printf("1. 6th October 2. Sheikh Zayed 3. Haram    4. Dokki      5. Agouza\n");
                printf("6. Imbaba     7. Faisal     8. Hawamdia   9. Badrasheen 10. Atfih\n");
            }
            else if (state_choice == 3) { // ALEXANDRIA
                printf("🏙️  Top 10 Cities/Districts in ALEXANDRIA:\n");
                printf("1. Montaza    2. Maamoura   3. Smouha     4. Stanley    5. Agami\n");
                printf("6. Borg El Arab 7. Miami    8. San Stefano 9. Gleem    10. Rosetta\n");
            }
            else if (state_choice == 4) { // DAKAHLIA
                printf("🏙️  Top 10 Cities in DAKAHLIA:\n");
                printf("1. Mansoura   2. Talkha     3. Mit Ghamr  4. Dekernes   5. Senbellawein\n");
                printf("6. Manzala    7. Aga        8. Sherbin    9. Gamasa     10. Mataria\n");
            }
            else if (state_choice == 5) { // SHARQIA
                printf("🏙️  Top 10 Cities in SHARQIA:\n");
                printf("1. Zagazig    2. 10th Ramadan 3. Bilbeis  4. Minya al-Qamh 5. Abu Hammad\n");
                printf("6. Faqus      7. Hehia      8. Abu Kabir  9. Kafr Saqr  10. Mashtool\n");
            }
            else if (state_choice == 6) { // BEHEIRA
                printf("🏙️  Top 10 Cities in BEHEIRA:\n");
                printf("1. Damanhur   2. Kafr El Dawar 3. Rashid   4. Edko       5. Abu Hummus\n");
                printf("6. Itay El Barud 7. Kom Hamada 8. Shubrakhit 9. Delengat  10. Wadi Natrun\n");
            }
            else if (state_choice == 7) { // MINYA
                printf("🏙️  Top 10 Cities in MINYA:\n");
                printf("1. Minya City 2. Mallawi    3. Maghagha   4. Beni Mazar 5. Samalut\n");
                printf("6. Abu Qurqas 7. El Idwa    8. Matai      9. Deir Mawas 10. New Minya\n");
            }
            else if (state_choice == 8) { // QALYUBIA
                printf("🏙️  Top 10 Cities in QALYUBIA:\n");
                printf("1. Banha      2. Shubra El Kheima 3. Obour 4. Khanka   5. Qalyub\n");
                printf("6. Shebin El Qanater 7. Tukh 8. Qaha      9. Kafr Shukr 10. Bahtim\n");
            }
            else if (state_choice == 9) { // SOHAG
                printf("🏙️  Top 10 Cities in SOHAG:\n");
                printf("1. Sohag City 2. Akhmim     3. Girga      4. Tahta      5. Tema\n");
                printf("6. Juhayna    7. Dar El Salam 8. Balyana   9. Itsa       10. Sakulta\n");
            }
            else if (state_choice == 10) { // GHARBIA
                printf("🏙️  Top 10 Cities in GHARBIA:\n");
                printf("1. Tanta      2. El Mahalla El Kubra 3. Kafr El Zayat 4. Zifta 5. Samannud\n");
                printf("6. قطور (Qutur) 7. El Santa  8. Basyoun    9. Birket El Sab 10. Sonbat\n");
            }
            else {
                printf("⚠️ Invalid Governorate Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Egypt\n");
                printf(">> Governorate Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid City Number.\n");
            }
        }

        else if (country_choice == 3) { // ETHIOPIA
            int state_choice, city_choice;
            
            printf(">> ETHIOPIA: Select a Region (1-10)\n");
            printf("1. Addis Ababa  2. Amhara       3. Oromia\n");
            printf("4. Tigray       5. Somali       6. Afar\n");
            printf("7. Sidama       8. Harari       9. Gambela\n");
            printf("10. Benishangul-Gumuz\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ADDIS ABABA
                printf("🏙️  Top 10 Districts/Areas in ADDIS ABABA:\n");
                printf("1. Bole       2. Arada      3. Kirkos     4. Gullele    5. Lideta\n");
                printf("6. Akaki      7. Yeka       8. Kolfe      9. Nifas Silk 10. Addis Ketema\n");
            } 
            else if (state_choice == 2) { // AMHARA
                printf("🏙️  Top 10 Cities in AMHARA:\n");
                printf("1. Bahir Dar  2. Gondar     3. Dessie     4. Debre Berhan 5. Kombolcha\n");
                printf("6. Debre Tabor 7. Weldiya    8. Debre Markos 9. Lalibela  10. Motta\n");
            }
            else if (state_choice == 3) { // OROMIA
                printf("🏙️  Top 10 Cities in OROMIA:\n");
                printf("1. Adama      2. Jimma      3. Bishoftu   4. Shashemene 5. Nekemte\n");
                printf("6. Asella     7. Robe       8. Sebeta     9. Ambo       10. Burayu\n");
            }
            else if (state_choice == 4) { // TIGRAY
                printf("🏙️  Top 10 Cities in TIGRAY:\n");
                printf("1. Mekelle    2. Adigrat    3. Aksum      4. Shire      5. Humera\n");
                printf("6. Adwa       7. Alamata    8. Wukro      9. Maychew    10. Sheraro\n");
            }
            else if (state_choice == 5) { // SOMALI
                printf("🏙️  Top 10 Cities in SOMALI:\n");
                printf("1. Jijiga     2. Gode       3. Kebridehar 4. Degehabur  5. Warder\n");
                printf("6. Shinile    7. Afder      8. Liben      9. Erer       10. Tog Wajale\n");
            }
            else if (state_choice == 6) { // AFAR
                printf("🏙️  Top 10 Cities in AFAR:\n");
                printf("1. Semera     2. Asaita     3. Logia      4. Awash      5. Gewane\n");
                printf("6. Chifra     7. Dubti      8. Mille      9. Aba'ala    10. Erebti\n");
            }
            else if (state_choice == 7) { // SIDAMA
                printf("🏙️  Top 10 Cities in SIDAMA:\n");
                printf("1. Hawassa    2. Yirgalem   3. Aleta Wendo 4. Leku      5. Bona\n");
                printf("6. Daye       7. Irba       8. Teticha    9. Shafina    10. Morocho\n");
            }
            else if (state_choice == 8) { // HARARI
                printf("🏙️  Top 10 Areas in HARARI:\n");
                printf("1. Harar City 2. Jin'Eala   3. Amir Nur   4. Aboker     5. Shenkor\n");
                printf("6. Sofi       7. Erer Gate  8. Dire Taye  9. Hakim      10. Suq Tatari\n");
            }
            else if (state_choice == 9) { // GAMBELA
                printf("🏙️  Top 10 Cities in GAMBELA:\n");
                printf("1. Gambela City 2. Itang     3. Pugnido    4. Abobo      5. Kuri\n");
                printf("6. Metar      7. Fugnido    8. Tierkidi   9. Jewi       10. Lare\n");
            }
            else if (state_choice == 10) { // BENISHANGUL-GUMUZ
                printf("🏙️  Top 10 Cities in BENISHANGUL-GUMUZ:\n");
                printf("1. Assosa     2. Kamashi    3. Gilgel Beles 4. Bambasi   5. Dibate\n");
                printf("6. Bulen      7. Wonbera    8. Guba       9. Menge      10. Oda\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Ethiopia\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid City Number.\n");
            }
        }

        else if (country_choice == 4) { // SOUTH AFRICA
            int state_choice, city_choice;
            
            printf(">> SOUTH AFRICA: Select a Province/Region (1-10)\n");
            printf("1. Gauteng          2. KwaZulu-Natal\n");
            printf("3. Western Cape     4. Eastern Cape\n");
            printf("5. Limpopo          6. Mpumalanga\n");
            printf("7. North West       8. Free State\n");
            printf("9. Northern Cape    10. Wildlife & Nature Reserves\n"); 
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // GAUTENG
                printf("🏙️  Top 10 Cities in GAUTENG:\n");
                printf("1. Johannesburg 2. Pretoria    3. Soweto     4. Benoni     5. Tembisa\n");
                printf("6. Vereeniging  7. Krugersdorp 8. Brakpan    9. Centurion  10. Midrand\n");
            } 
            else if (state_choice == 2) { // KWAZULU-NATAL
                printf("🏙️  Top 10 Cities in KWAZULU-NATAL:\n");
                printf("1. Durban       2. Pietermaritzburg 3. Newcastle 4. Richards Bay 5. Ladysmith\n");
                printf("6. Port Shepstone 7. Umhlanga 8. Vryheid    9. Empangeni  10. Ballito\n");
            }
            else if (state_choice == 3) { // WESTERN CAPE
                printf("🏙️  Top 10 Cities in WESTERN CAPE:\n");
                printf("1. Cape Town    2. George      3. Paarl      4. Worcester  5. Stellenbosch\n");
                printf("6. Knysna       7. Mossel Bay  8. Hermanus   9. Beaufort West 10. Saldanha\n");
            }
            else if (state_choice == 4) { // EASTERN CAPE
                printf("🏙️  Top 10 Cities in EASTERN CAPE:\n");
                printf("1. Gqeberha     2. East London 3. Mthatha   4. Makhanda   5. Bhisho\n");
                printf("6. Queenstown   7. Uitenhage   8. Graaff-Reinet 9. Cradock 10. Port St. Johns\n");
            }
            else if (state_choice == 5) { // LIMPOPO
                printf("🏙️  Top 10 Cities in LIMPOPO:\n");
                printf("1. Polokwane    2. Tzaneen     3. Mokopane   4. Thohoyandou 5. Musina\n");
                printf("6. Phalaborwa   7. Lephalale   8. Bela-Bela  9. Modimolle  10. Giyani\n");
            }
            else if (state_choice == 6) { // MPUMALANGA
                printf("🏙️  Top 10 Cities in MPUMALANGA:\n");
                printf("1. Mbombela     2. Emalahleni  3. Secunda    4. Ermelo     5. Middelburg\n");
                printf("6. Barberton    7. Standerton  8. Piet Retief 9. Lydenburg 10. White River\n");
            }
            else if (state_choice == 7) { // NORTH WEST
                printf("🏙️  Top 10 Cities in NORTH WEST:\n");
                printf("1. Mahikeng     2. Rustenburg  3. Potchefstroom 4. Klerksdorp 5. Brits\n");
                printf("6. Vryburg      7. Lichtenburg 8. Orkney     9. Zeerust    10. Fochville\n");
            }
            else if (state_choice == 8) { // FREE STATE
                printf("🏙️  Top 10 Cities in FREE STATE:\n");
                printf("1. Bloemfontein 2. Welkom      3. Sasolburg  4. Kroonstad  5. Bethlehem\n");
                printf("6. Harrismith   7. Parys       8. Botshabelo 9. Phuthaditjhaba 10. Ladybrand\n");
            }
            else if (state_choice == 9) { // NORTHERN CAPE
                printf("🏙️  Top 10 Cities in NORTHERN CAPE:\n");
                printf("1. Kimberley    2. Upington    3. Kuruman    4. Springbok  5. De Aar\n");
                printf("6. Postmasburg  7. Kathu       8. Calvinia   9. Prieska    10. Carnarvon\n");
            }
            else if (state_choice == 10) { // WILDLIFE RESERVES
                printf("🦁 Top 10 National Parks/Safari Areas:\n");
                printf("1. Kruger Park  2. Addo Elephant 3. Kgalagadi  4. Pilanesberg 5. Hluhluwe\n");
                printf("6. Tsitsikamma  7. Mapungubwe   8. Golden Gate 9. Augrabies   10. Marakele\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT OPTION NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Country: South Africa\n");
                printf(">> Category Code: %d, Choice Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Selection.\n");
            }
        }

        else if (country_choice == 5) { // KENYA
            int state_choice, city_choice;
            
            printf(">> KENYA: Select a County (1-10)\n");
            printf("1. Nairobi    2. Mombasa    3. Kiambu\n");
            printf("4. Nakuru     5. Kakamega   6. Bungoma\n");
            printf("7. Meru       8. Machakos   9. Kisumu\n");
            printf("10. Kilifi\n");
            
            printf("\nENTER COUNTY NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // NAIROBI
                printf("🏙️  Top 10 Districts/Areas in NAIROBI:\n");
                printf("1. Westlands  2. Lang'ata   3. Kasarani   4. Embakasi   5. Kibra\n");
                printf("6. Dagoretti  7. Makadara   8. Kamukunji  9. Mathare    10. Starehe\n");
            } 
            else if (state_choice == 2) { // MOMBASA
                printf("🏙️  Top 10 Districts/Areas in MOMBASA:\n");
                printf("1. Nyali      2. Likoni     3. Mvita      4. Changamwe  5. Kisauni\n");
                printf("6. Jomvu      7. Bamburi    8. Tudor      9. Mikindani  10. Majengo\n");
            }
            else if (state_choice == 3) { // KIAMBU
                printf("🏙️  Top 10 Cities/Towns in KIAMBU:\n");
                printf("1. Thika      2. Kiambu Town 3. Ruiru     4. Limuru     5. Kikuyu\n");
                printf("6. Karuri     7. Juja       8. Gatundu    9. Githunguri 10. Lari\n");
            }
            else if (state_choice == 4) { // NAKURU
                printf("🏙️  Top 10 Cities/Towns in NAKURU:\n");
                printf("1. Nakuru City 2. Naivasha  3. Molo       4. Gilgil     5. Njoro\n");
                printf("6. Rongai     7. Subukia    8. Bahati     9. Salgaa     10. Mai Mahiu\n");
            }
            else if (state_choice == 5) { // KAKAMEGA
                printf("🏙️  Top 10 Cities/Towns in KAKAMEGA:\n");
                printf("1. Kakamega Town 2. Mumias  3. Butere     4. Malava     5. Lumakanda\n");
                printf("6. Khayega    7. Navakholo  8. Matete     9. Shinyalu   10. Lugari\n");
            }
            else if (state_choice == 6) { // BUNGOMA
                printf("🏙️  Top 10 Cities/Towns in BUNGOMA:\n");
                printf("1. Bungoma Town 2. Webuye   3. Kimilili   4. Chwele     5. Malaba\n");
                printf("6. Sirisia    7. Kanduyi    8. Tongaren   9. Bumula     10. Mt. Elgon\n");
            }
            else if (state_choice == 7) { // MERU
                printf("🏙️  Top 10 Cities/Towns in MERU:\n");
                printf("1. Meru City  2. Maua       3. Nanyuki    4. Meru Town  5. Timau\n");
                printf("6. Mikinduri  7. Laare      8. Igoji      9. Kianjai    10. Gatimbi\n");
            }
            else if (state_choice == 8) { // MACHAKOS
                printf("🏙️  Top 10 Cities/Towns in MACHAKOS:\n");
                printf("1. Machakos Town 2. Athi River 3. Kangundo  4. Tala       5. Matuu\n");
                printf("6. Mwala      7. Kathiani   8. Masii      9. Mavoko     10. Joska\n");
            }
            else if (state_choice == 9) { // KISUMU
                printf("🏙️  Top 10 Cities/Towns in KISUMU:\n");
                printf("1. Kisumu City 2. Maseno    3. Ahero      4. Muhoroni   5. Chemelil\n");
                printf("6. Kombewa    7. Katito     8. Sondu      9. Kibos      10. Manyatta\n");
            }
            else if (state_choice == 10) { // KILIFI
                printf("🏙️  Top 10 Cities/Towns in KILIFI:\n");
                printf("1. Malindi    2. Kilifi Town 3. Watamu     4. Mtwapa     5. Mariakani\n");
                printf("6. Kaloleni   7. Gongoni    8. Marafa     9. Matsangoni 10. Kikambala\n");
            }
            else {
                printf("⚠️ Invalid County Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Kenya\n");
                printf(">> County Code: %d, City/Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 6) { // MOROCCO
            int state_choice, city_choice;
            
            printf(">> MOROCCO: Select a Region (1-10)\n");
            printf("1. Casablanca 2. Rabat      3. Marrakech\n");
            printf("4. Tangier    5. Fez        6. Agadir\n");
            printf("7. Meknes     8. Oujda      9. Kenitra\n");
            printf("10. Tetouan\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // CASABLANCA-SETTAT
                printf("🏙️  Top 10 Cities/Areas in CASABLANCA:\n");
                printf("1. Anfa       2. Maarif     3. Mohammedia 4. Settat     5. El Jadida\n");
                printf("6. Berrechid  7. Benslimane 8. Bouskoura  9. Ain Diab   10. Nouaceur\n");
            } 
            else if (state_choice == 2) { // RABAT-SALE-KENITRA
                printf("🏙️  Top 10 Cities/Areas in RABAT:\n");
                printf("1. Agdal      2. Hay Riad   3. Sale       4. Skhirat    5. Temara\n");
                printf("6. Kenitra    7. Sidi Kacem 8. Khemisset  9. Souk Arbaa 10. Touarga\n");
            }
            else if (state_choice == 3) { // MARRAKECH-SAFI
                printf("🏙️  Top 10 Cities/Areas in MARRAKECH:\n");
                printf("1. Medina     2. Gueliz     3. Hivernage  4. Safi       5. Essaouira\n");
                printf("6. El Kelaa   7. Benguerir  8. Chichaoua  9. Al Haouz   10. Tahannaout\n");
            }
            else if (state_choice == 4) { // TANGIER-TETOUAN-AL HOCEIMA
                printf("🏙️  Top 10 Cities/Areas in TANGIER:\n");
                printf("1. Ville Nouvelle 2. Malabata 3. Asilah    4. Larache    5. Ksar El Kebir\n");
                printf("6. Chefchaouen 7. Al Hoceima 8. Fnideq    9. M'diq      10. Martil\n");
            }
            else if (state_choice == 5) { // FEZ-MEKNES (Part 1)
                printf("🏙️  Top 10 Cities/Areas in FEZ:\n");
                printf("1. Fez El Bali 2. Fes Jdid  3. Sefrou     4. Taza       5. Taounate\n");
                printf("6. Missour    7. Moulay Yaacoub 8. Imouzzer 9. Boulemane 10. Ribat El Kheir\n");
            }
            else if (state_choice == 6) { // SOUSS-MASSA (AGADIR)
                printf("🏙️  Top 10 Cities/Areas in AGADIR:\n");
                printf("1. Talborjt   2. Marina     3. Inezgane   4. Ait Melloul 5. Taroudant\n");
                printf("6. Tiznit     7. Tata       8. Biougra    9. Tafraout   10. Sidi Ifni\n");
            }
            else if (state_choice == 7) { // MEKNES (Region Cluster)
                printf("🏙️  Top 10 Cities/Areas in MEKNES:\n");
                printf("1. Hamria     2. Moulay Idriss 3. Azrou    4. Ifrane     5. El Hajeb\n");
                printf("6. Khenifra   7. Midelt     8. Mrirt      9. Ain Leuh   10. Itzer\n");
            }
            else if (state_choice == 8) { // ORIENTAL (OUJDA)
                printf("🏙️  Top 10 Cities/Areas in OUJDA:\n");
                printf("1. Oujda City 2. Nador      3. Berkane    4. Taourirt   5. Jerada\n");
                printf("6. Figuig     7. Guercif    8. Saïdia     9. Ahfir      10. Driouch\n");
            }
            else if (state_choice == 9) { // KENITRA (Gharb Cluster)
                printf("🏙️  Top 10 Areas in KENITRA Region:\n");
                printf("1. Mehdia     2. Sidi Slimane 3. Sidi Yahya 4. Souk Tlet  5. Mograne\n");
                printf("6. Ben Mansour 7. Ameur Seflia 8. Arbaoua  9. Lalla Mimouna 10. Moulay Bousselham\n");
            }
            else if (state_choice == 10) { // TETOUAN (Northern Cluster)
                printf("🏙️  Top 10 Areas in TETOUAN Region:\n");
                printf("1. Ensanche   2. Jbel Dersa 3. Oued Laou  4. Bab Taza   5. Bab Berred\n");
                printf("6. Tamorot    7. Stehat     8. Jebha      9. Bni Bouayach 10. Imzouren\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Morocco\n");
                printf(">> Region Code: %d, City/Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 7) { // ALGERIA
            int state_choice, city_choice;
            
            printf(">> ALGERIA: Select a Province/Wilaya (1-10)\n");
            printf("1. Algiers    2. Oran       3. Constantine\n");
            printf("4. Annaba     5. Blida      6. Batna\n");
            printf("7. Setif      8. Chlef      9. Djelfa\n");
            printf("10. Biskra\n");
            
            printf("\nENTER WILAYA NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ALGIERS
                printf("🏙️  Top 10 Districts in ALGIERS:\n");
                printf("1. Casbah     2. Bab El Oued 3. El Biar     4. Hydra      5. Kouba\n");
                printf("6. Dely Ibrahim 7. Sidi M'Hamed 8. Bir Mourad Rais 9. Zeralda 10. Reghaia\n");
            } 
            else if (state_choice == 2) { // ORAN
                printf("🏙️  Top 10 Cities/Districts in ORAN:\n");
                printf("1. Akid Lotfi 2. Es Senia   3. Bir El Djir 4. Arzew      5. Ain El Turk\n");
                printf("6. Bethioua   7. Mers El Kebir 8. Gdyel     9. Boutlelis  10. Oued Tlelat\n");
            }
            else if (state_choice == 3) { // CONSTANTINE
                printf("🏙️  Top 10 Cities/Areas in CONSTANTINE:\n");
                printf("1. El Khroub  2. Hamma Bouziane 3. Zighoud Youcef 4. Didouche Mourad 5. Ain Abid\n");
                printf("6. Ben Zied   7. Ibn Ziad    8. Massinissa 9. Ali Mendjeli 10. Nouvelle Ville\n");
            }
            else if (state_choice == 4) { // ANNABA
                printf("🏙️  Top 10 Cities/Areas in ANNABA:\n");
                printf("1. El Bouni   2. Sidi Amar  3. Berrahal   4. El Hadjar  5. Seraidi\n");
                printf("6. Chetaibi   7. Ain Berda  8. Treat      9. Oued Aneb  10. Chorfa\n");
            }
            else if (state_choice == 5) { // BLIDA
                printf("🏙️  Top 10 Cities/Areas in BLIDA:\n");
                printf("1. Boufarik   2. Ouled Yaich 3. Beni Mered 4. El Affroun 5. Mouzaia\n");
                printf("6. Meftah     7. Larbaa     8. Bougara    9. Chebli     10. Oued El Alleug\n");
            }
            else if (state_choice == 6) { // BATNA
                printf("🏙️  Top 10 Cities/Areas in BATNA:\n");
                printf("1. Merouana   2. Barika     3. Ain Touta  4. Arris      5. Tazoult\n");
                printf("6. N'Gaous    7. Chemora    8. T'Kout     9. Ras El Aioun 10. Théniet El Abed\n");
            }
            else if (state_choice == 7) { // SETIF
                printf("🏙️  Top 10 Cities/Areas in SETIF:\n");
                printf("1. El Eulma   2. Bougaa     3. Ain Oulmene 4. Ain Azel   5. Beni Aziz\n");
                printf("6. Salah Bey  7. Hammam Souhna 8. Guidjel  9. Amoucha    10. Maoklane\n");
            }
            else if (state_choice == 8) { // CHLEF
                printf("🏙️  Top 10 Cities/Areas in CHLEF:\n");
                printf("1. Ténès      2. Oued Fodda 3. Boukadir   4. Ouled Fares 5. El Karimia\n");
                printf("6. Taougrit   7. Zeboudja   8. El Marsa   9. Sendjas    10. Abou El Hassan\n");
            }
            else if (state_choice == 9) { // DJELFA
                printf("🏙️  Top 10 Cities/Areas in DJELFA:\n");
                printf("1. Hassi Bahbah 2. Ain Oussera 3. Messaad  4. Dar Chioukh 5. Birine\n");
                printf("6. El Idrissia 7. Charef     8. Had-Sahary 9. Faidh El Baguel 10. Guernini\n");
            }
            else if (state_choice == 10) { // BISKRA
                printf("🏙️  Top 10 Cities/Areas in BISKRA:\n");
                printf("1. Tolga      2. Sidi Okba  3. El Kantara 4. Ouled Djellal 5. Zeribet El Oued\n");
                printf("6. M'Chouneche 7. Lioua     8. Branis     9. Chetma     10. Bouchagroune\n");
            }
            else {
                printf("⚠️ Invalid Wilaya Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/DISTRICT NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Algeria\n");
                printf(">> Wilaya Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 8) { // GHANA
            int state_choice, city_choice;
            
            printf(">> GHANA: Select a Region (1-10)\n");
            printf("1. Ashanti    2. Greater Accra 3. Eastern\n");
            printf("4. Central    5. Western    6. Northern\n");
            printf("7. Volta      8. Bono       9. Upper East\n");
            printf("10. Upper West\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ASHANTI
                printf("🏙️  Top 10 Cities/Towns in ASHANTI:\n");
                printf("1. Kumasi     2. Obuasi     3. Mampong    4. Konongo    5. Ejura\n");
                printf("6. Tafo       7. Bekwai     8. Nsuta      9. Offinso    10. Agona\n");
            } 
            else if (state_choice == 2) { // GREATER ACCRA
                printf("🏙️  Top 10 Cities/Districts in GREATER ACCRA:\n");
                printf("1. Accra      2. Tema       3. Madina     4. Ashaiman   5. Teshie\n");
                printf("6. Dansoman   7. Legon      8. Adenta     9. Nungua     10. Ada Foah\n");
            }
            else if (state_choice == 3) { // EASTERN
                printf("🏙️  Top 10 Cities/Towns in EASTERN:\n");
                printf("1. Koforidua  2. Nkawkaw    3. Akim Oda   4. Akosombo   5. Suhum\n");
                printf("6. Asamankese 7. Mpraeso    8. Aburi      9. Somanya    10. Kwahu\n");
            }
            else if (state_choice == 4) { // CENTRAL
                printf("🏙️  Top 10 Cities/Towns in CENTRAL:\n");
                printf("1. Cape Coast 2. Winneba    3. Kasoa      4. Mankessim  5. Elmina\n");
                printf("6. Saltpond   7. Apam       8. Dunkwa     9. Swedru     10. Buduburam\n");
            }
            else if (state_choice == 5) { // WESTERN
                printf("🏙️  Top 10 Cities/Towns in WESTERN:\n");
                printf("1. Sekondi    2. Takoradi   3. Tarkwa     4. Axim       5. Prestea\n");
                printf("6. Elubo      7. Bibiani    8. Shama      9. Dixcove    10. Kwesimintsim\n");
            }
            else if (state_choice == 6) { // NORTHERN
                printf("🏙️  Top 10 Cities/Towns in NORTHERN:\n");
                printf("1. Tamale     2. Yendi      3. Savelugu   4. Bimbilla   5. Gushiegu\n");
                printf("6. Kumbungu   7. Saboba     8. Walewale   9. Tolon      10. Karaga\n");
            }
            else if (state_choice == 7) { // VOLTA
                printf("🏙️  Top 10 Cities/Towns in VOLTA:\n");
                printf("1. Ho         2. Hohoe      3. Kpando     4. Aflao      5. Anloga\n");
                printf("6. Sogakope   7. Keta       8. Dzodze     9. Akatsi     10. Peki\n");
            }
            else if (state_choice == 8) { // BONO
                printf("🏙️  Top 10 Cities/Towns in BONO:\n");
                printf("1. Sunyani    2. Berekum    3. Dormaa     4. Wenchi     5. Sampa\n");
                printf("6. Nsuatre    7. Drobo      8. Wamfie     9. Jaman      10. Seikwa\n");
            }
            else if (state_choice == 9) { // UPPER EAST
                printf("🏙️  Top 10 Cities/Towns in UPPER EAST:\n");
                printf("1. Bolgatanga 2. Bawku      3. Navrongo   4. Paga       5. Sandema\n");
                printf("6. Garu       7. Zebilla    8. Bongo      9. Tongo      10. Widana\n");
            }
            else if (state_choice == 10) { // UPPER WEST
                printf("🏙️  Top 10 Cities/Towns in UPPER WEST:\n");
                printf("1. Wa         2. Tumu       3. Jirapa     4. Lawra      5. Nandom\n");
                printf("6. Lambussie  7. Daffiama   8. Wechiau    9. Nadawli    10. Funsi\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/TOWN NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Ghana\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 9) { // TANZANIA
            int state_choice, city_choice;
            
            printf(">> TANZANIA: Select a Region (1-10)\n");
            printf("1. Dar es Salaam 2. Mwanza      3. Arusha\n");
            printf("4. Dodoma        5. Mbeya       6. Morogoro\n");
            printf("7. Tanga         8. Kahama      9. Tabora\n");
            printf("10. Zanzibar\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // DAR ES SALAAM
                printf("🏙️  Top 10 Districts/Areas in DAR ES SALAAM:\n");
                printf("1. Ilala      2. Kinondoni  3. Temeke     4. Kigamboni  5. Ubungo\n");
                printf("6. Masaki     7. Mikocheni  8. Kariakoo   9. Posta      10. Mbezi\n");
            } 
            else if (state_choice == 2) { // MWANZA
                printf("🏙️  Top 10 Cities/Districts in MWANZA:\n");
                printf("1. Nyamagana  2. Ilemela    3. Magu       4. Misungwi   5. Sengerema\n");
                printf("6. Kwimba     7. Ukerewe    8. Buchosa    9. Usagara    10. Nyegezi\n");
            }
            else if (state_choice == 3) { // ARUSHA
                printf("🏙️  Top 10 Cities/Towns in ARUSHA:\n");
                printf("1. Arusha City 2. Meru      3. Karatu     4. Monduli    5. Arumeru\n");
                printf("6. Ngorongoro 7. Longido    8. Usa River  9. Namanga    10. Mto wa Mbu\n");
            }
            else if (state_choice == 4) { // DODOMA
                printf("🏙️  Top 10 Cities/Districts in DODOMA:\n");
                printf("1. Dodoma City 2. Kondoa    3. Kongwa     4. Mpwapwa    5. Chamwino\n");
                printf("6. Chemba     7. Bahi       8. Kibaigwa   9. Ihumwa     10. Makulu\n");
            }
            else if (state_choice == 5) { // MBEYA
                printf("🏙️  Top 10 Cities/Towns in MBEYA:\n");
                printf("1. Mbeya City 2. Mbarali    3. Chunya     4. Kyela      5. Rungwe\n");
                printf("6. Busokelo   7. Tukuyu     8. Mbalizi    9. Uyole      10. Tunduma\n");
            }
            else if (state_choice == 6) { // MOROGORO
                printf("🏙️  Top 10 Cities/Towns in MOROGORO:\n");
                printf("1. Morogoro Town 2. Kilosa  3. Ifakara    4. Malinyi    5. Ulanga\n");
                printf("6. Mvomero    7. Gairo      8. Mikumi     9. Turiani    10. Mahenge\n");
            }
            else if (state_choice == 7) { // TANGA
                printf("🏙️  Top 10 Cities/Towns in TANGA:\n");
                printf("1. Tanga City 2. Muheza     3. Korogwe    4. Lushoto    5. Handeni\n");
                printf("6. Pangani    7. Kilindi    8. Mkinga     9. Mlalo      10. Amani\n");
            }
            else if (state_choice == 8) { // KAHAMA (Shinyanga Region)
                printf("🏙️  Top 10 Areas in KAHAMA:\n");
                printf("1. Kahama Town 2. Ushetu    3. Msalala    4. Isaka      5. Nyasubi\n");
                printf("6. Kagongwa   7. Majengo    8. Busoka     9. Malunga    10. Bukombe\n");
            }
            else if (state_choice == 9) { // TABORA
                printf("🏙️  Top 10 Cities/Towns in TABORA:\n");
                printf("1. Tabora City 2. Nzega     3. Igunga     4. Sikonge    5. Urambo\n");
                printf("6. Kaliua     7. Uyui       8. Bukene     9. Isevya     10. Chemchem\n");
            }
            else if (state_choice == 10) { // ZANZIBAR
                printf("🏝️  Top 10 Areas in ZANZIBAR:\n");
                printf("1. Stone Town 2. Nungwi     3. Kendwa     4. Paje       5. Jambiani\n");
                printf("6. Chwaka     7. Mkokotoni  8. Bububu     9. Kizimkazi  10. Michamvi\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/DISTRICT NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Tanzania\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 10) { // UGANDA
            int state_choice, city_choice;
            
            printf(">> UGANDA: Select a District (1-10)\n");
            printf("1. Kampala    2. Wakiso     3. Mbarara\n");
            printf("4. Jinja      5. Gulu       6. Mukono\n");
            printf("7. Kasese     8. Masaka     9. Lira\n");
            printf("10. Mbale\n");
            
            printf("\nENTER DISTRICT NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // KAMPALA
                printf("🏙️  Top 10 Divisions/Areas in KAMPALA:\n");
                printf("1. Nakasero   2. Kololo     3. Makindye   4. Kawempe    5. Rubaga\n");
                printf("6. Nakawa     7. Kibuli     8. Mengo      9. Muyenga    10. Bugolobi\n");
            } 
            else if (state_choice == 2) { // WAKISO
                printf("🏙️  Top 10 Cities/Towns in WAKISO:\n");
                printf("1. Entebbe    2. Kira       3. Nansana    4. Kajjansi   5. Kasangati\n");
                printf("6. Bulenga    7. Gayaza     8. Magere     9. Kyengera   10. Wakiso Town\n");
            }
            else if (state_choice == 3) { // MBARARA
                printf("🏙️  Top 10 Cities/Areas in MBARARA:\n");
                printf("1. Mbarara City 2. Kakoba   3. Kamukuzi   4. Nyamitanga 5. Biharwe\n");
                printf("6. Nyakayojo  7. Rubindi    8. Bwizibwera 9. Kashari    10. Rwanyamahembe\n");
            }
            else if (state_choice == 4) { // JINJA
                printf("🏙️  Top 10 Cities/Areas in JINJA:\n");
                printf("1. Jinja City 2. Walukuba   3. Bugembe    4. Masese     5. Mpumudde\n");
                printf("6. Kakira     7. Buwenge    8. Budondo    9. Mafubira   10. Bujagali\n");
            }
            else if (state_choice == 5) { // GULU
                printf("🏙️  Top 10 Cities/Areas in GULU:\n");
                printf("1. Gulu City  2. Layibi     3. Pece       4. Laroo      5. Bardege\n");
                printf("6. Unyama     7. Bobi       8. Koro       9. Paicho     10. Awach\n");
            }
            else if (state_choice == 6) { // MUKONO
                printf("🏙️  Top 10 Cities/Towns in MUKONO:\n");
                printf("1. Mukono Town 2. Seeta     3. Lugazi     4. Mbalala    5. Nakifuma\n");
                printf("6. Goma       7. Nagojje    8. Katosi     9. Kisoga     10. Nama\n");
            }
            else if (state_choice == 7) { // KASESE
                printf("🏙️  Top 10 Cities/Towns in KASESE:\n");
                printf("1. Kasese Town 2. Mpondwe   3. Katwe      4. Hima       5. Kikorongo\n");
                printf("6. Bwera      7. Muhokya    8. Kisinga    9. Mubuku     10. Kyarumba\n");
            }
            else if (state_choice == 8) { // MASAKA
                printf("🏙️  Top 10 Cities/Areas in MASAKA:\n");
                printf("1. Masaka City 2. Nyendo    3. Kimaanya   4. Katwe      5. Lukaya\n");
                printf("6. Bukakata   7. Kyanamukaaka 8. Kabonera 9. Lambu     10. Buwunga\n");
            }
            else if (state_choice == 9) { // LIRA
                printf("🏙️  Top 10 Cities/Areas in LIRA:\n");
                printf("1. Lira City  2. Adyel      3. Central Div 4. Ojwina    5. Railways Div\n");
                printf("6. Agwata     7. Amach      8. Erute      9. Boroboro   10. Ireda\n");
            }
            else if (state_choice == 10) { // MBALE
                printf("🏙️  Top 10 Cities/Areas in MBALE:\n");
                printf("1. Mbale City 2. Industrial Div 3. Northern Div 4. Namatala 5. Wanale\n");
                printf("6. Nakaloke   7. Busiu      8. Bungokho   9. Bubyangu   10. Nabumali\n");
            }
            else {
                printf("⚠️ Invalid District Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Africa\n");
                printf(">> Country: Uganda\n");
                printf(">> District Code: %d, Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else {
            printf("⚠️ Invalid Country Selection within Africa.\n");
        }
    }



    else if (choice == 2) {
        int station_choice;

        printf("📍 CONTINENT: ANTARCTICA\n");
        printf("NOTE: Antarctica has no countries, but 10 Research Stations:\n");
        printf("1. McMurdo (USA)     2. Vostok (Russia)\n");
        printf("3. Amundsen (USA)    4. Showa (Japan)\n");
        printf("5. Maitri (India)    6. Bharati (India)\n");
        printf("7. Casey (Australia) 8. Esperanza (Argentina)\n");
        printf("9. Scott (NZ)        10. Concordia (FR/IT)\n");

        printf("\nCHOOSE A STATION (1-10) TO SEE DETAILS: ");
        scanf("%d", &station_choice);
        printf("------------------------------\n");

        if (station_choice == 1) {
            printf(">> STATION: MCMURDO (USA)\n");
            printf("1. Largest community in Antarctica\n");
            printf("2. Has an airport (Ice Runway)\n");
            printf("3. Features an underground 'Observation Tube'\n");
            printf("4. Population can reach 1,000 in summer\n");
        } 
        else if (station_choice == 2) {
            printf(">> STATION: VOSTOK (Russia)\n");
            printf("1. Located at the Southern Pole of Cold\n");
            printf("2. Records the lowest temperatures on Earth\n");
            printf("3. Sits above Lake Vostok (Subglacial lake)\n");
            printf("4. Famous for deep ice core drilling\n");
        }
        else if (station_choice == 3) {
            printf(">> STATION: AMUNDSEN-SCOTT (USA)\n");
            printf("1. Located exactly at the Geographic South Pole\n");
            printf("2. High altitude (2,835 meters)\n");
            printf("3. Experiences 6 months of dark, 6 months of light\n");
            printf("4. Key site for South Pole Telescope (SPT)\n");
        }
        else if (station_choice == 4) {
            printf(">> STATION: SHOWA (Japan)\n");
            printf("1. Located on East Ongul Island\n");
            printf("2. Focuses on upper atmosphere physics\n");
            printf("3. Famous for aurora observation\n");
            printf("4. Operational since 1957\n");
        }
        else if (station_choice == 5) {
            printf(">> STATION: MAITRI (India)\n");
            printf("1. India's second permanent research station\n");
            printf("2. Located in the Schirmacher Oasis\n");
            printf("3. Built with steel on a rocky foundation\n");
            printf("4. Near the freshwater Lake Priyadarshini\n");
        }
        else if (station_choice == 6) {
            printf(">> STATION: BHARATI (India)\n");
            printf("1. India's newest Antarctic research facility\n");
            printf("2. Constructed using 134 shipping containers\n");
            printf("3. Located at Larsemann Hills\n");
            printf("4. Focuses on oceanographic and geological research\n");
        }
        else if (station_choice == 7) {
            printf(">> STATION: CASEY (Australia)\n");
            printf("1. Located on the Vincennes Bay\n");
            printf("2. Originally built on stilts to let snow blow under\n");
            printf("3. Hub for Australian Antarctic flights\n");
            printf("4. Famous for the 'Red Shed' living quarters\n");
        }
        else if (station_choice == 8) {
            printf(">> STATION: ESPERANZA (Argentina)\n");
            printf("1. One of only two civilian settlements in Antarctica\n");
            printf("2. Has a school and a radio station\n");
            printf("3. Site of the first human birth in Antarctica\n");
            printf("4. Located at the tip of the Antarctic Peninsula\n");
        }
        else if (station_choice == 9) {
            printf(">> STATION: SCOTT BASE (New Zealand)\n");
            printf("1. Located at Pram Point, Ross Island\n");
            printf("2. Painted in a distinctive bright green color\n");
            printf("3. Studying the Ross Ice Shelf\n");
            printf("4. Close neighbors with McMurdo station\n");
        }
        else if (station_choice == 10) {
            printf(">> STATION: CONCORDIA (France/Italy)\n");
            printf("1. Shared station on a high Antarctic plateau\n");
            printf("2. Known as 'White Mars' for its isolation\n");
            printf("3. Air is extremely dry and thin (low oxygen)\n");
            printf("4. Used by ESA to simulate space travel\n");
        }
        else {
            printf("⚠️ Invalid Station Selection.\n");
        }
    }



    else if (choice == 3) {
        int country_choice;
        
        printf("📍 CONTINENT: ASIA\n");
        printf("TOP 10 COUNTRIES:\n");
        printf("1. India      2. China      3. Japan\n");
        printf("4. Indonesia  5. Pakistan   6. S. Korea\n");
        printf("7. Vietnam    8. Thailand   9. Turkey\n");
        printf("10. Saudi Arabia\n");

        printf("\nCHOOSE A COUNTRY (1-10): ");
        scanf("%d", &country_choice);
        printf("------------------------------\n");

        if (country_choice == 1) { // INDIA
            int state_choice, city_choice;
            
            printf(">> INDIA: Select a State/UT (1-10)\n");
            printf("1. Uttar Pradesh  2. Maharashtra  3. Bihar\n");
            printf("4. West Bengal    5. Madhya Pr.   6. Tamil Nadu\n");
            printf("7. Rajasthan      8. Karnataka    9. Gujarat\n");
            printf("10. Delhi (NCT)\n");
            
            printf("\nENTER STATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // UTTAR PRADESH
                printf("🏙️  Top 10 Cities in UTTAR PRADESH:\n");
                printf("1. Lucknow    2. Kanpur     3. Ghaziabad  4. Agra       5. Varanasi\n");
                printf("6. Meerut     7. Prayagraj  8. Bareilly   9. Aligarh    10. Noida\n");
            } 
            else if (state_choice == 2) { // MAHARASHTRA
                printf("🏙️  Top 10 Cities in MAHARASHTRA:\n");
                printf("1. Mumbai     2. Pune       3. Nagpur     4. Thane      5. Pimpri-Chinchwad\n");
                printf("6. Nashik     7. Kalyan     8. Vasai-Virar 9. Aurangabad 10. Navi Mumbai\n");
            }
            else if (state_choice == 3) { // BIHAR
                printf("🏙️  Top 10 Cities in BIHAR:\n");
                printf("1. Patna      2. Gaya       3. Bhagalpur  4. Muzaffarpur 5. Purnia\n");
                printf("6. Darbhanga  7. Arrah      8. Begusarai  9. Katihar    10. Munger\n");
            }
            else if (state_choice == 4) { // WEST BENGAL
                printf("🏙️  Top 10 Cities in WEST BENGAL:\n");
                printf("1. Kolkata    2. Howrah     3. Durgapur   4. Asansol    5. Siliguri\n");
                printf("6. Maheshtala 7. Rajpur     8. Berhampore 9. Malda      10. Bardhaman\n");
            }
            else if (state_choice == 5) { // MADHYA PRADESH
                printf("🏙️  Top 10 Cities in MADHYA PRADESH:\n");
                printf("1. Indore     2. Bhopal     3. Jabalpur   4. Gwalior    5. Ujjain\n");
                printf("6. Sagar      7. Dewas      8. Satna      9. Ratlam     10. Rewa\n");
            }
            else if (state_choice == 6) { // TAMIL NADU
                printf("🏙️  Top 10 Cities in TAMIL NADU:\n");
                printf("1. Chennai    2. Coimbatore 3. Madurai    4. Tiruchirappalli 5. Salem\n");
                printf("6. Tiruppur   7. Erode      8. Vellore    9. Thoothukudi 10. Thanjavur\n");
            }
            else if (state_choice == 7) { // RAJASTHAN
                printf("🏙️  Top 10 Cities in RAJASTHAN:\n");
                printf("1. Jaipur     2. Jodhpur    3. Kota       4. Bikaner    5. Ajmer\n");
                printf("6. Udaipur    7. Bhilwara   8. Alwar      9. Bharatpur  10. Sikar\n");
            }
            else if (state_choice == 8) { // KARNATAKA
                printf("🏙️  Top 10 Cities in KARNATAKA:\n");
                printf("1. Bengaluru  2. Hubli      3. Mysore     4. Kalaburagi 5. Belagavi\n");
                printf("6. Mangaluru  7. Davanagere 8. Ballari    9. Vijayapura 10. Shivamogga\n");
            }
            else if (state_choice == 9) { // GUJARAT
                printf("🏙️  Top 10 Cities in GUJARAT:\n");
                printf("1. Ahmedabad  2. Surat      3. Vadodara   4. Rajkot     5. Bhavnagar\n");
                printf("6. Jamnagar   7. Junagadh   8. Gandhidham 9. Nadiad     10. Gandhinagar\n");
            }
            else if (state_choice == 10) { // DELHI
                printf("🏙️  Top 10 Areas in DELHI:\n");
                printf("1. New Delhi  2. Dwarka     3. Rohini     4. Saket      5. Karol Bagh\n");
                printf("6. Chandni Chowk 7. Laxmi Nagar 8. Janakpuri 9. Vasant Kunj 10. Hauz Khas\n");
            }
            else {
                printf("⚠️ Invalid State Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: India\n");
                printf(">> State Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid City Number.\n");
            }
        }

        else if (country_choice == 2) { // CHINA
            int state_choice, city_choice;
            
            printf(">> CHINA: Select a Province (1-10)\n");
            printf("1. Guangdong      2. Shandong     3. Henan\n");
            printf("4. Sichuan        5. Jiangsu      6. Hebei\n");
            printf("7. Hunan          8. Zhejiang     9. Anhui\n");
            printf("10. Hubei\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // GUANGDONG
                printf("🏙️  Top 10 Cities in GUANGDONG:\n");
                printf("1. Guangzhou  2. Shenzhen   3. Dongguan   4. Foshan     5. Huizhou\n");
                printf("6. Zhongshan  7. Shantou    8. Jiangmen   9. Zhanjiang  10. Zhuhai\n");
            } 
            else if (state_choice == 2) { // SHANDONG
                printf("🏙️  Top 10 Cities in SHANDONG:\n");
                printf("1. Jinan      2. Qingdao    3. Zibo       4. Yantai     5. Weifang\n");
                printf("6. Jining     7. Tai'an     8. Weihai     9. Rizhao     10. Linyi\n");
            }
            else if (state_choice == 3) { // HENAN
                printf("🏙️  Top 10 Cities in HENAN:\n");
                printf("1. Zhengzhou  2. Kaifeng    3. Luoyang    4. Anyang     5. Xinxiang\n");
                printf("6. Jiaozuo    7. Puyang     8. Xuchang    9. Luohe      10. Nanyang\n");
            }
            else if (state_choice == 4) { // SICHUAN
                printf("🏙️  Top 10 Cities in SICHUAN:\n");
                printf("1. Chengdu    2. Zigong     3. Panzhihua  4. Luzhou     5. Deyang\n");
                printf("6. Mianyang   7. Guangyuan  8. Suining    9. Neijiang   10. Leshan\n");
            }
            else if (state_choice == 5) { // JIANGSU
                printf("🏙️  Top 10 Cities in JIANGSU:\n");
                printf("1. Nanjing    2. Wuxi       3. Xuzhou     4. Changzhou  5. Suzhou\n");
                printf("6. Nantong    7. Lianyungang 8. Huai'an   9. Yancheng   10. Yangzhou\n");
            }
            else if (state_choice == 6) { // HEBEI
                printf("🏙️  Top 10 Cities in HEBEI:\n");
                printf("1. Shijiazhuang 2. Tangshan 3. Qinhuangdao 4. Handan   5. Xingtai\n");
                printf("6. Baoding    7. Zhangjiakou 8. Chengde   9. Cangzhou   10. Langfang\n");
            }
            else if (state_choice == 7) { // HUNAN
                printf("🏙️  Top 10 Cities in HUNAN:\n");
                printf("1. Changsha   2. Zhuzhou    3. Xiangtan   4. Hengyang   5. Shaoyang\n");
                printf("6. Yueyang    7. Changde    8. Zhangjiajie 9. Yiyang    10. Chenzhou\n");
            }
            else if (state_choice == 8) { // ZHEJIANG
                printf("🏙️  Top 10 Cities in ZHEJIANG:\n");
                printf("1. Hangzhou   2. Ningbo     3. Wenzhou    4. Jiaxing    5. Huzhou\n");
                printf("6. Shaoxing   7. Jinhua     8. Quzhou     9. Zhoushan   10. Taizhou\n");
            }
            else if (state_choice == 9) { // ANHUI
                printf("🏙️  Top 10 Cities in ANHUI:\n");
                printf("1. Hefei      2. Wuhu       3. Bengbu     4. Huainan    5. Ma'anshan\n");
                printf("6. Huaibei    7. Tongling   8. Anqing     9. Huangshan  10. Chuzhou\n");
            }
            else if (state_choice == 10) { // HUBEI
                printf("🏙️  Top 10 Cities in HUBEI:\n");
                printf("1. Wuhan      2. Huangshi   3. Shiyan     4. Yichang    5. Xiangyang\n");
                printf("6. Ezhou      7. Jingmen    8. Xiaogan    9. Jingzhou   10. Huanggang\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: China\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid City Number.\n");
            }
        }

        else if (country_choice == 3) { // JAPAN
            int state_choice, city_choice;
            
            printf(">> JAPAN: Select a Prefecture (1-10)\n");
            printf("1. Tokyo          2. Kanagawa     3. Osaka\n");
            printf("4. Aichi          5. Saitama      6. Chiba\n");
            printf("7. Hyogo          8. Hokkaido     9. Fukuoka\n");
            printf("10. Shizuoka\n");
            
            printf("\nENTER PREFECTURE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // TOKYO
                printf("🏙️  Top 10 Cities/Districts in TOKYO:\n");
                printf("1. Shinjuku   2. Shibuya    3. Minato     4. Chuo       5. Koto\n");
                printf("6. Setagaya   7. Nerima     8. Edogawa    9. Adachi     10. Hachioji\n");
            } 
            else if (state_choice == 2) { // KANAGAWA
                printf("🏙️  Top 10 Cities in KANAGAWA:\n");
                printf("1. Yokohama   2. Kawasaki   3. Sagamihara 4. Fujisawa   5. Yokosuka\n");
                printf("6. Hiratsuka  7. Atsugi     8. Chigasaki  9. Yamato     10. Odawara\n");
            }
            else if (state_choice == 3) { // OSAKA
                printf("🏙️  Top 10 Cities in OSAKA:\n");
                printf("1. Osaka City 2. Sakai      3. Higashiosaka 4. Hirakata 5. Toyonaka\n");
                printf("6. Suita      7. Takatsuki  8. Ibaraki    9. Yao        10. Neyagawa\n");
            }
            else if (state_choice == 4) { // AICHI
                printf("🏙️  Top 10 Cities in AICHI:\n");
                printf("1. Nagoya     2. Toyota     3. Okazaki    4. Ichinomiya 5. Toyohashi\n");
                printf("6. Kasugai    5. Anjo       8. Toyokawa   9. Komaki     10. Kariya\n");
            }
            else if (state_choice == 5) { // SAITAMA
                printf("🏙️  Top 10 Cities in SAITAMA:\n");
                printf("1. Saitama City 2. Kawaguchi 3. Kawagoe  4. Tokorozawa 5. Koshigaya\n");
                printf("6. Soka       7. Kasukabe   8. Ageo       9. Kumagaya   10. Niiza\n");
            }
            else if (state_choice == 6) { // CHIBA
                printf("🏙️  Top 10 Cities in CHIBA:\n");
                printf("1. Chiba City 2. Funabashi  3. Matsudo    4. Ichikawa   5. Kashiwa\n");
                printf("6. Ichihara   7. Yachiyo    8. Nagareyama 9. Narashino  10. Sakura\n");
            }
            else if (state_choice == 7) { // HYOGO
                printf("🏙️  Top 10 Cities in HYOGO:\n");
                printf("1. Kobe       2. Himeji     3. Nishinomiya 4. Amagasaki 5. Akashi\n");
                printf("6. Kakogawa   7. Takarazuka 8. Itami      9. Kawanishi  10. Sanda\n");
            }
            else if (state_choice == 8) { // HOKKAIDO
                printf("🏙️  Top 10 Cities in HOKKAIDO:\n");
                printf("1. Sapporo    2. Asahikawa  3. Hakodate   4. Kushiro    5. Tomakomai\n");
                printf("6. Obihiro    7. Otaru      8. Kitami     9. Ebetsu     10. Muroran\n");
            }
            else if (state_choice == 9) { // FUKUOKA
                printf("🏙️  Top 10 Cities in FUKUOKA:\n");
                printf("1. Fukuoka City 2. Kitakyushu 3. Kurume   4. Iizuka     5. Omuta\n");
                printf("6. Kasuga     7. Chikushino 8. Onojo      9. Munakata   10. Itoshima\n");
            }
            else if (state_choice == 10) { // SHIZUOKA
                printf("🏙️  Top 10 Cities in SHIZUOKA:\n");
                printf("1. Hamamatsu  2. Shizuoka City 3. Fuji    4. Numazu     5. Iwata\n");
                printf("6. Yaizu      7. Fujieda    8. Mishima    9. Fujinomiya 10. Kakegawa\n");
            }
            else {
                printf("⚠️ Invalid Prefecture Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: Japan\n");
                printf(">> Prefecture Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid City Number.\n");
            }
        }

        else if (country_choice == 4) { // INDONESIA
            int state_choice, city_choice;
            
            printf(">> INDONESIA: Select a Province (1-10)\n");
            printf("1. West Java      2. East Java    3. Central Java\n");
            printf("4. North Sumatra  5. Banten       6. Jakarta\n");
            printf("7. South Sulawesi 8. Lampung      9. South Sumatra\n");
            printf("10. Riau\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // WEST JAVA
                printf("🏙️  Top 10 Cities in WEST JAVA:\n");
                printf("1. Bandung    2. Bekasi     3. Depok      4. Bogor      5. Tasikmalaya\n");
                printf("6. Cimahi     7. Sukabumi   8. Cirebon    9. Banjar     10. Sumedang\n");
            } 
            else if (state_choice == 2) { // EAST JAVA
                printf("🏙️  Top 10 Cities in EAST JAVA:\n");
                printf("1. Surabaya   2. Malang     3. Kediri     4. Probolinggo 5. Pasuruan\n");
                printf("6. Madiun     7. Batu       8. Blitar     9. Mojokerto  10. Jember\n");
            }
            else if (state_choice == 3) { // CENTRAL JAVA
                printf("🏙️  Top 10 Cities in CENTRAL JAVA:\n");
                printf("1. Semarang   2. Surakarta  3. Pekalongan 4. Tegal      5. Salatiga\n");
                printf("6. Magelang   7. Cilacap    8. Banyumas   9. Kudus      10. Brebes\n");
            }
            else if (state_choice == 4) { // NORTH SUMATRA
                printf("🏙️  Top 10 Cities in NORTH SUMATRA:\n");
                printf("1. Medan      2. Binjai     3. Pematangsiantar 4. Padangsidimpuan 5. Tebing Tinggi\n");
                printf("6. Sibolga    7. Tanjungbalai 8. Gunungsitoli 9. Deli Serdang 10. Karo\n");
            }
            else if (state_choice == 5) { // BANTEN
                printf("🏙️  Top 10 Cities in BANTEN:\n");
                printf("1. Tangerang  2. South Tangerang 3. Serang    4. Cilegon    5. Pandeglang\n");
                printf("6. Lebak      7. Ciputat    8. Pamulang   9. Balaraja   10. Tigaraksa\n");
            }
            else if (state_choice == 6) { // JAKARTA (Special Capital Region)
                printf("🏙️  Top 10 Areas in JAKARTA:\n");
                printf("1. Central Jakarta 2. West Jakarta 3. South Jakarta 4. East Jakarta 5. North Jakarta\n");
                printf("6. Kepulauan Seribu 7. Menteng  8. Kemang     9. Senayan    10. Kelapa Gading\n");
            }
            else if (state_choice == 7) { // SOUTH SULAWESI
                printf("🏙️  Top 10 Cities in SOUTH SULAWESI:\n");
                printf("1. Makassar   2. Palopo     3. Parepare   4. Gowa       5. Bone\n");
                printf("6. Maros      7. Bulukumba  8. Toraja     9. Luwu       10. Sidrap\n");
            }
            else if (state_choice == 8) { // LAMPUNG
                printf("🏙️  Top 10 Cities in LAMPUNG:\n");
                printf("1. Bandar Lampung 2. Metro   3. Pringsewu  4. Kotabumi   5. Kalianda\n");
                printf("6. Liwa       7. Menggala   8. Sukadana   9. Gunung Sugih 10. Mesuji\n");
            }
            else if (state_choice == 9) { // SOUTH SUMATRA
                printf("🏙️  Top 10 Cities in SOUTH SUMATRA:\n");
                printf("1. Palembang  2. Lubuklinggau 3. Pagar Alam 4. Prabumulih 5. Banyuasin\n");
                printf("6. Ogan Ilir  7. Muara Enim 8. Lahat      9. Musi Rawas 10. Sekayu\n");
            }
            else if (state_choice == 10) { // RIAU
                printf("🏙️  Top 10 Cities in RIAU:\n");
                printf("1. Pekanbaru  2. Dumai      3. Duri       4. Bengkalis  5. Tembilahan\n");
                printf("6. Pangkalan Kerinci 7. Bangkinang 8. Pasir Pengaraian 9. Siak Sri Indrapura 10. Rengat\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: Indonesia\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid City Number.\n");
            }
        }

        else if (country_choice == 5) { // PAKISTAN
            int state_choice, city_choice;
            
            printf(">> PAKISTAN: Select a Province/Territory (1-7)\n");
            printf("1. Punjab          2. Sindh        3. Khyber Pakhtunkhwa\n");
            printf("4. Balochistan     5. Islamabad    6. Azad Kashmir\n");
            printf("7. Gilgit-Baltistan\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // PUNJAB
                printf("🏙️  Top 10 Cities in PUNJAB:\n");
                printf("1. Lahore     2. Faisalabad 3. Rawalpindi 4. Multan    5. Gujranwala\n");
                printf("6. Bahawalpur 7. Sargodha   8. Sialkot    9. Sheikhupura 10. Rahim Yar Khan\n");
            } 
            else if (state_choice == 2) { // SINDH
                printf("🏙️  Top 10 Cities in SINDH:\n");
                printf("1. Karachi    2. Hyderabad  3. Sukkur     4. Larkana   5. Nawabshah\n");
                printf("6. Mirpur Khas 7. Jacobabad  8. Shikarpur  9. Khairpur  10. Dadu\n");
            }
            else if (state_choice == 3) { // KHYBER PAKHTUNKHWA
                printf("🏙️  Top 10 Cities in KPK:\n");
                printf("1. Peshawar   2. Mardan     3. Mingora    4. Kohat     5. Abbottabad\n");
                printf("6. Mansehra   7. Swabi      8. Nowshera   9. D.I. Khan 10. Charsadda\n");
            }
            else if (state_choice == 4) { // BALOCHISTAN
                printf("🏙️  Top 10 Cities in BALOCHISTAN:\n");
                printf("1. Quetta     2. Turbat     3. Khuzdar    4. Hub       5. Chaman\n");
                printf("6. Gwadar     7. Dera Murad Jamali 8. Usta Mohammad 9. Loralai 10. Pasni\n");
            }
            else if (state_choice == 5) { // ISLAMABAD (Capital)
                printf("🏙️  Top 10 Sectors/Areas in ISLAMABAD:\n");
                printf("1. Blue Area  2. Sector F-6 3. Sector F-7 4. Sector G-9 5. Sector I-8\n");
                printf("6. Bani Gala  7. Bahria Town 8. DHA       9. Gulberg    10. E-7\n");
            }
            else if (state_choice == 6) { // AZAD KASHMIR
                printf("🏙️  Top 10 Cities in AZAD KASHMIR:\n");
                printf("1. Muzaffarabad 2. Mirpur   3. Rawalakot  4. Kotli     5. Bhimber\n");
                printf("6. Bagh       7. Pallandri  8. Hattian    9. Haveli    10. Neelam\n");
            }
            else if (state_choice == 7) { // GILGIT-BALTISTAN
                printf("🏙️  Top 10 Cities/Areas in GILGIT-BALTISTAN:\n");
                printf("1. Gilgit     2. Skardu     3. Hunza      4. Chilas    5. Gupis\n");
                printf("6. Khaplu     7. Shigar     8. Nagar      9. Astore    10. Ghizer\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: Pakistan\n");
                printf(">> Unit Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid City Number.\n");
            }
        }

        else if (country_choice == 6) { // SOUTH KOREA
            int state_choice, city_choice;
            
            printf(">> SOUTH KOREA: Select a Region (1-10)\n");
            printf("1. Seoul          2. Gyeonggi     3. Busan\n");
            printf("4. Gyeongnam      5. Incheon      6. Gyeongbuk\n");
            printf("7. Daegu          8. Chungnam     9. Jeonnam\n");
            printf("10. Jeonbuk\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // SEOUL (Special City)
                printf("🏙️  Top 10 Districts in SEOUL:\n");
                printf("1. Gangnam    2. Myeong-dong 3. Hongdae    4. Itaewon    5. Songpa\n");
                printf("6. Yongsan    7. Yeouido    8. Jongno     9. Dongdaemun 10. Gwanak\n");
            } 
            else if (state_choice == 2) { // GYEONGGI
                printf("🏙️  Top 10 Cities in GYEONGGI:\n");
                printf("1. Suwon      2. Goyang     3. Yongin     4. Seongnam   5. Bucheon\n");
                printf("6. Ansan      7. Anyang     8. Hwaseong   9. Pyeongtaek 10. Uijeongbu\n");
            }
            else if (state_choice == 3) { // BUSAN (Metropolitan City)
                printf("🏙️  Top 10 Districts in BUSAN:\n");
                printf("1. Haeundae   2. Busanjin   3. Sahagu     4. Dongnae    5. Namgu\n");
                printf("6. Bukgu      7. Geumjeong  8. Sasang     9. Jung-gu    10. Yeonje\n");
            }
            else if (state_choice == 4) { // GYEONGNAM
                printf("🏙️  Top 10 Cities in GYEONGNAM:\n");
                printf("1. Changwon   2. Gimhae     3. Jinju      4. Yangsan    5. Geoje\n");
                printf("6. Tongyeong  7. Sacheon    8. Miryang    9. Namhae     10. Haman\n");
            }
            else if (state_choice == 5) { // INCHEON
                printf("🏙️  Top 10 Districts in INCHEON:\n");
                printf("1. Bupyeong   2. Namdong    3. Seo-gu     4. Michuhol   5. Yeonsu\n");
                printf("6. Gyeyang    7. Jung-gu    8. Dong-gu    9. Ganghwa    10. Ongjin\n");
            }
            else if (state_choice == 6) { // GYEONGBUK
                printf("🏙️  Top 10 Cities in GYEONGBUK:\n");
                printf("1. Pohang     2. Gumi       3. Gyeongju   4. Gyeongsan  5. Andong\n");
                printf("6. Gimcheon   7. Yeongju    8. Sangju     9. Yeongcheon 10. Mungyeong\n");
            }
            else if (state_choice == 7) { // DAEGU
                printf("🏙️  Top 10 Districts in DAEGU:\n");
                printf("1. Dalseo     2. Buk-gu     3. Suseong    4. Dong-gu    5. Seogu\n");
                printf("6. Nam-gu     7. Jung-gu    8. Dalseong   9. Ansim      10. Chilgok\n");
            }
            else if (state_choice == 8) { // CHUNGNAM
                printf("🏙️  Top 10 Cities in CHUNGNAM:\n");
                printf("1. Cheonan    2. Asan       3. Seosan     4. Dangjin    5. Gongju\n");
                printf("6. Nonsan     9. Boryeong   8. Gyeryong   9. Yesan      10. Buyeo\n");
            }
            else if (state_choice == 9) { // JEONNAM
                printf("🏙️  Top 10 Cities in JEONNAM:\n");
                printf("1. Yeosu      2. Suncheon   3. Mokpo      4. Gwangyang  5. Naju\n");
                printf("6. Muanda     7. Hwasun     8. Yeongam    9. Boseong    10. Damyang\n");
            }
            else if (state_choice == 10) { // JEONBUK
                printf("🏙️  Top 10 Cities in JEONBUK:\n");
                printf("1. Jeonju     2. Iksan      3. Gunsan     4. Jeongeup   5. Namwon\n");
                printf("6. Gimje      7. Wanju      8. Gochang    9. Buan       10. Sunchang\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/DISTRICT NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: South Korea\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 7) { // VIETNAM
            int state_choice, city_choice;
            
            printf(">> VIETNAM: Select a Province (1-10)\n");
            printf("1. Ho Chi Minh    2. Hanoi        3. Thanh Hoa\n");
            printf("4. Nghe An        5. Dong Nai     6. Binh Duong\n");
            printf("7. Hai Phong      8. An Giang     9. Dak Lak\n");
            printf("10. Thai Binh\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // HO CHI MINH CITY (Municipality)
                printf("🏙️  Top 10 Districts in HO CHI MINH CITY:\n");
                printf("1. District 1  2. District 3  3. District 7  4. Thu Duc City 5. Binh Thanh\n");
                printf("6. District 5  7. District 10 8. Tan Binh   9. District 4  10. Go Vap\n");
            } 
            else if (state_choice == 2) { // HANOI (Capital Municipality)
                printf("🏙️  Top 10 Districts in HANOI:\n");
                printf("1. Ba Dinh     2. Hoan Kiem   3. Tay Ho      4. Cau Giay    5. Dong Da\n");
                printf("6. Hai Ba Trung 7. Thanh Xuan 8. Long Bien   9. Ha Dong     10. Nam Tu Liem\n");
            }
            else if (state_choice == 3) { // THANH HOA
                printf("🏙️  Top 10 Cities/Towns in THANH HOA:\n");
                printf("1. Thanh Hoa City 2. Sam Son 3. Bim Son     4. Nghi Son    5. Tho Xuan\n");
                printf("6. Yen Dinh    7. Hoang Hoa   8. Nong Cong   9. Trieu Son   10. Thieu Hoa\n");
            }
            else if (state_choice == 4) { // NGHE AN
                printf("🏙️  Top 10 Cities/Towns in NGHE AN:\n");
                printf("1. Vinh City   2. Cua Lo      3. Thai Hoa    4. Quynh Luu   5. Dien Chau\n");
                printf("6. Yen Thanh   7. Do Luong    8. Nam Dan     9. Nghia Dan   10. Thanh Chuong\n");
            }
            else if (state_choice == 5) { // DONG NAI
                printf("🏙️  Top 10 Cities/Towns in DONG NAI:\n");
                printf("1. Bien Hoa    2. Long Khanh  3. Long Thanh  4. Nhon Trach  5. Trang Bom\n");
                printf("6. Xuan Loc    7. Dinh Quan   8. Tan Phu     9. Thong Nhat  10. Cam My\n");
            }
            else if (state_choice == 6) { // BINH DUONG
                printf("🏙️  Top 10 Cities/Towns in BINH DUONG:\n");
                printf("1. Thu Dau Mot 2. Thuan An    3. Di An       4. Tan Uyen    5. Ben Cat\n");
                printf("6. Bau Bang    7. Bac Tan Uyen 8. Dau Tieng  9. Phu Giao    10. VSIP Area\n");
            }
            else if (state_choice == 7) { // HAI PHONG (Municipality)
                printf("🏙️  Top 10 Districts in HAI PHONG:\n");
                printf("1. Hong Bang   2. Le Chan     3. Ngo Quyen   4. Kien An     5. Hai An\n");
                printf("6. Do Son      7. Duong Kinh  8. Thuy Nguyen 9. An Duong    10. Cat Ba\n");
            }
            else if (state_choice == 8) { // AN GIANG
                printf("🏙️  Top 10 Cities/Towns in AN GIANG:\n");
                printf("1. Long Xuyen  2. Chau Doc    3. Tan Chau    4. Cho Moi     5. Phu Tan\n");
                printf("6. Thoai Son   7. Tinh Bien   8. An Phu      9. Chau Phu    10. Chau Thanh\n");
            }
            else if (state_choice == 9) { // DAK LAK
                printf("🏙️  Top 10 Cities/Towns in DAK LAK:\n");
                printf("1. Buon Ma Thuot 2. Buon Ho   3. Ea H'leo    4. Krong Pac   5. Krong Ana\n");
                printf("6. Cu M'gar    7. Ea Kar      8. Krong Buk   9. Krong Nang  10. Lak\n");
            }
            else if (state_choice == 10) { // THAI BINH
                printf("🏙️  Top 10 Cities/Towns in THAI BINH:\n");
                printf("1. Thai Binh City 2. Dong Hung 3. Hung Ha   4. Kien Xuong  5. Quynh Phu\n");
                printf("6. Thai Thuy   7. Tien Hai    8. Vu Thu      9. Diem Dien   10. Tien Hai Port\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/DISTRICT NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: Vietnam\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 8) { // THAILAND
            int state_choice, city_choice;
            
            printf(">> THAILAND: Select a Province (1-10)\n");
            printf("1. Bangkok          2. Nakhon Ratchasima 3. Samut Prakan\n");
            printf("4. Chiang Mai       5. Khon Kaen         6. Chonburi\n");
            printf("7. Ubon Ratchathani 8. Nakhon Si Thammarat\n");
            printf("9. Buriram          10. Surat Thani\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // BANGKOK (Special Administrative Area)
                printf("🏙️  Top 10 Districts in BANGKOK:\n");
                printf("1. Khlong Toei 2. Watthana    3. Bang Rak    4. Pathum Wan  5. Dusit\n");
                printf("6. Chatuchak   7. Bang Na      8. Phaya Thai  9. Phra Nakhon 10. Yan Nawa\n");
            } 
            else if (state_choice == 2) { // NAKHON RATCHASIMA
                printf("🏙️  Top 10 Cities/Districts in NAKHON RATCHASIMA:\n");
                printf("1. Korat City  2. Pak Chong   3. Si Khiu     4. Phimai      5. Non Thai\n");
                printf("6. Sung Noen   7. Kham Thale So 8. Chok Chai  9. Dan Khun Thot 10. Bua Yai\n");
            }
            else if (state_choice == 3) { // SAMUT PRAKAN
                printf("🏙️  Top 10 Cities/Districts in SAMUT PRAKAN:\n");
                printf("1. Samut Prakan City 2. Phra Pradaeng 3. Bang Phli 4. Bang Bo 5. Bang Sao Thong\n");
                printf("6. Phra Samut Chedi 7. Bang Pu 8. Phraek Sa  9. Samrong    10. Bang Chalong\n");
            }
            else if (state_choice == 4) { // CHIANG MAI
                printf("🏙️  Top 10 Cities/Districts in CHIANG MAI:\n");
                printf("1. Chiang Mai City 2. Mae Rim 3. Hang Dong   4. San Sai     5. Doi Saket\n");
                printf("6. Saraphi     7. Mae Taeng   8. Chom Thong  9. Fang        10. San Pa Tong\n");
            }
            else if (state_choice == 5) { // KHON KAEN
                printf("🏙️  Top 10 Cities/Districts in KHON KAEN:\n");
                printf("1. Khon Kaen City 2. Ban Phai 3. Chum Phae   4. Kranuan     5. Nam Phong\n");
                printf("6. Phon        7. Puai Noi    8. Nong Ruea   9. Chonnabot   10. Si Chomphu\n");
            }
            else if (state_choice == 6) { // CHONBURI
                printf("🏙️  Top 10 Cities/Districts in CHONBURI:\n");
                printf("1. Chonburi City 2. Pattaya   3. Si Racha    4. Bang Lamung 5. Sattahip\n");
                printf("6. Phanat Nikhom 7. Ban Bueng 8. Ko Sichang  9. Phan Thong  10. Nong Yai\n");
            }
            else if (state_choice == 7) { // UBON RATCHATHANI
                printf("🏙️  Top 10 Cities/Districts in UBON RATCHATHANI:\n");
                printf("1. Ubon City   2. Warin Chamrap 3. Phibun Mangsahan 4. Det Udom 5. Khemarat\n");
                printf("6. Trakan Phuet Phon 7. Khuang Nai 8. Muang Sam Sip 9. Nam Yuen 10. Buntharik\n");
            }
            else if (state_choice == 8) { // NAKHON SI THAMMARAT
                printf("🏙️  Top 10 Cities/Districts in NAKHON SI THAMMARAT:\n");
                printf("1. Nakhon City 2. Thung Song  3. Pak Phanang 4. Sichon      5. Tha Sala\n");
                printf("6. Ron Phibun  7. Hua Sai     8. Khanom      9. Chawang     10. Lan Saka\n");
            }
            else if (state_choice == 9) { // BURIRAM
                printf("🏙️  Top 10 Cities/Districts in BURIRAM:\n");
                printf("1. Buriram City 2. Nang Rong  3. Prakhon Chai 4. Satuek    5. Lam Plai Mat\n");
                printf("6. Ban Kruat   7. Krasang     8. Khu Mueang  9. Non Suwan   10. Pa Kham\n");
            }
            else if (state_choice == 10) { // SURAT THANI
                printf("🏙️  Top 10 Cities/Districts in SURAT THANI:\n");
                printf("1. Surat City  2. Ko Samui    3. Ko Pha-ngan 4. Kanchanadit 5. Don Sak\n");
                printf("6. Tha Chana   7. Ban Na San  8. Wiang Sa    9. Phunphin    10. Chaiya\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/DISTRICT NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: Thailand\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 9) { // TURKEY
            int state_choice, city_choice;
            
            printf(">> TURKEY: Select a Province (1-10)\n");
            printf("1. Istanbul       2. Ankara       3. Izmir\n");
            printf("4. Bursa          5. Antalya      6. Adana\n");
            printf("7. Konya          8. Sanliurfa    9. Gaziantep\n");
            printf("10. Mersin\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ISTANBUL
                printf("🏙️  Top 10 Districts in ISTANBUL:\n");
                printf("1. Kadikoy    2. Besiktas   3. Fatih      4. Uskudar    5. Sisli\n");
                printf("6. Beyoglu    7. Bakirkoy   8. Sariyer    9. Pendik     10. Kartal\n");
            } 
            else if (state_choice == 2) { // ANKARA
                printf("🏙️  Top 10 Districts in ANKARA:\n");
                printf("1. Cankaya    2. Kecioren   3. Yenimahalle 4. Mamak     5. Etimesgut\n");
                printf("6. Sincan     7. Altindag   8. Pursaklar  9. Golbasi    10. Polatli\n");
            }
            else if (state_choice == 3) { // IZMIR
                printf("🏙️  Top 10 Districts in IZMIR:\n");
                printf("1. Konak      2. Karsiyaka  3. Bornova    4. Buca       5. Cigli\n");
                printf("6. Gaziemir   7. Balcova    8. Narlidere  9. Cesme      10. Aliaga\n");
            }
            else if (state_choice == 4) { // BURSA
                printf("🏙️  Top 10 Districts in BURSA:\n");
                printf("1. Osmangazi  2. Nilufer    3. Yildirim   4. Inegol     5. Gemlik\n");
                printf("6. Mudanya    7. Gursu      8. Kestel     9. Karacabey  10. Mustafakemalpasa\n");
            }
            else if (state_choice == 5) { // ANTALYA
                printf("🏙️  Top 10 Districts in ANTALYA:\n");
                printf("1. Muratpasa  2. Kepez      3. Konyaalti  4. Alanya     5. Manavgat\n");
                printf("6. Serik      7. Aksu       8. Kemer      9. Dosemealti 10. Kas\n");
            }
            else if (state_choice == 6) { // ADANA
                printf("🏙️  Top 10 Districts in ADANA:\n");
                printf("1. Cukurova   2. Seyhan     3. Saricam    4. Yuregir    5. Kozan\n");
                printf("6. Ceyhan     7. Imamoglu   8. Karatais   9. Pozanti    10. Aladag\n");
            }
            else if (state_choice == 7) { // KONYA
                printf("🏙️  Top 10 Districts in KONYA:\n");
                printf("1. Selcuklu   2. Meram      3. Karatay    4. Eregli     5. Aksehir\n");
                printf("6. Beysehir   7. Cumra      8. Seydisehir 9. Karapinar  10. Ilgin\n");
            }
            else if (state_choice == 8) { // SANLIURFA
                printf("🏙️  Top 10 Districts in SANLIURFA:\n");
                printf("1. Haliliye   2. Eyyubiye   3. Karakopru  4. Siverek    5. Viransehir\n");
                printf("6. Birecik    7. Suruc      8. Akcakale   9. Ceylanpinar 10. Harran\n");
            }
            else if (state_choice == 9) { // GAZIANTEP
                printf("🏙️  Top 10 Districts in GAZIANTEP:\n");
                printf("1. Sahinbey   2. Sehitkamil 3. Nizip      4. Islahiye   5. Nurdagi\n");
                printf("6. Araban     7. Oguzeli    8. Yavuzeli   9. Karkamis   10. Sahinbey Center\n");
            }
            else if (state_choice == 10) { // MERSIN
                printf("🏙️  Top 10 Districts in MERSIN:\n");
                printf("1. Yenisehir  2. Mezitli    3. Toroslar   4. Akdeniz    5. Tarsus\n");
                printf("6. Erdemli    7. Silifke    8. Anamur     9. Mut        10. Bozyazi\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/DISTRICT NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: Turkey\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 10) { // SAUDI ARABIA
            int state_choice, city_choice;
            
            printf(">> SAUDI ARABIA: Select a Region (1-10)\n");
            printf("1. Riyadh          2. Makkah       3. Eastern Province\n");
            printf("4. Asir            5. Madinah      6. Jizan\n");
            printf("7. Qassim          8. Tabuk        9. Hail\n");
            printf("10. Najran\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // RIYADH
                printf("🏙️  Top 10 Cities/Districts in RIYADH:\n");
                printf("1. Riyadh City 2. Al-Kharj   3. Al-Majma'ah 4. Ad-Dawadimi 5. Wadi ad-Dawasir\n");
                printf("6. Az-Zulfi    7. Afif       8. Al-Ghat     9. Thadig      10. Huraymila\n");
            } 
            else if (state_choice == 2) { // MAKKAH
                printf("🏙️  Top 10 Cities in MAKKAH REGION:\n");
                printf("1. Mecca City  2. Jeddah     3. Taif        4. Rabigh      5. Al-Lith\n");
                printf("6. Al-Qunfudhah 7. Khulais    8. Adham       9. Turabah     10. Al-Khurmah\n");
            }
            else if (state_choice == 3) { // EASTERN PROVINCE
                printf("🏙️  Top 10 Cities in EASTERN PROVINCE:\n");
                printf("1. Dammam      2. Al-Khobar  3. Dhahran     4. Al-Ahsa     5. Al-Jubail\n");
                printf("6. Qatif       7. Khafji     8. Hafr al-Batin 9. Ras Tanura 10. Abqaiq\n");
            }
            else if (state_choice == 4) { // ASIR
                printf("🏙️  Top 10 Cities in ASIR:\n");
                printf("1. Abha        2. Khamis Mushait 3. Bisha    4. Mohayil     5. Bareq\n");
                printf("6. Namas       7. Tanomah    8. Majardah    9. Sarat Abidah 10. Tathlith\n");
            }
            else if (state_choice == 5) { // MADINAH
                printf("🏙️  Top 10 Cities in MADINAH REGION:\n");
                printf("1. Medina City 2. Yanbu      3. Al-Ula      4. Badr        5. Khaybar\n");
                printf("6. Al Hinakiyah 7. Mahd adh Dhahab 8. Al-Ais 9. Wadi al-Far' 10. Yanbu al-Bahr\n");
            }
            else if (state_choice == 6) { // JIZAN
                printf("🏙️  Top 10 Cities in JIZAN:\n");
                printf("1. Jizan City  2. Sabya      3. Abu Arish   4. Samtah      5. Baish\n");
                printf("6. Ad-Darb     7. Ahad al-Masarihah 8. Al-Edabi 9. Al-Ardah 10. Farasan\n");
            }
            else if (state_choice == 7) { // QASSIM
                printf("🏙️  Top 10 Cities in QASSIM:\n");
                printf("1. Buraidah    2. Unaizah    3. Ar Rass     4. Al Mithnab  5. Al Bukayriyah\n");
                printf("6. Al Badaya   7. Riyadh Al Khabra 8. Al Asyah 9. Uyun Al Jiwa 10. Dariyah\n");
            }
            else if (state_choice == 8) { // TABUK
                printf("🏙️  Top 10 Cities in TABUK:\n");
                printf("1. Tabuk City  2. Al-Wajh    3. Duba        4. Tayma       5. Umluj\n");
                printf("6. Haql        7. Al-Bad'     8. Sharma      9. Magna       10. NEOM Area\n");
            }
            else if (state_choice == 9) { // HAIL
                printf("🏙️  Top 10 Cities in HAIL:\n");
                printf("1. Hail City   2. Baq'a      3. Al-Ghazalah 4. Ash-Shanan  5. Al-Hayit\n");
                printf("6. As-Slimi    7. Ash-Shamli 8. Mawga'      9. Al-Khittah  10. Jubbah\n");
            }
            else if (state_choice == 10) { // NAJRAN
                printf("🏙️  Top 10 Cities in NAJRAN:\n");
                printf("1. Najran City 2. Sharurah   3. Habuna      4. Badr al-Janub 5. Yadmah\n");
                printf("6. Thar        7. Khabbash    8. Al-Wark     9. Najran Suburb 10. Sultana\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Asia\n");
                printf(">> Country: Saudi Arabia\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else {
            printf("⚠️ Invalid Country Selection within Asia.\n");
        }
    }



    else if (choice == 4) {
        int country_choice;
        
        printf("📍 CONTINENT: AUSTRALIA / OCEANIA\n");
        printf("TOP 10 COUNTRIES:\n");
        printf("1. Australia  2. New Zealand 3. Fiji\n");
        printf("4. Papua NG   5. Solomon Is. 6. Vanuatu\n");
        printf("7. Samoa      8. Tonga       9. Kiribati\n");
        printf("10. Palau\n");

        printf("\nCHOOSE A COUNTRY (1-10): ");
        scanf("%d", &country_choice);
        printf("------------------------------\n");

        if (country_choice == 1) { // AUSTRALIA
            int state_choice, city_choice;
            
            printf(">> AUSTRALIA: Select a State/Territory (1-8)\n");
            printf("1. New South Wales   2. Victoria       3. Queensland\n");
            printf("4. Western Australia 5. South Australia 6. Tasmania\n");
            printf("7. ACT               8. Northern Territory\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // NEW SOUTH WALES
                printf("🏙️  Top 10 Cities/Areas in NEW SOUTH WALES:\n");
                printf("1. Sydney     2. Newcastle  3. Wollongong 4. Central Coast 5. Maitland\n");
                printf("6. Wagga Wagga 7. Albury    8. Port Macquarie 9. Tamworth 10. Orange\n");
            } 
            else if (state_choice == 2) { // VICTORIA
                printf("🏙️  Top 10 Cities/Areas in VICTORIA:\n");
                printf("1. Melbourne  2. Geelong    3. Ballarat   4. Bendigo    5. Shepparton\n");
                printf("6. Mildura    7. Wodonga    8. Warrnambool 9. Traralgon 10. Wangaratta\n");
            }
            else if (state_choice == 3) { // QUEENSLAND
                printf("🏙️  Top 10 Cities/Areas in QUEENSLAND:\n");
                printf("1. Brisbane   2. Gold Coast 3. Sunshine Coast 4. Townsville 5. Cairns\n");
                printf("6. Toowoomba  7. Mackay     8. Rockhampton 9. Bundaberg 10. Hervey Bay\n");
            }
            else if (state_choice == 4) { // WESTERN AUSTRALIA
                printf("🏙️  Top 10 Cities/Areas in WESTERN AUSTRALIA:\n");
                printf("1. Perth      2. Mandurah   3. Bunbury    4. Geraldton  5. Kalgoorlie\n");
                printf("6. Albany     7. Busselton  8. Karratha   9. Broome     10. Port Hedland\n");
            }
            else if (state_choice == 5) { // SOUTH AUSTRALIA
                printf("🏙️  Top 10 Cities/Areas in SOUTH AUSTRALIA:\n");
                printf("1. Adelaide   2. Mount Gambier 3. Whyalla  4. Murray Bridge 5. Port Lincoln\n");
                printf("6. Port Pirie 7. Port Augusta 8. Victor Harbor 9. Goolwa    10. Gawler\n");
            }
            else if (state_choice == 6) { // TASMANIA
                printf("🏙️  Top 10 Cities/Areas in TASMANIA:\n");
                printf("1. Hobart     2. Launceston 3. Devonport  4. Burnie     5. Kingston\n");
                printf("6. Ulverstone 7. New Norfolk 8. Wynyard   9. George Town 10. Sorell\n");
            }
            else if (state_choice == 7) { // ACT (Australian Capital Territory)
                printf("🏙️  Top 10 Areas in ACT (Canberra):\n");
                printf("1. Civic      2. Belconnen  3. Tuggeranong 4. Gungahlin 5. Woden Valley\n");
                printf("6. Weston Creek 7. Molonglo Valley 8. Kingston 9. Manuka   10. Hall\n");
            }
            else if (state_choice == 8) { // NORTHERN TERRITORY
                printf("🏙️  Top 10 Cities/Areas in NORTHERN TERRITORY:\n");
                printf("1. Darwin     2. Palmerston 3. Alice Springs 4. Katherine 5. Nhulunbuy\n");
                printf("6. Tennant Creek 7. Jabiru  8. Yulara     9. Batchelor  10. Pine Creek\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Australia\n");
                printf(">> State/Territory Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 2) { // NEW ZEALAND
            int state_choice, city_choice;
            
            printf(">> NEW ZEALAND: Select a Region (1-10)\n");
            printf("1. Auckland       2. Canterbury     3. Wellington\n");
            printf("4. Waikato        5. Bay of Plenty  6. Manawatu-Whanganui\n");
            printf("7. Otago          8. Northland      9. Hawke's Bay\n");
            printf("10. Taranaki\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // AUCKLAND
                printf("🏙️  Top 10 Areas in AUCKLAND:\n");
                printf("1. CBD        2. Manukau    3. North Shore 4. Waitakere  5. Ponsonby\n");
                printf("6. Parnell    7. Newmarket  8. Howick      9. Takapuna   10. Henderson\n");
            } 
            else if (state_choice == 2) { // CANTERBURY
                printf("🏙️  Top 10 Cities/Towns in CANTERBURY:\n");
                printf("1. Christchurch 2. Timaru   3. Ashburton   4. Rangiora   5. Rolleston\n");
                printf("6. Kaiapoi    7. Lincoln    8. Temuka      9. Waimate    10. Akaroa\n");
            }
            else if (state_choice == 3) { // WELLINGTON
                printf("🏙️  Top 10 Cities/Areas in WELLINGTON:\n");
                printf("1. Wellington City 2. Lower Hutt 3. Upper Hutt 4. Porirua 5. Kapiti Coast\n");
                printf("6. Masterton  7. Petone     8. Miramar     9. Johnsonville 10. Karori\n");
            }
            else if (state_choice == 4) { // WAIKATO
                printf("🏙️  Top 10 Cities/Towns in WAIKATO:\n");
                printf("1. Hamilton   2. Taupo      3. Cambridge   4. Te Awamutu 5. Tokoroa\n");
                printf("6. Huntly     7. Matamata   8. Morrinsville 9. Thames    10. Putaruru\n");
            }
            else if (state_choice == 5) { // BAY OF PLENTY
                printf("🏙️  Top 10 Cities/Towns in BAY OF PLENTY:\n");
                printf("1. Tauranga   2. Rotorua    3. Whakatane   4. Te Puke    5. Kawerau\n");
                printf("6. Katikati   7. Opotiki    8. Mount Maunganui 9. Papamoa 10. Maketu\n");
            }
            else if (state_choice == 6) { // MANAWATU-WHANGANUI
                printf("🏙️  Top 10 Cities/Towns in MANAWATU-WHANGANUI:\n");
                printf("1. Palmerston North 2. Whanganui 3. Levin  4. Feilding   5. Dannevirke\n");
                printf("6. Taumarunui 7. Marton     8. Pahiatua    9. Bulls      10. Ohakune\n");
            }
            else if (state_choice == 7) { // OTAGO
                printf("🏙️  Top 10 Cities/Towns in OTAGO:\n");
                printf("1. Dunedin    2. Queenstown 3. Wanaka      4. Oamaru     5. Alexandra\n");
                printf("6. Cromwell   7. Balclutha  8. Arrowtown   9. Milton     10. Mosgiel\n");
            }
            else if (state_choice == 8) { // NORTHLAND
                printf("🏙️  Top 10 Cities/Towns in NORTHLAND:\n");
                printf("1. Whangarei  2. Kerikeri   3. Kaitaia     4. Kaikohe    5. Dargaville\n");
                printf("6. Paihia     7. Mangawhai  8. Russell     9. Kawakawa   10. Taipa\n");
            }
            else if (state_choice == 9) { // HAWKE'S BAY
                printf("🏙️  Top 10 Cities/Towns in HAWKE'S BAY:\n");
                printf("1. Napier     2. Hastings   3. Havelock North 4. Wairoa  5. Waipukurau\n");
                printf("6. Waipawa    7. Taradale   8. Clive       9. Bay View   10. Porangahau\n");
            }
            else if (state_choice == 10) { // TARANAKI
                printf("🏙️  Top 10 Cities/Towns in TARANAKI:\n");
                printf("1. New Plymouth 2. Hawera   3. Stratford   4. Waitara    5. Inglewood\n");
                printf("6. Eltham     7. Opunake    8. Patea       9. Manaia     10. Mokau\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: New Zealand\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 3) { // FIJI
            int state_choice, city_choice;
            
            printf(">> FIJI: Select a Province/Division (1-10)\n");
            printf("1. Ba             2. Naitasiri     3. Rewa\n");
            printf("4. Tailevu        5. Macuata       6. Nadroga-Navosa\n");
            printf("7. Cakaudrove     8. Namosi        9. Serua\n");
            printf("10. Ra\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // BA
                printf("🏙️  Top 10 Cities/Towns in BA:\n");
                printf("1. Lautoka    2. Nadi       3. Ba Town    4. Tavua      5. Vuda\n");
                printf("6. Namaka     7. Martintar  8. Sabeto     9. Lautoka City 10. Yasawa\n");
            } 
            else if (state_choice == 2) { // NAITASIRI
                printf("🏙️  Top 10 Areas in NAITASIRI:\n");
                printf("1. Nasinu     2. Sawani     3. Vunidawa   4. Baulevu    5. Kalabu\n");
                printf("6. Nabua      7. Colo-i-Suva 8. Wainasasa 9. Tovata     10. Nadera\n");
            }
            else if (state_choice == 3) { // REWA
                printf("🏙️  Top 10 Cities/Areas in REWA:\n");
                printf("1. Suva City  2. Lami Town  3. Rewa Delta 4. Vunivaivai 5. Noco\n");
                printf("6. Burebasaga 7. Dreketi    8. Toga       9. Tokatoka   10. Nasali\n");
            }
            else if (state_choice == 4) { // TAILEVU
                printf("🏙️  Top 10 Cities/Towns in TAILEVU:\n");
                printf("1. Nausori Town 2. Korovou  3. Bau Island 4. Wainibuka  5. Verata\n");
                printf("6. Namara     7. Nakelo     8. Sawakasa   9. Lodoni     10. Natovi\n");
            }
            else if (state_choice == 5) { // MACUATA
                printf("🏙️  Top 10 Cities/Towns in MACUATA:\n");
                printf("1. Labasa Town 2. Seaqaqa   3. Malau      4. Wainikoro  5. Naduri\n");
                printf("6. Labasa West 7. Bulileka   8. Wailevu    9. Macuata-i-Wai 10. Sasa\n");
            }
            else if (state_choice == 6) { // NADROGA-NAVOSA
                printf("🏙️  Top 10 Cities/Towns in NADROGA-NAVOSA:\n");
                printf("1. Sigatoka Town 2. Korotogo 3. Cuvu       4. Natadola   5. Keiyasi\n");
                printf("6. Kulukulu   7. Olosara    8. Sanasana   9. Malevu     10. Lomawai\n");
            }
            else if (state_choice == 7) { // CAKAUDROVE
                printf("🏙️  Top 10 Cities/Towns in CAKAUDROVE:\n");
                printf("1. Savusavu Town 2. Tukavesi 3. Matei      4. Somosomo   5. Buca Bay\n");
                printf("6. Natewa     7. Wailevu East 8. Saqani    9. Navakaka   10. Yaroi\n");
            }
            else if (state_choice == 8) { // NAMOSI
                printf("🏙️  Top 10 Areas in NAMOSI:\n");
                printf("1. Namosi Village 2. Navua River 3. Veivatuloa 4. Wainikoroiluva 5. Mau\n");
                printf("6. Nakavu     7. Dada Village 8. Naqarawai 9. Wainiyavu  10. Namuamua\n");
            }
            else if (state_choice == 9) { // SERUA
                printf("🏙️  Top 10 Cities/Towns in SERUA:\n");
                printf("1. Navua Town 2. Pacific Harbour 3. Deuba   4. Galoa      5. Naitonitoni\n");
                printf("6. Serua Island 7. Yarromi   8. Nabukelevu 9. Rovadrau   10. Vakabalea\n");
            }
            else if (state_choice == 10) { // RA
                printf("🏙️  Top 10 Cities/Towns in RA:\n");
                printf("1. Rakiraki Town 2. Vaileka  3. Ellington  4. Nabouwalu Rd 5. Nakorotubu\n");
                printf("6. Nanukuloa  7. Penang     8. Nananu-i-Ra 9. Volivoli   10. Togovere\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/TOWN NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Fiji\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 4) { // PAPUA NEW GUINEA
            int state_choice, city_choice;
            
            printf(">> PAPUA NEW GUINEA: Select a Province (1-10)\n");
            printf("1. Morobe            2. Western Highlands 3. Eastern Highlands\n");
            printf("4. Madang            5. East Sepik        6. Enga\n");
            printf("7. Southern Highlands 8. National Capital  9. Milne Bay\n");
            printf("10. West New Britain\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // MOROBE
                printf("🏙️  Top 10 Cities/Areas in MOROBE:\n");
                printf("1. Lae City   2. Bulolo     3. Wau        4. Finschhafen 5. Mutzing\n");
                printf("6. Markham    7. Huon Gulf  8. Kaiapit     9. Menyamya   10. Siassi\n");
            } 
            else if (state_choice == 2) { // WESTERN HIGHLANDS
                printf("🏙️  Top 10 Cities/Areas in WESTERN HIGHLANDS:\n");
                printf("1. Mount Hagen 2. Baiyer    3. Dei        4. Tambul      5. Nebilyer\n");
                printf("6. Muglamp    7. Kuta       8. Togoba     9. Kelua       10. Kagamuga\n");
            }
            else if (state_choice == 3) { // EASTERN HIGHLANDS
                printf("🏙️  Top 10 Cities/Areas in EASTERN HIGHLANDS:\n");
                printf("1. Goroka     2. Kainantu   3. Henganofi  4. Daulo       5. Lufa\n");
                printf("6. Okapa      7. Obura      8. Wonenara   9. Bena        10. Watabung\n");
            }
            else if (state_choice == 4) { // MADANG
                printf("🏙️  Top 10 Cities/Areas in MADANG:\n");
                printf("1. Madang Town 2. Alexishafen 3. Bogia     4. Saidor      5. Bundi\n");
                printf("6. Aiome      7. Usino      8. Karkar Is. 9. Walium      10. Ramu\n");
            }
            else if (state_choice == 5) { // EAST SEPIK
                printf("🏙️  Top 10 Cities/Areas in EAST SEPIK:\n");
                printf("1. Wewak      2. Maprik     3. Angoram    4. Ambunti     5. Yangoru\n");
                printf("6. Pagwi      7. Dreikikier 8. Karawari   9. Kairiru Is. 10. Mushu Is.\n");
            }
            else if (state_choice == 6) { // ENGA
                printf("🏙️  Top 10 Cities/Areas in ENGA:\n");
                printf("1. Wabag      2. Porgera    3. Laiagam    4. Kandep      5. Wapenamanda\n");
                printf("6. Maramuni   7. Kompiam    8. Sirunki     9. Paiela      10. Tsak\n");
            }
            else if (state_choice == 7) { // SOUTHERN HIGHLANDS
                printf("🏙️  Top 10 Cities/Areas in SOUTHERN HIGHLANDS:\n");
                printf("1. Mendi      2. Ialibu     3. Pangia     4. Kagua       5. Nipa\n");
                printf("6. Erave      7. Poroma     8. Lake Kutubu 9. Pimaga     10. Kaupena\n");
            }
            else if (state_choice == 8) { // NATIONAL CAPITAL DISTRICT
                printf("🏙️  Top 10 Areas in PORT MORESBY (NCD):\n");
                printf("1. Waigani    2. Boroko     3. Gordons    4. Konedobu    5. Badili\n");
                printf("6. Gerehu     7. Hohola     8. Koki       9. Hanuabada   10. 6-Mile\n");
            }
            else if (state_choice == 9) { // MILNE BAY
                printf("🏙️  Top 10 Cities/Areas in MILNE BAY:\n");
                printf("1. Alotau     2. Samarai    3. Esa'ala    4. Losuia      5. Misima\n");
                printf("6. Kiriwina   7. Sideia     8. Rabaraba   9. Woodlark    10. Normanby Is.\n");
            }
            else if (state_choice == 10) { // WEST NEW BRITAIN
                printf("🏙️  Top 10 Cities/Areas in WEST NEW BRITAIN:\n");
                printf("1. Kimbe      2. Hoskins    3. Bialla     4. Talasea     5. Gloucester\n");
                printf("6. Kandrian   7. Gasmata    8. Mosa       9. Nahavio     10. Buluma\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Papua New Guinea\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 5) { // SOLOMON ISLANDS
            int state_choice, city_choice;
            
            printf(">> SOLOMON ISLANDS: Select a Province (1-10)\n");
            printf("1. Malaita          2. Guadalcanal    3. Western\n");
            printf("4. Makira-Ulawa     5. Choiseul       6. Central\n");
            printf("7. Isabel           8. Temotu         9. Rennell and Bellona\n");
            printf("10. Honiara (Capital Territory)\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // MALAITA
                printf("🏙️  Top 10 Areas in MALAITA:\n");
                printf("1. Auki Town  2. Malu'u      3. Atori       4. Rohinari    5. Afio\n");
                printf("6. Fauabu     7. Buma        8. Langalanga  9. Lau Lagoon  10. Baunani\n");
            } 
            else if (state_choice == 2) { // GUADALCANAL
                printf("🏙️  Top 10 Areas in GUADALCANAL:\n");
                printf("1. Henderson  2. Lungga      3. Tetere      4. Marau       5. Lambi\n");
                printf("6. Avuavu     7. Ruavatu     8. Weather Coast 9. Wanderer Bay 10. Aola\n");
            }
            else if (state_choice == 3) { // WESTERN
                printf("🏙️  Top 10 Cities/Towns in WESTERN:\n");
                printf("1. Gizo Town  2. Munda       3. Noro        4. Seghe       5. Ringgi\n");
                printf("6. Viru Harbor 7. Kukudu     8. Poitete     9. Gizo Island 10. Vella Lavella\n");
            }
            else if (state_choice == 4) { // MAKIRA-ULAWA
                printf("🏙️  Top 10 Areas in MAKIRA-ULAWA:\n");
                printf("1. Kirakira   2. Namuga      3. Star Harbour 4. Ulawa      5. Santa Ana\n");
                printf("6. Santa Catalina 7. Pamua   8. Makira East 9. Makira West 10. Three Sisters\n");
            }
            else if (state_choice == 5) { // CHOISEUL
                printf("🏙️  Top 10 Areas in CHOISEUL:\n");
                printf("1. Taro Island 2. Pangoe      3. Sasamungga  4. Nanango     5. Voza\n");
                printf("6. Wagina     7. Choiseul Bay 8. Mole        9. Robroy      10. Katupika\n");
            }
            else if (state_choice == 6) { // CENTRAL
                printf("🏙️  Top 10 Areas in CENTRAL:\n");
                printf("1. Tulagi     2. Savo Island 3. Ngella      4. Russell Is. 5. Yandina\n");
                printf("6. Pavuvu     7. Anuha       8. Ironbottom Sound 9. Mbanika  10. Nggela Sule\n");
            }
            else if (state_choice == 7) { // ISABEL
                printf("🏙️  Top 10 Areas in ISABEL:\n");
                printf("1. Buala Town 2. Kia         3. Tatamba     4. Susubona    5. Allardyce\n");
                printf("6. Kaevanga   7. Samasodu    8. Papatura    9. Maringe     10. Gao\n");
            }
            else if (state_choice == 8) { // TEMOTU
                printf("🏙️  Top 10 Areas in TEMOTU:\n");
                printf("1. Lata Town  2. Santa Cruz  3. Reef Islands 4. Duff Is.   5. Tikopia\n");
                printf("6. Anuta      7. Vanikoro    8. Utupua      9. Nendo       10. Graciosa Bay\n");
            }
            else if (state_choice == 9) { // RENNELL AND BELLONA
                printf("🏙️  Top 10 Areas in RENNELL AND BELLONA:\n");
                printf("1. Tigoa Town 2. Lake Tengano 3. West Rennell 4. East Rennell 5. Bellona Island\n");
                printf("6. Matangi    7. Gongau      8. Lavanggu    9. Niupani     10. Hutuna\n");
            }
            else if (state_choice == 10) { // HONIARA
                printf("🏙️  Top 10 Areas in HONIARA:\n");
                printf("1. Point Cruz 2. Chinatown   3. Kukum       4. Panatina    5. White River\n");
                printf("6. Naha       7. Kola'a Ridge 8. Skyline     9. Mbokonavera 10. Lungga\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Solomon Islands\n");
                printf(">> Province Code: %d, Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 6) { // VANUATU
            int state_choice, city_choice;
            
            printf(">> VANUATU: Select a Province (1-6)\n");
            printf("1. Malampa         2. Penama         3. Sanma\n");
            printf("4. Shefa           5. Tafea          6. Torba\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // MALAMPA
                printf("🏙️  Top 10 Areas in MALAMPA:\n");
                printf("1. Lakatoro    2. Norsup     3. Lamap      4. Paama      5. Ambrym\n");
                printf("6. Fanla       7. Craig Cove 8. South West Bay 9. Unmet  10. Litzlitz\n");
            } 
            else if (state_choice == 2) { // PENAMA
                printf("🏙️  Top 10 Areas in PENAMA:\n");
                printf("1. Saratamata  2. Longana    3. Lolowai    4. Ambae      5. Maewo\n");
                printf("6. Pentecost   7. Abwatuntora 8. Melsisi   9. Loltong    10. Nasawa\n");
            }
            else if (state_choice == 3) { // SANMA
                printf("🏙️  Top 10 Cities/Areas in SANMA:\n");
                printf("1. Luganville  2. Hog Harbour 3. Port Olry   4. Aore Island 5. Malo\n");
                printf("6. Turtle Bay  7. Champagne Beach 8. Million Dollar Point 9. Canal Fanal 10. Santo East\n");
            }
            else if (state_choice == 4) { // SHEFA
                printf("🏙️  Top 10 Areas in SHEFA:\n");
                printf("1. Port Vila   2. Bauerfield 3. Mele       4. Epi        5. Tongoa\n");
                printf("6. Emae        7. Nguna      8. Ifira      9. Pango      10. Erakor\n");
            }
            else if (state_choice == 5) { // TAFEA
                printf("🏙️  Top 10 Areas in TAFEA:\n");
                printf("1. Isangel     2. Lenakel    3. Port Resolution 4. Erromango 5. Aneityum\n");
                printf("6. Futuna      7. Aniwa      8. White Sands 9. Sulphur Bay 10. Yasur\n");
            }
            else if (state_choice == 6) { // TORBA
                printf("🏙️  Top 10 Areas in TORBA:\n");
                printf("1. Sola        2. Vanua Lava 3. Gaua       4. Mota Lava  5. Loh\n");
                printf("6. Tegua       7. Toga       8. Hiw        9. Merig      10. Merelava\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Vanuatu\n");
                printf(">> Province Code: %d, Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 7) { // SAMOA
            int state_choice, city_choice;
            
            printf(">> SAMOA: Select a District (1-10)\n");
            printf("1. Tuamasaga      2. A'ana         3. Aiga-i-le-Tai\n");
            printf("4. Atua           5. Va'a-o-Fonoti  6. Fa'asaleleaga\n");
            printf("7. Gaga'emauga    8. Gaga'ifomauga 9. Palauli\n");
            printf("10. Satupa'itea\n");
            
            printf("\nENTER DISTRICT NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // TUAMASAGA
                printf("🏘️  Top 10 Villages/Areas in TUAMASAGA:\n");
                printf("1. Apia Town  2. Vaivase      3. Faleata     4. Malie       5. Afiamalu\n");
                printf("6. Vailima    7. Vaimoso      8. Moamoa      9. Si'umu      10. Safata\n");
            } 
            else if (state_choice == 2) { // A'ANA
                printf("🏘️  Top 10 Villages/Areas in A'ANA:\n");
                printf("1. Leulumoega 2. Fasito'o Uta 3. Nofoali'i   4. Fasito'o Tai 5. Faleasi'u\n");
                printf("6. Samatau    7. Falelatai    8. Mulifanua   9. Satapuala   10. Magia\n");
            }
            else if (state_choice == 3) { // AIGA-I-LE-TAI
                printf("🏘️  Top 10 Villages/Areas in AIGA-I-LE-TAI:\n");
                printf("1. Mulifanua  2. Manono Island 3. Apolima Is. 4. Fuailalo    5. Salua\n");
                printf("6. Lepuia'i   7. Faleu        8. Apai        9. Manono-uta  10. Pa'epa'e\n");
            }
            else if (state_choice == 4) { // ATUA
                printf("🏘️  Top 10 Villages/Areas in ATUA:\n");
                printf("1. Lufilufi    2. Falefa       3. Lotofaga    4. Lepa        5. Aleipata\n");
                printf("6. Lalomanu    7. Aufaga       8. Saleapaga   9. Ti'avea     10. Samusu\n");
            }
            else if (state_choice == 5) { // VA'A-O-FONOTI
                printf("🏘️  Top 10 Villages/Areas in VA'A-O-FONOTI:\n");
                printf("1. Samamea     2. Lona         3. Ta'elefaga  4. Maasina     5. Salimu\n");
                printf("6. Musumusu    7. Uafato       8. Fagaloa Bay 9. Sauago      10. Faleapuna\n");
            }
            else if (state_choice == 6) { // FA'ASALELEAGA
                printf("🏘️  Top 10 Villages/Areas in FA'ASALELEAGA:\n");
                printf("1. Salelologa  2. Sapapali'i   3. Safotulafai 4. Pu'apu'a    5. Iva\n");
                printf("6. Si'ufaga    7. Fusi         8. Tuasivi     9. Fogapoa     10. Malae\n");
            }
            else if (state_choice == 7) { // GAGA'EMAUGA
                printf("🏘️  Top 10 Villages/Areas in GAGA'EMAUGA:\n");
                printf("1. Sale'aula   2. Sato'alepai  3. Fagamalo    4. Lelepa      5. Safai\n");
                printf("6. Mauga       7. Patamea      8. Samalae'ulu 9. Salamumu    10. Le'auva'a\n");
            }
            else if (state_choice == 8) { // GAGA'IFOMAUGA
                printf("🏘️  Top 10 Villages/Areas in GAGA'IFOMAUGA:\n");
                printf("1. Safotu      2. Safune       3. Sasina      4. Letui       5. Aopo\n");
                printf("6. Samauga     7. Manase       8. Lefagaoali'i 9. Paia       10. Faletagaloa\n");
            }
            else if (state_choice == 9) { // PALAULI
                printf("🏘️  Top 10 Villages/Areas in PALAULI:\n");
                printf("1. Vailoa      2. Gataivai     3. Gautavai    4. Puleia      5. Sili\n");
                printf("6. Taga        7. Satuiatua    8. Salailua    9. Si'utu      10. Papa\n");
            }
            else if (state_choice == 10) { // SATUPA'ITEA
                printf("🏘️  Top 10 Villages/Areas in SATUPA'ITEA:\n");
                printf("1. Satupa'itea 2. Vaega        3. Pitonu'u    4. Moasula     5. Satufia\n");
                printf("6. Alataua     7. Tufutafoe    8. Neiafu      9. Falelima    10. Falealupo\n");
            }
            else {
                printf("⚠️ Invalid District Selection.\n");
                return 0;
            }

            printf("\nSELECT VILLAGE/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Samoa\n");
                printf(">> District Code: %d, Village Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 8) { // TONGA
            int state_choice, city_choice;
            
            printf(">> TONGA: Select a Division Group (1-5)\n");
            printf("1. Tongatapu      2. Vava'u        3. Ha'apai\n");
            printf("4. 'Eua           5. Ongo Niua\n");
            
            printf("\nENTER DIVISION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // TONGATAPU
                printf("🏙️  Top 10 Villages/Areas in TONGATAPU:\n");
                printf("1. Nuku'alofa  2. Mu'a          3. Vaini        4. Houma        5. Kolovai\n");
                printf("6. Ha'asini     7. Tatakamotonga 8. Lapaha       9. Nukunuku     10. Fua'amotu\n");
            } 
            else if (state_choice == 2) { // VAVA'U
                printf("🏙️  Top 10 Villages/Areas in VAVA'U:\n");
                printf("1. Neiafu      2. Pangaimotu    3. Leimatua     4. Holonga      5. Longomapu\n");
                printf("6. Feletoa     7. Taoa          8. Talau        9. Toula        10. Tefisi\n");
            }
            else if (state_choice == 3) { // HA'APAI
                printf("🏙️  Top 10 Villages/Areas in HA'APAI:\n");
                printf("1. Pangai      2. Hihifo        3. Ha'ano       4. Uiha         5. Nomuka\n");
                printf("6. Lifuka      7. Foa           8. Lofanga      9. Fotuha'a     10. Tungua\n");
            }
            else if (state_choice == 4) { // 'EUA
                printf("🏙️  Top 10 Villages/Areas in 'EUA:\n");
                printf("1. 'Ohonua     2. Pangai        3. Tufuvai      4. Houma        5. Ha'atu'ua\n");
                printf("6. Angaha      7. Kolomaile     8. Petani       9. Mata'aho     10. Sapa'ata\n");
            }
            else if (state_choice == 5) { // ONGO NIUA
                printf("🏙️  Top 10 Villages/Areas in ONGO NIUA:\n");
                printf("1. Hihifo      2. Vaipoa        3. Falehau      4. Futu         5. Esia\n");
                printf("6. Kolofo'ou   7. Sapa'ata      8. Alele'jo     9. Niuafo'ou    10. Niuatoputapu\n");
            }
            else {
                printf("⚠️ Invalid Division Selection.\n");
                return 0;
            }

            printf("\nSELECT VILLAGE/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Tonga\n");
                printf(">> Division Code: %d, Village Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 9) { // KIRIBATI
            int state_choice, city_choice;
            
            printf(">> KIRIBATI: Select an Island Group (1-3)\n");
            printf("1. Gilbert Islands   2. Line Islands   3. Phoenix Islands\n");
            
            printf("\nENTER GROUP NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // GILBERT ISLANDS
                printf("🏙️  Top 10 Atolls/Areas in GILBERT ISLANDS:\n");
                printf("1. Tarawa (South) 2. Tarawa (North) 3. Butaritari  4. Abaiang     5. Abemama\n");
                printf("6. Tabiteuea     7. Beru           8. Nonouti      9. Onotoa      10. Maiana\n");
            } 
            else if (state_choice == 2) { // LINE ISLANDS
                printf("🏙️  Top 10 Atolls/Areas in LINE ISLANDS:\n");
                printf("1. Kiritimati (Christmas Is.) 2. Tabuaeran  3. Teraina  4. Caroline  5. Vostok\n");
                printf("6. Flint Island  7. Starbuck Is.   8. Malden Is.   9. Millennium 10. Filippo Reef\n");
            }
            else if (state_choice == 3) { // PHOENIX ISLANDS
                printf("🏙️  Top 10 Atolls/Areas in PHOENIX ISLANDS:\n");
                printf("1. Kanton Island 2. Enderbury      3. Rawaki       4. Manra       5. Birnie\n");
                printf("6. McKean       7. Nikumaroro     8. Orona        9. Winslow     10. Carondelet\n");
            }
            else {
                printf("⚠️ Invalid Group Selection.\n");
                return 0;
            }

            printf("\nSELECT ATOLL/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Kiribati\n");
                printf(">> Group Code: %d, Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 10) { // PALAU
            int state_choice, city_choice;
            
            printf(">> PALAU: Select a State (1-10)\n");
            printf("1. Airai           2. Koror          3. Aimeliik\n");
            printf("4. Melekeok        5. Ngaraard       6. Ngarchelong\n");
            printf("7. Ngardmau        8. Ngatpang       9. Ngchesar\n");
            printf("10. Ngiwal\n");
            
            printf("\nENTER STATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // AIRAI
                printf("🏙️  Top 10 Areas in AIRAI:\n");
                printf("1. Ngetkib     2. Ngeruluobel 3. Ngerusar    4. Ordomel    5. Beluu\n");
                printf("6. Oikull      7. Airai View  8. Airport Rd  9. KB Bridge  10. Aimeliik Border\n");
            } 
            else if (state_choice == 2) { // KOROR
                printf("🏙️  Top 10 Areas in KOROR:\n");
                printf("1. Malakal     2. Ngermid     3. Ngerbeched  4. Meyuns      5. Ngerkesoaol\n");
                printf("6. Madalaii    7. Ngerkebesang 8. Idid       9. Meketii     10. Ikelau\n");
            }
            else if (state_choice == 3) { // AIMELIIK
                printf("🏙️  Top 10 Areas in AIMELIIK:\n");
                printf("1. Mongami     2. Medorm      3. Imul        4. Elechui     5. Ngchemiangel\n");
                printf("6. Aimeliik Port 7. Terrace    8. West Coast  9. Jungle Path 10. Hill Side\n");
            }
            else if (state_choice == 4) { // MELEKEOK (Capital State)
                printf("🏙️  Top 10 Areas in MELEKEOK:\n");
                printf("1. Ngerulmud   2. Melekeok Vill 3. Ngermelech 4. Ngerubesang 5. Ngeremecheluch\n");
                printf("6. Capitol Hill 7. Lake Ngardok 8. Beach Front 9. East Coast 10. New Rd\n");
            }
            else if (state_choice == 5) { // NGARAARD
                printf("🏙️  Top 10 Areas in NGARAARD:\n");
                printf("1. Choll       2. Elab        3. Ngebuked    4. Ngkeklau    5. Ulimang\n");
                printf("6. Ngaraard Rd 7. North Beach 8. Jungle Trek 9. East Hills  10. West Shore\n");
            }
            else if (state_choice == 6) { // NGARCHELONG
                printf("🏙️  Top 10 Areas in NGARCHELONG:\n");
                printf("1. Mengellang  2. Ollei       3. Ngebei      4. Ngerbau     5. Iebukel\n");
                printf("6. Badrulchau  7. North Point 8. Coral Reef  9. Dock Area   10. High View\n");
            }
            else if (state_choice == 7) { // NGARDMAU
                printf("🏙️  Top 10 Areas in NGARDMAU:\n");
                printf("1. Ngetpang    2. Pkulrekerel 3. Ngardmau Falls 4. Bauxite Mine 5. West Hill\n");
                printf("6. Forest Path 7. Eco Park    8. Coastal Rd  9. River Side  10. View Point\n");
            }
            else if (state_choice == 8) { // NGATPANG
                printf("🏙️  Top 10 Areas in NGATPANG:\n");
                printf("1. Ngatpang Vill 2. Ibobang    3. Ngereklmai  4. Bay Side    5. Mangrove Walk\n");
                printf("6. South Hills 7. Inland Path 8. Dock View   9. Old Town    10. Farm Area\n");
            }
            else if (state_choice == 9) { // NGCHESAR
                printf("🏙️  Top 10 Areas in NGCHESAR:\n");
                printf("1. Ngerkeai    2. Ngchesar Vill 3. Ngeraus    4. Ngeruikl    5. North Ngchesar\n");
                printf("6. South Road  7. River Basin 8. Forest Edge 9. East View   10. Coastline\n");
            }
            else if (state_choice == 10) { // NGIWAL
                printf("🏙️  Top 10 Areas in NGIWAL:\n");
                printf("1. Ngercheluuk 2. Ngermechau  3. Ngiwal Beach 4. School Dist 5. Village Center\n");
                printf("6. North Ngiwal 7. South Ngiwal 8. Hill Top   9. Farm Land   10. Ocean Drive\n");
            }
            else {
                printf("⚠️ Invalid State Selection.\n");
                return 0;
            }

            printf("\nSELECT AREA/VILLAGE NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Australia/Oceania\n");
                printf(">> Country: Palau\n");
                printf(">> State Code: %d, Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else {
            printf("⚠️ Invalid Country Selection within Oceania.\n");
        }
    }



    else if (choice == 5) {
        int country_choice;
        
        printf("📍 CONTINENT: EUROPE\n");
        printf("TOP 10 COUNTRIES:\n");
        printf("1. France      2. Germany    3. Italy\n");
        printf("4. UK          5. Spain      6. Russia\n");
        printf("7. Switzerland 8. Greece     9. Norway\n");
        printf("10. Netherlands\n");

        printf("\nCHOOSE A COUNTRY (1-10): ");
        scanf("%d", &country_choice);
        printf("------------------------------\n");

        if (country_choice == 1) { // FRANCE
            int state_choice, city_choice;
            
            printf(">> FRANCE: Select a Department (1-10)\n");
            printf("1. Paris          2. Nord           3. Bouches-du-Rhone\n");
            printf("4. Rhone          5. Gironde        6. Pas-de-Calais\n");
            printf("7. Yvelines       8. Haute-Garonne  9. Loire-Atlantique\n");
            printf("10. Seine-Saint-Denis\n");
            
            printf("\nENTER DEPARTMENT NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // PARIS (75)
                printf("🏙️  Top 10 Districts (Arrondissements) in PARIS:\n");
                printf("1. Louvre     2. Le Marais  3. Luxembourg 4. Pantheon   5. Champs-Elysees\n");
                printf("6. Opera      7. Bastille   8. Montmartre 9. Passy      10. Batignolles\n");
            } 
            else if (state_choice == 2) { // NORD (59)
                printf("🏙️  Top 10 Cities in NORD:\n");
                printf("1. Lille      2. Roubaix    3. Tourcoing  4. Dunkerque  5. Villeneuve-d'Ascq\n");
                printf("6. Valenciennes 7. Wattrelos 8. Douai      9. Marcq      10. Cambrai\n");
            }
            else if (state_choice == 3) { // BOUCHES-DU-RHONE (13)
                printf("🏙️  Top 10 Cities in BOUCHES-DU-RHONE:\n");
                printf("1. Marseille  2. Aix-en-Provence 3. Arles   4. Martigues  5. Aubagne\n");
                printf("6. Salon      7. Istres     8. Vitrolles  9. Marignane  10. Cassis\n");
            }
            else if (state_choice == 4) { // RHONE (69)
                printf("🏙️  Top 10 Cities in RHONE:\n");
                printf("1. Lyon       2. Villeurbanne 3. Venissieux 4. Vaulx      5. Saint-Priest\n");
                printf("6. Caluire    7. Bron       8. Villefranche 9. Meyzieu    10. Givors\n");
            }
            else if (state_choice == 5) { // GIRONDE (33)
                printf("🏙️  Top 10 Cities in GIRONDE:\n");
                printf("1. Bordeaux   2. Merignac   3. Pessac     4. Talence    5. Villenave\n");
                printf("6. Saint-Medard 7. Libourne 8. Begles     9. Cenon      10. Gradignan\n");
            }
            else if (state_choice == 6) { // PAS-DE-CALAIS (62)
                printf("🏙️  Top 10 Cities in PAS-DE-CALAIS:\n");
                printf("1. Calais     2. Arras      3. Boulogne   4. Lens       5. Lievin\n");
                printf("6. Henin      7. Bethune    8. Bruay      9. Avion      10. Carvin\n");
            }
            else if (state_choice == 7) { // YVELINES (78)
                printf("🏙️  Top 10 Cities in YVELINES:\n");
                printf("1. Versailles 2. Sartrouville 3. Mantes     4. Saint-Germain 5. Poissy\n");
                printf("6. Conflans   7. Montigny   8. Houilles   9. Plaisir    10. Chatou\n");
            }
            else if (state_choice == 8) { // HAUTE-GARONNE (31)
                printf("🏙️  Top 10 Cities in HAUTE-GARONNE:\n");
                printf("1. Toulouse   2. Colomiers  3. Tournefeuille 4. Muret   5. Blagnac\n");
                printf("6. Plaisance  7. Cugnaux    8. Balma      9. L'Union    10. Saint-Gaudens\n");
            }
            else if (state_choice == 9) { // LOIRE-ATLANTIQUE (44)
                printf("🏙️  Top 10 Cities in LOIRE-ATLANTIQUE:\n");
                printf("1. Nantes     2. Saint-Nazaire 3. Saint-Herblain 4. Reze  5. Saint-Sebastien\n");
                printf("6. Orvault    7. Vertou     8. Coueron    9. Carquefou  10. La Chapelle\n");
            }
            else if (state_choice == 10) { // SEINE-SAINT-DENIS (93)
                printf("🏙️  Top 10 Cities in SEINE-SAINT-DENIS:\n");
                printf("1. Saint-Denis 2. Montreuil 3. Aubervilliers 4. Aulnay   5. Drancy\n");
                printf("6. Noisy-le-Grand 7. Pantin 8. Bondy      9. Epinay     10. Bobigny\n");
            }
            else {
                printf("⚠️ Invalid Department Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: France\n");
                printf(">> Department Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 2) { // GERMANY
            int state_choice, city_choice;
            
            printf(">> GERMANY: Select a State (1-10)\n");
            printf("1. Bavaria          2. Berlin           3. Hamburg\n");
            printf("4. Saxony           5. Hesse            6. Baden-Wurttemberg\n");
            printf("7. N. Rhine-Westphalia 8. Lower Saxony  9. Bremen\n");
            printf("10. Thuringia\n");
            
            printf("\nENTER STATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // BAVARIA (Bayern)
                printf("🏙️  Top 10 Cities in BAVARIA:\n");
                printf("1. Munich     2. Nuremberg  3. Augsburg   4. Regensburg 5. Ingolstadt\n");
                printf("6. Furth      7. Wurzburg   8. Erlangen   9. Bamberg    10. Bayreuth\n");
            } 
            else if (state_choice == 2) { // BERLIN (City-State)
                printf("🏙️  Top 10 Districts in BERLIN:\n");
                printf("1. Mitte      2. Pankow     3. Charlottenburg 4. Spandau  5. Steglitz\n");
                printf("6. Neukolln   7. Tempelhof  8. Lichtenberg 9. Marzahn   10. Treptow\n");
            }
            else if (state_choice == 3) { // HAMBURG (City-State)
                printf("🏙️  Top 10 Districts in HAMBURG:\n");
                printf("1. Altona     2. Bergedorf  3. Eimsbuttel 4. Harburg    5. Wandsbek\n");
                printf("6. Hamburg-Mitte 7. Hamburg-Nord 8. St. Pauli 9. Blankenese 10. Eppendorf\n");
            }
            else if (state_choice == 4) { // SAXONY (Sachsen)
                printf("🏙️  Top 10 Cities in SAXONY:\n");
                printf("1. Leipzig    2. Dresden    3. Chemnitz   4. Zwickau    5. Plauen\n");
                printf("6. Gorlitz    7. Freiberg   8. Bautzen    9. Pirna      10. Hoyerswerda\n");
            }
            else if (state_choice == 5) { // HESSE (Hessen)
                printf("🏙️  Top 10 Cities in HESSE:\n");
                printf("1. Frankfurt  2. Wiesbaden  3. Kassel     4. Darmstadt  5. Offenbach\n");
                printf("6. Hanau      7. Giessen    8. Marburg    9. Fulda      10. Wetzlar\n");
            }
            else if (state_choice == 6) { // BADEN-WURTTEMBERG
                printf("🏙️  Top 10 Cities in BADEN-WURTTEMBERG:\n");
                printf("1. Stuttgart  2. Mannheim   3. Karlsruhe  4. Freiburg   5. Heidelberg\n");
                printf("6. Ulm        7. Heilbronn  8. Pforzheim  9. Reutlingen 10. Ludwigsburg\n");
            }
            else if (state_choice == 7) { // NORTH RHINE-WESTPHALIA (NRW)
                printf("🏙️  Top 10 Cities in NRW:\n");
                printf("1. Cologne    2. Dusseldorf 3. Dortmund   4. Essen      5. Duisburg\n");
                printf("6. Bochum     7. Wuppertal  8. Bielefeld  9. Bonn       10. Munster\n");
            }
            else if (state_choice == 8) { // LOWER SAXONY (Niedersachsen)
                printf("🏙️  Top 10 Cities in LOWER SAXONY:\n");
                printf("1. Hanover    2. Brunswick  3. Oldenburg  4. Osnabruck  5. Wolfsburg\n");
                printf("6. Gottingen  7. Hildesheim 8. Salzgitter 9. Wilhelmshaven 10. Delmenhorst\n");
            }
            else if (state_choice == 9) { // BREMEN
                printf("🏙️  Top 10 Areas in BREMEN:\n");
                printf("1. Bremen City 2. Bremerhaven 3. Vegesack   4. Hemelingen 5. Osterholz\n");
                printf("6. Neustadt   7. Vahr       8. Findorff   9. Burglesum  10. Horn-Lehe\n");
            }
            else if (state_choice == 10) { // THURINGIA (Thuringen)
                printf("🏙️  Top 10 Cities in THURINGIA:\n");
                printf("1. Erfurt     2. Jena       3. Gera       4. Weimar     5. Gotha\n");
                printf("6. Nordhausen 7. Eisenach   8. Suhl       9. Altenburg  10. Muhlhausen\n");
            }
            else {
                printf("⚠️ Invalid State Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: Germany\n");
                printf(">> State Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 3) { // ITALY
            int state_choice, city_choice;
            
            printf(">> ITALY: Select a Region (1-10)\n");
            printf("1. Lombardy       2. Lazio          3. Campania\n");
            printf("4. Sicily         5. Veneto         6. Piedmont\n");
            printf("7. Emilia-Romagna 8. Tuscany        9. Puglia\n");
            printf("10. Liguria\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // LOMBARDY
                printf("🏙️  Top 10 Cities in LOMBARDY:\n");
                printf("1. Milan      2. Brescia    3. Monza      4. Bergamo    5. Como\n");
                printf("6. Varese     7. Pavia      8. Cremona    9. Mantua     10. Lecco\n");
            } 
            else if (state_choice == 2) { // LAZIO
                printf("🏙️  Top 10 Cities in LAZIO:\n");
                printf("1. Rome       2. Latina     3. Guidonia   4. Fiumicino  5. Aprilia\n");
                printf("6. Viterbo    7. Pomezia    8. Tivoli     9. Velletri   10. Civitavecchia\n");
            }
            else if (state_choice == 3) { // CAMPANIA
                printf("🏙️  Top 10 Cities in CAMPANIA:\n");
                printf("1. Naples     2. Salerno    3. Giugliano  4. Caserta    5. Castellammare\n");
                printf("6. Afragola   7. Benevento  8. Acerra     9. Avellino   10. Portici\n");
            }
            else if (state_choice == 4) { // SICILY
                printf("🏙️  Top 10 Cities in SICILY:\n");
                printf("1. Palermo    2. Catania    3. Messina    4. Syracuse   5. Marsala\n");
                printf("6. Gela       7. Ragusa     8. Trapani    9. Caltanissetta 10. Agrigento\n");
            }
            else if (state_choice == 5) { // VENETO
                printf("🏙️  Top 10 Cities in VENETO:\n");
                printf("1. Venice     2. Verona     3. Padua      4. Vicenza    5. Treviso\n");
                printf("6. Rovigo     7. Chioggia   8. Bassano    9. San Dona   10. Belluno\n");
            }
            else if (state_choice == 6) { // PIEDMONT
                printf("🏙️  Top 10 Cities in PIEDMONT:\n");
                printf("1. Turin      2. Novara     3. Alessandria 4. Asti      5. Moncalieri\n");
                printf("6. Cuneo      8. Collegno   8. Rivoli     9. Vercelli   10. Biella\n");
            }
            else if (state_choice == 7) { // EMILIA-ROMAGNA
                printf("🏙️  Top 10 Cities in EMILIA-ROMAGNA:\n");
                printf("1. Bologna    2. Parma      3. Modena     4. Reggio Emilia 5. Ravenna\n");
                printf("6. Rimini     7. Ferrara    8. Forli      9. Piacenza   10. Cesena\n");
            }
            else if (state_choice == 8) { // TUSCANY
                printf("🏙️  Top 10 Cities in TUSCANY:\n");
                printf("1. Florence   2. Prato      3. Livorno    4. Arezzo     5. Pistoia\n");
                printf("6. Lucca      7. Pisa       8. Grosseto   9. Massa      10. Carrara\n");
            }
            else if (state_choice == 9) { // PUGLIA
                printf("🏙️  Top 10 Cities in PUGLIA:\n");
                printf("1. Bari       2. Taranto    3. Foggia     4. Andria     5. Lecce\n");
                printf("6. Barletta   7. Brindisi   8. Altamura   9. Molfetta   10. Manfredonia\n");
            }
            else if (state_choice == 10) { // LIGURIA
                printf("🏙️  Top 10 Cities in LIGURIA:\n");
                printf("1. Genoa      2. La Spezia  3. Savona     4. Sanremo    5. Imperia\n");
                printf("6. Rapallo    7. Chiavari   8. Ventimiglia 9. Albenga   10. Sarzana\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: Italy\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 4) { // UNITED KINGDOM
            int state_choice, city_choice;
            
            printf(">> UNITED KINGDOM: Select a Country or Major City (1-10)\n");
            printf("1. England        2. Scotland       3. Wales\n");
            printf("4. N. Ireland     5. London         6. Manchester\n");
            printf("7. Birmingham     8. Glasgow        9. Liverpool\n");
            printf("10. Edinburgh\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ENGLAND
                printf("🏙️  Top 10 Cities in ENGLAND:\n");
                printf("1. Leeds      2. Sheffield  3. Bristol    4. Leicester  5. Nottingham\n");
                printf("6. Newcastle  7. Brighton   8. Hull       9. Plymouth   10. Derby\n");
            } 
            else if (state_choice == 2) { // SCOTLAND
                printf("🏙️  Top 10 Cities/Towns in SCOTLAND:\n");
                printf("1. Aberdeen   2. Dundee     3. Paisley    4. Inverness  5. Perth\n");
                printf("6. Stirling   7. Ayr        8. Livingston 9. Hamilton   10. Dunfermline\n");
            }
            else if (state_choice == 3) { // WALES
                printf("🏙️  Top 10 Cities/Towns in WALES:\n");
                printf("1. Cardiff    2. Swansea    3. Newport    4. Wrexham    5. Barry\n");
                printf("6. Neath      7. Bridgend   8. Llanelli   9. Merthyr    10. Aberystwyth\n");
            }
            else if (state_choice == 4) { // NORTHERN IRELAND
                printf("🏙️  Top 10 Cities/Towns in N. IRELAND:\n");
                printf("1. Belfast    2. Derry      3. Lisburn    4. Newtownabbey 5. Bangor\n");
                printf("6. Castlereagh 7. Ballymena  8. Newtownards 9. Newry      10. Carrickfergus\n");
            }
            else if (state_choice == 5) { // LONDON (Districts)
                printf("🏙️  Top 10 Areas in LONDON:\n");
                printf("1. Westminster 2. Camden    3. Greenwich  4. Hackney    5. Islington\n");
                printf("6. Chelsea     7. Kensington 8. Richmond   9. Croydon    10. Stratford\n");
            }
            else if (state_choice == 6) { // MANCHESTER
                printf("🏙️  Top 10 Areas in MANCHESTER:\n");
                printf("1. Deansgate  2. Castlefield 3. Salford    4. Trafford   5. Didsbury\n");
                printf("6. Cheetham   7. Gorton     8. Chorlton   9. Ancoats    10. Wythenshawe\n");
            }
            else if (state_choice == 7) { // BIRMINGHAM
                printf("🏙️  Top 10 Areas in BIRMINGHAM:\n");
                printf("1. Edgbaston  2. Digbeth    3. Solihull   4. Aston      5. Moseley\n");
                printf("6. Selly Oak  7. Harborne   8. Sutton Coldfield 9. Erdington 10. Handsworth\n");
            }
            else if (state_choice == 8) { // GLASGOW
                printf("🏙️  Top 10 Areas in GLASGOW:\n");
                printf("1. West End   2. City Centre 3. Govan     4. Maryhill   5. Gorbals\n");
                printf("6. Pollokshields 7. Bearsden 8. Partick   9. Easterhouse 10. Shawlands\n");
            }
            else if (state_choice == 9) { // LIVERPOOL
                printf("🏙️  Top 10 Areas in LIVERPOOL:\n");
                printf("1. Anfield    2. Everton    3. Speke      4. Aigburth   5. Woolton\n");
                printf("6. Crosby     7. Kirkby     8. Toxteth    9. Walton     10. West Derby\n");
            }
            else if (state_choice == 10) { // EDINBURGH
                printf("🏙️  Top 10 Areas in EDINBURGH:\n");
                printf("1. Old Town   2. New Town   3. Leith      4. Stockbridge 5. Portobello\n");
                printf("6. Morningside 7. Corstorphine 8. Liberton 9. Gorgie     10. Southside\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT AREA/CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: United Kingdom\n");
                printf(">> Selection Code: %d, Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 5) { // SPAIN
            int state_choice, city_choice;
            
            printf(">> SPAIN: Select an Autonomous Community (1-10)\n");
            printf("1. Andalusia      2. Catalonia      3. Madrid\n");
            printf("4. Valencia       5. Galicia        6. Castile and Leon\n");
            printf("7. Basque Country 8. Canary Islands 9. Murcia\n");
            printf("10. Aragon\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ANDALUSIA
                printf("🏙️  Top 10 Cities in ANDALUSIA:\n");
                printf("1. Seville    2. Malaga     3. Cordoba    4. Granada    5. Jerez\n");
                printf("6. Almeria    7. Huelva     8. Cadiz      9. Marbella   10. Dos Hermanas\n");
            } 
            else if (state_choice == 2) { // CATALONIA
                printf("🏙️  Top 10 Cities in CATALONIA:\n");
                printf("1. Barcelona  2. L'Hospitalet 3. Badalona  4. Terrassa   5. Sabadell\n");
                printf("6. Lleida     7. Tarragona  8. Mataro     9. Girona     10. Reus\n");
            }
            else if (state_choice == 3) { // MADRID
                printf("🏙️  Top 10 Cities/Districts in MADRID:\n");
                printf("1. Madrid City 2. Mostoles   3. Alcala     4. Fuenlabrada 5. Leganes\n");
                printf("6. Getafe     7. Alcorcon   8. Parla      9. Torrejon   10. Alcobendas\n");
            }
            else if (state_choice == 4) { // VALENCIA
                printf("🏙️  Top 10 Cities in VALENCIA:\n");
                printf("1. Valencia City 2. Alicante 3. Elche      4. Castellon  5. Torrevieja\n");
                printf("6. Torrent    7. Orihuela   8. Gandia     9. Paterna    10. Sagunto\n");
            }
            else if (state_choice == 5) { // GALICIA
                printf("🏙️  Top 10 Cities in GALICIA:\n");
                printf("1. Vigo       2. A Coruña   3. Ourense    4. Lugo       5. Santiago\n");
                printf("6. Pontevedra 7. Ferrol     8. Narón      9. Vilagarcía 10. Oleiros\n");
            }
            else if (state_choice == 6) { // CASTILE AND LEON
                printf("🏙️  Top 10 Cities in CASTILE AND LEON:\n");
                printf("1. Valladolid 2. Burgos     3. Salamanca  4. Leon       5. Palencia\n");
                printf("6. Ponferrada 7. Zamora     8. Avila      9. Segovia    10. Soria\n");
            }
            else if (state_choice == 7) { // BASQUE COUNTRY
                printf("🏙️  Top 10 Cities in BASQUE COUNTRY:\n");
                printf("1. Bilbao     2. Vitoria    3. San Sebastian 4. Barakaldo 5. Getxo\n");
                printf("6. Irun       7. Portugalete 8. Santurtzi  9. Basauri    10. Errenteria\n");
            }
            else if (state_choice == 8) { // CANARY ISLANDS
                printf("🏙️  Top 10 Cities/Islands in CANARY ISLANDS:\n");
                printf("1. Las Palmas 2. Tenerife   3. La Laguna  4. Telde      5. Arona\n");
                printf("6. Santa Cruz 7. Arrecife   8. Lanzarote  9. Fuerteventura 10. La Palma\n");
            }
            else if (state_choice == 9) { // MURCIA
                printf("🏙️  Top 10 Cities in MURCIA:\n");
                printf("1. Murcia City 2. Cartagena  3. Lorca      4. Molina     5. Alcantarilla\n");
                printf("6. Mazarrón   7. Cieza      8. Yecla      9. Águilas    10. Torre-Pacheco\n");
            }
            else if (state_choice == 10) { // ARAGON
                printf("🏙️  Top 10 Cities in ARAGON:\n");
                printf("1. Zaragoza   2. Huesca     3. Teruel     4. Calatayud  5. Utebo\n");
                printf("6. Monzón     7. Barbastro  8. Ejea       9. Alcañiz    10. Fraga\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: Spain\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 6) { // RUSSIA
            int state_choice, city_choice;
            
            printf(">> RUSSIA: Select a Federal Subject (1-10)\n");
            printf("1. Moscow City    2. St. Petersburg  3. Tatarstan\n");
            printf("4. Krasnodar      5. Sverdlovsk      6. Rostov\n");
            printf("7. Bashkortostan  8. Moscow Oblast   9. Samara\n");
            printf("10. Chelyabinsk\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // MOSCOW CITY
                printf("🏙️  Top 10 Districts/Areas in MOSCOW:\n");
                printf("1. Central    2. Khamovniki 3. Tverskoy   4. Arbat      5. Presnensky\n");
                printf("6. Basmanny   7. Zamoskvorechye 8. Sokolniki 9. Maryina Roshcha 10. Tagansky\n");
            } 
            else if (state_choice == 2) { // ST. PETERSBURG
                printf("🏙️  Top 10 Districts in ST. PETERSBURG:\n");
                printf("1. Centralny  2. Admiralteysky 3. Vasileostrovsky 4. Petrogradsky 5. Pushkinsky\n");
                printf("6. Petergof   7. Vyborgsky  8. Primorsky  9. Moskovsky  10. Kronshtadt\n");
            }
            else if (state_choice == 3) { // TATARSTAN
                printf("🏙️  Top 10 Cities in TATARSTAN:\n");
                printf("1. Kazan      2. Naberezhnye Chelny 3. Almetyevsk 4. Nizhnekamsk 5. Zelenodolsk\n");
                printf("6. Bugulma    7. Yelabuga   8. Leninogorsk 9. Chistopol  10. Aznakayevo\n");
            }
            else if (state_choice == 4) { // KRASNODAR KRAI
                printf("🏙️  Top 10 Cities in KRASNODAR:\n");
                printf("1. Krasnodar City 2. Sochi  3. Novorossiysk 4. Armavir   5. Anapa\n");
                printf("6. Gelendzhik 7. Tuapse     8. Yeysk      9. Kropotkin  10. Slavyansk\n");
            }
            else if (state_choice == 5) { // SVERDLOVSK OBLAST
                printf("🏙️  Top 10 Cities in SVERDLOVSK:\n");
                printf("1. Yekaterinburg 2. Nizhny Tagil 3. Kamensk-Uralsky 4. Pervouralsk 5. Serov\n");
                printf("6. Novouralsk 7. Asbest     8. Polevskoy  9. Revda      10. Verkhnyaya Pyshma\n");
            }
            else if (state_choice == 6) { // ROSTOV OBLAST
                printf("🏙️  Top 10 Cities in ROSTOV:\n");
                printf("1. Rostov-on-Don 2. Taganrog 3. Shakhty   4. Novocherkassk 5. Volgodonsk\n");
                printf("6. Bataysk    7. Novoshahtinsk 8. Azov    9. Kamensk-Shakhtinsky 10. Gukovo\n");
            }
            else if (state_choice == 7) { // BASHKORTOSTAN
                printf("🏙️  Top 10 Cities in BASHKORTOSTAN:\n");
                printf("1. Ufa        2. Sterlitamak 3. Salavat    4. Neftekamsk 5. Oktyabrsky\n");
                printf("6. Beloretsk  7. Ishimbay   8. Tuymazy    9. Kumertau   10. Meleuz\n");
            }
            else if (state_choice == 8) { // MOSCOW OBLAST (Region surrounding Moscow)
                printf("🏙️  Top 10 Cities in MOSCOW OBLAST:\n");
                printf("1. Balashikha 2. Podolsk    3. Khimki     4. Mytishchi  5. Korolyov\n");
                printf("6. Lyubertsy  7. Krasnogorsk 8. Elektrostal 9. Kolomna  10. Odintsovo\n");
            }
            else if (state_choice == 9) { // SAMARA OBLAST
                printf("🏙️  Top 10 Cities in SAMARA:\n");
                printf("1. Samara City 2. Tolyatti  3. Syzran     4. Novokuybyshevsk 5. Chapayevsk\n");
                printf("6. Zhigulyovsk 7. Otradny   8. Kinel      9. Pokhvistnevo 10. Oktyabrsk\n");
            }
            else if (state_choice == 10) { // CHELYABINSK OBLAST
                printf("🏙️  Top 10 Cities in CHELYABINSK:\n");
                printf("1. Chelyabinsk City 2. Magnitogorsk 3. Zlatoust 4. Miass 5. Kopeysk\n");
                printf("6. Ozersk     7. Troitsk    8. Snezhinsk  9. Satka      10. Chebarkul\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe/Asia (Russia)\n");
                printf(">> Country: Russia\n");
                printf(">> Subject Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 7) { // SWITZERLAND
            int state_choice, city_choice;
            
            printf(">> SWITZERLAND: Select a Canton (1-10)\n");
            printf("1. Zurich         2. Bern           3. Vaud\n");
            printf("4. Aargau         5. St. Gallen     6. Geneva\n");
            printf("7. Lucerne        8. Ticino         9. Valais\n");
            printf("10. Basel-Stadt\n");
            
            printf("\nENTER CANTON NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ZURICH
                printf("🏙️  Top 10 Cities in ZURICH:\n");
                printf("1. Zurich City 2. Winterthur 3. Uster      4. Dubendorf  5. Dietikon\n");
                printf("6. Wetzikon   7. Wädenswil  8. Horgen     9. Bülach     10. Adliswil\n");
            } 
            else if (state_choice == 2) { // BERN
                printf("🏙️  Top 10 Cities in BERN:\n");
                printf("1. Bern City  2. Biel/Bienne 3. Thun       4. Köniz      5. Ostermundigen\n");
                printf("6. Burgdorf   7. Steffisburg 8. Langenthal 9. Lyss       10. Muri\n");
            }
            else if (state_choice == 3) { // VAUD
                printf("🏙️  Top 10 Cities in VAUD:\n");
                printf("1. Lausanne   2. Yverdon    3. Montreux   4. Nyon       5. Renens\n");
                printf("6. Vevey      7. Pully      8. Morges     9. Gland      10. Ecublens\n");
            }
            else if (state_choice == 4) { // AARGAU
                printf("🏙️  Top 10 Cities in AARGAU:\n");
                printf("1. Aarau      2. Wettingen  3. Baden      4. Wohlen     5. Olten (Near)\n");
                printf("6. Bremgarten 7. Zofingen   8. Rheinfelden 9. Spreitenbach 10. Brugg\n");
            }
            else if (state_choice == 5) { // ST. GALLEN
                printf("🏙️  Top 10 Cities in ST. GALLEN:\n");
                printf("1. St. Gallen City 2. Rapperswil 3. Wil    4. Gossau     5. Uzwil\n");
                printf("6. Altstätten 7. Buchs      8. Flawil     9. Rorschach  10. Wattwil\n");
            }
            else if (state_choice == 6) { // GENEVA
                printf("🏙️  Top 10 Municipalities in GENEVA:\n");
                printf("1. Geneva City 2. Vernier    3. Lancy      4. Meyrin     5. Carouge\n");
                printf("6. Onex       7. Thônex     8. Versoix    9. Chêne-Bougeries 10. Le Grand-Saconnex\n");
            }
            else if (state_choice == 7) { // LUCERNE
                printf("🏙️  Top 10 Cities in LUCERNE:\n");
                printf("1. Lucerne City 2. Emmen     3. Kriens     4. Horw       5. Ebikon\n");
                printf("6. Sursee     7. Hochdorf   8. Willisau   9. Root       10. Malters\n");
            }
            else if (state_choice == 8) { // TICINO
                printf("🏙️  Top 10 Cities in TICINO:\n");
                printf("1. Lugano     2. Bellinzona 3. Locarno    4. Mendrisio  5. Chiasso\n");
                printf("6. Giubiasco  7. Minusio    8. Losone     9. Capriasca  10. Biasca\n");
            }
            else if (state_choice == 9) { // VALAIS
                printf("🏙️  Top 10 Cities in VALAIS:\n");
                printf("1. Sion       2. Martigny   3. Monthey    4. Sierre     5. Brig-Glis\n");
                printf("6. Zermatt    7. Visp       8. Naters     9. Crans-Montana 10. Saint-Maurice\n");
            }
            else if (state_choice == 10) { // BASEL-STADT
                printf("🏙️  Top 10 Districts/Areas in BASEL:\n");
                printf("1. Grossbasel 2. Kleinbasel 3. Riehen     4. Bettingen  5. St. Alban\n");
                printf("6. Gundeldingen 7. Bachletten 8. Iselin    9. Matthäus   10. Wettstein\n");
            }
            else {
                printf("⚠️ Invalid Canton Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: Switzerland\n");
                printf(">> Canton Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 8) { // GREECE
            int state_choice, city_choice;
            
            printf(">> GREECE: Select a Region (1-10)\n");
            printf("1. Attica           2. Central Macedonia 3. Thessaly\n");
            printf("4. W. Greece        5. Crete             6. Peloponnese\n");
            printf("7. Epirus           8. South Aegean      9. North Aegean\n");
            printf("10. Central Greece\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ATTICA
                printf("🏙️  Top 10 Cities/Districts in ATTICA:\n");
                printf("1. Athens City 2. Piraeus    3. Peristeri  4. Kallithea  5. Acharnes\n");
                printf("6. Glyfada    7. Kifissia   8. Marousi    9. Zografou   10. Egaleo\n");
            } 
            else if (state_choice == 2) { // CENTRAL MACEDONIA
                printf("🏙️  Top 10 Cities in CENTRAL MACEDONIA:\n");
                printf("1. Thessaloniki 2. Kalamaria 3. Katerini   4. Serres     5. Evosmos\n");
                printf("6. Veria      7. Giannitsa  8. Kilkis     9. Edessa     10. Thermi\n");
            }
            else if (state_choice == 3) { // THESSALY
                printf("🏙️  Top 10 Cities in THESSALY:\n");
                printf("1. Larissa    2. Volos      3. Trikala    4. Karditsa   5. Tyrnavos\n");
                printf("6. Elassona   7. Farsala    8. Kalabaka   9. Almyros    10. Skopelos\n");
            }
            else if (state_choice == 4) { // WESTERN GREECE
                printf("🏙️  Top 10 Cities in WESTERN GREECE:\n");
                printf("1. Patras     2. Agrinio    3. Pyrgos     4. Aigio      5. Mesolonghi\n");
                printf("6. Nafpaktos  7. Amaliada   8. Akraifnio  9. Ovrya      10. Kato Achaia\n");
            }
            else if (state_choice == 5) { // CRETE
                printf("🏙️  Top 10 Cities/Towns in CRETE:\n");
                printf("1. Heraklion  2. Chania     3. Rethymno   4. Ierapetra  5. Agios Nikolaos\n");
                printf("6. Siteia     7. Kissamos   8. Malia      9. Moires     10. Arkalochori\n");
            }
            else if (state_choice == 6) { // PELOPONNESE
                printf("🏙️  Top 10 Cities in PELOPONNESE:\n");
                printf("1. Kalamata   2. Tripoli    3. Corinth    4. Argos      5. Sparta\n");
                printf("6. Nafplio    7. Kiato      8. Xylokastro 9. Messini    10. Kyparissia\n");
            }
            else if (state_choice == 7) { // EPIRUS
                printf("🏙️  Top 10 Cities in EPIRUS:\n");
                printf("1. Ioannina   2. Arta       3. Preveza    4. Igoumenitsa 5. Konitsa\n");
                printf("6. Metsovo    7. Paramythia 8. Filippiada 9. Parga      10. Anato\n");
            }
            else if (state_choice == 8) { // SOUTH AEGEAN
                printf("🏙️  Top 10 Islands/Cities in SOUTH AEGEAN:\n");
                printf("1. Rhodes City 2. Kos Town   3. Santorini  4. Mykonos    5. Naxos\n");
                printf("6. Paros      7. Syros      8. Kalymnos   9. Ialysos    10. Karpathos\n");
            }
            else if (state_choice == 9) { // NORTH AEGEAN
                printf("🏙️  Top 10 Islands/Cities in NORTH AEGEAN:\n");
                printf("1. Mytilene   2. Chios Town 3. Samos Town 4. Lemnos     5. Karlovasi\n");
                printf("6. Plomari    7. Myrina     8. Vathy      9. Ikaria     10. Kalloni\n");
            }
            else if (state_choice == 10) { // CENTRAL GREECE
                printf("🏙️  Top 10 Cities in CENTRAL GREECE:\n");
                printf("1. Chalkida   2. Lamia      3. Thiva      4. Livadeia   5. Amfissa\n");
                printf("6. Karpenisi  7. Psachna    8. Aliveri    9. Atalanti   10. Orchomenos\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: Greece\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 9) { // NORWAY
            int state_choice, city_choice;
            
            printf(">> NORWAY: Select a County (1-10)\n");
            printf("1. Oslo           2. Viken          3. Vestland\n");
            printf("4. Rogaland       5. Trøndelag      6. Innlandet\n");
            printf("7. Agder          8. Nordland       9. Vestfold og Telemark\n");
            printf("10. Troms og Finnmark\n");
            
            printf("\nENTER COUNTY NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // OSLO (City-County)
                printf("🏙️  Top 10 Districts in OSLO:\n");
                printf("1. Gamle Oslo  2. Grünerløkka 3. Frogner    4. St. Hanshaugen 5. Ullern\n");
                printf("6. Vestre Aker 7. Nordre Aker 8. Sagene     9. Alna       10. Majorstuen\n");
            } 
            else if (state_choice == 2) { // VIKEN
                printf("🏙️  Top 10 Cities in VIKEN:\n");
                printf("1. Drammen     2. Fredrikstad 3. Sarpsborg  4. Asker      5. Bærum\n");
                printf("6. Moss        7. Lillestrøm  8. Ski        9. Jessheim   10. Drøbak\n");
            }
            else if (state_choice == 3) { // VESTLAND
                printf("🏙️  Top 10 Cities/Towns in VESTLAND:\n");
                printf("1. Bergen      2. Askøy       3. Fana       4. Os         5. Stord\n");
                printf("6. Førde       7. Voss        8. Florø      9. Knarvik    10. Odda\n");
            }
            else if (state_choice == 4) { // ROGALAND
                printf("🏙️  Top 10 Cities in ROGALAND:\n");
                printf("1. Stavanger   2. Sandnes     3. Haugesund  4. Sola       5. Bryne\n");
                printf("6. Kopervik    7. Egersund    8. Jørpeland  9. Åkrehamn   10. Sauda\n");
            }
            else if (state_choice == 5) { // TRØNDELAG
                printf("🏙️  Top 10 Cities in TRØNDELAG:\n");
                printf("1. Trondheim   2. Stjørdal    3. Steinkjer  4. Levanger   5. Verdal\n");
                printf("6. Orkanger    7. Namsos      8. Oppdal     9. Røros      10. Brekstad\n");
            }
            else if (state_choice == 6) { // INNLANDET
                printf("🏙️  Top 10 Cities in INNLANDET:\n");
                printf("1. Hamar       2. Lillehammer 3. Gjøvik     4. Elverum    5. Kongsvinger\n");
                printf("6. Brumunddal  7. Moelv       8. Otta       9. Tynset     10. Fagernes\n");
            }
            else if (state_choice == 7) { // AGDER
                printf("🏙️  Top 10 Cities in AGDER:\n");
                printf("1. Kristiansand 2. Arendal    3. Grimstad   4. Mandal     5. Vennesla\n");
                printf("6. Lillesand   7. Flekkefjord 8. Risør      9. Farsund    10. Lyngdal\n");
            }
            else if (state_choice == 8) { // NORDLAND
                printf("🏙️  Top 10 Cities in NORDLAND:\n");
                printf("1. Bodø        2. Mo i Rana   3. Narvik     4. Mosjøen    5. Fauske\n");
                printf("6. Sandnessjøen 7. Sortland   8. Brønnøysund 9. Svolvær   10. Stokmarknes\n");
            }
            else if (state_choice == 9) { // VESTFOLD OG TELEMARK
                printf("🏙️  Top 10 Cities in VESTFOLD OG TELEMARK:\n");
                printf("1. Tønsberg    2. Sandefjord  3. Skien      4. Porsgrunn  5. Larvik\n");
                printf("6. Horten      7. Notodden    8. Holmestrand 9. Kragerø   10. Rjukan\n");
            }
            else if (state_choice == 10) { // TROMS OG FINNMARK
                printf("🏙️  Top 10 Cities in TROMS OG FINNMARK:\n");
                printf("1. Tromsø      2. Harstad     3. Alta       4. Hammerfest 5. Kirkenes\n");
                printf("6. Vadsø       7. Finnsnes    8. Vardø      9. Honningsvåg 10. Lakselv\n");
            }
            else {
                printf("⚠️ Invalid County Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: Norway\n");
                printf(">> County Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 10) { // NETHERLANDS
            int state_choice, city_choice;
            
            printf(">> NETHERLANDS: Select a Province (1-10)\n");
            printf("1. S. Holland      2. N. Holland      3. N. Brabant\n");
            printf("4. Utrecht         5. Gelderland      6. Overijssel\n");
            printf("7. Limburg         8. Friesland       9. Groningen\n");
            printf("10. Drenthe\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // SOUTH HOLLAND (Zuid-Holland)
                printf("🏙️  Top 10 Cities in SOUTH HOLLAND:\n");
                printf("1. Rotterdam  2. The Hague   3. Leiden     4. Dordrecht  5. Delft\n");
                printf("6. Schiedam   7. Alphen      8. Gouda      9. Zoetermeer 10. Westland\n");
            } 
            else if (state_choice == 2) { // NORTH HOLLAND (Noord-Holland)
                printf("🏙️  Top 10 Cities in NORTH HOLLAND:\n");
                printf("1. Amsterdam  2. Haarlem     3. Zaanstad   4. Alkmaar    5. Hoofddorp\n");
                printf("6. Hilversum  7. Amstelveen  8. Purmerend  9. Hoorn      10. Den Helder\n");
            }
            else if (state_choice == 3) { // NORTH BRABANT (Noord-Brabant)
                printf("🏙️  Top 10 Cities in NORTH BRABANT:\n");
                printf("1. Eindhoven  2. Tilburg     3. Breda      4. Den Bosch  5. Helmond\n");
                printf("6. Oss        7. Roosendaal  8. Bergen op Zoom 9. Waalwijk 10. Veldhoven\n");
            }
            else if (state_choice == 4) { // UTRECHT
                printf("🏙️  Top 10 Cities in UTRECHT:\n");
                printf("1. Utrecht City 2. Amersfoort 3. Zeist     4. Nieuwegein 5. Veenendaal\n");
                printf("6. Houten     7. Woerden     8. IJsselstein 9. Soest      10. De Ronde Venen\n");
            }
            else if (state_choice == 5) { // GELDERLAND
                printf("🏙️  Top 10 Cities in GELDERLAND:\n");
                printf("1. Nijmegen   2. Arnhem      3. Apeldoorn  4. Ede        5. Doetinchem\n");
                printf("6. Barneveld  7. Zutphen     8. Harderwijk 9. Tiel       10. Wageningen\n");
            }
            else if (state_choice == 6) { // OVERIJSSEL
                printf("🏙️  Top 10 Cities in OVERIJSSEL:\n");
                printf("1. Enschede   2. Zwolle      3. Deventer   4. Hengelo    5. Almelo\n");
                printf("6. Kampen     7. Hardenberg  8. Oldenzaal  9. Raalte     10. Steenwijkerland\n");
            }
            else if (state_choice == 7) { // LIMBURG
                printf("🏙️  Top 10 Cities in LIMBURG:\n");
                printf("1. Maastricht 2. Venlo       3. Sittard    4. Heerlen    5. Roermond\n");
                printf("6. Weert      7. Kerkrade    8. Landgraaf  9. Brunssum   10. Venray\n");
            }
            else if (state_choice == 8) { // FRIESLAND (Fryslân)
                printf("🏙️  Top 10 Cities/Towns in FRIESLAND:\n");
                printf("1. Leeuwarden 2. Drachten    3. Sneek      4. Heerenveen 5. Harlingen\n");
                printf("6. Joure      7. Franeker    8. Dokkum     9. Wolvega    10. Lemmer\n");
            }
            else if (state_choice == 9) { // GRONINGEN
                printf("🏙️  Top 10 Cities/Towns in GRONINGEN:\n");
                printf("1. Groningen City 2. Veendam 3. Stadskanaal 4. Delfzijl  5. Winschoten\n");
                printf("6. Haren      7. Hoogezand   8. Appingedam 9. Bedum      10. Ter Apel\n");
            }
            else if (state_choice == 10) { // DRENTHE
                printf("🏙️  Top 10 Cities/Towns in DRENTHE:\n");
                printf("1. Assen      2. Emmen       3. Hoogeveen  4. Meppel     5. Coevorden\n");
                printf("6. Roden      7. Klazienaveen 8. Beilen    9. Zuidlaren  10. Eelde\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: Europe\n");
                printf(">> Country: Netherlands\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else {
            printf("⚠️ Invalid Country Selection within Europe.\n");
        }
    }



    else if (choice == 6) {
        int country_choice;
        
        printf("📍 CONTINENT: NORTH AMERICA\n");
        printf("TOP 10 COUNTRIES:\n");
        printf("1. USA        2. Canada     3. Mexico\n");
        printf("4. Cuba       5. Panama     6. Jamaica\n");
        printf("7. Costa Rica 8. Guatemala  9. Bahamas\n");
        printf("10. Honduras\n");

        printf("\nCHOOSE A COUNTRY (1-10): ");
        scanf("%d", &country_choice);
        printf("------------------------------\n");

        if (country_choice == 1) { // USA
            int state_choice, city_choice;
            
            printf(">> USA: Select a State (1-10)\n");
            printf("1. California     2. Texas          3. Florida\n");
            printf("4. New York       5. Illinois       6. Pennsylvania\n");
            printf("7. Ohio           8. Georgia        9. N. Carolina\n");
            printf("10. Michigan\n");
            
            printf("\nENTER STATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // CALIFORNIA
                printf("🏙️  Top 10 Cities in CALIFORNIA:\n");
                printf("1. Los Angeles 2. San Diego  3. San Jose    4. San Francisco 5. Fresno\n");
                printf("6. Sacramento  7. Long Beach 8. Oakland     9. Bakersfield  10. Anaheim\n");
            } 
            else if (state_choice == 2) { // TEXAS
                printf("🏙️  Top 10 Cities in TEXAS:\n");
                printf("1. Houston     2. San Antonio 3. Dallas     4. Austin       5. Fort Worth\n");
                printf("6. El Paso     7. Arlington   8. Corpus Christi 9. Plano    10. Lubbock\n");
            }
            else if (state_choice == 3) { // FLORIDA
                printf("🏙️  Top 10 Cities in FLORIDA:\n");
                printf("1. Jacksonville 2. Miami     3. Tampa       4. Orlando      5. St. Petersburg\n");
                printf("6. Hialeah     7. Tallahassee 8. Fort Lauderdale 9. Port St. Lucie 10. Cape Coral\n");
            }
            else if (state_choice == 4) { // NEW YORK
                printf("🏙️  Top 10 Cities in NEW YORK:\n");
                printf("1. NYC (Manhattan) 2. NYC (Brooklyn) 3. Buffalo 4. Rochester 5. Yonkers\n");
                printf("6. Syracuse    7. Albany      8. New Rochelle 9. Mount Vernon 10. Schenectady\n");
            }
            else if (state_choice == 5) { // ILLINOIS
                printf("🏙️  Top 10 Cities in ILLINOIS:\n");
                printf("1. Chicago     2. Aurora      3. Joliet      4. Naperville   5. Rockford\n");
                printf("6. Springfield 7. Elgin       8. Peoria      9. Champaign    10. Waukegan\n");
            }
            else if (state_choice == 6) { // PENNSYLVANIA
                printf("🏙️  Top 10 Cities in PENNSYLVANIA:\n");
                printf("1. Philadelphia 2. Pittsburgh 3. Allentown   4. Erie         5. Reading\n");
                printf("6. Scranton    7. Bethlehem   8. Lancaster   9. Harrisburg   10. York\n");
            }
            else if (state_choice == 7) { // OHIO
                printf("🏙️  Top 10 Cities in OHIO:\n");
                printf("1. Columbus    2. Cleveland   3. Cincinnati  4. Toledo       5. Akron\n");
                printf("6. Dayton      7. Parma       8. Canton      9. Youngstown   10. Lorain\n");
            }
            else if (state_choice == 8) { // GEORGIA
                printf("🏙️  Top 10 Cities in GEORGIA:\n");
                printf("1. Atlanta     2. Augusta     3. Columbus    4. Macon        5. Savannah\n");
                printf("6. Athens      7. Sandy Springs 8. Roswell   9. Johns Creek  10. Warner Robins\n");
            }
            else if (state_choice == 9) { // NORTH CAROLINA
                printf("🏙️  Top 10 Cities in N. CAROLINA:\n");
                printf("1. Charlotte   2. Raleigh     3. Greensboro  4. Durham       5. Winston-Salem\n");
                printf("6. Fayetteville 7. Cary       8. Wilmington  9. High Point   10. Concord\n");
            }
            else if (state_choice == 10) { // MICHIGAN
                printf("🏙️  Top 10 Cities in MICHIGAN:\n");
                printf("1. Detroit     2. Grand Rapids 3. Warren     4. Sterling Heights 5. Ann Arbor\n");
                printf("6. Lansing     7. Flint       8. Dearborn    9. Livonia      10. Troy\n");
            }
            else {
                printf("⚠️ Invalid State Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America\n");
                printf(">> Country: USA\n");
                printf(">> State Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 2) { // CANADA
            int state_choice, city_choice;
            
            printf(">> CANADA: Select a Province/Territory (1-10)\n");
            printf("1. Ontario         2. Quebec          3. British Columbia\n");
            printf("4. Alberta         5. Manitoba        6. Saskatchewan\n");
            printf("7. Nova Scotia     8. New Brunswick   9. Newfoundland\n");
            printf("10. PEI (Prince Edward Island)\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ONTARIO
                printf("🏙️  Top 10 Cities in ONTARIO:\n");
                printf("1. Toronto    2. Ottawa     3. Mississauga 4. Brampton   5. Hamilton\n");
                printf("6. London     7. Markham    8. Vaughan     9. Kitchener  10. Windsor\n");
            } 
            else if (state_choice == 2) { // QUEBEC
                printf("🏙️  Top 10 Cities in QUEBEC:\n");
                printf("1. Montreal   2. Quebec City 3. Laval      4. Gatineau   5. Longueuil\n");
                printf("6. Sherbrooke 7. Levis      8. Saguenay    9. Trois-Rivieres 10. Terrebonne\n");
            }
            else if (state_choice == 3) { // BRITISH COLUMBIA
                printf("🏙️  Top 10 Cities in BRITISH COLUMBIA:\n");
                printf("1. Vancouver  2. Surrey      3. Burnaby    4. Richmond   5. Abbotsford\n");
                printf("6. Coquitlam  7. Kelowna     8. Langley    9. Saanich    10. Victoria\n");
            }
            else if (state_choice == 4) { // ALBERTA
                printf("🏙️  Top 10 Cities in ALBERTA:\n");
                printf("1. Calgary    2. Edmonton    3. Red Deer   4. Lethbridge 5. St. Albert\n");
                printf("6. Medicine Hat 7. Grande Prairie 8. Airdrie 9. Spruce Grove 10. Leduc\n");
            }
            else if (state_choice == 5) { // MANITOBA
                printf("🏙️  Top 10 Cities in MANITOBA:\n");
                printf("1. Winnipeg   2. Brandon     3. Steinbach  4. Thompson   5. Portage la Prairie\n");
                printf("6. Winkler    7. Selkirk     8. Morden     9. Dauphin    10. The Pas\n");
            }
            else if (state_choice == 6) { // SASKATCHEWAN
                printf("🏙️  Top 10 Cities in SASKATCHEWAN:\n");
                printf("1. Saskatoon  2. Regina      3. Prince Albert 4. Moose Jaw 5. Swift Current\n");
                printf("6. Yorkton    7. North Battleford 8. Estevan 9. Weyburn 10. Lloydminster\n");
            }
            else if (state_choice == 7) { // NOVA SCOTIA
                printf("🏙️  Top 10 Cities/Towns in NOVA SCOTIA:\n");
                printf("1. Halifax    2. Sydney      3. Dartmouth  4. Truro      5. New Glasgow\n");
                printf("6. Glace Bay  7. Kentville   8. Amherst    9. Bridgewater 10. Yarmouth\n");
            }
            else if (state_choice == 8) { // NEW BRUNSWICK
                printf("🏙️  Top 10 Cities in NEW BRUNSWICK:\n");
                printf("1. Moncton    2. Saint John  3. Fredericton 4. Dieppe    5. Riverview\n");
                printf("6. Quispamsis 7. Miramichi   8. Edmundston 9. Bathurst   10. Rothesay\n");
            }
            else if (state_choice == 9) { // NEWFOUNDLAND AND LABRADOR
                printf("🏙️  Top 10 Cities/Towns in NEWFOUNDLAND:\n");
                printf("1. St. John's 2. Mount Pearl 3. Paradise   4. Conception Bay 5. Corner Brook\n");
                printf("6. Grand Falls 7. Gander     8. Portugal Cove 9. Torbay  10. Labrador City\n");
            }
            else if (state_choice == 10) { // PRINCE EDWARD ISLAND
                printf("🏙️  Top 10 Areas in PEI:\n");
                printf("1. Charlottetown 2. Summerside 3. Stratford 4. Cornwall  5. Three Rivers\n");
                printf("6. Kensington 7. Souris      8. Alberton   9. Tignish    10. Borden-Carleton\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America\n");
                printf(">> Country: Canada\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 3) { // MEXICO
            int state_choice, city_choice;
            
            printf(">> MEXICO: Select a State (1-10)\n");
            printf("1. Mexico City    2. Jalisco         3. Veracruz\n");
            printf("4. Puebla         5. Guanajuato      6. Nuevo Leon\n");
            printf("7. Chiapas        8. Michoacan       9. Oaxaca\n");
            printf("10. Guerrero\n");
            
            printf("\nENTER STATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // MEXICO CITY (CDMX)
                printf("🏙️  Top 10 Boroughs in MEXICO CITY:\n");
                printf("1. Iztapalapa  2. Gustavo Madero 3. Alvaro Obregon 4. Tlalpan    5. Coyoacan\n");
                printf("6. Cuauhtemoc  7. Venustiano     8. Azcapotzalco   9. Xochimilco 10. Miguel Hidalgo\n");
            } 
            else if (state_choice == 2) { // JALISCO
                printf("🏙️  Top 10 Cities in JALISCO:\n");
                printf("1. Guadalajara 2. Zapopan     3. Tlaquepaque   4. Tonala     5. Puerto Vallarta\n");
                printf("6. Tlajomulco  7. El Salto    8. Lagos de Moreno 9. Tepatitlan 10. Zapotlan\n");
            }
            else if (state_choice == 3) { // VERACRUZ
                printf("🏙️  Top 10 Cities in VERACRUZ:\n");
                printf("1. Veracruz City 2. Xalapa     3. Coatzacoalcos 4. Cordoba    5. Poza Rica\n");
                printf("6. Orizaba     7. Minatitlan  8. Tuxpan        9. Boca del Rio 10. Papantla\n");
            }
            else if (state_choice == 4) { // PUEBLA
                printf("🏙️  Top 10 Cities in PUEBLA:\n");
                printf("1. Puebla City 2. Tehuacan    3. Cholula       4. Atlixco    5. San Martin\n");
                printf("6. Huauchinango 7. Teziutlan  8. Amozoc        9. Cuautlancingo 10. Zacatlan\n");
            }
            else if (state_choice == 5) { // GUANAJUATO
                printf("🏙️  Top 10 Cities in GUANAJUATO:\n");
                printf("1. Leon        2. Irapuato    3. Celaya        4. Salamanca  5. Guanajuato City\n");
                printf("6. Silao       7. San Miguel  8. Valle de Santiago 9. Cortazar 10. Dolores Hidalgo\n");
            }
            else if (state_choice == 6) { // NUEVO LEON
                printf("🏙️  Top 10 Cities in NUEVO LEON:\n");
                printf("1. Monterrey   2. Guadalupe   3. Apodaca       4. San Nicolas 5. Santa Catarina\n");
                printf("6. Escobedo    7. San Pedro   8. Juarez        9. Garcia     10. Cadereyta\n");
            }
            else if (state_choice == 7) { // CHIAPAS
                printf("🏙️  Top 10 Cities in CHIAPAS:\n");
                printf("1. Tuxtla      2. Tapachula   3. San Cristobal 4. Comitan    5. Chiapa de Corzo\n");
                printf("6. Palenque    7. Tonala      8. Cintalapa     9. Ocosingo   10. Villaflores\n");
            }
            else if (state_choice == 8) { // MICHOACAN
                printf("🏙️  Top 10 Cities in MICHOACAN:\n");
                printf("1. Morelia     2. Uruapan     3. Zamora        4. Lazaro Cardenas 5. Zitacuaro\n");
                printf("6. Apatzingan  7. La Piedad   8. Hidalgo       9. Patzcuaro  10. Sahuayo\n");
            }
            else if (state_choice == 9) { // OAXACA
                printf("🏙️  Top 10 Cities in OAXACA:\n");
                printf("1. Oaxaca City 2. Juchitan    3. Tuxtepec      4. Salina Cruz 5. Huajuapan\n");
                printf("6. Tehuantepec 7. Pochutla    8. Huatulco      9. Puerto Escondido 10. Tlacolula\n");
            }
            else if (state_choice == 10) { // GUERRERO
                printf("🏙️  Top 10 Cities in GUERRERO:\n");
                printf("1. Acapulco    2. Chilpancingo 3. Iguala       4. Zihuatanejo 5. Taxco\n");
                printf("6. Tixtla      7. Chilapa     8. Tlapa         9. Ometepec   10. Coyuca\n");
            }
            else {
                printf("⚠️ Invalid State Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America\n");
                printf(">> Country: Mexico\n");
                printf(">> State Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 4) { // CUBA
            int state_choice, city_choice;
            
            printf(">> CUBA: Select a Province (1-10)\n");
            printf("1. Havana          2. Santiago        3. Holguin\n");
            printf("4. Villa Clara     5. Camaguey        6. Matanzas\n");
            printf("7. Pinar del Rio   8. Las Tunas       9. Artemisa\n");
            printf("10. Granma\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // HAVANA (La Habana)
                printf("🏙️  Top 10 Municipalities in HAVANA:\n");
                printf("1. Old Havana  2. Vedado      3. Miramar     4. Centro Habana 5. Playa\n");
                printf("6. Guanabacoa  7. Boyeros     8. Diez de Octubre 9. Marianao  10. Cotorro\n");
            } 
            else if (state_choice == 2) { // SANTIAGO DE CUBA
                printf("🏙️  Top 10 Cities/Towns in SANTIAGO:\n");
                printf("1. Santiago City 2. Palma Soriano 3. Contramaestre 4. San Luis 5. Songo-La Maya\n");
                printf("6. El Cobre    7. Mella       8. Cruce de los Baños 9. Chivirico 10. Siboney\n");
            }
            else if (state_choice == 3) { // HOLGUIN
                printf("🏙️  Top 10 Cities in HOLGUIN:\n");
                printf("1. Holguin City 2. Moa         3. Banes       4. Mayari      5. Gibara\n");
                printf("6. Cueto       7. Urbano Noris 8. Sagua de Tanamo 9. Calixto Garcia 10. Antilla\n");
            }
            else if (state_choice == 4) { // VILLA CLARA
                printf("🏙️  Top 10 Cities in VILLA CLARA:\n");
                printf("1. Santa Clara 2. Sagua la Grande 3. Placetas  4. Caibarien   5. Remedios\n");
                printf("6. Camajuani   7. Santo Domingo 8. Ranchuelo  9. Corralillo  10. Manicaragua\n");
            }
            else if (state_choice == 5) { // CAMAGUEY
                printf("🏙️  Top 10 Cities in CAMAGUEY:\n");
                printf("1. Camaguey City 2. Florida    3. Nuevitas    4. Vertientes  5. Guaimaro\n");
                printf("6. Santa Cruz  7. Minas       8. Sibanicu    9. Jimaguayu   10. Esmeralda\n");
            }
            else if (state_choice == 6) { // MATANZAS
                printf("🏙️  Top 10 Cities in MATANZAS:\n");
                printf("1. Matanzas City 2. Varadero   3. Cardenas    4. Colon       5. Jovellanos\n");
                printf("6. Jagüey Grande 7. Marti      8. Perico      9. Limonar     10. Union de Reyes\n");
            }
            else if (state_choice == 7) { // PINAR DEL RIO
                printf("🏙️  Top 10 Cities in PINAR DEL RIO:\n");
                printf("1. Pinar City  2. Viñales     3. Consolacion 4. San Juan    5. Guane\n");
                printf("6. Mantua      7. Los Palacios 8. Sandino     9. Minas       10. La Palma\n");
            }
            else if (state_choice == 8) { // LAS TUNAS
                printf("🏙️  Top 10 Cities in LAS TUNAS:\n");
                printf("1. Las Tunas City 2. Puerto Padre 3. Jobabo   4. Colombia    5. Amancio\n");
                printf("6. Majibacoa   7. Manati      8. Menendez    9. Elia        10. Bartle\n");
            }
            else if (state_choice == 9) { // ARTEMISA
                printf("🏙️  Top 10 Cities in ARTEMISA:\n");
                printf("1. Artemisa City 2. Mariel     3. Bauta       4. San Antonio 5. Bahia Honda\n");
                printf("6. Güira       7. Guanajay    8. Caimito     9. Candelaria  10. San Cristobal\n");
            }
            else if (state_choice == 10) { // GRANMA
                printf("🏙️  Top 10 Cities in GRANMA:\n");
                printf("1. Bayamo      2. Manzanillo  3. Jiguaní     4. Niquero     5. Campechuela\n");
                printf("6. Guisa       7. Media Luna  8. Yara        9. Bartolome Maso 10. Rio Cauto\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/MUNICIPALITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America (Caribbean)\n");
                printf(">> Country: Cuba\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 5) { // PANAMA
            int state_choice, city_choice;
            
            printf(">> PANAMA: Select a Province/Region (1-10)\n");
            printf("1. Panama          2. Chiriqui        3. West Panama\n");
            printf("4. Colon           5. Cocle           6. Veraguas\n");
            printf("7. Herrera         8. Los Santos      9. Bocas del Toro\n");
            printf("10. Darien\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // PANAMA (Province & Capital City)
                printf("🏙️  Top 10 Districts/Areas in PANAMA:\n");
                printf("1. Panama City 2. San Miguelito 3. Chepo      4. Balboa      5. Casco Viejo\n");
                printf("6. Bella Vista 7. Juan Diaz   8. Bethania    9. Ancon       10. Pacora\n");
            } 
            else if (state_choice == 2) { // CHIRIQUI
                printf("🏙️  Top 10 Cities/Districts in CHIRIQUI:\n");
                printf("1. David City  2. Boquete     3. Bugaba     4. Volcan      5. Puerto Armuelles\n");
                printf("6. Dolega      7. Baru        8. Alanje     9. Gualaca     10. Remedios\n");
            }
            else if (state_choice == 3) { // WEST PANAMA (Panama Oeste)
                printf("🏙️  Top 10 Cities in WEST PANAMA:\n");
                printf("1. La Chorrera 2. Arraijan    3. Chame       4. Capira      5. San Carlos\n");
                printf("6. Coronado    7. Gorgona     8. Vacamonte   9. Veracruz    10. Puerto Caimito\n");
            }
            else if (state_choice == 4) { // COLON
                printf("🏙️  Top 10 Cities/Districts in COLON:\n");
                printf("1. Colon City  2. Portobelo   3. Chagres     4. Donoso      5. Santa Isabel\n");
                printf("6. Sabanitas   7. Buena Vista 8. Cristobal   9. Escobal     10. Miguel de la Borda\n");
            }
            else if (state_choice == 5) { // COCLE
                printf("🏙️  Top 10 Cities/Districts in COCLE:\n");
                printf("1. Penonome    2. Anton       3. Nata        4. Ola         5. Aguadulce\n");
                printf("6. La Pintada  7. El Valle    8. Rio Hato    9. Farallon    10. Pocrí\n");
            }
            else if (state_choice == 6) { // VERAGUAS
                printf("🏙️  Top 10 Cities/Districts in VERAGUAS:\n");
                printf("1. Santiago    2. Atalaya     3. Calobre     4. Cañazas     5. La Mesa\n");
                printf("6. Las Palmas  7. Montijo     8. Rio de Jesus 9. Santa Fe   10. Sona\n");
            }
            else if (state_choice == 7) { // HERRERA
                printf("🏙️  Top 10 Cities/Districts in HERRERA:\n");
                printf("1. Chitre      2. Las Minas   3. Los Pozos   4. Ocu         5. Parita\n");
                printf("6. Pese        7. Santa Maria 8. Monagrillo  9. La Arena    10. Llano Bonito\n");
            }
            else if (state_choice == 8) { // LOS SANTOS
                printf("🏙️  Top 10 Cities/Districts in LOS SANTOS:\n");
                printf("1. Las Tablas  2. Guarare     3. Los Santos  4. Macaracas   5. Pedasi\n");
                printf("6. Pocrí       7. Tonosi      8. Venao       9. Santo Domingo 10. Canajagua\n");
            }
            else if (state_choice == 9) { // BOCAS DEL TORO
                printf("🏙️  Top 10 Cities/Areas in BOCAS DEL TORO:\n");
                printf("1. Bocas Town  2. Changuinola 3. Chiriqui Grande 4. Almirante 5. Bastimentos\n");
                printf("6. Isla Colon  7. Isla Carenero 8. Carenero   9. Guabito     10. Punta Laurel\n");
            }
            else if (state_choice == 10) { // DARIEN
                printf("🏙️  Top 10 Areas/Towns in DARIEN:\n");
                printf("1. La Palma    2. El Real     3. Meteti      4. Yaviza      5. Sambu\n");
                printf("6. Garachine   7. Chepigana   8. Pinogana    9. Jaqué       10. Santa Fe\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/DISTRICT NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America (Central America)\n");
                printf(">> Country: Panama\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 6) { // JAMAICA
            int state_choice, city_choice;
            
            printf(">> JAMAICA: Select a Parish (1-10)\n");
            printf("1. St. Andrew      2. St. Catherine   3. Clarendon\n");
            printf("4. St. James       5. St. Ann         6. St. Elizabeth\n");
            printf("7. Manchester      8. Westmoreland    9. St. Mary\n");
            printf("10. Portland\n");
            
            printf("\nENTER PARISH NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ST. ANDREW (Kingston Metropolitan Area)
                printf("🏙️  Top 10 Areas in ST. ANDREW:\n");
                printf("1. Half Way Tree 2. Cross Roads 3. Constant Spring 4. Liguanea 5. Stony Hill\n");
                printf("6. Gordon Town 7. August Town 8. Barbican    9. Red Hills  10. Norbrook\n");
            } 
            else if (state_choice == 2) { // ST. CATHERINE
                printf("🏙️  Top 10 Cities/Towns in ST. CATHERINE:\n");
                printf("1. Spanish Town 2. Portmore   3. Old Harbour 4. Linstead   5. Bog Walk\n");
                printf("6. Ewarton     7. Gregory Park 8. Central Village 9. Hellshire 10. Caymanas\n");
            }
            else if (state_choice == 3) { // CLARENDON
                printf("🏙️  Top 10 Cities/Towns in CLARENDON:\n");
                printf("1. May Pen     2. Chapelton   3. Lionel Town 4. Frankfield 5. Hayes\n");
                printf("6. Spaldings   7. Kellits     8. Rock River  9. Milk River 10. Race Course\n");
            }
            else if (state_choice == 4) { // ST. JAMES
                printf("🏙️  Top 10 Areas in ST. JAMES:\n");
                printf("1. Montego Bay 2. Cambridge   3. Catadupa    4. Granville  5. Adelphi\n");
                printf("6. Rose Hall   7. Reading     8. Ironshore   9. Montpelier 10. Anchovy\n");
            }
            else if (state_choice == 5) { // ST. ANN
                printf("🏙️  Top 10 Cities/Towns in ST. ANN:\n");
                printf("1. Ocho Rios   2. St. Ann's Bay 3. Brown's Town 4. Discovery Bay 5. Runaway Bay\n");
                printf("6. Claremont   7. Moneague    8. Alexandria  9. Bamboo     10. Watt Town\n");
            }
            else if (state_choice == 6) { // ST. ELIZABETH
                printf("🏙️  Top 10 Cities/Towns in ST. ELIZABETH:\n");
                printf("1. Black River 2. Santa Cruz  3. Balaclava   4. Junction   5. Malvern\n");
                printf("6. Lacovia     7. Maggotty    8. Bull Savanna 9. Southfield 10. Middle Quarters\n");
            }
            else if (state_choice == 7) { // MANCHESTER
                printf("🏙️  Top 10 Cities/Towns in MANCHESTER:\n");
                printf("1. Mandeville  2. Christiana  3. Porus       4. Williamsfield 5. Mile Gully\n");
                printf("6. Newport     7. Alligator Pond 8. Pratville 9. Royal Flat 10. Kendal\n");
            }
            else if (state_choice == 8) { // WESTMORELAND
                printf("🏙️  Top 10 Cities/Towns in WESTMORELAND:\n");
                printf("1. Savanna-la-Mar 2. Negril   3. Grange Hill 4. Little London 5. Petersfield\n");
                printf("6. Whitehouse  7. Bethel Town 8. Bluefields  9. Frome      10. Sheffield\n");
            }
            else if (state_choice == 9) { // ST. MARY
                printf("🏙️  Top 10 Cities/Towns in ST. MARY:\n");
                printf("1. Port Maria  2. Annotto Bay 3. Oracabessa  4. Highgate   5. Gayle\n");
                printf("6. Richmond    7. Guy's Hill  8. Castleton   9. Boscobel   10. Islington\n");
            }
            else if (state_choice == 10) { // PORTLAND
                printf("🏙️  Top 10 Cities/Towns in PORTLAND:\n");
                printf("1. Port Antonio 2. Buff Bay   3. Hope Bay    4. Manchioneal 5. Moore Town\n");
                printf("6. Fairy Hill  7. Long Bay    8. Port Morant 9. St. Margaret's Bay 10. Skibo\n");
            }
            else {
                printf("⚠️ Invalid Parish Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/TOWN NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America (Caribbean)\n");
                printf(">> Country: Jamaica\n");
                printf(">> Parish Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 7) { // COSTA RICA
            int state_choice, city_choice;
            
            printf(">> COSTA RICA: Select a Province (1-7)\n");
            printf("1. San Jose       2. Alajuela       3. Cartago\n");
            printf("4. Heredia        5. Guanacaste     6. Puntarenas\n");
            printf("7. Limon\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // SAN JOSE
                printf("🏙️  Top 10 Areas in SAN JOSE:\n");
                printf("1. San Jose City 2. Escazu     3. Desamparados 4. Puriscal   5. Tibas\n");
                printf("6. Moravia      7. Santa Ana   8. Goicoechea  9. Perez Zeledon 10. Coronado\n");
            } 
            else if (state_choice == 2) { // ALAJUELA
                printf("🏙️  Top 10 Areas in ALAJUELA:\n");
                printf("1. Alajuela City 2. San Ramon  3. Grecia      4. San Carlos 5. Atenas\n");
                printf("6. Naranjo      7. Palmares    8. Poas        9. Orotina    10. Guatuso\n");
            }
            else if (state_choice == 3) { // CARTAGO
                printf("🏙️  Top 10 Areas in CARTAGO:\n");
                printf("1. Cartago City  2. Paraiso    3. La Union    4. Jimenez    5. Turrialba\n");
                printf("6. Alvarado      7. Oreamuno   8. El Guarco   9. Pacayas    10. Tres Rios\n");
            }
            else if (state_choice == 4) { // HEREDIA
                printf("🏙️  Top 10 Areas in HEREDIA:\n");
                printf("1. Heredia City  2. Barva      3. Santo Domingo 4. Santa Barbara 5. San Rafael\n");
                printf("6. San Isidro    7. Belen      8. Flores      9. San Pablo  10. Sarapiqui\n");
            }
            else if (state_choice == 5) { // GUANACASTE
                printf("🏙️  Top 10 Areas in GUANACASTE:\n");
                printf("1. Liberia       2. Nicoya     3. Santa Cruz  4. Bagaces    5. Cañas\n");
                printf("6. Abangares     7. Tilaran    8. Nandayure   9. La Cruz    10. Hojancha\n");
            }
            else if (state_choice == 6) { // PUNTARENAS
                printf("🏙️  Top 10 Areas in PUNTARENAS:\n");
                printf("1. Puntarenas City 2. Esparza  3. Buenos Aires 4. Montes de Oro 5. Osa\n");
                printf("6. Quepos        7. Golfito    8. Coto Brus   9. Parrita    10. Garabito\n");
            }
            else if (state_choice == 7) { // LIMON
                printf("🏙️  Top 10 Areas in LIMON:\n");
                printf("1. Limon City    2. Pococí     3. Siquirres   4. Talamanca  5. Matina\n");
                printf("6. Guacimo       7. Puerto Viejo 8. Cahuita    9. Tortuguero 10. Bribri\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/AREA NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America (Central America)\n");
                printf(">> Country: Costa Rica\n");
                printf(">> Province Code: %d, Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }
        
        else if (country_choice == 8) { // GUATEMALA
            int state_choice, city_choice;
            
            printf(">> GUATEMALA: Select a Department (1-10)\n");
            printf("1. Guatemala      2. Huehuetenango  3. Alta Verapaz\n");
            printf("4. San Marcos     5. Quiche         6. Quetzaltenango\n");
            printf("7. Escuintla      8. Suchitepequez  9. Totonicapan\n");
            printf("10. Solola\n");
            
            printf("\nENTER DEPARTMENT NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // GUATEMALA (Department)
                printf("🏙️  Top 10 Areas in GUATEMALA (Dept):\n");
                printf("1. Guatemala City 2. Mixco       3. Villa Nueva 4. Santa Catarina 5. San Juan\n");
                printf("6. San Jose Pinula 7. Amatitlan  8. Chinautla   9. Fraijanes    10. Petapa\n");
            } 
            else if (state_choice == 2) { // HUEHUETENANGO
                printf("🏙️  Top 10 Areas in HUEHUETENANGO:\n");
                printf("1. Huehuetenango City 2. Chiantla 3. Jacaltenango 4. Soloma    5. Cuilco\n");
                printf("6. Barillas     7. Aguacatan   8. San Mateo   9. Todos Santos 10. La Libertad\n");
            }
            else if (state_choice == 3) { // ALTA VERAPAZ
                printf("🏙️  Top 10 Areas in ALTA VERAPAZ:\n");
                printf("1. Coban        2. San Pedro Carcha 3. Chamelco 4. Senahu     5. Cahabon\n");
                printf("6. Panzos       7. Chisec      8. Tucuru      9. Lanquin     10. Tactic\n");
            }
            else if (state_choice == 4) { // SAN MARCOS
                printf("🏙️  Top 10 Areas in SAN MARCOS:\n");
                printf("1. San Marcos City 2. San Pedro Sac. 3. Malacatan 4. Ayutla    5. Catarina\n");
                printf("6. Tejutla      7. Tajumulco   8. El Tumbador 9. Pajapita    10. Comitancillo\n");
            }
            else if (state_choice == 5) { // QUICHE
                printf("🏙️  Top 10 Areas in QUICHE:\n");
                printf("1. Santa Cruz   2. Chichicastenango 3. Joyabaj 4. Nebaj      5. Zacualpa\n");
                printf("6. Cunen        7. Ixcan       8. Sacapulas   9. Uspantan    10. Chicaman\n");
            }
            else if (state_choice == 6) { // QUETZALTENANGO
                printf("🏙️  Top 10 Areas in QUETZALTENANGO:\n");
                printf("1. Quetzaltenango City 2. Coatepeque 3. Salcaja 4. Cantel    5. Olintepeque\n");
                printf("6. San Juan Ostun. 7. Colomba  8. San Carlos Sija 9. Almolonga 10. Zunil\n");
            }
            else if (state_choice == 7) { // ESCUINTLA
                printf("🏙️  Top 10 Areas in ESCUINTLA:\n");
                printf("1. Escuintla City 2. Santa Lucia 3. Tiquisate  4. Puerto San Jose 5. Palin\n");
                printf("6. San Vicente  7. La Gomera   8. Masagua     9. Guanagazapa 10. Siquinala\n");
            }
            else if (state_choice == 8) { // SUCHITEPEQUEZ
                printf("🏙️  Top 10 Areas in SUCHITEPEQUEZ:\n");
                printf("1. Mazatenango  2. Cuyotenango 3. Patulul    4. Chicacao    5. San Antonio\n");
                printf("6. Samayac      7. San Bernardino 8. Rio Bravo 9. Santo Tomas 10. Zunilito\n");
            }
            else if (state_choice == 9) { // TOTONICAPAN
                printf("🏙️  Top 10 Areas in TOTONICAPAN:\n");
                printf("1. Totonicapan City 2. San Cristobal 3. Momostenango 4. San Francisco 5. Santa Maria\n");
                printf("6. San Bartolo  7. San Andres  8. Santa Lucia 9. Paquix      10. Chuisuc\n");
            }
            else if (state_choice == 10) { // SOLOLA
                printf("🏙️  Top 10 Areas in SOLOLA:\n");
                printf("1. Solola City  2. Panajachel  3. Santiago Atitlan 4. San Lucas Toliman 5. Nahuala\n");
                printf("6. Santa Catarina 7. San Pedro  8. San Juan    9. San Marcos  10. Santa Cruz\n");
            }
            else {
                printf("⚠️ Invalid Department Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/MUNICIPALITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America (Central America)\n");
                printf(">> Country: Guatemala\n");
                printf(">> Department Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 9) { // BAHAMAS
            int state_choice, city_choice;
            
            printf(">> BAHAMAS: Select an Island/District (1-10)\n");
            printf("1. New Providence 2. Grand Bahama   3. Abaco\n");
            printf("4. Eleuthera      5. Andros         6. Exuma\n");
            printf("7. Long Island    8. Bimini         9. Cat Island\n");
            printf("10. Inagua\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // NEW PROVIDENCE (Contains Capital Nassau)
                printf("🏙️  Top 10 Areas in NEW PROVIDENCE:\n");
                printf("1. Nassau City 2. Paradise Is. 3. Lyford Cay  4. Cable Beach 5. Fox Hill\n");
                printf("6. Adelaide    7. Gambier Vill. 8. Sea Breeze  9. Yamacraw    10. South Beach\n");
            } 
            else if (state_choice == 2) { // GRAND BAHAMA
                printf("🏙️  Top 10 Areas in GRAND BAHAMA:\n");
                printf("1. Freeport    2. Lucaya       3. West End    4. High Rock   5. Eight Mile Rock\n");
                printf("6. McLean's Town 7. Smith's Point 8. Pinder's Point 9. Pelican Point 10. Xanadu\n");
            }
            else if (state_choice == 3) { // ABACO
                printf("🏙️  Top 10 Areas in ABACO:\n");
                printf("1. Marsh Harbour 2. Hope Town  3. Green Turtle Cay 4. Treasure Cay 5. Man-O-War Cay\n");
                printf("6. Sandy Point  7. Cooper's Town 8. Cherokee Sound 9. Guana Cay 10. Little Harbour\n");
            }
            else if (state_choice == 4) { // ELEUTHERA
                printf("🏙️  Top 10 Areas in ELEUTHERA:\n");
                printf("1. Governor's Harb. 2. Harbour Is. 3. Spanish Wells 4. Rock Sound 5. Tarpum Bay\n");
                printf("6. Gregory Town 7. Alice Town   8. Hatchet Bay 9. Bannerman Town 10. Current\n");
            }
            else if (state_choice == 5) { // ANDROS
                printf("🏙️  Top 10 Areas in ANDROS:\n");
                printf("1. Andros Town 2. Nicholl's Town 3. Congo Town 4. Kemps Bay  5. Fresh Creek\n");
                printf("6. Stafford Creek 7. Staniard Creek 8. Red Bays 9. Morgan's Bluff 10. Behring Point\n");
            }
            else if (state_choice == 6) { // EXUMA
                printf("🏙️  Top 10 Areas in EXUMA:\n");
                printf("1. George Town 2. Staniel Cay  3. Little Exuma 4. Rolleville  5. Steventon\n");
                printf("6. Stocking Is. 7. Black Point  8. Farmer's Cay 9. Forbes Hill 10. Moss Town\n");
            }
            else if (state_choice == 7) { // LONG ISLAND
                printf("🏙️  Top 10 Areas in LONG ISLAND:\n");
                printf("1. Clarence Town 2. Deadman's Cay 3. Stella Maris 4. Simms      5. Salt Pond\n");
                printf("6. Buckley's   7. Thompson Bay 8. Roses        9. Seymours    10. Mortimers\n");
            }
            else if (state_choice == 8) { // BIMINI
                printf("🏙️  Top 10 Areas in BIMINI:\n");
                printf("1. Alice Town  2. Bailey Town  3. Porgy Bay   4. North Bimini 5. South Bimini\n");
                printf("6. Gun Cay     7. Cat Cay      8. Ocean Cay   9. Paradise Point 10. Blue Water\n");
            }
            else if (state_choice == 9) { // CAT ISLAND
                printf("🏙️  Top 10 Areas in CAT ISLAND:\n");
                printf("1. Arthur's Town 2. New Bight   3. Old Bight   4. Port Howe   5. Orange Creek\n");
                printf("6. Smith Bay   7. Dumfries     8. Tea Bay     9. Knowles's   10. Moss Town\n");
            }
            else if (state_choice == 10) { // INAGUA
                printf("🏙️  Top 10 Areas in INAGUA:\n");
                printf("1. Matthew Town 2. Northwest Pt 3. Salt Pond   4. Union Creek 5. South Bay\n");
                printf("6. Man-O-War Bay 7. Lantern Head 8. Carmichael  9. Miner's Bay 10. Palmetto Pt\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT AREA/CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America (Caribbean)\n");
                printf(">> Country: Bahamas\n");
                printf(">> Island Code: %d, Area Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 10) { // HONDURAS
            int state_choice, city_choice;
            
            printf(">> HONDURAS: Select a Department (1-10)\n");
            printf("1. Francisco Morazan 2. Cortes          3. Choluteca\n");
            printf("4. Comayagua         5. El Paraiso      6. Atlantida\n");
            printf("7. Yoro              8. Olancho         9. Santa Barbara\n");
            printf("10. Copan\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // FRANCISCO MORAZAN (Contains Capital)
                printf("🏙️  Top 10 Cities/Areas in FRANCISCO MORAZAN:\n");
                printf("1. Tegucigalpa 2. Comayagüela 3. Santa Ana   4. Valle de Angeles 5. Cantarranas\n");
                printf("6. Ojojona     7. Talanga     8. Cedros      9. Lepaterique  10. Tatumbla\n");
            } 
            else if (state_choice == 2) { // CORTES
                printf("🏙️  Top 10 Cities in CORTES:\n");
                printf("1. San Pedro Sula 2. Choloma  3. Puerto Cortes 4. Villanueva  5. La Lima\n");
                printf("6. Santa Cruz  7. San Manuel  8. Pimienta    9. Potrerillos 10. Omoa\n");
            }
            else if (state_choice == 3) { // CHOLUTECA
                printf("🏙️  Top 10 Cities in CHOLUTECA:\n");
                printf("1. Choluteca City 2. Marcovia 3. El Triunfo  4. Pespire     5. Namasigue\n");
                printf("6. Orocuina    7. Morolica    8. Santa Ana   9. San Marcos  10. El Corpus\n");
            }
            else if (state_choice == 4) { // COMAYAGUA
                printf("🏙️  Top 10 Cities in COMAYAGUA:\n");
                printf("1. Comayagua City 2. Siguatepeque 3. Taulabe 4. San Jeronimo 5. Esquias\n");
                printf("6. El Rosario  7. Ajuterique  8. Lejamani    9. Meambar     10. Ojo de Agua\n");
            }
            else if (state_choice == 5) { // EL PARAISO
                printf("🏙️  Top 10 Cities in EL PARAISO:\n");
                printf("1. Danli       2. El Paraiso City 3. Yuscaran 4. Teupasenti  5. Moroceli\n");
                printf("6. Trojes      7. Jacaleapa   8. Alauca      9. San Lucas   10. Soledad\n");
            }
            else if (state_choice == 6) { // ATLANTIDA
                printf("🏙️  Top 10 Cities in ATLANTIDA:\n");
                printf("1. La Ceiba    2. Tela        3. El Porvenir 4. San Francisco 5. Jutiapa\n");
                printf("6. La Masica   7. Esparta     8. Arizona     9. Mezapa      10. San Juan\n");
            }
            else if (state_choice == 7) { // YORO
                printf("🏙️  Top 10 Cities in YORO:\n");
                printf("1. El Progreso 2. Olanchito   3. Yoro City   4. Santa Rita  5. Morazan\n");
                printf("6. Sulaco      7. Victoria    8. Yorito      9. El Negrito  10. Arenal\n");
            }
            else if (state_choice == 8) { // OLANCHO
                printf("🏙️  Top 10 Cities in OLANCHO:\n");
                printf("1. Juticalpa   2. Catacamas   3. Campamento  4. Dulce Nombre 5. Manto\n");
                printf("6. Salama      7. San Esteban 8. Silca       9. Gualaco     10. Concordia\n");
            }
            else if (state_choice == 9) { // SANTA BARBARA
                printf("🏙️  Top 10 Cities in SANTA BARBARA:\n");
                printf("1. Santa Barbara City 2. Quimistan 3. Trinidad 4. Azacualpa 5. Macuelizo\n");
                printf("6. Ilama       7. Gualala     8. Petoa       9. San Nicolas 10. Las Vegas\n");
            }
            else if (state_choice == 10) { // COPAN
                printf("🏙️  Top 10 Cities/Areas in COPAN:\n");
                printf("1. Santa Rosa  2. Copan Ruinas 3. La Entrada 4. Cucuyagua  5. Florida\n");
                printf("6. Corquin     7. Dulce Nombre 8. San Pedro  9. San Juan    10. Vera Cruz\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/MUNICIPALITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: North America\n");
                printf(">> Country: Honduras\n");
                printf(">> Department Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else {
            printf("⚠️ Invalid Country Selection within North America.\n");
        }
    }



    else if (choice == 7) {
        int country_choice;
        
        printf("📍 CONTINENT: SOUTH AMERICA\n");
        printf("TOP 10 COUNTRIES:\n");
        printf("1. Brazil     2. Argentina  3. Colombia\n");
        printf("4. Peru       5. Chile      6. Venezuela\n");
        printf("7. Ecuador    8. Bolivia    9. Paraguay\n");
        printf("10. Uruguay\n");

        printf("\nCHOOSE A COUNTRY (1-10): ");
        scanf("%d", &country_choice);
        printf("------------------------------\n");

        if (country_choice == 1) { // BRAZIL
            int state_choice, city_choice;
            
            printf(">> BRAZIL: Select a State (1-10)\n");
            printf("1. São Paulo      2. Minas Gerais   3. Rio de Janeiro\n");
            printf("4. Bahia          5. Paraná         6. Rio Grande do Sul\n");
            printf("7. Pernambuco     8. Ceará          9. Pará\n");
            printf("10. Santa Catarina\n");
            
            printf("\nENTER STATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // SÃO PAULO
                printf("🏙️  Top 10 Cities in SÃO PAULO:\n");
                printf("1. São Paulo City 2. Guarulhos   3. Campinas    4. São Bernardo 5. Santo André\n");
                printf("6. Osasco      7. Sorocaba    8. Ribeirão Preto 9. São José dos Campos 10. Santos\n");
            } 
            else if (state_choice == 2) { // MINAS GERAIS
                printf("🏙️  Top 10 Cities in MINAS GERAIS:\n");
                printf("1. Belo Horizonte 2. Uberlândia  3. Contagem    4. Juiz de Fora 5. Betim\n");
                printf("6. Montes Claros 7. Ribeirão das Neves 8. Uberaba 9. Governador Valadares 10. Ipatinga\n");
            }
            else if (state_choice == 3) { // RIO DE JANEIRO
                printf("🏙️  Top 10 Cities in RIO DE JANEIRO:\n");
                printf("1. Rio City    2. São Gonçalo 3. Duque de Caxias 4. Nova Iguaçu 5. Niterói\n");
                printf("6. Campos      7. Belford Roxo 8. São João de Meriti 9. Petrópolis 10. Volta Redonda\n");
            }
            else if (state_choice == 4) { // BAHIA
                printf("🏙️  Top 10 Cities in BAHIA:\n");
                printf("1. Salvador    2. Feira de Santana 3. Vitória da Conquista 4. Camaçari 5. Itabuna\n");
                printf("6. Juazeiro    7. Lauro de Freitas 8. Ilhéus 9. Jequié 10. Alagoinhas\n");
            }
            else if (state_choice == 5) { // PARANÁ
                printf("🏙️  Top 10 Cities in PARANÁ:\n");
                printf("1. Curitiba    2. Londrina    3. Maringá     4. Ponta Grossa 5. Cascavel\n");
                printf("6. São José dos Pinhais 7. Foz do Iguaçu 8. Colombo 9. Guarapuava 10. Paranaguá\n");
            }
            else if (state_choice == 6) { // RIO GRANDE DO SUL
                printf("🏙️  Top 10 Cities in RIO GRANDE DO SUL:\n");
                printf("1. Porto Alegre 2. Caxias do Sul 3. Canoas    4. Pelotas     5. Santa Maria\n");
                printf("6. Gravataí    7. Viamão      8. Novo Hamburgo 9. São Leopoldo 10. Rio Grande\n");
            }
            else if (state_choice == 7) { // PERNAMBUCO
                printf("🏙️  Top 10 Cities in PERNAMBUCO:\n");
                printf("1. Recife      2. Jaboatão    3. Olinda      4. Caruaru     5. Petrolina\n");
                printf("6. Paulista    7. Cabo de Santo Agostinho 8. Camaragibe 9. Garanhuns 10. Vitória\n");
            }
            else if (state_choice == 8) { // CEARÁ
                printf("🏙️  Top 10 Cities in CEARÁ:\n");
                printf("1. Fortaleza   2. Caucaia     3. Juazeiro do Norte 4. Maracanaú 5. Sobral\n");
                printf("6. Itapipoca   7. Maranguape  8. Iguatu      9. Quixadá     10. Pacatuba\n");
            }
            else if (state_choice == 9) { // PARÁ
                printf("🏙️  Top 10 Cities in PARÁ:\n");
                printf("1. Belém       2. Ananindeua  3. Santarém    4. Marabá      5. Castanhal\n");
                printf("6. Parauapebas 7. Abaetetuba  8. Cametá      9. Marituba    10. Bragança\n");
            }
            else if (state_choice == 10) { // SANTA CATARINA
                printf("🏙️  Top 10 Cities in SANTA CATARINA:\n");
                printf("1. Joinville   2. Florianópolis 3. Blumenau   4. São José    5. Itajaí\n");
                printf("6. Chapecó     7. Criciúma    8. Jaraguá do Sul 9. Lages      10. Palhoça\n");
            }
            else {
                printf("⚠️ Invalid State Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Brazil\n");
                printf(">> State Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 2) { // ARGENTINA
            int state_choice, city_choice;
            
            printf(">> ARGENTINA: Select a Province (1-10)\n");
            printf("1. Buenos Aires   2. Córdoba         3. Santa Fe\n");
            printf("4. Mendoza        5. Tucumán         6. Entre Ríos\n");
            printf("7. Salta          8. Chaco           9. Corrientes\n");
            printf("10. Misiones\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // BUENOS AIRES (Province & Federal District)
                printf("🏙️  Top 10 Cities/Districts in BUENOS AIRES:\n");
                printf("1. La Plata    2. Mar del Plata 3. Bahía Blanca 4. Merlo      5. Quilmes\n");
                printf("6. Lanús       7. Pilar       8. Tandil      9. Tigre      10. San Nicolás\n");
            } 
            else if (state_choice == 2) { // CÓRDOBA
                printf("🏙️  Top 10 Cities in CÓRDOBA:\n");
                printf("1. Córdoba City 2. Río Cuarto  3. Villa María 4. Carlos Paz 5. San Francisco\n");
                printf("6. Alta Gracia 7. Río Tercero  8. Bell Ville  9. La Calera  10. Villa Dolores\n");
            }
            else if (state_choice == 3) { // SANTA FE
                printf("🏙️  Top 10 Cities in SANTA FE:\n");
                printf("1. Rosario     2. Santa Fe City 3. Rafaela    4. Venado Tuerto 5. Reconquista\n");
                printf("6. S. Lorenzo  7. V. G. Gálvez  8. Santo Tomé 9. Esperanza  10. Casilda\n");
            }
            else if (state_choice == 4) { // MENDOZA
                printf("🏙️  Top 10 Cities in MENDOZA:\n");
                printf("1. Mendoza City 2. San Rafael  3. Godoy Cruz  4. Guaymallén  5. Las Heras\n");
                printf("6. Maipú       7. Luján de Cuyo 8. Rivadavia  9. San Martín  10. Tunuyán\n");
            }
            else if (state_choice == 5) { // TUCUMÁN
                printf("🏙️  Top 10 Cities in TUCUMÁN:\n");
                printf("1. S.M. de Tucumán 2. Yerba Buena 3. Tafí Viejo 4. Concepción 5. Banda del Río\n");
                printf("6. Lules       7. Monteros     8. Aguilares   9. Famaillá   10. Burruyacú\n");
            }
            else if (state_choice == 6) { // ENTRE RÍOS
                printf("🏙️  Top 10 Cities in ENTRE RÍOS:\n");
                printf("1. Paraná      2. Concordia    3. Gualeguaychú 4. Concepción 5. Gualeguay\n");
                printf("6. Villaguay   7. Chajarí      8. Victoria    9. La Paz     10. Diamante\n");
            }
            else if (state_choice == 7) { // SALTA
                printf("🏙️  Top 10 Cities in SALTA:\n");
                printf("1. Salta City  2. Orán         3. Tartagal    4. Gral. Güemes 5. Metán\n");
                printf("6. Rosario Lerma 7. Embarcación 8. Cafayate   9. Pichanal    10. Joaquín V. G.\n");
            }
            else if (state_choice == 8) { // CHACO
                printf("🏙️  Top 10 Cities in CHACO:\n");
                printf("1. Resistencia 2. Sáenz Peña   3. Barranqueras 4. Fontona    5. Villa Ángela\n");
                printf("6. Castelli    7. Charata      8. Las Breñas  9. Machagai   10. Quitilipi\n");
            }
            else if (state_choice == 9) { // CORRIENTES
                printf("🏙️  Top 10 Cities in CORRIENTES:\n");
                printf("1. Corrientes City 2. Goya     3. Paso Libres 4. Curuzú Cuatiá 5. Mercedes\n");
                printf("6. Bella Vista 7. Santo Tomé   8. Ituzaingó   9. Monte Caseros 10. Esquina\n");
            }
            else if (state_choice == 10) { // MISIONES
                printf("🏙️  Top 10 Cities in MISIONES:\n");
                printf("1. Posadas     2. Oberá        3. Eldoardo    4. Iguazú      5. Apóstoles\n");
                printf("6. L.N. Alem   7. Jardín América 8. San Vicente 9. Montecarlo 10. El Soberbio\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Argentina\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 3) { // COLOMBIA
            int state_choice, city_choice;
            
            printf(">> COLOMBIA: Select a Department (1-10)\n");
            printf("1. Antioquia      2. Valle del Cauca 3. Cundinamarca\n");
            printf("4. Santander      5. Atlántico       6. Bolívar\n");
            printf("7. Córdoba        8. Nariño          9. Tolima\n");
            printf("10. Boyacá\n");
            
            printf("\nENTER DEPARTMENT NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ANTIOQUIA
                printf("🏙️  Top 10 Cities in ANTIOQUIA:\n");
                printf("1. Medellín   2. Bello       3. Itagüí     4. Envigado   5. Apartadó\n");
                printf("6. Rionegro   7. Turbo       8. Caucasia   9. Caldas     10. Copacabana\n");
            } 
            else if (state_choice == 2) { // VALLE DEL CAUCA
                printf("🏙️  Top 10 Cities in VALLE DEL CAUCA:\n");
                printf("1. Cali       2. Buenaventura 3. Palmira    4. Tuluá      5. Cartago\n");
                printf("6. Jamundí    7. Buga        8. Yumbo      9. Florida    10. Pradera\n");
            }
            else if (state_choice == 3) { // CUNDINAMARCA (Including Bogotá DC)
                printf("🏙️  Top 10 Cities in CUNDINAMARCA:\n");
                printf("1. Bogotá     2. Soacha      3. Fusagasugá 4. Facatativá 5. Zipaquirá\n");
                printf("6. Chía       7. Girardot    8. Mosquera   9. Madrid     10. Funza\n");
            }
            else if (state_choice == 4) { // SANTANDER
                printf("🏙️  Top 10 Cities in SANTANDER:\n");
                printf("1. Bucaramanga 2. Floridablanca 3. Barrancabermeja 4. Girón 5. Piedecuesta\n");
                printf("6. San Gil    7. Socorro     8. Barbosa    9. Lebrija    10. Sabana de Torres\n");
            }
            else if (state_choice == 5) { // ATLÁNTICO
                printf("🏙️  Top 10 Cities in ATLÁNTICO:\n");
                printf("1. Barranquilla 2. Soledad   3. Malambo    4. Sabanalarga 5. Galapa\n");
                printf("6. Baranoa    7. Puerto Colombia 8. Santo Tomás 9. Palmar 10. Sabanagrande\n");
            }
            else if (state_choice == 6) { // BOLÍVAR
                printf("🏙️  Top 10 Cities in BOLÍVAR:\n");
                printf("1. Cartagena  2. Magangué    3. El Carmen  4. Turbaco    5. Arjona\n");
                printf("6. Mompós     7. María La Baja 8. San Jacinto 9. Santa Rosa 10. Villanueva\n");
            }
            else if (state_choice == 7) { // CÓRDOBA
                printf("🏙️  Top 10 Cities in CÓRDOBA:\n");
                printf("1. Montería   2. Cereté      3. Lorica     4. Sahagún    5. Montelíbano\n");
                printf("6. Tierralta  7. Planeta Rica 8. Ciénaga de Oro 9. Ayapel 10. Chinú\n");
            }
            else if (state_choice == 8) { // NARIÑO
                printf("🏙️  Top 10 Cities in NARIÑO:\n");
                printf("1. Pasto      2. Tumaco      3. Ipiales    4. Samaniego  5. Tuquerres\n");
                printf("6. Barbacoas  7. La Unión    8. Cumbal     9. El Tambo   10. Guaitarilla\n");
            }
            else if (state_choice == 9) { // TOLIMA
                printf("🏙️  Top 10 Cities in TOLIMA:\n");
                printf("1. Ibagué     2. Espinal     3. Chaparral  4. Líbano     5. Melgar\n");
                printf("6. Mariquita  7. Honda       8. Fresno     9. Ortega     10. Guamo\n");
            }
            else if (state_choice == 10) { // BOYACÁ
                printf("🏙️  Top 10 Cities in BOYACÁ:\n");
                printf("1. Tunja      2. Sogamoso    3. Duitama    4. Chiquinquirá 5. Puerto Boyacá\n");
                printf("6. Paipa      7. Moniquirá   8. Samacá     9. Villa de Leyva 10. Garagoa\n");
            }
            else {
                printf("⚠️ Invalid Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Colombia\n");
                printf(">> Department Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 4) { // PERU
            int state_choice, city_choice;
            
            printf(">> PERU: Select a Region (1-10)\n");
            printf("1. Lima           2. Arequipa       3. La Libertad\n");
            printf("4. Piura          5. Cajamarca      6. Puno\n");
            printf("7. Junín          8. Cusco          9. Lambayeque\n");
            printf("10. Áncash\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // LIMA (Province & Region)
                printf("🏙️  Top 10 Districts in LIMA:\n");
                printf("1. Miraflores 2. San Isidro  3. Barranco    4. Santiago Surco 5. San Borja\n");
                printf("6. Callao     7. La Molina   8. Lima Center 9. San Miguel    10. Magdalena\n");
            } 
            else if (state_choice == 2) { // AREQUIPA
                printf("🏙️  Top 10 Cities/Districts in AREQUIPA:\n");
                printf("1. Arequipa City 2. Cayma    3. Yanahuara   4. Mollendo    5. Camana\n");
                printf("6. Majes      7. Cerro Colorado 8. Paucarpata 9. Chivay   10. Aplao\n");
            }
            else if (state_choice == 3) { // LA LIBERTAD
                printf("🏙️  Top 10 Cities in LA LIBERTAD:\n");
                printf("1. Trujillo   2. Huanchaco   3. Víctor Larco 4. El Porvenir 5. Chepén\n");
                printf("6. Pacasmayo  7. Huamachuco  8. Otuzco      9. Virú       10. Chao\n");
            }
            else if (state_choice == 4) { // PIURA
                printf("🏙️  Top 10 Cities in PIURA:\n");
                printf("1. Piura City 2. Sullana     3. Talara      4. Paita       5. Catacaos\n");
                printf("6. Chulucanas 7. Sechura     8. Mancora     9. Huancabamba 10. Ayabaca\n");
            }
            else if (state_choice == 5) { // CAJAMARCA
                printf("🏙️  Top 10 Cities in CAJAMARCA:\n");
                printf("1. Cajamarca City 2. Jaén    3. Chota       4. Cutervo     5. Celendín\n");
                printf("6. Cajabamba  7. Bambamarca  8. San Ignacio 9. Hualgayoc  10. Contumaza\n");
            }
            else if (state_choice == 6) { // PUNO
                printf("🏙️  Top 10 Cities in PUNO:\n");
                printf("1. Puno City  2. Juliaca     3. Azángaro    4. Ayaviri     5. Huancané\n");
                printf("6. Ilave      7. Yunguyo     8. Putina      9. Lampa      10. Desaguadero\n");
            }
            else if (state_choice == 7) { // JUNÍN
                printf("🏙️  Top 10 Cities in JUNÍN:\n");
                printf("1. Huancayo   2. Tarma       3. Jauja       4. La Oroya    5. Chanchamayo\n");
                printf("6. Satipo     7. Concepción  8. Pichanaqui  9. San Ramón  10. Junín City\n");
            }
            else if (state_choice == 8) { // CUSCO
                printf("🏙️  Top 10 Areas in CUSCO:\n");
                printf("1. Cusco City 2. Machu Picchu 3. Ollantaytambo 4. Pisac     5. Urubamba\n");
                printf("6. Sicuani    7. Calca       8. Chinchero   9. Espinar    10. Paucartambo\n");
            }
            else if (state_choice == 9) { // LAMBAYEQUE
                printf("🏙️  Top 10 Cities in LAMBAYEQUE:\n");
                printf("1. Chiclayo   2. Lambayeque City 3. Ferreñafe 4. Olmos     5. Motupe\n");
                printf("6. Monsefú    7. Pimentel    8. Jayanca     9. Illimo     10. Tucume\n");
            }
            else if (state_choice == 10) { // ÁNCASH
                printf("🏙️  Top 10 Cities in ÁNCASH:\n");
                printf("1. Huaraz     2. Chimbote    3. Nuevo Chimbote 4. Caraz     5. Huari\n");
                printf("6. Casma      7. Yungay      8. Pomabamba   9. Recuay     10. Sihuas\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/DISTRICT NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Peru\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 5) { // CHILE
            int state_choice, city_choice;
            
            printf(">> CHILE: Select a Region (1-10)\n");
            printf("1. Metropolitana   2. Valparaíso     3. Biobío\n");
            printf("4. Maule           5. Araucanía      6. O'Higgins\n");
            printf("7. Los Lagos       8. Coquimbo       9. Antofagasta\n");
            printf("10. Los Ríos\n");
            
            printf("\nENTER REGION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // METROPOLITANA (Santiago Area)
                printf("🏙️  Top 10 Communes in METROPOLITANA:\n");
                printf("1. Santiago Center 2. Puente Alto 3. Maipú      4. La Florida  5. Las Condes\n");
                printf("6. Peñalolén    7. Pudahuel    8. Vitacura    9. Providencia 10. Quilicura\n");
            } 
            else if (state_choice == 2) { // VALPARAÍSO
                printf("🏙️  Top 10 Cities/Communes in VALPARAÍSO:\n");
                printf("1. Valparaíso City 2. Viña del Mar 3. Quilpué   4. Villa Alemana 5. Quillota\n");
                printf("6. San Antonio  7. Los Andes   8. San Felipe  9. Concón      10. Quintero\n");
            }
            else if (state_choice == 3) { // BIOBÍO
                printf("🏙️  Top 10 Cities in BIOBÍO:\n");
                printf("1. Concepción   2. Talcahuano  3. San Pedro   4. Los Ángeles 5. Coronel\n");
                printf("6. Hualpén      7. Chiguayante 8. Lota        9. Penco       10. Tomé\n");
            }
            else if (state_choice == 4) { // MAULE
                printf("🏙️  Top 10 Cities in MAULE:\n");
                printf("1. Talca        2. Curicó      3. Linares     4. Constitución 5. Cauquenes\n");
                printf("6. Molina       7. Parral      8. San Javier  9. Teno        10. San Clemente\n");
            }
            else if (state_choice == 5) { // ARAUCANÍA
                printf("🏙️  Top 10 Cities in ARAUCANÍA:\n");
                printf("1. Temuco       2. Padre Las Casas 3. Villarrica 4. Angol     5. Pucón\n");
                printf("6. Lautaro      7. Victoria    8. Nueva Imperial 9. Traiguén  10. Collipulli\n");
            }
            else if (state_choice == 6) { // O'HIGGINS
                printf("🏙️  Top 10 Cities in O'HIGGINS:\n");
                printf("1. Rancagua     2. Machalí     3. Rengo       4. San Fernando 5. Pichilemu\n");
                printf("6. San Vicente  7. Graneros    8. Chimbarongo 9. Mostazal    10. Requínoa\n");
            }
            else if (state_choice == 7) { // LOS LAGOS
                printf("🏙️  Top 10 Cities in LOS LAGOS:\n");
                printf("1. Puerto Montt 2. Osorno      3. Castro      4. Puerto Varas 5. Ancud\n");
                printf("6. Quellón      7. Calbuco     8. Frutillar   9. Llanquihue  10. Purranque\n");
            }
            else if (state_choice == 8) { // COQUIMBO
                printf("🏙️  Top 10 Cities in COQUIMBO:\n");
                printf("1. La Serena    2. Coquimbo City 3. Ovalle     4. Illapel     5. Vicuña\n");
                printf("6. Salamanca    7. Los Vilos   8. Andacollo   9. Combarbalá  10. Canela\n");
            }
            else if (state_choice == 9) { // ANTOFAGASTA
                printf("🏙️  Top 10 Cities in ANTOFAGASTA:\n");
                printf("1. Antofagasta City 2. Calama  3. Tocopilla   4. Taltal      5. Mejillones\n");
                printf("6. San Pedro de Atacama 7. Sierra Gorda 8. Baquedano 9. María Elena 10. Ollagüe\n");
            }
            else if (state_choice == 10) { // LOS RÍOS
                printf("🏙️  Top 10 Cities in LOS RÍOS:\n");
                printf("1. Valdivia     2. La Unión    3. Panguipulli 4. Río Bueno   5. Paillaco\n");
                printf("6. Mariquina    7. Lanco       8. Los Lagos   9. Futrono     10. Máfil\n");
            }
            else {
                printf("⚠️ Invalid Region Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/COMMUNE NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Chile\n");
                printf(">> Region Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 6) { // VENEZUELA
            int state_choice, city_choice;
            
            printf(">> VENEZUELA: Select a State (1-10)\n");
            printf("1. Zulia          2. Miranda        3. Carabobo\n");
            printf("4. Distrito Cap.  5. Lara           6. Aragua\n");
            printf("7. Bolívar        8. Anzoátegui     9. Táchira\n");
            printf("10. Sucre\n");
            
            printf("\nENTER STATE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // ZULIA
                printf("🏙️  Top 10 Cities in ZULIA:\n");
                printf("1. Maracaibo   2. Cabimas     3. San Francisco 4. Ciudad Ojeda 5. Machiques\n");
                printf("6. Mara        7. La Concepción 8. Santa Rita  9. Bachaquero 10. Altagracia\n");
            } 
            else if (state_choice == 2) { // MIRANDA
                printf("🏙️  Top 10 Cities/Areas in MIRANDA:\n");
                printf("1. Los Teques  2. Petare      3. Baruta      4. Chacao     5. El Hatillo\n");
                printf("6. Guarenas    7. Guatire     8. Ocumare     9. Cúa        10. Higuerote\n");
            }
            else if (state_choice == 3) { // CARABOBO
                printf("🏙️  Top 10 Cities in CARABOBO:\n");
                printf("1. Valencia    2. Puerto Cabello 3. Guacara   4. Naguanagua 5. San Diego\n");
                printf("6. Mariara     7. Bejuma      8. Carlos Arvelo 9. Tocuyito  10. Morón\n");
            }
            else if (state_choice == 4) { // DISTRITO CAPITAL (Caracas)
                printf("🏙️  Top 10 Parishes in DISTRITO CAPITAL:\n");
                printf("1. Libertador  2. El Recreo   3. Sucre (Catia) 4. Caricuao   5. El Valle\n");
                printf("6. Antímano    7. La Vega     8. San Juan    9. 23 de Enero 10. Macarao\n");
            }
            else if (state_choice == 5) { // LARA
                printf("🏙️  Top 10 Cities in LARA:\n");
                printf("1. Barquisimeto 2. Cabudare    3. Carora      4. El Tocuyo  5. Quíbor\n");
                printf("6. Duaca       7. Sarare      8. Sanare      9. Siquisique 10. Aguada Grande\n");
            }
            else if (state_choice == 6) { // ARAGUA
                printf("🏙️  Top 10 Cities in ARAGUA:\n");
                printf("1. Maracay     2. Turmero     3. El Limón    4. La Victoria 5. Cagua\n");
                printf("6. Villa de Cura 7. Palo Negro 8. San Mateo  9. El Consejo 10. Ocumare de la Costa\n");
            }
            else if (state_choice == 7) { // BOLÍVAR
                printf("🏙️  Top 10 Cities in BOLÍVAR:\n");
                printf("1. Ciudad Guayana 2. Ciudad Bolívar 3. Upata   4. Caicara    5. Tumeremo\n");
                printf("6. El Callao   7. Guasipati   8. Santa Elena 9. Maripa     10. El Manteco\n");
            }
            else if (state_choice == 8) { // ANZOÁTEGUI
                printf("🏙️  Top 10 Cities in ANZOÁTEGUI:\n");
                printf("1. Barcelona   2. Puerto La Cruz 3. El Tigre  4. Anaco      5. Guanta\n");
                printf("6. Lechería    7. San José de Guanipa 8. Cantaura 9. Puerto Píritu 10. Pariaguán\n");
            }
            else if (state_choice == 9) { // TÁCHIRA
                printf("🏙️  Top 10 Cities in TÁCHIRA:\n");
                printf("1. San Cristóbal 2. Táriba     3. Rubio       4. San Antonio 5. La Grita\n");
                printf("6. Colón       7. Palmira     8. Capacho     9. Ureña      10. Queniquea\n");
            }
            else if (state_choice == 10) { // SUCRE
                printf("🏙️  Top 10 Cities in SUCRE:\n");
                printf("1. Cumaná      2. Carúpano    3. Güiria      4. Casanay     5. Cariaco\n");
                printf("6. Río Caribe  7. El Pilar    8. Cumanacoa   9. Marigüitar 10. Araya\n");
            }
            else {
                printf("⚠️ Invalid State Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Venezuela\n");
                printf(">> State Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 7) { // ECUADOR
            int state_choice, city_choice;
            
            printf(">> ECUADOR: Select a Province (1-10)\n");
            printf("1. Guayas         2. Pichincha      3. Manabí\n");
            printf("4. Azuay          5. Los Ríos       6. El Oro\n");
            printf("7. Tungurahua     8. Loja           9. Chimborazo\n");
            printf("10. Imbabura\n");
            
            printf("\nENTER PROVINCE NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // GUAYAS
                printf("🏙️  Top 10 Cities/Cantons in GUAYAS:\n");
                printf("1. Guayaquil  2. Durán       3. Milagro     4. Daule       5. Samborondón\n");
                printf("6. El Empalme 7. Naranjal    8. Balzar      9. Playas      10. Yaguachi\n");
            } 
            else if (state_choice == 2) { // PICHINCHA
                printf("🏙️  Top 10 Cities/Cantons in PICHINCHA:\n");
                printf("1. Quito      2. Sangolquí   3. Cayambe     4. Machachi    5. Tabacundo\n");
                printf("6. Puerto Quito 7. Pedro Vicente 8. Tumbaco  9. Cumbayá    10. Calderón\n");
            }
            else if (state_choice == 3) { // MANABÍ
                printf("🏙️  Top 10 Cities in MANABÍ:\n");
                printf("1. Portoviejo 2. Manta       3. Chone       4. El Carmen   5. Montecristi\n");
                printf("6. Jipijapa   7. Bahía       8. Calceta     9. Pedernales  10. Flavio Alfaro\n");
            }
            else if (state_choice == 4) { // AZUAY
                printf("🏙️  Top 10 Cities in AZUAY:\n");
                printf("1. Cuenca     2. Gualaceo    3. Paute       4. Santa Isabel 5. Camilo Ponce\n");
                printf("6. Sígsig     7. Girón       8. Chordeleg   9. Nabón       10. Pucará\n");
            }
            else if (state_choice == 5) { // LOS RÍOS
                printf("🏙️  Top 10 Cities in LOS RÍOS:\n");
                printf("1. Quevedo    2. Babahoyo    3. Ventanas    4. Buena Fe    5. Vinces\n");
                printf("6. Valencia   7. Baba        8. Montalvo    9. Puebloviejo 10. Mocache\n");
            }
            else if (state_choice == 6) { // EL ORO
                printf("🏙️  Top 10 Cities in EL ORO:\n");
                printf("1. Machala    2. Pasaje      3. Santa Rosa  4. Huaquillas  5. El Guabo\n");
                printf("6. Piñas      7. Arenillas   8. Zaruma      9. Portovelo   10. Balsas\n");
            }
            else if (state_choice == 7) { // TUNGURAHUA
                printf("🏙️  Top 10 Cities in TUNGURAHUA:\n");
                printf("1. Ambato     2. Baños       3. Pelileo     4. Píllaro     5. Cevallos\n");
                printf("6. Quero      7. Mocha       8. Tisaleo     9. Patate      10. Santa Rosa\n");
            }
            else if (state_choice == 8) { // LOJA
                printf("🏙️  Top 10 Cities in LOJA:\n");
                printf("1. Loja City  2. Catamayo    3. Cariamanga  4. Macará      5. Saraguro\n");
                printf("6. Catacocha  7. Alamor      8. Celica      9. Zapotillo   10. Vilcabamba\n");
            }
            else if (state_choice == 9) { // CHIMBORAZO
                printf("🏙️  Top 10 Cities in CHIMBORAZO:\n");
                printf("1. Riobamba   2. Guano       3. Alausí      4. Colta       5. Cumandá\n");
                printf("6. Guamote     Pallatanga    8. Chambo      9. Penipe      10. Chunchi\n");
            }
            else if (state_choice == 10) { // IMBABURA
                printf("🏙️  Top 10 Cities in IMBABURA:\n");
                printf("1. Ibarra     2. Otavalo     3. Cotacachi   4. Atuntaqui   5. Pimampiro\n");
                printf("6. Urcuquí    7. Antonio Ante 8. Natabuela  9. San Pablo   10. Quiroga\n");
            }
            else {
                printf("⚠️ Invalid Province Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/CANTON NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Ecuador\n");
                printf(">> Province Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 8) { // BOLIVIA
            int state_choice, city_choice;
            
            printf(">> BOLIVIA: Select a Department (1-9)\n");
            printf("1. La Paz         2. Santa Cruz     3. Cochabamba\n");
            printf("4. Potosí         5. Chuquisaca     6. Oruro\n");
            printf("7. Tarija         8. Beni           9. Pando\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // LA PAZ
                printf("🏙️  Top 10 Cities in LA PAZ:\n");
                printf("1. La Paz City  2. El Alto      3. Viacha       4. Caranavi     5. Achacachi\n");
                printf("6. Copacabana   7. Patacamaya   8. Coroico      9. Guanay       10. Laja\n");
            } 
            else if (state_choice == 2) { // SANTA CRUZ
                printf("🏙️  Top 10 Cities in SANTA CRUZ:\n");
                printf("1. Santa Cruz   2. Montero      3. Warnes       4. La Guardia   5. El Torno\n");
                printf("6. Camiri       7. San Ignacio  8. Vallegrande  9. Cotoca       10. Portachuelo\n");
            }
            else if (state_choice == 3) { // COCHABAMBA
                printf("🏙️  Top 10 Cities in COCHABAMBA:\n");
                printf("1. Cochabamba   2. Sacaba       3. Quillacollo  4. Tiquipaya    5. Colcapirhua\n");
                printf("6. Vinto        3. Punata       8. Cliza        9. Mizque       10. Aiquile\n");
            }
            else if (state_choice == 4) { // POTOSÍ
                printf("🏙️  Top 10 Cities in POTOSÍ:\n");
                printf("1. Potosí City  2. Uyuni        3. Llallagua    4. Tupiza       5. Villazón\n");
                printf("6. Uncía        7. Betanzos     8. Cotagaita    9. Colcha K     10. Vitichi\n");
            }
            else if (state_choice == 5) { // CHUQUISACA
                printf("🏙️  Top 10 Cities in CHUQUISACA:\n");
                printf("1. Sucre        2. Camargo      3. Monteagudo   4. Padilla      5. Tarabuco\n");
                printf("6. Muyupampa    7. Villa Abecia 8. Zudáñez      9. Sopachuy     10. Presto\n");
            }
            else if (state_choice == 6) { // ORURO
                printf("🏙️  Top 10 Cities in ORURO:\n");
                printf("1. Oruro City   2. Huanuni      3. Challapata   4. Caracollo    5. Machacamarca\n");
                printf("6. Eucaliptus   7. Sabaya       8. Huari        9. Toledo       10. Poopó\n");
            }
            else if (state_choice == 7) { // TARIJA
                printf("🏙️  Top 10 Cities in TARIJA:\n");
                printf("1. Tarija City  2. Yacuiba      3. Bermejo      4. Villa Montes 5. Entre Ríos\n");
                printf("6. San Lorenzo  7. Padcaya      8. Caraparí     9. Uriondo      10. El Puente\n");
            }
            else if (state_choice == 8) { // BENI
                printf("🏙️  Top 10 Cities in BENI:\n");
                printf("1. Trinidad     2. Riberalta    3. Guayaramerín 4. San Borja    5. Santa Ana\n");
                printf("6. Rurrenabaque 7. Reyes        8. San Ignacio  9. Magdalena    10. Baures\n");
            }
            else if (state_choice == 9) { // PANDO
                printf("🏙️  Top 10 Cities in PANDO:\n");
                printf("1. Cobija       2. Porvenir     3. Puerto Rico  4. Gonzalo Moreno 5. Filadelfia\n");
                printf("6. Sena         7. San Lorenzo  8. Blanca Flor  9. Humaita      10. Bolpebra\n");
            }
            else {
                printf("⚠️ Invalid Department Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY/MUNICIPALITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Bolivia\n");
                printf(">> Dept Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 9) { // PARAGUAY
            int state_choice, city_choice;
            
            printf(">> PARAGUAY: Select a Department (1-10)\n");
            printf("1. Central        2. Alto Paraná    3. Itapúa\n");
            printf("4. Caaguazú       5. San Pedro      6. Cordillera\n");
            printf("7. Paraguarí      8. Concepción     9. Guairá\n");
            printf("10. Caazapá\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // CENTRAL (Most Populated)
                printf("🏙️  Top 10 Cities in CENTRAL:\n");
                printf("1. Luque      2. San Lorenzo 3. Lambaré     4. Fernando    5. Limpio\n");
                printf("6. Ñemby      7. Capiatá     8. Mariano R.  9. Itauguá     10. Villa Elisa\n");
            } 
            else if (state_choice == 2) { // ALTO PARANÁ
                printf("🏙️  Top 10 Cities in ALTO PARANÁ:\n");
                printf("1. Cdad. Este 2. Hernandarias 3. Pres. Franco 4. Minga Guazú 5. Santa Rita\n");
                printf("6. Itakyry    7. Mallorquín  8. Naranjal    9. San Alberto 10. Iruña\n");
            }
            else if (state_choice == 3) { // ITAPÚA
                printf("🏙️  Top 10 Cities in ITAPÚA:\n");
                printf("1. Encarnación 2. Cambyretá   3. Fram        4. Bella Vista 5. Hohenau\n");
                printf("6. Obligado    7. Natalio     8. Maria Aux.  9. Coronel B.  10. San Pedro\n");
            }
            else if (state_choice == 4) { // CAAGUAZÚ
                printf("🏙️  Top 10 Cities in CAAGUAZÚ:\n");
                printf("1. Cnel. Oviedo 2. Caaguazú City 3. J.E. Estigarribia 4. Repatriación 5. Yhú\n");
                printf("6. San José    7. Pastoreo    8. Carayaó     9. Vaquería    10. Cecilio Báez\n");
            }
            else if (state_choice == 5) { // SAN PEDRO
                printf("🏙️  Top 10 Cities in SAN PEDRO:\n");
                printf("1. San Pedro   2. Santaní     3. Guayaibí    4. Itacurubí   5. Capiibary\n");
                printf("6. Lima        7. Resquín     8. Tacuatí     9. Choré       10. Yataity\n");
            }
            else if (state_choice == 6) { // CORDILLERA
                printf("🏙️  Top 10 Cities in CORDILLERA:\n");
                printf("1. Caacupé     2. Piribebuy   3. Itacurubí   4. Eusebio A.  5. Tobatí\n");
                printf("6. Arroyos     7. Emboscada   8. San B.      9. Caraguatay  10. Valenzuela\n");
            }
            else if (state_choice == 7) { // PARAGUARÍ
                printf("🏙️  Top 10 Cities in PARAGUARÍ:\n");
                printf("1. Paraguarí   2. Carapeguá   3. Yaguarón    4. Quiindy     5. Ybycuí\n");
                printf("6. Pirayú      7. Acahay      8. Mbuyapey    9. Caapucú     10. Sapucai\n");
            }
            else if (state_choice == 8) { // CONCEPCIÓN
                printf("🏙️  Top 10 Cities in CONCEPCIÓN:\n");
                printf("1. Concepción  2. Horqueta    3. Yby Yaú     4. Belén       5. Loreto\n");
                printf("6. Azotey      7. San Lázaro  8. Paso Barreto 9. Sargento L. 10. San Carlos\n");
            }
            else if (state_choice == 9) { // GUAIRÁ
                printf("🏙️  Top 10 Cities in GUAIRÁ:\n");
                printf("1. Villarrica  2. Paso Yobái  3. Iturbe      4. Mbocayaty   5. Yataity\n");
                printf("6. Independencia 7. Borja     8. Fassardi    9. Troche      10. San Salvador\n");
            }
            else if (state_choice == 10) { // CAAZAPÁ
                printf("🏙️  Top 10 Cities in CAAZAPÁ:\n");
                printf("1. Caazapá City 2. S.J. Nepomuceno 3. Yuty    4. Tavaí       5. Abaí\n");
                printf("6. Yegros      7. Buena Vista 8. Enramada    9. Bertoni     10. Maciel\n");
            }
            else {
                printf("⚠️ Invalid Department Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Paraguay\n");
                printf(">> Dept Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }

        else if (country_choice == 10) { // URUGUAY
            int state_choice, city_choice;
            
            printf(">> URUGUAY: Select a Department (1-10)\n");
            printf("1. Montevideo     2. Canelones      3. Maldonado\n");
            printf("4. Salto          5. Colonia        6. Paysandú\n");
            printf("7. San José       8. Rivera         9. Tacuarembó\n");
            printf("10. Florida\n");
            
            printf("\nENTER SELECTION NUMBER: ");
            scanf("%d", &state_choice);
            printf("------------------------------\n");

            if (state_choice == 1) { // MONTEVIDEO (Capital Region)
                printf("🏙️  Top 10 Areas in MONTEVIDEO:\n");
                printf("1. Ciudad Vieja 2. Pocitos      3. Carrasco    4. Prado       5. Punta Carretas\n");
                printf("6. Buceo       7. Malvín       8. Cordón      9. Aguada      10. Cerro\n");
            } 
            else if (state_choice == 2) { // CANELONES
                printf("🏙️  Top 10 Cities in CANELONES:\n");
                printf("1. Ciudad Costa 2. Las Piedras  3. Pando       4. Canelones City 5. La Paz\n");
                printf("6. Santa Lucía 7. Progreso     8. Paso Carrasco 9. Sauce     10. Atlántida\n");
            }
            else if (state_choice == 3) { // MALDONADO
                printf("🏙️  Top 10 Cities/Resorts in MALDONADO:\n");
                printf("1. Maldonado City 2. Punta del Este 3. San Carlos 4. Piriápolis 5. Pan de Azúcar\n");
                printf("6. Aiguá       7. Punta Ballena 8. José Ignacio 9. Solís      10. Portezuelo\n");
            }
            else if (state_choice == 4) { // SALTO
                printf("🏙️  Top 10 Cities/Areas in SALTO:\n");
                printf("1. Salto City  2. Termas Daymán 3. Constitución 4. Belén      5. San Antonio\n");
                printf("6. Albisu      7. Garibaldi    8. Biassini    9. Saucedo     10. Sarandí Arapey\n");
            }
            else if (state_choice == 5) { // COLONIA
                printf("🏙️  Top 10 Cities in COLONIA:\n");
                printf("1. Colonia Sac. 2. Carmelo      3. Juan Lacaze 4. Nueva Helvecia 5. Rosario\n");
                printf("6. Nueva Palmira 7. Tarariras   8. Florencio S. 9. Ombúes      10. Conchillas\n");
            }
            else if (state_choice == 6) { // PAYSANDÚ
                printf("🏙️  Top 10 Cities in PAYSANDÚ:\n");
                printf("1. Paysandú City 2. Guichón     3. Quebracho   4. Nuevo Paysandú 5. Piedras Col.\n");
                printf("6. Lorenzo Geyres 7. Gallinal   8. Orgoroso    9. Tambores    10. Porvenir\n");
            }
            else if (state_choice == 7) { // SAN JOSÉ
                printf("🏙️  Top 10 Cities in SAN JOSÉ:\n");
                printf("1. San José Mayo 2. Cdad. de Plata 3. Libertad   4. Rodríguez   5. Ecilda Paullier\n");
                printf("6. Puntas Valdez 7. Rafael Perazza 8. Kiyú       9. Mal Abrigo  10. Capurro\n");
            }
            else if (state_choice == 8) { // RIVERA
                printf("🏙️  Top 10 Cities in RIVERA:\n");
                printf("1. Rivera City 2. Tranqueras   3. Vichadero   4. Minas Corrales 5. Masoller\n");
                printf("6. Paso Hospital 7. Lapuente   8. Lagos del Norte 9. Amarillo   10. Cerros Blancos\n");
            }
            else if (state_choice == 9) { // TACUAREMBÓ
                printf("🏙️  Top 10 Cities in TACUAREMBÓ:\n");
                printf("1. Tacuarembó City 2. Paso de Toros 3. San Gregorio 4. Ansina     5. Curtina\n");
                printf("6. Achar       7. Tambores     8. Las Toscas  9. Clara       10. Cardozo\n");
            }
            else if (state_choice == 10) { // FLORIDA
                printf("🏙️  Top 10 Cities in FLORIDA:\n");
                printf("1. Florida City 2. Sarandí Grande 3. Casupá     4. Fray Marcos 5. 25 de Mayo\n");
                printf("6. 25 de Agosto 7. Alejandro Gallinal 8. Cardal 9. Nico Pérez  10. Capilla Cucuú\n");
            }
            else {
                printf("⚠️ Invalid Department Selection.\n");
                return 0;
            }

            printf("\nSELECT CITY NUMBER (1-10): ");
            scanf("%d", &city_choice);
            
            if (city_choice >= 1 && city_choice <= 10) {
                printf("\n✅ SUCCESS: Destination Locked!\n");
                printf(">> Continent: South America\n");
                printf(">> Country: Uruguay\n");
                printf(">> Dept Code: %d, City Code: %d\n", state_choice, city_choice);
            } else {
                printf("⚠️ Invalid Number.\n");
            }
        }
        
        else {
            printf("⚠️ Invalid Country Selection within South America.\n");
        }
    }


    else {
        printf("⚠️  ERROR: ACCESS DENIED. INVALID COORDINATES!\n");

    }

    printf("--------------------------------------------------\n");
    printf("         END OF TRANSMISSION... STAY SAFE!        \n");
    printf("==================================================\n");

    return 0;
}
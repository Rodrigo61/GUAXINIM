#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

const ll mod = 2e9 + 33;

int precalc_vals[] = {1, 552315535, 1651416169, 1128106233, 396260173, 1137843892, 1636933053, 1121309556, 1655515412, 706383387, 1251162751, 129564348, 1310559111, 588406971, 700884672, 381182727, 1141984598, 1215261365, 1171017917, 1046308502, 350077357, 835809638, 140593227, 1220823735, 623805375, 1002954486, 29433304, 403692176, 1341760179, 1408565426, 1851648393, 1440852843, 333978962, 1389054527, 309496471, 1597263137, 253597327, 1606886447, 1891079520, 588874118, 1112447095, 1089216002, 1571754128, 1915435738, 900939644, 732939928, 285149750, 1911317463, 1724405690, 1535838720, 880551715, 553094346, 1675556618, 210722749, 184051076, 1481388310, 1048440811, 1800155769, 152120796, 1673684301, 257356951, 1236240903, 1386844130, 658474732, 391061092, 746793974, 1570651566, 1594257319, 1720061582, 73501093, 852674675, 412940813, 990944750, 1696150597, 873220470, 400196819, 1189425168, 1940691596, 105845651, 1182767326, 1627987191, 1861553381, 1391615165, 1494064992, 1923948467, 1119201157, 1323398595, 1520141615, 1379824718, 193770724, 53167437, 1596484579, 714019615, 1942652816, 898866528, 1061556962, 1237718582, 1596537623, 605169406, 1606285947, 328257488, 1353740764, 695957371, 1862017588, 1613632721, 1896297651, 1429991467, 860113904, 849523623, 1957274227, 1413395447, 714518189, 65515354, 492459489, 1816359059, 1955030189, 1530250969, 1340323916, 107280281, 443540704, 302283618, 120733661, 986084830, 706382034, 1337149092, 863325725, 344448073, 1816755475, 1785328748, 1234843107, 1011310407, 1582115845, 717500079, 26582717, 1704211420, 1132835006, 433411043, 1168486655, 1751010039, 1816251686, 1964979127, 1589472526, 201964391, 537047400, 372561350, 921806957, 1836945366, 14733260, 976373873, 1236753466, 929999809, 1531071589, 743432890, 208041739, 1567815451, 1808645466, 1472817776, 1577046364, 271211912, 1370194969, 286544666, 553427587, 1270843598, 301476842, 1189258612, 853718692, 1516195090, 1440145562, 1719625281, 1713877254, 208558685, 1427959094, 1561295226, 1052948629, 1491761230, 1156919287, 1823216729, 421518942, 1152337326, 448799126, 290875450, 1399521583, 82421993, 1778125063, 220805738, 1432677832, 936575643, 1948550318, 1876063801, 1770083824, 201509193, 601005393, 551996421, 210394443, 1096758346, 1790427025, 815555810, 1738456123, 1268698551, 504486018, 806877960, 156082180, 895280860, 387276154, 1395218135, 482839559, 394729215, 1265412636, 1200559061, 1142281023, 1108257622, 448340583, 108399785, 200468998, 32781053, 1584106661, 1293757038, 940465532, 910480354, 1610836612, 736977759, 232694776, 260057919, 616329604, 949637468, 263108340, 1065522591, 308635347, 753082957, 1009775710, 1131176568, 1546416171, 1314798139, 1674695712, 78000696, 729110558, 972072510, 804058948, 376930426, 1467039328, 1923347461, 415044416, 1794653748, 362496877, 1828348168, 407433330, 1739545865, 808581137, 296200682, 1516516867, 1640910653, 284761022, 196527456, 32731869, 1422926926, 1070099604, 1012661528, 1983017424, 428900270, 1898120083, 669774043, 1370004143, 1587699065, 1343921910, 921464328, 1962474463, 1358496427, 674161251, 188632516, 610785044, 218446476, 967815619, 232278082, 991696224, 1097284688, 35260167, 1668939561, 221051799, 688811646, 1166880790, 1958178602, 484337709, 873309456, 1238504116, 891848785, 1390081050, 463749320, 1259716380, 726115979, 1720564204, 77179303, 236813540, 1184971263, 1581769527, 465813929, 640134245, 1740672384, 1551047045, 1226317351, 1057816854, 154683426, 1844307392, 108438217, 1258577357, 729684877, 723160437, 1460605038, 1302955209, 889711916, 957500487, 368457986, 1187920410, 1725561418, 1095459986, 1457293433, 1329561200, 1393877850, 375357240, 847393169, 1255700793, 1266099367, 638286869, 341726588, 718201918, 844255020, 9446366, 976196074, 1162299398, 274049950, 45962075, 23716247, 492506274, 754938717, 271802311, 834661725, 737382717, 1551526344, 1576512418, 22141200, 1070922551, 498125168, 184102992, 236253129, 275715809, 243743825, 1659868418, 719143557, 270049193, 966194483, 758233573, 36264068, 286763710, 1542727666, 1703787660, 1327728112, 1159229243, 1678798021, 1443308104, 1574312557, 1490026923, 1866524596, 1289173026, 1766576026, 730223041, 1716424093, 1955381691, 1338438755, 1672589237, 799882770, 1190657401, 709004988, 947125343, 1373202462, 1149824554, 1061096194, 1044936298, 1490280895, 591950374, 129913951, 831124411, 1921216289, 1214694538, 1031087280, 1784380594, 1341095596, 1604552922, 290739386, 828979390, 533427054, 1710099325, 761018106, 1041047080, 240835378, 1246862565, 26295044, 1374025610, 349448915, 1022402818, 27094486, 1500136336, 461747765, 1593132206, 1025988088, 512940278, 1635692249, 946976999, 1299041157, 333221911, 417620167, 800515028, 1518475931, 1386679292, 499092475, 513027571, 843444030, 889049278, 992622054, 147104441, 270785035, 815921390, 245686889, 1204263301, 863279130, 373293220, 770631442, 1485451082, 944007593, 1011153059, 1205737148, 1165118273, 744798050, 1109316911, 1149145176, 1785952089, 501262953, 731741783, 1917989898, 1603816941, 664523619, 1339381751, 1942185646, 1172698670, 259419354, 535737426, 88494825, 1860985688, 1857850799, 295945677, 335579065, 1125269500, 778510105, 365725035, 610233251, 719597306, 84166010, 1313305032, 1635045857, 1806337288, 1995052679, 1495064323, 1656378057, 626223737, 1217665742, 1179089999, 255602801, 1267967292, 1732103517, 937307509, 286462532, 930468864, 627971825, 828336177, 66099181, 506116538, 414253577, 954982794, 567763619, 238676320, 1940642873, 299835202, 1958110154, 1012320844, 337236815, 751688263, 992502436, 1071402382, 269877178, 1020495687, 926900245, 297029121, 1994876583, 853474809, 350277898, 1126362045, 270411706, 85564576, 883195308, 1871320517, 721814901, 1582273396, 51696316, 1700850457, 888328119, 1065881682, 654771060, 911045624, 1175347428, 501555802, 350257242, 217918970, 988046390, 1407289668, 126075643, 731732704, 1683379187, 2298499, 1766199375, 527465196, 103258059, 954605300, 1460573525, 283826041, 549904459, 1292886531, 1730166159, 678242557, 661236883, 177799184, 1950378835, 638207307, 909053866, 1632516988, 879082475, 425652363, 568767213, 295680771, 625485107, 1040307465, 817898460, 1704043071, 1172873538, 1907020107, 932677996, 1952139747, 1391424760, 1325233843, 1995139108, 1942140651, 1762467068, 642062607, 1607209387, 1555070806, 924567767, 1601499030, 691001307, 1139277863, 492530393, 1972847495, 1772836994, 861524990, 771703767, 1342199841, 255157857, 1842675482, 1497945106, 780574690, 1614647231, 1904868454, 1037357603, 364717977, 5952343, 133665589, 919499473, 313855782, 1591997193, 6372050, 317620433, 1281979115, 1513461766, 1185156219, 399878921, 1499889366, 171028165, 985261721, 490254104, 1396735128, 167952694, 206846645, 1647494596, 905734846, 1511157576, 1659116151, 444162083, 123853166, 886016624, 1876352839, 1909730792, 729920089, 170382942, 30608318, 237605074, 1804088465, 1432734676, 1233222761, 1623461753, 538038780, 1014282158, 1463006619, 1557612517, 600395418, 1349760071, 1634936192, 1117487462, 1687925599, 1424293253, 71723001, 701549457, 1781178106, 1659256746, 1017299075, 1249876122, 1137853206, 1791685384, 1700095632, 1238690182, 1139393950, 142503573, 892518665, 975114401, 1773675647, 279288967, 599817604, 1596681385, 959186283, 1008272572, 1185797187, 464584369, 751449638, 770595983, 814654515, 1403003268, 51556769, 1693007432, 379148239, 1289422674, 81067427, 1783346187, 523634675, 836567968, 1480806838, 1976100871, 1456673057, 143746782, 841534888, 1534217147, 794686713, 647178894, 1315834618, 17560840, 1990084235, 1088504736, 752698425, 1609489435, 1837773544, 1791684473, 1736059556, 117087567, 6724943, 1196007068, 1117270808, 757580911, 953291751, 717739525, 682319216, 337852126, 781161553, 1130832110, 683681927, 1405392074, 1596528817, 1676674886, 1946688638, 1385216035, 1192473281, 404888842, 878865910, 335508267, 1842776580, 507760511, 1241281792, 516014416, 1911715589, 945384673, 577596791, 1525991509, 1952715489, 921135008, 1653865941, 91629910, 1444667291, 1974583214, 944243587, 1162688437, 183962064, 1682180375, 1686091337, 784097972, 412625109, 882886594, 1674880427, 1216765126, 1389285157, 906582119, 1988977893, 1132633824, 789412340, 537435685, 773004962, 1230785141, 1759910716, 25269103, 493932170, 1199820083, 1159333432, 1578850521, 1294886730, 1679217426, 218543551, 237477260, 1710613201, 1555487890, 1887177911, 520672905, 509015344, 182328195, 476661639, 1824810831, 413054025, 1884172958, 1472713262, 1879337741, 1795496979, 497049145, 282589262, 1022359854, 967740440, 983532760, 144868430, 1124805910, 1977085001, 456052887, 1347450802, 957832435, 709478477, 1258256454, 504473479, 1782955905, 811351153, 343351829, 374269265, 1840203726, 111545713, 1143338053, 1391220926, 75429620, 842900168, 185780945, 929242680, 1318356526, 842115082, 385799689, 1911465634, 1557416618, 1888215931, 1909622082, 1257818757, 1294324591, 1470165365, 223592161, 833707902, 658195325, 1854018385, 331587934, 260695454, 1205431507, 1483085937, 451438345, 177154987, 42904167, 193833868, 275782181, 482511590, 776596244, 1198866280, 1760939964, 1378726226, 1957323780, 183750269, 1088943001, 1389555124, 1642015503, 1457711353, 694210223, 237011773, 1903256604, 1786620763, 390583614, 933174264, 1892879448, 1815452968, 718301187, 1134614175, 1484497748, 1842932121, 354423514, 408027784, 1659455761, 1529209517, 466224629, 1925735108, 626248487, 1304378513, 1695789776, 954073191, 867212559, 451798365, 802853782, 1004904704, 688051738, 1641408416, 331730489, 437068292, 1699570374, 739752406, 1464528570, 292145521, 927063297, 1440445872, 116791305, 931304545, 549094125, 1787181228, 1646987448, 88735089, 886624900, 712925516, 741269426, 774455960, 1810312280, 485248952, 1194866433, 1630455112, 500346742, 101065576, 1559543999, 357340050, 995430414, 841696004, 34445190, 969018761, 864521495, 1763858706, 1332217269, 300243764, 450065042, 1146234745, 760065452, 391132567, 172645463, 1141689449, 564350879, 970295795, 615679428, 1073593056, 1062399614, 1237260936, 1634179979, 444511394, 13831077, 1849012938, 25432896, 1542110415, 535182398, 839466803, 581539883, 1244506602, 1951755435, 219825678, 1564306786, 1501640711, 1195137306, 1548097155, 1739781174, 724789032, 448843495, 137910525, 489197680, 291140207, 213399142, 1437119197, 149790347, 535605854, 239077734, 1209143016, 885100588, 216478436, 1610038479, 1059413994, 940796036, 1461323374, 577611886, 924914557, 321572339, 1600599912, 842293901, 1568621680, 342188182, 1193340757, 1539629883, 1508056281, 849014014, 1637240807, 622556036, 423464499, 1477811975, 288053605, 994212246, 1483455209, 418130506, 1304833579, 969234510, 1572106661, 557312981, 1851552836, 526782964, 1334243965, 541546198, 405446531, 1926918792, 271879572, 1109075097, 486584565, 1901009520, 1156197761, 491198853, 1741735731, 1490266049, 1098742692, 349954203, 1232163048, 1525194851, 83658626, 1887779013, 1773048835, 922182852, 1876172935, 1662201936, 1919256188, 1895084194, 1729197725, 179001484, 1354970210, 608344383, 890293932, 1892953385, 1878737964, 1174126196, 301022017, 852989730, 1737790774, 1020696886, 1713366090, 1232582545, 624863731, 1959487161, 300881594, 628360770, 1111791418, 1352994262, 1140252520, 1710132300, 1448729948, 1798490704, 101808271, 1651738137, 1200709626, 1851280560, 10543915, 149629486, 1067265955, 399477604, 536102977, 1274808905, 1670110215, 1901162459, 782322674, 1845137012, 759595972, 4895565, 1631688781, 1829387073, 1650276041, 889394619, 1984391990, 855075366, 83459324, 955483295, 944446311, 1180852682, 1998930983, 1917400384, 602285462, 1383945783, 615458559, 1793528605, 1881698741, 9613214, 1418718411, 1248157024, 901962946, 31918056, 305120846, 560429955, 104315961, 1001989342, 1090021576, 1057403810, 897840229, 1142694642, 867400697, 386676024, 1452354122, 34526974, 1667661733, 1427632201, 1058772314, 1893652377, 1617534917, 713554240, 221404866, 517464885, 1094132639, 833318400, 904440443, 450345216, 1296333972, 1560640502, 846120650, 1318878445, 973282380, 1169178287, 325712529, 464464604, 1056828603, 1714451099, 1093238294, 1344365411, 1754915137, 1076813480, 1029188834, 217015120, 87057004, 1933348698, 1577134776, 309820117, 1527574035, 1146989879, 483101459, 1986788799, 162835417, 698876880, 1644435228, 1973628682, 1807329735, 1279921808, 378905486, 476385085, 8085686, 1671966194, 1830316595, 988258823, 730077395, 1076540714, 244037468, 1398948088, 812008877, 1545602597, 1927737155, 831855001, 1646848477, 124846250, 75849397, 1211838713, 1580618706, 553281006, 1567153734, 1225385643, 391027644, 1189893910, 810319448, 1010593985, 1134378163, 7704835, 507189147, 1105551436, 1047872008, 1980519910, 1173773102, 1442067558, 157009342, 1352495223, 1185813212, 1468249737, 673314752, 1118790990, 1357883550, 1743198299, 1123379680, 959130560, 1580808048, 315977927, 867247920, 1316290111, 1308670468, 1982476315, 1140986600, 1360893371, 526390254, 1969567263, 1444288816, 500301217, 1868065475, 992583719, 1348131428, 557686925, 1123476819, 471445964, 1138490281, 175153706, 209486478, 1904117487, 801402530, 796450057, 753770831, 1802444797, 1287151272, 1998709374, 304280033, 1273584588, 158080984, 1713560319, 1816949434, 715570952, 1572339298, 474760532, 1382699214, 684144556, 829033445, 1328208214, 656226985, 1554409040, 1323006672, 761417202, 1042763084, 1628133671, 1402596610, 1992029829, 1563885324, 1476476132, 641477629, 1733258119, 1272160873, 733647352, 161469610, 234069940, 1112147393, 1553713988, 63877000, 1893450755, 249832571, 436918803, 1414682518, 1630072513, 876666851, 800150083, 968342054, 806181135, 555989003, 1649862714, 23682074, 1354604421, 918421943, 1244884066, 1478064802, 755022329, 1613025810, 190321287, 1583705264, 1017699023, 1352871672, 627449034, 365475630, 1308209418, 1316470311, 1998663991, 628883708, 905855469, 1922566147, 1729607410, 1712597435, 609072193, 786385859, 126655387, 465987296, 1223203125, 1031530595, 890954988, 1333234252, 1945434681, 441901449, 23164199, 219020752, 75556431, 1871404996, 1003756336, 1492738938, 656416483, 1046983075, 206602206, 1568622897, 1547768463, 1152577127, 457313654, 1564786776, 506190080, 1859250314, 717136394, 1227811017, 1031309426, 1385094079, 933279383, 65335594, 1802721341, 1302663350, 935001855, 1574126379, 368102667, 1066227024, 952020981, 64096765, 667808258, 999234844, 401705913, 1362587939, 474803715, 887815558, 1052910207, 1321539218, 422111996, 1220470947, 1457460229, 1053742120, 539939317, 1429153357, 469831626, 1360360783, 1229427712, 694273877, 1181428320, 1713413324, 706672567, 627075988, 1552878256, 1664989818, 630118960, 255930074, 1600058301, 1948543135, 1201338681, 1580533852, 1150300986, 1799731320, 1835540897, 156149645, 1043133195, 1576695460, 841547252, 1134491323, 652635874, 1863940310, 266088362, 487573614, 1221985621, 969125098, 1311903122, 32684471, 1505240976, 649906219, 1922309947, 825474466, 602046378, 1829222604, 699374098, 104437726, 20806102, 1257538402, 1973139050, 672450448, 253363999, 1052010305, 330298214, 282617450, 1252264375, 903540626, 1057629336, 522764360, 1213944169, 1140016375, 141485725, 1298260727, 1135606815, 869458666, 295093558, 1071765640, 1213512621, 517313193, 631306607, 164496750, 1788814350, 1508184097, 1013100711, 486077091, 1016582181, 1487946608, 274897371, 1072358015, 80354123, 203589635, 1284015850, 1635342826, 969950824, 187747391, 1910386534, 1602395276, 1411342442, 1403317310, 1507994772, 110984183, 1852027869, 1272817467, 1973980980, 645613441, 1853237441, 1472635148, 1834623409, 745617799, 962809447, 1445158068, 683887748, 1204788063, 354131387, 192653349, 698661543, 1983815097, 1308940922, 153439650, 1183483492, 505771688, 216127372, 1103093035, 127492335, 1462020415, 450655577, 339278555, 793344046, 902043897, 121866804, 1637791989, 68486893, 656343962, 1987722923, 1797165269, 1567630820, 249652946, 1990545147, 742075019, 1111778784, 205541441, 292146742, 1859334627, 766360274, 1816053348, 645097881, 1817485622, 591412071, 1787448768, 1527034685, 761654800, 840088357, 1859636138, 1256112075, 307412791, 949834445, 1994371309, 633472992, 525067526, 813432817, 1144765852, 135405375, 276237965, 1951625682, 1630852907, 1341640632, 29843229, 379383217, 136471015, 1698056423, 576173752, 59793348, 1206273184, 109525606, 1853313331, 879960393, 447568392, 1290303207, 26081249, 868957618, 1385729193, 1655828395, 1969540282, 1537463645, 66253822, 1607252773, 843712513, 271669346, 398783875, 1966527915, 947578713, 1199462979, 705524197, 145834094, 480025418, 221712864, 1176623855, 1532917502, 1567896709, 334103534, 299626378, 106918919, 162852276, 1281929907, 317939453, 1084647389, 1572882592, 1074195891, 290814035, 1836788925, 1827277682, 1397373060, 1271713515, 1801513207, 821474399, 1316516897, 393996898, 80642795, 386861289, 720245462, 1873960148, 1529014961, 17605152, 1940189457, 1422325798, 593818536, 1404542710, 417603094, 1424256265, 1360194976, 306106431, 977909370, 986334460, 1745176370, 663569376, 207590444, 1099423686, 1733133587, 134629703, 1073122488, 872737698, 1685406147, 1712693339, 857647830, 1249618350, 1770398925, 354629209, 1421693922, 1054766886, 1431946043, 1576939381, 665004253, 435851078, 1827296304, 1766210125, 81215507, 97335907, 1270123765, 1737501140, 1388739394, 1542962431, 344524379, 1705977689, 21727930, 357794631, 1000919165, 1352593097, 1643402680, 1046452216, 744488169, 1940065394, 1974623216, 744491963, 795644181, 1744143113, 678421362, 1839990633, 346313585, 1114447364, 995232528, 848391466, 1919780355, 106103333, 147501999, 1539604713, 1755781405, 1194371974, 1005715286, 236015438, 1234918628, 1130859717, 1146071992, 1186864217, 1993045348, 677231059, 843431692, 840342266, 1213497796, 39054368, 1352855917, 995347275, 1935573448, 836761108, 1907299319, 901979406, 101596301, 1667697544, 1479728256, 1956119207, 331347382, 401519705, 520011144, 1574246288, 1831218376, 406719985, 1133641636, 400982807, 1789917555, 1301419503, 8405457, 1822564780, 1943747436, 1619819944, 866194837, 1446217503, 267893667, 955167600, 1773707714, 1242648198, 600284835, 1957231865, 981940585, 295326899, 666590121, 851639597, 1006635248, 69769362, 1166714426, 795052610, 230491432, 740908378, 407458997, 1305203290, 784243231, 1222589690, 957836481, 1714557659, 1585193031, 360028612, 864581082, 1495388482, 116629533, 1072496563, 1747733021, 112759233, 758713994, 160269984, 1805726035, 1003652128, 562340338, 66895070, 466028662, 1169845262, 1243790990, 1094683725, 1098970226, 144968840, 743530869, 1089746748, 1139669011, 99086213, 933713769, 991912378, 1709836745, 893785834, 1389821089, 280552672, 220170488, 335963407, 975398442, 1316345233, 940148848, 1798860901, 1594462068, 1987552979, 872302976, 1125677797, 1228376724, 558914154, 1776442693, 1240439535, 380771294, 862813231, 1906616450, 544171197, 1973227455, 1391642553, 1195935900, 1268268810, 151807233, 1098207762, 1587186692, 1985952671, 1741917140, 1068630922, 84001436, 1552657205, 415952244, 56209609, 247748087, 1761261188, 408289425, 912664615, 838149879, 911876474, 404049889, 1572742080, 1173334723, 1407651156, 1143167428, 1496030429, 547933385, 1975318875, 739111891, 1587302245, 394835098, 1548280192, 1117058387, 1081112023, 1909513452, 1852948471, 485845072, 1596644717, 1203546227, 1964122609, 1670080444, 1311356974, 420107178, 1622654727, 1841565808, 416928710, 1957086224, 692662530, 1342874513, 1329768893, 1163089667, 1137484274, 167088440, 464786150, 1168044976, 760374699, 771281605, 1506893491, 1089278927, 1963872679, 1653265263, 1180218823, 1809430248, 570500987, 988507150, 75521339, 897751982, 618395997, 1896626896, 1845432322, 9317670, 1927844336, 1690862960, 1078648621, 514672408, 463969722, 1623922294, 788839358, 1318209686, 446886871, 1081219439, 1821244682, 1150203183, 1736133876, 1502446862, 463539420, 1177331231, 1405775462, 89140483, 424504928, 1449799429, 1090542829, 693849685, 1231252009, 1944743815, 158287450, 511840610, 1597878520, 1448306752, 273519348, 851526918, 738827567, 1435868410, 106595658, 862041912, 1857557607, 266540037, 749657865, 78125531, 190252497, 1257238314, 110719852, 1873959976, 542170884, 247305580, 476252450, 261650870, 1542113757, 1191920225, 979468097, 825606030, 1627505198, 1844112160, 105959685, 1718577922, 1975778978, 1576494379, 1658276819, 632783033, 307198475, 611972416, 673082456, 329229701, 1765902571, 1640858327, 1614343903, 1173838475, 733218133, 1550836786, 892330219, 380187859, 1188460618, 557516097, 53347636, 958422500, 1287899689, 318124926, 175298068, 119539911, 676434468, 1530950307, 207934787, 695564286, 1510763188, 478220825, 837701797, 1918239431, 825741453, 1450679008, 253135356, 1522645762, 902069820, 1487427305, 1966686772, 1401808722, 1014514270, 386837173, 1258827726, 953691648, 15945009, 407264011, 1431849233, 729899436, 1634728546, 1201005762, 1926428122, 1516680920, 307947278, 223308684, 1462904428, 516908287, 1510193694, 1713415548, 653166293, 791056288, 1697986748, 1867739089, 630132863, 403869749, 15688796, 1908396188, 1122738979, 72583996, 1855303011, 1039957742, 1099790436, 542449410, 979932127, 738948877, 1599307539, 1969046811, 1471963747, 1109694062, 472180233, 186567585, 153164232, 858852661, 413674926, 287118184, 96983865, 1068798572, 551358244, 153379173, 645879306, 585643600, 89905905, 498844620, 699872268, 1061126342, 57338425, 1082954951, 1782854193, 836375767, 1521704904, 995202320, 1712210314, 1825222718, 1250520201, 762646206, 1428530431, 1851489464, 1322307373, 816961651, 1913155506, 190698471, 1893587641, 1834991787, 1894421377, 1566620585, 834962260, 808949568, 836152376, 1507818408, 823523766, 522815623, 596801790, 352534872, 21577572, 1217643192, 1573038623, 313307741, 1753116820, 649652868, 318535914, 590271537, 826236720, 742451263, 405967083, 1482999239, 349081817, 100489907, 536389599, 430772712, 589947766, 1081436283, 362739154, 1974841722, 211862547, 1698429420, 32919312, 602054765, 1097733838, 1622034589, 1012642544, 1297712544, 20688292, 625869141, 746108080, 422087945, 1529221851, 304271957, 1149154003, 1494397528, 702172290, 1082586985, 292436532, 1418586279, 675054428, 693026461, 1491503420, 310472898, 1329114816, 408522486, 193077553, 578167819, 1854435019, 905393821, 1389264142, 1672877021, 614330779, 1058975540, 1173241587, 12312886, 479617185, 985564445, 1175833392, 1943783004, 514925852, 1551025479, 369833966, 1387626786, 38397322, 214112187, 764175313, 68821755, 420050232, 1279299223, 958817975, 10106264, 1045003288, 844617013, 1332685778, 156970734, 525016973, 372886935, 299390372, 1580121240, 48397042, 1060280563, 1263022979, 726081509, 756390642, 569744847, 1373236354, 1612807077, 1173542163, 1553715679, 1785302488, 595293600, 1678049520, 1849349708, 626416193, 1574054157, 800806873, 553491416, 234102181, 856640201, 954145196, 804927721, 1483372466, 1927984640, 1387939096, 1743422832, 299851261, 1409483256, 1813486807, 969275753, 25885090, 537054664};

ll mul_mod(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll sub_mod(ll a, ll b) { return ((a % mod) - (b % mod) + mod) % mod; }

template<class T>
T gcd(T a, T b, T &x, T &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

ll fact(ll x)
{
    db(x);
    if (x % 1000000 == 0) return precalc_vals[x];
    int i = x / 1000000;
    db(i);
    ll res = precalc_vals[i];
    for (int j = 1000000*i + 1; j <= x; j++)
    {
        db(j);
        res = mul_mod(res, j);
    }
    db(res);
    return res;
}

template<class T>
T mod_inverse(T a, T m)
{
	T x, y;
	assert(gcd(a, m, x, y) == 1); // Or return something, if gcd is not 1 the inverse doesn't exist.
	return (x % m + m) % m;
}

ll chooseModP(ll n, ll m, int p)
{
    ll c = 1;
    while (n || m)
    {
        ll a = n % p, b = m % p;
        if (a < b)
            return 0;
        c = c * fact(a) % p * mod_inverse<ll>(fact(b), p) % p * mod_inverse<ll>(fact(a - b), p) % p;
        n /= p;
        m /= p;
    }
    return c;
}

int main()
{
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);

    ll mi = min(n, m);

    ll c = chooseModP(n + m - 2, mi - 1, mod);
    printf("%lld\n", mul_mod(sub_mod(mul_mod(n, m), k), c));
}
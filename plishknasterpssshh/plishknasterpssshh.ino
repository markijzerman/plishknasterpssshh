 #include <SimpleTimer.h>
 #include <Morse.h>
 #include <Adafruit_NeoPixel.h>

 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, 9, NEO_GRB + NEO_KHZ800);

  // Set values
 int readCounter = 0;
 int WPM = 15;
 int flashPin = 13;

 // Class declaration
 Morse morse(flashPin, WPM);
 SimpleTimer timer;

 /////////// /////////// /////////// /////////// ///////////
  /////////// /////////// /////////// /////////// ///////////

 // Set the strings first
#include <avr/pgmspace.h>

// STRINGS HERE!
// max length: /////////////////////////////////////////////////////////////////
const char string_0[] PROGMEM = "moe = Cow mooing = Afrikaans / ";
const char string_1[] PROGMEM = "mAa = Sheep bleating = Afrikaans / ";
const char string_2[] PROGMEM = "mu = Cow mooing = Basque / ";
const char string_3[] PROGMEM = "mee = Sheep bleating = Basque / ";
const char string_4[] PROGMEM = "bee = Goat bleating = Basque / ";
const char string_5[] PROGMEM = "kurrin-kurrin = Pig grunting = Basque / ";
const char string_6[] PROGMEM = "hamba = Cow mooing = Bengali / ";
const char string_7[] PROGMEM = "ghnot ghnot = Pig grunting = Bengali / ";
const char string_8[] PROGMEM = "muu = Cow mooing = Croatian / ";
const char string_9[] PROGMEM = "bee = Sheep bleating = Croatian / ";
const char string_10[] PROGMEM = "meee = Goat bleating = Czech / ";
const char string_11[] PROGMEM = "muh = Cow mooing = Danish / ";
const char string_12[] PROGMEM = "boe = Cow mooing = Dutch / ";
const char string_13[] PROGMEM = "knor knor = Pig grunting = Dutch / ";
const char string_14[] PROGMEM = "moo = Cow mooing = English / ";
const char string_15[] PROGMEM = "baa = Sheep bleating = English / ";
const char string_16[] PROGMEM = "oink oink = Pig grunting = English / ";
const char string_17[] PROGMEM = "bree bree = Pig squealing = English / ";
const char string_18[] PROGMEM = "rAPh rAPh rAPh = Pig grunting = Estonian / ";
const char string_19[] PROGMEM = "bAaAah = Sheep bleating = French / ";
const char string_20[] PROGMEM = "veee = Sheep bleating = Georgian / ";
const char string_21[] PROGMEM = "muh = Cow mooing = German / ";
const char string_22[] PROGMEM = "moo = Cow mooing = Hindi / ";
const char string_23[] PROGMEM = "bee = Sheep bleating = Hungarian / ";
const char string_24[] PROGMEM = "mek mek = Goat bleating = Hungarian / ";
const char string_25[] PROGMEM = "mee = Sheep bleating = Icelandic / ";
const char string_26[] PROGMEM = "mooh = Cow mooing = Indonesian / ";
const char string_27[] PROGMEM = "mbek = Goat bleating = Indonesian / ";
const char string_28[] PROGMEM = "grok grok = Pig grunting = Indonesian / ";
const char string_29[] PROGMEM = "mu = Cow mooing = Italian / ";
const char string_30[] PROGMEM = "bee = Sheep bleating = Italian / ";
const char string_31[] PROGMEM = "bee = Sheep bleating = Latin / ";
const char string_32[] PROGMEM = "be = Sheep bleating = Lithuanian / ";
const char string_33[] PROGMEM = "bA-bA = Sheep bleating = Persian / ";
const char string_34[] PROGMEM = "muuu = Cow mooing = Polish / ";
const char string_35[] PROGMEM = "beee = Sheep bleating = Polish / ";
const char string_36[] PROGMEM = "beee = Goat bleating = Polish / ";
const char string_37[] PROGMEM = "chrum chrum = Pig grunting = Polish / ";
const char string_38[] PROGMEM = "kwi kwi = Pig squealing = Polish / ";
const char string_39[] PROGMEM = "mu mu = Cow mooing = Portuguese / ";
const char string_40[] PROGMEM = "meh = Sheep bleating = Portuguese / ";
const char string_41[] PROGMEM = "mu = Cow mooing = Romanian / ";
const char string_42[] PROGMEM = "groh groh = Pig grunting = Romanian / ";
const char string_43[] PROGMEM = "hrju hrju = Pig grunting = Russian / ";
const char string_44[] PROGMEM = "mu = Cow mooing = Slovene / ";
const char string_45[] PROGMEM = "mu = Cow mooing = Spanish / ";
const char string_46[] PROGMEM = "beee = Sheep bleating = Spanish / ";
const char string_47[] PROGMEM = "mu = Cow mooing = Swedish / ";
const char string_48[] PROGMEM = "ungaa = Cow mooing = Tagalog / ";
const char string_49[] PROGMEM = "ngok ngok = Pig grunting = Tagalog / ";
const char string_50[] PROGMEM = "mae = Sheep bleating = Telugu / ";
const char string_51[] PROGMEM = "mAP = Cow mooing = Turkish / ";
const char string_52[] PROGMEM = "mee = Sheep bleating = Turkish / ";
const char string_53[] PROGMEM = "grun grun = Pig grunting = Uropi / ";
const char string_54[] PROGMEM = "be be = Sheep bleating = Vietnamese / ";
const char string_55[] PROGMEM = "be be = Goat bleating = Vietnamese / ";
const char string_56[] PROGMEM = "soch soch = Pig grunting = Welsh / ";
const char string_57[] PROGMEM = "kloek kloek = Chicken clucking = Afrikaans / ";
const char string_58[] PROGMEM = "koekeloekoe = Rooster crowing = Afrikaans / ";
const char string_59[] PROGMEM = "kwaak = Duck calling = Afrikaans / ";
const char string_60[] PROGMEM = "kikiriku = Rooster crowing = Albanian / ";
const char string_61[] PROGMEM = "mak-mak = Duck calling = Albanian / ";
const char string_62[] PROGMEM = "kakara-kakara = Chicken clucking = Basque / ";
const char string_63[] PROGMEM = "kukurruku = Rooster crowing = Basque / ";
const char string_64[] PROGMEM = "karra-karra = Goose calling = Basque / ";
const char string_65[] PROGMEM = "par-par = Duck calling = Basque / ";
const char string_66[] PROGMEM = "kotek-kotek = Chicken clucking = Batak / ";
const char string_67[] PROGMEM = "kuak-kuak = Duck calling = Batak / ";
const char string_68[] PROGMEM = "kuk-ku-ruk-kooo = Rooster crowing = Bengali / ";
const char string_69[] PROGMEM = "pnak pnak = Duck calling = Bengali / ";
const char string_70[] PROGMEM = "kukuriku = Rooster crowing = Croatian / ";
const char string_71[] PROGMEM = "ga ga = Goose calling = Croatian / ";
const char string_72[] PROGMEM = "kva kva = Duck calling = Croatian / ";
const char string_73[] PROGMEM = "kykirikA = Rooster crowing = Czech / ";
const char string_74[] PROGMEM = "hudry hudry = Turkey calling = Czech / ";
const char string_75[] PROGMEM = "ga ga = Goose calling = Czech / ";
const char string_76[] PROGMEM = "kykkeliky = Rooster crowing = Danish / ";
const char string_77[] PROGMEM = "rap rap = Duck calling = Danish / ";
const char string_78[] PROGMEM = "tok tok tok = Chicken clucking = Dutch / ";
const char string_79[] PROGMEM = "kukeleku = Rooster crowing = Dutch / ";
const char string_80[] PROGMEM = "gak gak = Goose calling = Dutch / ";
const char string_81[] PROGMEM = "cock a doodle doo = Rooster crowing = English / ";
const char string_82[] PROGMEM = "gobble gobble = Turkey calling = English / ";
const char string_83[] PROGMEM = "honk honk = Goose calling = English / ";
const char string_84[] PROGMEM = "quack = Duck calling = English / ";
const char string_85[] PROGMEM = "kaak kaak = Goose calling = Estonian / ";
const char string_86[] PROGMEM = "kot kot = Chicken clucking = Finnish / ";
const char string_87[] PROGMEM = "klu klu klu = Turkey calling = Finnish / ";
const char string_88[] PROGMEM = "kvaak kvaak = Duck calling = Finnish / ";
const char string_89[] PROGMEM = "ca car = Goose calling = French / ";
const char string_90[] PROGMEM = "qiqliqo = Rooster crowing = Georgian / ";
const char string_91[] PROGMEM = "gack gack gack = Chicken clucking = German / ";
const char string_92[] PROGMEM = "ku-kudu-koo = Rooster crowing = Hindi / ";
const char string_93[] PROGMEM = "kukurikAo = Rooster crowing = Hungarian / ";
const char string_94[] PROGMEM = "bra bra = Duck calling = Icelandic / ";
const char string_95[] PROGMEM = "petok-petok = Chicken clucking = Indonesian / ";
const char string_96[] PROGMEM = "kukuruyuk = Rooster crowing = Indonesian / ";
const char string_97[] PROGMEM = "kwak kwak = Goose calling = Indonesian / ";
const char string_98[] PROGMEM = "kwek kwek = Duck calling = Indonesian / ";
const char string_99[] PROGMEM = "cuc-adiAo-dil-Ao = Rooster crowing = Irish / ";
const char string_100[] PROGMEM = "qyt-qyt = Chicken clucking = Kazakh / ";
const char string_101[] PROGMEM = "qaq-qaq = Duck calling = Kazakh / ";
const char string_102[] PROGMEM = "kA kA = Chicken clucking = Latgalian / ";
const char string_103[] PROGMEM = "gA gA = Goose calling = Latgalian / ";
const char string_104[] PROGMEM = "cocococo = Rooster crowing = Latin / ";
const char string_105[] PROGMEM = "kluk kluk = Chicken clucking = Latvian / ";
const char string_106[] PROGMEM = "gA gA = Goose calling = Latvian / ";
const char string_107[] PROGMEM = "pAk pAk = Duck calling = Latvian / ";
const char string_108[] PROGMEM = "kva kva = Duck calling = Lithuanian / ";
const char string_109[] PROGMEM = "kokarakkoo = Rooster crowing = Malayalam / ";
const char string_110[] PROGMEM = "kukhuri kaa = Rooster crowing = Nepali / ";
const char string_111[] PROGMEM = "braaaq caaq = Duck calling = Nepali / ";
const char string_112[] PROGMEM = "klukk klukk = Chicken clucking = Norwegian / ";
const char string_113[] PROGMEM = "kykkeliky = Rooster crowing = Norwegian / ";
const char string_114[] PROGMEM = "kvakk kvakk = Duck calling = Norwegian / ";
const char string_115[] PROGMEM = "Northern = Duck calling = Persian / ";
const char string_116[] PROGMEM = "kukuryku = Rooster crowing = Polish / ";
const char string_117[] PROGMEM = "gul gul = Turkey calling = Polish / ";
const char string_118[] PROGMEM = "gA gA = Goose calling = Polish / ";
const char string_119[] PROGMEM = "kwa kwa kwa = Duck calling = Polish / ";
const char string_120[] PROGMEM = "cotcodac = Chicken clucking = Romanian / ";
const char string_121[] PROGMEM = "cucurigu = Rooster crowing = Romanian / ";
const char string_122[] PROGMEM = "ga ga = Goose calling = Romanian / ";
const char string_123[] PROGMEM = "mac mac = Duck calling = Romanian / ";
const char string_124[] PROGMEM = "ku-ka-re-ku = Rooster crowing = Russian / ";
const char string_125[] PROGMEM = "krja krja = Duck calling = Russian / ";
const char string_126[] PROGMEM = "kikiriki = Rooster crowing = Slovene / ";
const char string_127[] PROGMEM = "ga ga = Goose calling = Slovene / ";
const char string_128[] PROGMEM = "kikiriki = Chicken clucking = Spanish / ";
const char string_129[] PROGMEM = "kongkorongok = Rooster crowing = Sundanese / ";
const char string_130[] PROGMEM = "kuckeliku = Rooster crowing = Swedish / ";
const char string_131[] PROGMEM = "kvack kvack = Duck calling = Swedish / ";
const char string_132[] PROGMEM = "po-kok = Chicken clucking = Tagalog / ";
const char string_133[] PROGMEM = "ong ong = Goose calling = Tagalog / ";
const char string_134[] PROGMEM = "kwak kwak = Duck calling = Tagalog / ";
const char string_135[] PROGMEM = "kokkara-ko-ko = Rooster crowing = Tamil / ";
const char string_136[] PROGMEM = "baack baack = Goose calling = Tamil / ";
const char string_137[] PROGMEM = "kua kua = Duck calling = Tamil / ";
const char string_138[] PROGMEM = "kokkaro-ko = Rooster crowing = Telugu / ";
const char string_139[] PROGMEM = "gulu gulu = Turkey calling = Turkish / ";
const char string_140[] PROGMEM = "vak vak = Goose calling = Turkish / ";
const char string_141[] PROGMEM = "vak vak = Duck calling = Turkish / ";
const char string_142[] PROGMEM = "koo-ku-ri-koo = Rooster crowing = Ukrainian / ";
const char string_143[] PROGMEM = "kakh kakh = Duck calling = Ukrainian / ";
const char string_144[] PROGMEM = "kwa kwa = Duck calling = Uropi / ";
const char string_145[] PROGMEM = "runnik = Horse whinnying = Afrikaans / ";
const char string_146[] PROGMEM = "deregin-deregin = Horse trotting = Arabic / ";
const char string_147[] PROGMEM = "njihaa = Horse whinnying = Croatian / ";
const char string_148[] PROGMEM = "klop klop = Horse trotting = Croatian / ";
const char string_149[] PROGMEM = "i-a = Donkey braying = Croatian / ";
const char string_150[] PROGMEM = "vrinsk = Horse whinnying = Danish / ";
const char string_151[] PROGMEM = "gadagung gadagung = Horse trotting = Danish / ";
const char string_152[] PROGMEM = "kataklop kataklop = Horse trotting = Dutch / ";
const char string_153[] PROGMEM = "ii-ha-haa = Horse whinnying = Finnish / ";
const char string_154[] PROGMEM = "ihaa = Donkey braying = Finnish / ";
const char string_155[] PROGMEM = "hiii hiii = Horse whinnying = French / ";
const char string_156[] PROGMEM = "pa-ta-clop = Horse trotting = French / ";
const char string_157[] PROGMEM = "hi han = Donkey braying = French / ";
const char string_158[] PROGMEM = "wiehiehie = Horse whinnying = German / ";
const char string_159[] PROGMEM = "i-ah = Donkey braying = German / ";
const char string_160[] PROGMEM = "nyihaha = Horse whinnying = Hungarian / ";
const char string_161[] PROGMEM = "klop-klop-klop = Horse trotting = Hungarian / ";
const char string_162[] PROGMEM = "yihaa = Horse whinnying = Indonesian / ";
const char string_163[] PROGMEM = "hiii hiii = Horse whinnying = Italian / ";
const char string_164[] PROGMEM = "ih oh = Donkey braying = Italian / ";
const char string_165[] PROGMEM = "hi-ing = Horse whinnying = Korean / ";
const char string_166[] PROGMEM = "hinni = Horse whinnying = Latin / ";
const char string_167[] PROGMEM = "klap klap = Horse trotting = Latvian / ";
const char string_168[] PROGMEM = "dipada-dapada = Horse galloping = Latvian / ";
const char string_169[] PROGMEM = "vrinsk = Horse whinnying = Norwegian / ";
const char string_170[] PROGMEM = "iii-haaa = Horse whinnying = Polish / ";
const char string_171[] PROGMEM = "iii-haa = Donkey braying = Polish / ";
const char string_172[] PROGMEM = "hi hi = Horse whinnying = Portuguese / ";
const char string_173[] PROGMEM = "ni-ha-ha = Horse whinnying = Romanian / ";
const char string_174[] PROGMEM = "trop trop = Horse trotting = Romanian / ";
const char string_175[] PROGMEM = "i-ha = Donkey braying = Romanian / ";
const char string_176[] PROGMEM = "ji ji = Horse whinnying = Spanish / ";
const char string_177[] PROGMEM = "tucutun tucutun = Horse trotting = Spanish / ";
const char string_178[] PROGMEM = "i-o = Donkey braying = Spanish / ";
const char string_179[] PROGMEM = "hihihi haha = Horse whinnying = Tagalog / ";
const char string_180[] PROGMEM = "ih-hi-i-i = Horse whinnying = Turkish / ";
const char string_181[] PROGMEM = "aa-ii = Donkey braying = Turkish / ";
const char string_182[] PROGMEM = "hA hA hA = Horse whinnying = Vietnamese / ";
const char string_183[] PROGMEM = "nhong nhong = Horse trotting = Vietnamese / ";
const char string_184[] PROGMEM = "woef = Dog barking = Afrikaans / ";
const char string_185[] PROGMEM = "mjau-mjau = Cat meowing = Albanian / ";
const char string_186[] PROGMEM = "ham ham = Dog barking = Albanian / ";
const char string_187[] PROGMEM = "mau = Cat meowing = Basque / ";
const char string_188[] PROGMEM = "ulu-ulu = Dog or wolf howling = Basque / ";
const char string_189[] PROGMEM = "ngeong = Cat meowing = Batak / ";
const char string_190[] PROGMEM = "kung-kung = Dog barking = Batak / ";
const char string_191[] PROGMEM = "auuung = Dog or wolf howling = Batak / ";
const char string_192[] PROGMEM = "huukka huuya = Dog or wolf howling = Bengali / ";
const char string_193[] PROGMEM = "auuu = Dog or wolf howling = Bulgarian / ";
const char string_194[] PROGMEM = "mAu-mAu = Cat meowing = Chinese, Cantonese / ";
const char string_195[] PROGMEM = "wAu-wAu = Dog barking = Chinese, Cantonese / ";
const char string_196[] PROGMEM = "mjau = Cat meowing = Croatian / ";
const char string_197[] PROGMEM = "vau vau = Dog barking = Croatian / ";
const char string_198[] PROGMEM = "haf haf = Dog barking = Czech / ";
const char string_199[] PROGMEM = "miu = Cat meowing = Egyptian / ";
const char string_200[] PROGMEM = "awooo = Dog or wolf howling = English / ";
const char string_201[] PROGMEM = "auh auh = Dog barking = Estonian / ";
const char string_202[] PROGMEM = "auuu = Dog or wolf howling = Finnish / ";
const char string_203[] PROGMEM = "aoouu = Dog or wolf howling = French / ";
const char string_204[] PROGMEM = "jau jau = Dog barking = Galician / ";
const char string_205[] PROGMEM = "vau vau = Dog barking = Hungarian / ";
const char string_206[] PROGMEM = "voff voff = Dog barking = Icelandic / ";
const char string_207[] PROGMEM = "meong = Cat meowing = Indonesian / ";
const char string_208[] PROGMEM = "guk guk = Dog barking = Indonesian / ";
const char string_209[] PROGMEM = "auuu = Dog or wolf howling = Indonesian / ";
const char string_210[] PROGMEM = "auuu = Dog or wolf howling = Italian / ";
const char string_211[] PROGMEM = "bow bow = Dog barking = Kannada / ";
const char string_212[] PROGMEM = "Aau Aau = Cat meowing = Latgalian / ";
const char string_213[] PROGMEM = "vau vau = Dog barking = Latgalian / ";
const char string_214[] PROGMEM = "vau = Dog barking = Latvian / ";
const char string_215[] PROGMEM = "miau = Cat meowing = Lithuanian / ";
const char string_216[] PROGMEM = "au au = Dog barking = Lithuanian / ";
const char string_217[] PROGMEM = "myaoo myaoo = Cat meowing = Malayalam / ";
const char string_218[] PROGMEM = "bau bau = Dog barking = Malayalam / ";
const char string_219[] PROGMEM = "mjau = Cat meowing = Norwegian / ";
const char string_220[] PROGMEM = "mioo mioo = Cat meowing = Persian / ";
const char string_221[] PROGMEM = "miau = Cat meowing = Polish / ";
const char string_222[] PROGMEM = "hau hau = Dog barking = Polish / ";
const char string_223[] PROGMEM = "a-uuu = Dog or wolf howling = Polish / ";
const char string_224[] PROGMEM = "auuu = Dog or wolf howling = Portuguese / ";
const char string_225[] PROGMEM = "miau = Cat meowing = Romanian / ";
const char string_226[] PROGMEM = "ham ham = Dog barking = Romanian / ";
const char string_227[] PROGMEM = "auuu = Dog or wolf howling = Romanian / ";
const char string_228[] PROGMEM = "wu-u-u = Dog or wolf howling = Russian / ";
const char string_229[] PROGMEM = "mijav = Cat meowing = Slovene / ";
const char string_230[] PROGMEM = "hov hov = Dog barking = Slovene / ";
const char string_231[] PROGMEM = "auuu = Dog or wolf howling = Spanish / ";
const char string_232[] PROGMEM = "aw aw = Dog barking = Tagalog / ";
const char string_233[] PROGMEM = "miao= m = Cat meowing = Telugu / ";
const char string_234[] PROGMEM = "bau bau = Dog barking = Telugu / ";
const char string_235[] PROGMEM = "miyav = Cat meowing = Turkish / ";
const char string_236[] PROGMEM = "hav hav = Dog barking = Turkish / ";
const char string_237[] PROGMEM = "auuu = Dog or wolf howling = Turkish / ";
const char string_238[] PROGMEM = "miaw = Cat meowing = Uropi / ";
const char string_239[] PROGMEM = "waw waw = Dog barking = Uropi / ";
const char string_240[] PROGMEM = "meo = Cat meowing = Vietnamese / ";
const char string_241[] PROGMEM = "u-u e-e = Monkey chatting = Czech / ";
const char string_242[] PROGMEM = "roar = Lion/tiger roaring = English / ";
const char string_243[] PROGMEM = "oo-ooh a-aah = Monkey chatting = English / ";
const char string_244[] PROGMEM = "mur = Lion/tiger roaring = Finnish / ";
const char string_245[] PROGMEM = "braah = Elephant trumpeting = French / ";
const char string_246[] PROGMEM = "ouah ah ah hein = Monkey chatting = French / ";
const char string_247[] PROGMEM = "tAPrAPAP = Elephant trumpeting = German / ";
const char string_248[] PROGMEM = "mak-mak = Monkey chatting = Hungarian / ";
const char string_249[] PROGMEM = "ngoah = Elephant trumpeting = Indonesian / ";
const char string_250[] PROGMEM = "aum = Lion/tiger roaring = Indonesian / ";
const char string_251[] PROGMEM = "kak kak kak = Monkey chatting = Indonesian / ";
const char string_252[] PROGMEM = "baaa = Elephant trumpeting = Italian / ";
const char string_253[] PROGMEM = "roar = Lion/tiger roaring = Italian / ";
const char string_254[] PROGMEM = "u-u-ah-ah-ah = Monkey chatting = Italian / ";
const char string_255[] PROGMEM = "ars = Lion/tiger roaring = Kazakh / ";
const char string_256[] PROGMEM = "u-u = Monkey chatting = Polish / ";
const char string_257[] PROGMEM = "urawr = Lion/tiger roaring = Portuguese / ";
const char string_258[] PROGMEM = "grrrrr = Lion/tiger roaring = Romanian / ";
const char string_259[] PROGMEM = "biaaah = Elephant trumpeting = Spanish / ";
const char string_260[] PROGMEM = "tuut = Elephant trumpeting = Swedish / ";
const char string_261[] PROGMEM = "awoo = Elephant trumpeting = Tagalog / ";
const char string_262[] PROGMEM = "hoo-hoo-aah = Monkey chatting = Tagalog / ";
const char string_263[] PROGMEM = "ravr = Lion/tiger roaring = Turkish / ";
const char string_264[] PROGMEM = "zoem = Bee buzzing = Afrikaans / ";
const char string_265[] PROGMEM = "kwaak = Frog croaking = Afrikaans / ";
const char string_266[] PROGMEM = "sis = Snake hissing = Afrikaans / ";
const char string_267[] PROGMEM = "brun-brun = Bee buzzing = Basque / ";
const char string_268[] PROGMEM = "kro-kro = Frog croaking = Basque / ";
const char string_269[] PROGMEM = "zi-zi = Snake hissing = Basque / ";
const char string_270[] PROGMEM = "ngung-ngung = Bee buzzing = Batak / ";
const char string_271[] PROGMEM = "gun gun = Bee buzzing = Bengali / ";
const char string_272[] PROGMEM = "phnosh = Snake hissing = Bengali / ";
const char string_273[] PROGMEM = "sss = Snake hissing = Bulgarian / ";
const char string_274[] PROGMEM = "kre kre = Frog croaking = Croatian / ";
const char string_275[] PROGMEM = "hsss = Snake hissing = Croatian / ";
const char string_276[] PROGMEM = "bzzz = Bee buzzing = Czech / ";
const char string_277[] PROGMEM = "sss = Snake hissing = Czech / ";
const char string_278[] PROGMEM = "sum = Bee buzzing = Danish / ";
const char string_279[] PROGMEM = "kwaak kwaak = Frog croaking = Dutch / ";
const char string_280[] PROGMEM = "summ-summ-summ = Bee buzzing = Estonian / ";
const char string_281[] PROGMEM = "krooks krooks = Frog croaking = Estonian / ";
const char string_282[] PROGMEM = "bzzz = Bee buzzing = French / ";
const char string_283[] PROGMEM = "croa croa = Frog croaking = French / ";
const char string_284[] PROGMEM = "siff = Snake hissing = French / ";
const char string_285[] PROGMEM = "cro cro = Frog croaking = Galician / ";
const char string_286[] PROGMEM = "summ = Bee buzzing = German / ";
const char string_287[] PROGMEM = "zisch = Snake hissing = German / ";
const char string_288[] PROGMEM = "tarr tarr = Frog croaking = Hindi / ";
const char string_289[] PROGMEM = "sssz = Snake hissing = Hungarian / ";
const char string_290[] PROGMEM = "nguing = Bee buzzing = Indonesian / ";
const char string_291[] PROGMEM = "krok krok = Frog croaking = Indonesian / ";
const char string_292[] PROGMEM = "pis pis = Snake hissing = Italian / ";
const char string_293[] PROGMEM = "kvA kvA = Frog croaking = Latvian / ";
const char string_294[] PROGMEM = "kva kva = Frog croaking = Lithuanian / ";
const char string_295[] PROGMEM = "zzz = Bee buzzing = Marathi / ";
const char string_296[] PROGMEM = "sum sum = Bee buzzing = Norwegian / ";
const char string_297[] PROGMEM = "vez-vez = Bee buzzing = Persian / ";
const char string_298[] PROGMEM = "sss = Snake hissing = Polish / ";
const char string_299[] PROGMEM = "croac croac = Frog croaking = Portuguese / ";
const char string_300[] PROGMEM = "sss = Snake hissing = Portuguese / ";
const char string_301[] PROGMEM = "oac oac = Frog croaking = Romanian / ";
const char string_302[] PROGMEM = "sss = Snake hissing = Romanian / ";
const char string_303[] PROGMEM = "zhhh = Bee buzzing = Russian / ";
const char string_304[] PROGMEM = "shhh = Snake hissing = Russian / ";
const char string_305[] PROGMEM = "aPPaP aPPaP baka baka = Frog croaking = Sinhalese / ";
const char string_306[] PROGMEM = "zum = Bee buzzing = Spanish / ";
const char string_307[] PROGMEM = "croac croac = Frog croaking = Spanish / ";
const char string_308[] PROGMEM = "sss = Snake hissing = Spanish / ";
const char string_309[] PROGMEM = "surr surr = Bee buzzing = Swedish / ";
const char string_310[] PROGMEM = "zzz = Bee buzzing = Tagalog / ";
const char string_311[] PROGMEM = "kokak kokak = Frog croaking = Tagalog / ";
const char string_312[] PROGMEM = "sss = Snake hissing = Tagalog / ";
const char string_313[] PROGMEM = "beka beka = Frog croaking = Telugu / ";
const char string_314[] PROGMEM = "buss = Snake hissing = Telugu / ";
const char string_315[] PROGMEM = "vrak vrak = Frog croaking = Turkish / ";
const char string_316[] PROGMEM = "twiet twiet = Bird singing = Afrikaans / ";
const char string_317[] PROGMEM = "hoe-hoe = Owl hooting = Afrikaans / ";
const char string_318[] PROGMEM = "ciu-ciu = Bird singing = Albanian / ";
const char string_319[] PROGMEM = "txio-txio = Bird singing = Basque / ";
const char string_320[] PROGMEM = "karra-karra = Crow calling = Basque / ";
const char string_321[] PROGMEM = "kichir michir = Bird singing = Bengali / ";
const char string_322[] PROGMEM = "huup huup = Owl hooting = Bengali / ";
const char string_323[] PROGMEM = "Aip Aip = Bird singing = Bosnian / ";
const char string_324[] PROGMEM = "xut = Owl hooting = Catalan / ";
const char string_325[] PROGMEM = "Aip Aip = Bird singing = Croatian / ";
const char string_326[] PROGMEM = "kra kra = Crow calling = Croatian / ";
const char string_327[] PROGMEM = "hu hu = Owl hooting = Croatian / ";
const char string_328[] PROGMEM = "kra kra = Crow calling = Danish / ";
const char string_329[] PROGMEM = "kra kra = Crow calling = Dutch / ";
const char string_330[] PROGMEM = "oehoe = Owl hooting = Dutch / ";
const char string_331[] PROGMEM = "caw caw = Crow calling = English / ";
const char string_332[] PROGMEM = "kraaks kraaks = Crow calling = Estonian / ";
const char string_333[] PROGMEM = "uhuu = Owl hooting = Estonian / ";
const char string_334[] PROGMEM = "kraa kraa = Crow calling = Finnish / ";
const char string_335[] PROGMEM = "huhuu = Owl hooting = Finnish / ";
const char string_336[] PROGMEM = "ouh ouh = Owl hooting = French / ";
const char string_337[] PROGMEM = "krah krah = Crow calling = German / ";
const char string_338[] PROGMEM = "hu hu = Owl hooting = German / ";
const char string_339[] PROGMEM = "cheh cheh = Bird singing = Hindi / ";
const char string_340[] PROGMEM = "kaa kaa = Crow calling = Hindi / ";
const char string_341[] PROGMEM = "csip-csirip = Bird singing = Hungarian / ";
const char string_342[] PROGMEM = "hAo hAo = Owl hooting = Hungarian / ";
const char string_343[] PROGMEM = "bAbA = Bird singing = Icelandic / ";
const char string_344[] PROGMEM = "kuk-kuk = Owl hooting = Indonesian / ";
const char string_345[] PROGMEM = "cra cra = Crow calling = Italian / ";
const char string_346[] PROGMEM = "huu huu = Owl hooting = Italian / ";
const char string_347[] PROGMEM = "kha-kha = Crow calling = Kannada / ";
const char string_348[] PROGMEM = "qarq-qarq = Crow calling = Kazakh / ";
const char string_349[] PROGMEM = "krA = Crow calling = Latgalian / ";
const char string_350[] PROGMEM = "krA = Crow calling = Latvian / ";
const char string_351[] PROGMEM = "kar kar = Crow calling = Lithuanian / ";
const char string_352[] PROGMEM = "cip cip = Bird singing = Malay / ";
const char string_353[] PROGMEM = "coo coo = Bird singing = Malayalam / ";
const char string_354[] PROGMEM = "kra kra = Crow calling = Malayalam / ";
const char string_355[] PROGMEM = "kra kra = Crow calling = Norwegian / ";
const char string_356[] PROGMEM = "qAr-qAr = Crow calling = Persian / ";
const char string_357[] PROGMEM = "kra kra = Crow calling = Polish / ";
const char string_358[] PROGMEM = "hu-huuu = Owl hooting = Polish / ";
const char string_359[] PROGMEM = "piu piu = Bird singing = Portuguese / ";
const char string_360[] PROGMEM = "cra cra = Crow calling = Portuguese / ";
const char string_361[] PROGMEM = "u-huu = Owl hooting = Portuguese / ";
const char string_362[] PROGMEM = "cra cra = Crow calling = Romanian / ";
const char string_363[] PROGMEM = "hu-huuu = Owl hooting = Romanian / ";
const char string_364[] PROGMEM = "kar kar = Crow calling = Russian / ";
const char string_365[] PROGMEM = "ciju-ciju = Bird singing = Serbian / ";
const char string_366[] PROGMEM = "Aiv Aiv = Bird singing = Slovene / ";
const char string_367[] PROGMEM = "kra kra = Crow calling = Slovene / ";
const char string_368[] PROGMEM = "kvitter kvitter = Bird singing = Swedish / ";
const char string_369[] PROGMEM = "ho-hoo = Owl hooting = Swedish / ";
const char string_370[] PROGMEM = "twit twit = Bird singing = Tagalog / ";
const char string_371[] PROGMEM = "koo koo = Bird singing = Tamil / ";
const char string_372[] PROGMEM = "kaa kaa = Crow calling = Tamil / ";
const char string_373[] PROGMEM = "kaau kaau = Crow calling = Telugu / ";
const char string_374[] PROGMEM = "gaak gaak = Crow calling = Turkish / ";
const char string_375[] PROGMEM = "gu guk guuk = Owl hooting = Turkish / ";
const char string_376[] PROGMEM = "chAp chAp = Bird singing = Vietnamese / ";
const char string_377[] PROGMEM = "knetter = Fire = Afrikaans / ";
const char string_378[] PROGMEM = "su-su = Fire = Basque / ";
const char string_379[] PROGMEM = "knetter = Fire = Dutch / ";
const char string_380[] PROGMEM = "crackle crackle = Fire = English / ";
const char string_381[] PROGMEM = "knister knister = Fire = German / ";
const char string_382[] PROGMEM = "rip-rop = Fire = Hungarian / ";
const char string_383[] PROGMEM = "Pachi pachi = Fire = Japanese / ";
const char string_384[] PROGMEM = "trzask = Fire = Polish / ";
const char string_385[] PROGMEM = "knaster knaster = Fire = Swedish / ";
const char string_386[] PROGMEM = "prueb = Fire = Thai / ";
const char string_387[] PROGMEM = "burrun = Lightning = Basque / ";
const char string_388[] PROGMEM = "huist = Lightning = Batak / ";
const char string_389[] PROGMEM = "zack = Lightning = German / ";
const char string_390[] PROGMEM = "beonjjeok = Lightning = Korean / ";
const char string_391[] PROGMEM = "kadaad = Lightning = Marathi / ";
const char string_392[] PROGMEM = "priang = Lightning = Thai / ";
const char string_393[] PROGMEM = "sis = Steam hissing = Afrikaans / ";
const char string_394[] PROGMEM = "fssss = Steam hissing = Arabic / ";
const char string_395[] PROGMEM = "ssssss = Steam hissing = Batak / ";
const char string_396[] PROGMEM = "psss = Steam hissing = English / ";
const char string_397[] PROGMEM = "zisch = Steam hissing = German / ";
const char string_398[] PROGMEM = "psss = Steam hissing = Hebrew / ";
const char string_399[] PROGMEM = "pushu = Steam hissing = Japanese / ";
const char string_400[] PROGMEM = "fas = Steam hissing = Romanian / ";
const char string_401[] PROGMEM = "psssh = Steam hissing = Russian / ";
const char string_402[] PROGMEM = "pssst = Steam hissing = Swedish / ";
const char string_403[] PROGMEM = "sssss = Steam hissing = Tagalog / ";
const char string_404[] PROGMEM = "fuu = Steam hissing = Thai / ";
const char string_405[] PROGMEM = "tueng = Strikes = Thai / ";
const char string_406[] PROGMEM = "rapak = Thunder = Batak / ";
const char string_407[] PROGMEM = "rapak = Thunder = Batak / ";
const char string_408[] PROGMEM = "drip = Water = Afrikaans / ";
const char string_409[] PROGMEM = "tik tik = Water = Arabic / ";
const char string_410[] PROGMEM = "tup tup = Water = Bengali / ";
const char string_411[] PROGMEM = "cap-cap = Water = Bulgarian / ";
const char string_412[] PROGMEM = "dihk-dihk = Water = Chinese, Cantonese / ";
const char string_413[] PROGMEM = "di da = Water = Chinese, Mandarin / ";
const char string_414[] PROGMEM = "kap kap = Water = Croatian / ";
const char string_415[] PROGMEM = "kap = Water = Czech / ";
const char string_416[] PROGMEM = "dryp dryp = Water = Danish / ";
const char string_417[] PROGMEM = "drup drup = Water = Dutch / ";
const char string_418[] PROGMEM = "drip drop = Water = English / ";
const char string_419[] PROGMEM = "tilks tilks = Water = Estonian / ";
const char string_420[] PROGMEM = "tip tip = Water = Finnish / ";
const char string_421[] PROGMEM = "plitsch = Water = German / ";
const char string_422[] PROGMEM = "plits plits = Water = Greek / ";
const char string_423[] PROGMEM = "tif taf = Water = Hebrew / ";
const char string_424[] PROGMEM = "csop-csop = Water = Hungarian / ";
const char string_425[] PROGMEM = "tik tik = Water = Indonesian / ";
const char string_426[] PROGMEM = "plin plin = Water = Italian / ";
const char string_427[] PROGMEM = "potsu potsu = Water = Japanese / ";
const char string_428[] PROGMEM = "ttokttok = Water = Korean / ";
const char string_429[] PROGMEM = "pik pik = Water = Latvian / ";
const char string_430[] PROGMEM = "krapt krapt = Water = Lithuanian / ";
const char string_431[] PROGMEM = "cap cap = Water = Macedonian / ";
const char string_432[] PROGMEM = "tap-tap = Water = Marathi / ";
const char string_433[] PROGMEM = "cek cek = Water = Persian / ";
const char string_434[] PROGMEM = "kap kap = Water = Polish / ";
const char string_435[] PROGMEM = "plim plim = Water = Portuguese / ";
const char string_436[] PROGMEM = "pic pic = Water = Romanian / ";
const char string_437[] PROGMEM = "kap kap = Water = Russian / ";
const char string_438[] PROGMEM = "ploc ploc = Water = Spanish / ";
const char string_439[] PROGMEM = "dripp dropp = Water = Swedish / ";
const char string_440[] PROGMEM = "tuk tuk tuk = Water = Tagalog / ";
const char string_441[] PROGMEM = "sottu-sottu = Water = Tamil / ";
const char string_442[] PROGMEM = "tup tup = Water = Telugu / ";
const char string_443[] PROGMEM = "ting ting = Water = Thai / ";
const char string_444[] PROGMEM = "sip sip = Water = Turkish / ";
const char string_445[] PROGMEM = "plok = Water = Uropi / ";
const char string_446[] PROGMEM = "tong tong = Water = Vietnamese / ";
const char string_447[] PROGMEM = "plyok = Wet strike = Bulgarian / ";
const char string_448[] PROGMEM = "xap = Wet strike = Catalan / ";
const char string_449[] PROGMEM = "sljap = Wet strike = Croatian / ";
const char string_450[] PROGMEM = "plesk = Wet strike = Czech / ";
const char string_451[] PROGMEM = "ba-ji = Wet strike = Chinese, Mandarin / ";
const char string_452[] PROGMEM = "plask = Wet strike = Danish / ";
const char string_453[] PROGMEM = "plons = Wet strike = Dutch / ";
const char string_454[] PROGMEM = "splash = Wet strike = English / ";
const char string_455[] PROGMEM = "larts = Wet strike = Estonian / ";
const char string_456[] PROGMEM = "loiskis = Wet strike = Finnish / ";
const char string_457[] PROGMEM = "plouf = Wet strike = French / ";
const char string_458[] PROGMEM = "patsch = Wet strike = German / ";
const char string_459[] PROGMEM = "platty = Wet strike = Hungarian / ";
const char string_460[] PROGMEM = "crot = Wet strike = Indonesian / ";
const char string_461[] PROGMEM = "bicha = Wet strike = Japanese / ";
const char string_462[] PROGMEM = "cheolpudeok = Wet strike = Korean / ";
const char string_463[] PROGMEM = "chalp = Wet strike = Kyrgyz / ";
const char string_464[] PROGMEM = "trushh = Wet strike = Malay / ";
const char string_465[] PROGMEM = "colop-colop = Wet strike = Persian / ";
const char string_466[] PROGMEM = "plask = Wet strike = Polish / ";
const char string_467[] PROGMEM = "tchibum = Wet strike = Portuguese / ";
const char string_468[] PROGMEM = "pleosc = Wet strike = Romanian / ";
const char string_469[] PROGMEM = "bultykh = Wet strike = Russian / ";
const char string_470[] PROGMEM = "plask = Wet strike = Swedish / ";
const char string_471[] PROGMEM = "plok = Wet strike = Tagalog / ";
const char string_472[] PROGMEM = "plo = Wet strike = Thai / ";
const char string_473[] PROGMEM = "plac = Wet strike = Uropi / ";
const char string_474[] PROGMEM = "bep = Wet strike = Vietnamese / ";
const char string_475[] PROGMEM = "bho = Wind blowing = Bengali / ";
const char string_476[] PROGMEM = "fiiuu = Wind blowing = Bulgarian / ";
const char string_477[] PROGMEM = "fuuu = Wind blowing = Chinese, Mandarin / ";
const char string_478[] PROGMEM = "fiju = Wind blowing = Croatian / ";
const char string_479[] PROGMEM = "fiiii = Wind blowing = Czech / ";
const char string_480[] PROGMEM = "woesh = Wind blowing = Dutch / ";
const char string_481[] PROGMEM = "whoo = Wind blowing = English / ";
const char string_482[] PROGMEM = "viuuh = Wind blowing = Finnish / ";
const char string_483[] PROGMEM = "frou-frou = Wind blowing = French / ";
const char string_484[] PROGMEM = "huiiih = Wind blowing = German / ";
const char string_485[] PROGMEM = "fru fru = Wind blowing = Greek / ";
const char string_486[] PROGMEM = "sarr sarr = Wind blowing = Hindi / ";
const char string_487[] PROGMEM = "hiss-huss = Wind blowing = Hungarian / ";
const char string_488[] PROGMEM = "fiuu = Wind blowing = Italian / ";
const char string_489[] PROGMEM = "byuu byuu = Wind blowing = Japanese / ";
const char string_490[] PROGMEM = "wing-wing = Wind blowing = Korean / ";
const char string_491[] PROGMEM = "sss = Wind blowing = Lithuanian / ";
const char string_492[] PROGMEM = "fuuuu fuuuu = Wind blowing = Macedonian / ";
const char string_493[] PROGMEM = "moj = Wind blowing = Persian / ";
const char string_494[] PROGMEM = "szszszsz = Wind blowing = Polish / ";
const char string_495[] PROGMEM = "Vuuuush = Wind blowing = Portuguese / ";
const char string_496[] PROGMEM = "vaj = Wind blowing = Romanian / ";
const char string_497[] PROGMEM = "uu-u = Wind blowing = Russian / ";
const char string_498[] PROGMEM = "fuuuu fuuuu = Wind blowing = Spanish / ";
const char string_499[] PROGMEM = "svisch = Wind blowing = Swedish / ";
const char string_500[] PROGMEM = "fuuuu fuuuu = Wind blowing = Tagalog / ";
const char string_501[] PROGMEM = "shhhhhhhhhh = Wind blowing = Tamil / ";
const char string_502[] PROGMEM = "shhhhhhh = Wind blowing = Telugu / ";
const char string_503[] PROGMEM = "wio wio = Wind blowing = Thai / ";
const char string_504[] PROGMEM = "vuuuu vuuuu = Wind blowing = Turkish / ";
const char string_505[] PROGMEM = "vi vu = Wind blowing = Vietnamese / ";

int numOfStrings = 506;

const char * const string_table[] PROGMEM =
{
string_0,
string_1,
string_2,
string_3,
string_4,
string_5,
string_6,
string_7,
string_8,
string_9,
string_10,
string_11,
string_12,
string_13,
string_14,
string_15,
string_16,
string_17,
string_18,
string_19,
string_20,
string_21,
string_22,
string_23,
string_24,
string_25,
string_26,
string_27,
string_28,
string_29,
string_30,
string_31,
string_32,
string_33,
string_34,
string_35,
string_36,
string_37,
string_38,
string_39,
string_40,
string_41,
string_42,
string_43,
string_44,
string_45,
string_46,
string_47,
string_48,
string_49,
string_50,
string_51,
string_52,
string_53,
string_54,
string_55,
string_56,
string_57,
string_58,
string_59,
string_60,
string_61,
string_62,
string_63,
string_64,
string_65,
string_66,
string_67,
string_68,
string_69,
string_70,
string_71,
string_72,
string_73,
string_74,
string_75,
string_76,
string_77,
string_78,
string_79,
string_80,
string_81,
string_82,
string_83,
string_84,
string_85,
string_86,
string_87,
string_88,
string_89,
string_90,
string_91,
string_92,
string_93,
string_94,
string_95,
string_96,
string_97,
string_98,
string_99,
string_100,
string_101,
string_102,
string_103,
string_104,
string_105,
string_106,
string_107,
string_108,
string_109,
string_110,
string_111,
string_112,
string_113,
string_114,
string_115,
string_116,
string_117,
string_118,
string_119,
string_120,
string_121,
string_122,
string_123,
string_124,
string_125,
string_126,
string_127,
string_128,
string_129,
string_130,
string_131,
string_132,
string_133,
string_134,
string_135,
string_136,
string_137,
string_138,
string_139,
string_140,
string_141,
string_142,
string_143,
string_144,
string_145,
string_146,
string_147,
string_148,
string_149,
string_150,
string_151,
string_152,
string_153,
string_154,
string_155,
string_156,
string_157,
string_158,
string_159,
string_160,
string_161,
string_162,
string_163,
string_164,
string_165,
string_166,
string_167,
string_168,
string_169,
string_170,
string_171,
string_172,
string_173,
string_174,
string_175,
string_176,
string_177,
string_178,
string_179,
string_180,
string_181,
string_182,
string_183,
string_184,
string_185,
string_186,
string_187,
string_188,
string_189,
string_190,
string_191,
string_192,
string_193,
string_194,
string_195,
string_196,
string_197,
string_198,
string_199,
string_200,
string_201,
string_202,
string_203,
string_204,
string_205,
string_206,
string_207,
string_208,
string_209,
string_210,
string_211,
string_212,
string_213,
string_214,
string_215,
string_216,
string_217,
string_218,
string_219,
string_220,
string_221,
string_222,
string_223,
string_224,
string_225,
string_226,
string_227,
string_228,
string_229,
string_230,
string_231,
string_232,
string_233,
string_234,
string_235,
string_236,
string_237,
string_238,
string_239,
string_240,
string_241,
string_242,
string_243,
string_244,
string_245,
string_246,
string_247,
string_248,
string_249,
string_250,
string_251,
string_252,
string_253,
string_254,
string_255,
string_256,
string_257,
string_258,
string_259,
string_260,
string_261,
string_262,
string_263,
string_264,
string_265,
string_266,
string_267,
string_268,
string_269,
string_270,
string_271,
string_272,
string_273,
string_274,
string_275,
string_276,
string_277,
string_278,
string_279,
string_280,
string_281,
string_282,
string_283,
string_284,
string_285,
string_286,
string_287,
string_288,
string_289,
string_290,
string_291,
string_292,
string_293,
string_294,
string_295,
string_296,
string_297,
string_298,
string_299,
string_300,
string_301,
string_302,
string_303,
string_304,
string_305,
string_306,
string_307,
string_308,
string_309,
string_310,
string_311,
string_312,
string_313,
string_314,
string_315,
string_316,
string_317,
string_318,
string_319,
string_320,
string_321,
string_322,
string_323,
string_324,
string_325,
string_326,
string_327,
string_328,
string_329,
string_330,
string_331,
string_332,
string_333,
string_334,
string_335,
string_336,
string_337,
string_338,
string_339,
string_340,
string_341,
string_342,
string_343,
string_344,
string_345,
string_346,
string_347,
string_348,
string_349,
string_350,
string_351,
string_352,
string_353,
string_354,
string_355,
string_356,
string_357,
string_358,
string_359,
string_360,
string_361,
string_362,
string_363,
string_364,
string_365,
string_366,
string_367,
string_368,
string_369,
string_370,
string_371,
string_372,
string_373,
string_374,
string_375,
string_376,
string_377,
string_378,
string_379,
string_380,
string_381,
string_382,
string_383,
string_384,
string_385,
string_386,
string_387,
string_388,
string_389,
string_390,
string_391,
string_392,
string_393,
string_394,
string_395,
string_396,
string_397,
string_398,
string_399,
string_400,
string_401,
string_402,
string_403,
string_404,
string_405,
string_406,
string_407,
string_408,
string_409,
string_410,
string_411,
string_412,
string_413,
string_414,
string_415,
string_416,
string_417,
string_418,
string_419,
string_420,
string_421,
string_422,
string_423,
string_424,
string_425,
string_426,
string_427,
string_428,
string_429,
string_430,
string_431,
string_432,
string_433,
string_434,
string_435,
string_436,
string_437,
string_438,
string_439,
string_440,
string_441,
string_442,
string_443,
string_444,
string_445,
string_446,
string_447,
string_448,
string_449,
string_450,
string_451,
string_452,
string_453,
string_454,
string_455,
string_456,
string_457,
string_458,
string_459,
string_460,
string_461,
string_462,
string_463,
string_464,
string_465,
string_466,
string_467,
string_468,
string_469,
string_470,
string_471,
string_472,
string_473,
string_474,
string_475,
string_476,
string_477,
string_478,
string_479,
string_480,
string_481,
string_482,
string_483,
string_484,
string_485,
string_486,
string_487,
string_488,
string_489,
string_490,
string_491,
string_492,
string_493,
string_494,
string_495,
string_496,
string_497,
string_498,
string_499,
string_500,
string_501,
string_502,
string_503,
string_504,
string_505,
};


// set max characters. 65 characters per sentence. otherwise it will NOT start!
char buffer[65];



 // a function to be executed periodically
 void repeatMe()
 {
   morse.update();
   if(digitalRead(13) == HIGH) { 
    pixels.setPixelColor(0, pixels.Color(255,255,255));
    pixels.show();
   }

   if(digitalRead(13) == LOW) { 
    pixels.setPixelColor(0, pixels.Color(0,0,0));
    pixels.show();
   }
 }

 void setup()
 { 
    Serial.begin(9600);
    pixels.begin(); // This initializes the NeoPixel library.
    timer.setInterval(1, repeatMe);

    delay(1000);

 }

 void loop() {
   timer.run();
   // if the board is not busy, send next message

   if (morse.busy == 0) {
      strcpy_P(buffer, (char*)pgm_read_word(&(string_table[random(numOfStrings)]))); // Necessary casts and dereferencing, just copy.
      Serial.println( buffer );
      Serial.println(readCounter);
      morse.send(buffer); 
      readCounter ++;
   }
 }

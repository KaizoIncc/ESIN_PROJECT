###! Memoria general
#set_memory 100000 1000000000
###!----------------------------------------------
###!
###! JOCS DE PROVA DE LA CLASSE ANAGRAMES
###!
###!----------------------------------------------
###!
###!  1. Diccionari buit
###!     Errors: string no es canonic i 
###!     longitud(s) < 3, longitud(s) = 3, longitud(s) > 3
###!     string canonic i longitud(s) < 3, longitud(s) = 3, longitud(s) > 3
###!  2. Diccionari no buit
###!     Errors: string no es canonic i 
###!     string canonic i longitud(s) < 3, longitud(s) = 3, longitud(s) > 3
###!  3. longitud(string) = 3, sortida = cero, una, algunes 
###!  4. longitud(string) = 4, sortida = cero, una, algunes
###!  5. longitud(string) = 5, sortida = cero, una, algunes
###!  6. longitud(string) = 6, sortida = cero, una, algunes
###!  7. string = string canonic, sortida = una, dos, algunes
###!  8. string conte repeticions
###!  9. Diccionari 500 paraules
###!
###!------------------------------------------------------------------
###1 Diccionari buit
###!------------------------------------------------------------------
###!
#init a anagrames
###!
#mac COSA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac CA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac OCA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac ACO
[]
##[]
#mac AAACDDILSU
[]
##[]
#mac AC
[]
##[]
###!
#a destroy
###!
###!
###!
###!------------------------------------------------------------------
###2 Diccionari no buit
###!------------------------------------------------------------------
###!
#init a anagrames
#a_ins RASO
#a_ins TOSCA
#a_ins OSA
#a_ins ROSA
#a_ins ORAS
#a_ins SOTA
#a_ins CORSA
#a_ins TACOS
#a_ins TROCAS
#a_ins TROCA
#a_ins CARO
#a_ins ASCO
#a_ins RAS
#a_ins TOS
#a_ins TAS
#a_ins ROTA
#a_ins TACO
#a_ins ATO
#a_ins ORA
#a_ins CATO
#a_ins COSTRA
#a_ins OTRAS
#a_ins ACTOS
#a_ins CASTO
#a_ins CAROS
#a_ins COSA
#a_ins COSTA
#a_ins TOSAS
#a_ins ACTO
#a_ins ARO
#a_ins TOCA
#a_ins TRAS
#a_ins TARO
#a_ins ROCAS
#a_ins RATOS
#a_ins OCAS
#a_ins TASO
#a_ins OSAR
#a_ins CASO
#a_ins OCA
#a_ins CORTAS
#a_ins TOSA
#a_ins ROTAS
#a_ins TOCAS
#a_ins CORTA
#a_ins ASO
#a_ins SACO
#a_ins RATO
#a_ins COTA
#a_ins COTAS
#a_ins OTRA
#a_ins LA
#a_ins DO
#a_ins A
#a_ins AMOS
#a_ins CORTES
#a_ins DEMOSTUX
#a_ins LUZOT
#a_ins TOZUL
#a_ins LOTUZ
#a_ins ZUTOL
#a_ins DEMOSTU
#a_ins DETOSMU
#a_ins TOLUZ
###!
#a_pre OCASO
OCAS
##OCAS
###!
#mac ACCSOCA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac CA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac ASO
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac ACS
[]
##[]
#mac AAACDDILSU
[]
##[]
#mac AC
[]
##[]
###!
###!
###!
###!------------------------------------------------------------------
###3 longitud(string) = 3
###!------------------------------------------------------------------
###!
#mac ORT
[]
##[]
#mac OST
[TOS]
##[TOS]
#mac AOS
[ASO, OSA]
##[ASO, OSA]
###!
###!
###!
###!------------------------------------------------------------------
###4 longitud(string) = 4
###!------------------------------------------------------------------
###!
#mac BOTU
[]
##[]
#mac ARST
[TRAS]
##[TRAS]
#mac ACOT
[ACTO, CATO, COTA, TACO, TOCA]
##[ACTO, CATO, COTA, TACO, TOCA]
###!
###!
###!
###!------------------------------------------------------------------
###5 longitud(string) = 5
###!------------------------------------------------------------------
###!
#mac CORST
[]
##[]
#mac ACORT
[CORTA, TROCA]
##[CORTA, TROCA]
#mac ACORS
[CAROS, CORSA, ROCAS]
##[CAROS, CORSA, ROCAS]
###!
###!
###!
###!------------------------------------------------------------------
###6 longitud(string) = 6
###!------------------------------------------------------------------
###!
#mac EMORST
[]
##[]
#mac CEORST
[CORTES]
##[CORTES]
#mac ACORST
[CORTAS, COSTRA, TROCAS]
##[CORTAS, COSTRA, TROCAS]
###!
###!
###!
###!------------------------------------------------------------------
###7 string = string canonic
###!------------------------------------------------------------------
###!
#mac DEMOSTUX
[DEMOSTUX]
##[DEMOSTUX]
#mac DEMOSTU
[DEMOSTU, DETOSMU]
##[DEMOSTU, DETOSMU]
#mac LOTUZ
[LOTUZ, LUZOT, TOLUZ, TOZUL, ZUTOL]
##[LOTUZ, LUZOT, TOLUZ, TOZUL, ZUTOL]
###!
###!
###!
###!------------------------------------------------------------------
###8 String conte repeticions
###!------------------------------------------------------------------
###!
###!------------------------------------------------------------------
###8.1 String conte una repeticio
###!------------------------------------------------------------------
###!
#a_ins PLAGA
#a_ins APAGO
#a_ins AGOLPA
#a_ins GALOPA
#a_ins ALAGO
#a_ins OLA
#a_ins GOL
#a_ins ALA
#a_ins LAGO
#a_ins LAPA
#a_ins ALGA
#a_ins PAGALO
#a_ins PAGA
#a_ins GALA
#a_ins PALO
#a_ins ALGO
#a_ins PAGO
#a_ins PALA
#a_ins CROAR
#a_ins CORO
#a_ins ORO
#a_ins ACORRO
#a_ins RARO
#a_ins ORAR
#a_ins OCA
#a_ins ARO
#a_ins CORROA
#a_ins CORRO
#a_ins ORCO
#a_ins CARO
#a_ins CARRO
#a_ins ORA
#a_ins ARCO
#a_ins ROCA
#a_ins ORCA
#a_ins CORRO
#a_ins ACORO
#a_ins COORRUUZ
#a_ins CORORUZU
#a_ins CURORUZO
#a_ins CURUROZO
###!
###!
#mac AAL
[ALA]
##[ALA]
#mac AAGL
[ALGA, GALA]
##[ALGA, GALA]
#mac AALP
[LAPA, PALA]
##[LAPA, PALA]
#mac AAGLP
[PLAGA]
##[PLAGA]
#mac AAGLOP
[AGOLPA, GALOPA, PAGALO]
##[AGOLPA, GALOPA, PAGALO]
###!
###!
#mac OOR
[ORO]
##[ORO]
#mac COOR
[CORO, ORCO]
##[CORO, ORCO]
#mac AORR
[ORAR, RARO]
##[ORAR, RARO]
#mac COORR
[CORRO]
##[CORRO]
#mac ACOORR
[ACORRO, CORROA]
##[ACORRO, CORROA]
###!
###!
#mac COORRUUZ
[COORRUUZ, CORORUZU, CURORUZO, CURUROZO]
##[COORRUUZ, CORORUZU, CURORUZO, CURUROZO]
###!
#a destroy
###!
###!
###!
###!------------------------------------------------------------------
###9 Diccionari 500 paraules
###!------------------------------------------------------------------
###!
#init a anagrames
###!
#load anagrames500.in
###!
###! DICCIONARI 500 i algunes mes per inserir en un anagrames
###!
###!
#a_ins RASAS
#a_ins ARMAS
#a_ins MASA
#a_ins AMAR
#a_ins AMA
#a_ins ARA
#a_ins MAR
#a_ins RAMAS
#a_ins SARA
#a_ins RASA
#a_ins ARMA
#a_ins AMAR
#a_ins AMAS
#a_ins ASMA
#a_ins MASAS
#a_ins MASAR
#a_ins ASA
#a_ins MAS
#a_ins RAS
#a_ins MARSAS
#a_ins FRUTAS
#a_ins BROMISTA
#a_ins ADEMAN
#a_ins ANILLO
#a_ins NATURAL
#a_ins BURO
#a_ins RECIBIR
#a_ins ANTRO
#a_ins APANAR
#a_ins APARICION
#a_ins APERITIVO
#a_ins APICE
#a_ins DESCUIDO
#a_ins DESDICHADO
#a_ins INTOLERABLE
#a_ins INVENTARIO
#a_ins SUPEDITAR
#a_ins SUPERVISAR
#a_ins GUINDO
#a_ins HACHON
#a_ins EFECTO
#a_ins APICULTURA
#a_ins MANICOMIO
#a_ins APLIQUE
#a_ins APREHENSION
#a_ins APUNTAR
#a_ins VIAJANTE
#a_ins ARABE
#a_ins ARABIGO
#a_ins ARAGONES
#a_ins ARBOLEDA
#a_ins BUFANDA
#a_ins ABADESA
#a_ins ARCHIDUQUESA
#a_ins VERANEO
#a_ins ARCIPRESTE
#a_ins LEVITAR
#a_ins DOCUMENTACION
#a_ins SOLIDEZ
#a_ins ARDER
#a_ins PARADOR
#a_ins AHOGADILLA
#a_ins ARPA
#a_ins ANDRAJO
#a_ins ASILO
#a_ins ASTRONAUTICO
#a_ins ATEO
#a_ins ATROFIA
#a_ins ATURRULLAR
#a_ins AUDICION
#a_ins AUDITORIA
#a_ins AUTOCRACIA
#a_ins AVANZADA
#a_ins AVISPA
#a_ins AVISPADO
#a_ins BAILABLE
#a_ins MANGAR
#a_ins CONFERENCIA
#a_ins CONFERENCIANTE
#a_ins FLUIDEZ
#a_ins FOLLAR
#a_ins FOTOCOPIA
#a_ins FUEGO
#a_ins DESPREOCUPACION
#a_ins GALERIAS
#a_ins ELECTRIZANTE
#a_ins ELEMENTO
#a_ins ELIMINATORIO
#a_ins DICIEMBRE
#a_ins GASOIL
#a_ins IMPUGNAR
#a_ins IMPUTACION
#a_ins CARGAMENTO
#a_ins CARRUAJE
#a_ins CARTERISTA
#a_ins CACHEMIR
#a_ins ALUMNO
#a_ins ALZACUELLO
#a_ins ALZADO
#a_ins AMANUENSE
#a_ins RESPIRACION
#a_ins COPAS
#a_ins RESULTAR
#a_ins CHICHARRO
#a_ins CASTANAZO
#a_ins MANOJO
#a_ins CALDERILLA
#a_ins CASTOR
#a_ins CATACUMBAS
#a_ins MANIFESTANTE
#a_ins SILLON
#a_ins MUEBLES
#a_ins CACHARRERIA
#a_ins CACHONDEO
#a_ins CALENTON
#a_ins CINCUENTENARIO
#a_ins CAMINO
#a_ins VENTA
#a_ins CANSAR
#a_ins CAPACITAR
#a_ins ALBORNOZ
#a_ins ALCAHUETE
#a_ins ALCOHOLERO
#a_ins ALCORNOQUE
#a_ins LEOPARDO
#a_ins DOPING
#a_ins DOQUIER
#a_ins DOTAR
#a_ins DROMEDARIO
#a_ins TRASLITERAR
#a_ins BARCO
#a_ins PAGA
#a_ins ENCABEZAMIENTO
#a_ins COMPORTAR
#a_ins DEGUSTACION
#a_ins DELEITAR
#a_ins DEPONER
#a_ins COMPRESA
#a_ins CONDENSADOR
#a_ins HIPNOTIZAR
#a_ins HIPOTENUSA
#a_ins CATE
#a_ins CATETO
#a_ins CATORCEAVO
#a_ins CAZA
#a_ins CE
#a_ins CEBADA
#a_ins CHANDAL
#a_ins CHAPARRAL
#a_ins CHAQUETA
#a_ins HOSTELERIA
#a_ins CHARRETERA
#a_ins CARNE
#a_ins CARNICERIA
#a_ins CHUPADA
#a_ins CIBERNETICA
#a_ins CAL
#a_ins GERANIO
#a_ins CLAVEL
#a_ins PROMONTORIO
#a_ins ANDADURA
#a_ins TUMBONA
#a_ins PROPAROXITONO
#a_ins PROPUGNAR
#a_ins CLIP
#a_ins SOBRESALIENTE
#a_ins SOFISTICADO
#a_ins SOGA
#a_ins LETRA
#a_ins CRISTIANAR
#a_ins FAENA
#a_ins PONCHO
#a_ins BROZA
#a_ins NATA
#a_ins BRONCO
#a_ins ABULIA
#a_ins ACORAZONADO
#a_ins BALEAR
#a_ins BALLENERO
#a_ins RECORRER
#a_ins BALOMPIE
#a_ins BANDOLINA
#a_ins BEBE
#a_ins BERZA
#a_ins BIBLIOGRAFIA
#a_ins BICOCA
#a_ins BIOMBO
#a_ins BISUTERIA
#a_ins BOA
#a_ins BOGAVANTE
#a_ins BOHEMIA
#a_ins HEGIRA
#a_ins ESCALADA
#a_ins BOLA
#a_ins BOMBONES
#a_ins BONITO
#a_ins ABSTENCIONISMO
#a_ins ABANICAR
#a_ins RESPECTIVAMENTE
#a_ins RESURGIR
#a_ins BORDAR
#a_ins ABANIQUEO
#a_ins ABANICAR
#a_ins ABANICAR
#a_ins ABANICO
#a_ins ABATIMIENTO
#a_ins MANOMETRO
#a_ins CABEZUDO
#a_ins CASTANETEO
#a_ins AZUCARERO
#a_ins CHOFER
#a_ins CABALLERO
#a_ins CHIQUILLERIA
#a_ins ASCENSION
#a_ins ACTUALMENTE
#a_ins ACUCIAR
#a_ins ACUOSO
#a_ins ALTERNO
#a_ins AMAR
#a_ins AMOTINAR
#a_ins ANALGESICO
#a_ins ANDAR
#a_ins FANTASTICO
#a_ins FARDO
#a_ins FERMENTAR
#a_ins FESTIVAL
#a_ins AJUSTICIAMIENTO
#a_ins FIEL
#a_ins JETA
#a_ins JOCOSIDAD
#a_ins JOVIAL
#a_ins FIEREZA
#a_ins HINDUISMO
#a_ins HIPERTENSION
#a_ins HIRIENTE
#a_ins FIGON
#a_ins FILMAR
#a_ins CRUSTACEO
#a_ins CUADROS
#a_ins MANOTEAR
#a_ins CULOMBIO
#a_ins DEBIL
#a_ins DEPRECIAR
#a_ins DESASISTIR
#a_ins DESATENDER
#a_ins DESCALCIFICACION
#a_ins ALEGRIA
#a_ins ALETAS
#a_ins ALFA
#a_ins ALMOHADA
#a_ins ALPINISMO
#a_ins DESCALIFICACION
#a_ins DESCREMAR
#a_ins EL
#a_ins ELASTICO
#a_ins ELECTORALISMO
#a_ins OSADIA
#a_ins PROBLEMATICO
#a_ins PROFUGO
#a_ins PROSCRIBIR
#a_ins PROSELITISTA
#a_ins PROSTATA
#a_ins PROVERBIAL
#a_ins EMBAJADOR
#a_ins EMBALSE
#a_ins DESENFRENADO
#a_ins HEROE
#a_ins HERRERIA
#a_ins DESENLAZAR
#a_ins DESESPERADO
#a_ins DESGASTAR
#a_ins DESISTIR
#a_ins DESLUSTRAR
#a_ins DESPERDIGAMIENTO
#a_ins EXIGIR
#a_ins EXORCISTA
#a_ins EXPRESION
#a_ins DESPOTA
#a_ins DIABETICO
#a_ins DIOSA
#a_ins SINCRONIA
#a_ins SLIP
#a_ins SOBAR
#a_ins FRANCOTIRADOR
#a_ins DOCTRINARIO
#a_ins ADMIRATIVO
#a_ins ADMONICION
#a_ins CANCIONERO
#a_ins AGARROTAR
#a_ins AGENTE
#a_ins AGENCIA
#a_ins AGUERRIDO
#a_ins AHORRO
#a_ins BALADA
#a_ins AJENO
#a_ins AJUSTICIAR
#a_ins ALARDE
#a_ins ALBARAN
#a_ins BUROCRATICO
#a_ins ALBERGUE
#a_ins ALBORADA
#a_ins GASTRONOMIA
#a_ins CUESTIONAR
#a_ins GEMIDO
#a_ins GIMNASTICO
#a_ins GLUTEO
#a_ins GRASA
#a_ins GRATINAR
#a_ins GUADALAJARENO
#a_ins GUANTES
#a_ins TREN
#a_ins TRILLON
#a_ins TRIMESTRE
#a_ins TRIPTONGO
#a_ins TRIPULAR
#a_ins TRIUNFAR
#a_ins TUBERCULOSO
#a_ins HERMOSURA
#a_ins HILVAN
#a_ins PERJURIO
#a_ins DESPEREZARSE
#a_ins ESTAMENTO
#a_ins IMPRESIONISTA
#a_ins ESGUINCE
#a_ins LEGUMBRES
#a_ins MANZANO
#a_ins ESTAMPIDO
#a_ins CONQUISTADOR
#a_ins HOSTILIDAD
#a_ins HOTEL
#a_ins HUESPED
#a_ins HUESUDO
#a_ins HULE
#a_ins HUMILLACION
#a_ins INDOMITO
#a_ins TIROTEAR
#a_ins MACEDONIA
#a_ins MACHORRO
#a_ins COCHE
#a_ins COLECTIVIZACION
#a_ins TRANSFORMATIVO
#a_ins TRANSITORIO
#a_ins CEREALISTA
#a_ins CEREBRAL
#a_ins TRANSITORIO
#a_ins TRANSITORIO
#a_ins TRANSITORIO
#a_ins TRANSVERSAL
#a_ins HEREJE
#a_ins HERETICO
#a_ins IDEA
#a_ins INCOGNITO
#a_ins INDESCIFRABLE
#a_ins INDESCRIPTIBLE
#a_ins IMPONER
#a_ins MERENDERO
#a_ins MARXISMO
#a_ins MATRICULA
#a_ins PASA
#a_ins INSISTENCIA
#a_ins INSOLACION
#a_ins INSOSLAYABLE
#a_ins INSUFICIENTE
#a_ins INSUMISION
#a_ins INSUSTANCIAL
#a_ins INTEGRANTE
#a_ins AFORTUNADO
#a_ins CAMISA
#a_ins INVENTO
#a_ins INVIERNO
#a_ins IRRESPONSABILIDAD
#a_ins JACTANCIA
#a_ins JADE
#a_ins JOYA
#a_ins JUGO
#a_ins LATA
#a_ins PEDAGOGO
#a_ins PEDESTAL
#a_ins INMOVILIZAR
#a_ins INMUNDO
#a_ins MANTO
#a_ins LAUD
#a_ins LAXANTE
#a_ins IMPONDERABLE
#a_ins LENCERIA
#a_ins LICENCIA
#a_ins LICENCIATURA
#a_ins LIMONERO
#a_ins LIOSO
#a_ins LIRIO
#a_ins LISONJA
#a_ins LLEGADA
#a_ins MALETIN
#a_ins MALTRATO
#a_ins INCONSCIENCIA
#a_ins INDEFENSO
#a_ins MANIATAR
#a_ins MENTIR
#a_ins METALURGIA
#a_ins NATURALIZAR
#a_ins NITROGLICERINA
#a_ins NOMADISMO
#a_ins MICROONDAS
#a_ins MIGRACION
#a_ins MOCHILA
#a_ins PARAGUAS
#a_ins CONSUMISMO
#a_ins ENEBRO
#a_ins IMPERDIBLE
#a_ins REBOSAR
#a_ins REBUSCAR
#a_ins RECIBIR
#a_ins NON
#a_ins NOTICIARIO
#a_ins NUBLADO
#a_ins RECONSTITUYENTE
#a_ins RES
#a_ins RESALADO
#a_ins VIDEO
#a_ins VIDEOJUEGO
#a_ins VIEIRA
#a_ins VIGENCIA
#a_ins COPULATIVO
#a_ins COQUETO
#a_ins CORDIAL
#a_ins CORRESPONDER
#a_ins ENCOFRAR
#a_ins ENCRUCIJADA
#a_ins SAGA
#a_ins SALPICAR
#a_ins SALVAGUARDAR
#a_ins SAYO
#a_ins IMPASIBILIDAD
#a_ins ESTERNOCLEIDOMASTOIDEO
#a_ins MACHETE
#a_ins EPIGLOTIS
#a_ins ESTERNON
#a_ins ESTRECHAR
#a_ins PESEBRE
#a_ins PESIMISTA
#a_ins PILAR
#a_ins PILLAJE
#a_ins PINTURERO
#a_ins PIROPEAR
#a_ins POSIBILIDAD
#a_ins DESPIOJAR
#a_ins TROTAMUNDOS
#a_ins MODA
#a_ins MODELO
#a_ins MONGOLICO
#a_ins RETABLO
#a_ins RETICENTE
#a_ins O
#a_ins OBLICUIDAD
#a_ins HOMOSEXUAL
#a_ins YESO
#a_ins YO
#a_ins YOQUI
#a_ins ZAGUERO
#a_ins ZANAHORIA
#a_ins ZARZAMORA
#a_ins ASEMEJAR
#a_ins ZOO
#a_ins ORDENAR
#a_ins OSTRA
#a_ins OTORRINOLARINGOLOGO
#a_ins PACHON
#a_ins PAN
#a_ins PANADERO
#a_ins PANECILLO
#a_ins DESPIADADO
#a_ins CONGELADOR
#a_ins CONGELAR
#a_ins SEBORREA
#a_ins SECADORA
#a_ins SEDANTE
#a_ins SEMENTAL
#a_ins CALVICIE
#a_ins SEMILLA
#a_ins SENSACION
#a_ins HOMOGENEO
#a_ins SEQUITO
#a_ins SERVICIO
#a_ins SICOANALISIS
#a_ins SIMETRICO
#a_ins STATUS
#a_ins SU
#a_ins SUBSIDIO
#a_ins SUBSTANCIOSO
#a_ins ASERCION
#a_ins SUBSTITUTO
#a_ins SULFATAR
#a_ins TABASCO
#a_ins BROCHE
#a_ins TARTAMUDEAR
#a_ins TEATRAL
#a_ins TIENDA
#a_ins TILO
#a_ins VANIDAD
#a_ins ESTRES
#a_ins DESPRENDIMIENTO
#a_ins DESPRENDIDO
#a_ins VASO
#a_ins TOQUE
#a_ins ZOPENCO
#a_ins CALLEJERO
#a_ins HOMICIDA
#a_ins ZUTANO
#a_ins PRENDIMIENTO
#a_ins PRENAR
#a_ins RESOLUCION
#a_ins GRAMA
#a_ins PROGRAMADOR
#a_ins PULPITO
#a_ins PURPURINA
#a_ins QUEDAR
#a_ins RADIACTIVO
#a_ins RADIADOR
#a_ins ASUNTO
#a_ins REBELARSE
#a_ins ESO
#a_ins TOS
#a_ins ESTIO
#a_ins HITO
#a_ins TIESO
#a_ins ESTO
#a_ins OISTE
#a_ins HITOS
#a_ins TOSE
#a_ins TIOS
#a_ins SITOS
#a_ins SETO
#a_ins SET
#a_ins TIO
#a_ins OIS
#a_ins ESPESA
#a_ins SEPAS
#a_ins SEAS
#a_ins SEPA
#a_ins ASPEES
#a_ins PASES
#a_ins PESAS
#a_ins SEA
#a_ins ESE
#a_ins SES
#a_ins ASE
#a_ins ASES
#a_ins ESAS
#a_ins PASE
#a_ins PEAS
#a_ins SESEA
#a_ins ASPES
#a_ins PASESE
#a_ins PESASE
#a_ins PESA
#a_ins PESE
#a_ins ESES
#a_ins SE
#a_ins ES
###!
#mac EIOST
[ESTIO, OISTE, TIESO]
##[ESTIO, OISTE, TIESO]
#mac AEPS
[PASE, PEAS, PESA, SEPA]
##[PASE, PEAS, PESA, SEPA]
#mac AEPSS
[ASPES, PASES, PESAS, SEPAS]
##[ASPES, PASES, PESAS, SEPAS]
#mac AAMR
[AMAR, ARMA]
##[AMAR, ARMA]
#mac AAMRS
[ARMAS, MASAR, RAMAS]
##[ARMAS, MASAR, RAMAS]
#mac AAMS
[AMAS, ASMA, MASA]
##[AMAS, ASMA, MASA]
#mac AADGMOOPRRR
[PROGRAMADOR]
##[PROGRAMADOR]
###!
#a destroy
[0/0]

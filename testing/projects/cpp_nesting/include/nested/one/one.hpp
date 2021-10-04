/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2019                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief This file should be one level down in the hierarchy.
 */
#pragma once

namespace nested {
    /// The first class inside the ``nested`` namespace.
    struct one {
        /// Nesting even further: ``nested::one::params``.
        struct params {
            /// A union that occupies four bytes: http://en.cppreference.com/w/cpp/language/union
            union four_bytes {
                std::int32_t n;    ///< occupies 4 bytes
                std::uint16_t s[2];///< occupies 4 bytes
                std::uint8_t c;    ///< occupies 1 byte
            };

            /// Returns ``true`` ;)
            bool compiles() { return true; }
        };

        /// Returns ``true`` ;)
        bool compiles() { return true; }
    };
}

#if defined(DOXYGEN_TEST_PAGES)
/**
 * \page chapter_I CHAPTER I: Jonathan Harker's Journal
 *
 * (_Kept in shorthand._)
 *
 * _3 May. Bistritz._--Left Munich at 8:35 P. M., on 1st May, arriving at
 * Vienna early next morning; should have arrived at 6:46, but train was an
 * hour late. Buda-Pesth seems a wonderful place, from the glimpse which I
 * got of it from the train and the little I could walk through the
 * streets. I feared to go very far from the station, as we had arrived
 * late and would start as near the correct time as possible. The
 * impression I had was that we were leaving the West and entering the
 * East; the most western of splendid bridges over the Danube, which is
 * here of noble width and depth, took us among the traditions of Turkish
 * rule.
 *
 * We left in pretty good time, and came after nightfall to Klausenburgh.
 * Here I stopped for the night at the Hotel Royale. I had for dinner, or
 * rather supper, a chicken done up some way with red pepper, which was
 * very good but thirsty. (_Mem._, get recipe for Mina.) I asked the
 * waiter, and he said it was called "paprika hendl," and that, as it was a
 * national dish, I should be able to get it anywhere along the
 * Carpathians. I found my smattering of German very useful here; indeed, I
 * don't know how I should be able to get on without it.
 *
 * Having had some time at my disposal when in London, I had visited the
 * British Museum, and made search among the books and maps in the library
 * regarding Transylvania; it had struck me that some foreknowledge of the
 * country could hardly fail to have some importance in dealing with a
 * nobleman of that country. I find that the district he named is in the
 * extreme east of the country, just on the borders of three states,
 * Transylvania, Moldavia and Bukovina, in the midst of the Carpathian
 * mountains; one of the wildest and least known portions of Europe. I was
 * not able to light on any map or work giving the exact locality of the
 * Castle Dracula, as there are no maps of this country as yet to compare
 * with our own Ordnance Survey maps; but I found that Bistritz, the post
 * town named by Count Dracula, is a fairly well-known place. I shall enter
 * here some of my notes, as they may refresh my memory when I talk over my
 * travels with Mina.
 *
 * In the population of Transylvania there are four distinct nationalities:
 * Saxons in the South, and mixed with them the Wallachs, who are the
 * descendants of the Dacians; Magyars in the West, and Szekelys in the
 * East and North. I am going among the latter, who claim to be descended
 * from Attila and the Huns. This may be so, for when the Magyars conquered
 * the country in the eleventh century they found the Huns settled in it. I
 * read that every known superstition in the world is gathered into the
 * horseshoe of the Carpathians, as if it were the centre of some sort of
 * imaginative whirlpool; if so my stay may be very interesting. (_Mem._, I
 * must ask the Count all about them.)
 *
 * I did not sleep well, though my bed was comfortable enough, for I had
 * all sorts of queer dreams. There was a dog howling all night under my
 * window, which may have had something to do with it; or it may have been
 * the paprika, for I had to drink up all the water in my carafe, and was
 * still thirsty. Towards morning I slept and was wakened by the continuous
 * knocking at my door, so I guess I must have been sleeping soundly then.
 * I had for breakfast more paprika, and a sort of porridge of maize flour
 * which they said was "mamaliga," and egg-plant stuffed with forcemeat, a
 * very excellent dish, which they call "impletata." (_Mem._, get recipe
 * for this also.) I had to hurry breakfast, for the train started a little
 * before eight, or rather it ought to have done so, for after rushing to
 * the station at 7:30 I had to sit in the carriage for more than an hour
 * before we began to move. It seems to me that the further east you go the
 * more unpunctual are the trains. What ought they to be in China?
 *
 * All day long we seemed to dawdle through a country which was full of
 * beauty of every kind. Sometimes we saw little towns or castles on the
 * top of steep hills such as we see in old missals; sometimes we ran by
 * rivers and streams which seemed from the wide stony margin on each side
 * of them to be subject to great floods. It takes a lot of water, and
 * running strong, to sweep the outside edge of a river clear. At every
 * station there were groups of people, sometimes crowds, and in all sorts
 * of attire. Some of them were just like the peasants at home or those I
 * saw coming through France and Germany, with short jackets and round hats
 * and home-made trousers; but others were very picturesque. The women
 * looked pretty, except when you got near them, but they were very clumsy
 * about the waist. They had all full white sleeves of some kind or other,
 * and most of them had big belts with a lot of strips of something
 * fluttering from them like the dresses in a ballet, but of course there
 * were petticoats under them. The strangest figures we saw were the
 * Slovaks, who were more barbarian than the rest, with their big cow-boy
 * hats, great baggy dirty-white trousers, white linen shirts, and enormous
 * heavy leather belts, nearly a foot wide, all studded over with brass
 * nails. They wore high boots, with their trousers tucked into them, and
 * had long black hair and heavy black moustaches. They are very
 * picturesque, but do not look prepossessing. On the stage they would be
 * set down at once as some old Oriental band of brigands. They are,
 * however, I am told, very harmless and rather wanting in natural
 * self-assertion.
 *
 * It was on the dark side of twilight when we got to Bistritz, which is a
 * very interesting old place. Being practically on the frontier--for the
 * Borgo Pass leads from it into Bukovina--it has had a very stormy
 * existence, and it certainly shows marks of it. Fifty years ago a series
 * of great fires took place, which made terrible havoc on five separate
 * occasions. At the very beginning of the seventeenth century it underwent
 * a siege of three weeks and lost 13,000 people, the casualties of war
 * proper being assisted by famine and disease.
 *
 * Count Dracula had directed me to go to the Golden Krone Hotel, which I
 * found, to my great delight, to be thoroughly old-fashioned, for of
 * course I wanted to see all I could of the ways of the country. I was
 * evidently expected, for when I got near the door I faced a
 * cheery-looking elderly woman in the usual peasant dress--white
 * undergarment with long double apron, front, and back, of coloured stuff
 * fitting almost too tight for modesty. When I came close she bowed and
 * said, "The Herr Englishman?" "Yes," I said, "Jonathan Harker." She
 * smiled, and gave some message to an elderly man in white shirt-sleeves,
 * who had followed her to the door. He went, but immediately returned with
 * a letter:--
 *
 *      "My Friend.--Welcome to the Carpathians. I am anxiously expecting
 *      you. Sleep well to-night. At three to-morrow the diligence will
 *      start for Bukovina; a place on it is kept for you. At the Borgo
 *      Pass my carriage will await you and will bring you to me. I trust
 *      that your journey from London has been a happy one, and that you
 *      will enjoy your stay in my beautiful land.
 *
 * "Your friend,
 *
 * "DRACULA."
 *
 *
 * _4 May._--I found that my landlord had got a letter from the Count,
 * directing him to secure the best place on the coach for me; but on
 * making inquiries as to details he seemed somewhat reticent, and
 * pretended that he could not understand my German. This could not be
 * true, because up to then he had understood it perfectly; at least, he
 * answered my questions exactly as if he did. He and his wife, the old
 * lady who had received me, looked at each other in a frightened sort of
 * way. He mumbled out that the money had been sent in a letter, and that
 * was all he knew. When I asked him if he knew Count Dracula, and could
 * tell me anything of his castle, both he and his wife crossed themselves,
 * and, saying that they knew nothing at all, simply refused to speak
 * further. It was so near the time of starting that I had no time to ask
 * any one else, for it was all very mysterious and not by any means
 * comforting.
 *
 * Just before I was leaving, the old lady came up to my room and said in a
 * very hysterical way:
 *
 * "Must you go? Oh! young Herr, must you go?" She was in such an excited
 * state that she seemed to have lost her grip of what German she knew, and
 * mixed it all up with some other language which I did not know at all. I
 * was just able to follow her by asking many questions. When I told her
 * that I must go at once, and that I was engaged on important business,
 * she asked again:
 *
 * "Do you know what day it is?" I answered that it was the fourth of May.
 * She shook her head as she said again:
 *
 * "Oh, yes! I know that! I know that, but do you know what day it is?" On
 * my saying that I did not understand, she went on:
 *
 * "It is the eve of St. George's Day. Do you not know that to-night, when
 * the clock strikes midnight, all the evil things in the world will have
 * full sway? Do you know where you are going, and what you are going to?"
 * She was in such evident distress that I tried to comfort her, but
 * without effect. Finally she went down on her knees and implored me not
 * to go; at least to wait a day or two before starting. It was all very
 * ridiculous but I did not feel comfortable. However, there was business
 * to be done, and I could allow nothing to interfere with it. I therefore
 * tried to raise her up, and said, as gravely as I could, that I thanked
 * her, but my duty was imperative, and that I must go. She then rose and
 * dried her eyes, and taking a crucifix from her neck offered it to me. I
 * did not know what to do, for, as an English Churchman, I have been
 * taught to regard such things as in some measure idolatrous, and yet it
 * seemed so ungracious to refuse an old lady meaning so well and in such a
 * state of mind. She saw, I suppose, the doubt in my face, for she put the
 * rosary round my neck, and said, "For your mother's sake," and went out
 * of the room. I am writing up this part of the diary whilst I am waiting
 * for the coach, which is, of course, late; and the crucifix is still
 * round my neck. Whether it is the old lady's fear, or the many ghostly
 * traditions of this place, or the crucifix itself, I do not know, but I
 * am not feeling nearly as easy in my mind as usual. If this book should
 * ever reach Mina before I do, let it bring my good-bye. Here comes the
 * coach!
 *
 *        *       *       *       *       *
 *
 * _5 May. The Castle._--The grey of the morning has passed, and the sun is
 * high over the distant horizon, which seems jagged, whether with trees or
 * hills I know not, for it is so far off that big things and little are
 * mixed. I am not sleepy, and, as I am not to be called till I awake,
 * naturally I write till sleep comes. There are many odd things to put
 * down, and, lest who reads them may fancy that I dined too well before I
 * left Bistritz, let me put down my dinner exactly. I dined on what they
 * called "robber steak"--bits of bacon, onion, and beef, seasoned with red
 * pepper, and strung on sticks and roasted over the fire, in the simple
 * style of the London cat's meat! The wine was Golden Mediasch, which
 * produces a queer sting on the tongue, which is, however, not
 * disagreeable. I had only a couple of glasses of this, and nothing else.
 *
 * When I got on the coach the driver had not taken his seat, and I saw him
 * talking with the landlady. They were evidently talking of me, for every
 * now and then they looked at me, and some of the people who were sitting
 * on the bench outside the door--which they call by a name meaning
 * "word-bearer"--came and listened, and then looked at me, most of them
 * pityingly. I could hear a lot of words often repeated, queer words, for
 * there were many nationalities in the crowd; so I quietly got my polyglot
 * dictionary from my bag and looked them out. I must say they were not
 * cheering to me, for amongst them were "Ordog"--Satan, "pokol"--hell,
 * "stregoica"--witch, "vrolok" and "vlkoslak"--both of which mean the same
 * thing, one being Slovak and the other Servian for something that is
 * either were-wolf or vampire. (_Mem._, I must ask the Count about these
 * superstitions)
 *
 * When we started, the crowd round the inn door, which had by this time
 * swelled to a considerable size, all made the sign of the cross and
 * pointed two fingers towards me. With some difficulty I got a
 * fellow-passenger to tell me what they meant; he would not answer at
 * first, but on learning that I was English, he explained that it was a
 * charm or guard against the evil eye. This was not very pleasant for me,
 * just starting for an unknown place to meet an unknown man; but every one
 * seemed so kind-hearted, and so sorrowful, and so sympathetic that I
 * could not but be touched. I shall never forget the last glimpse which I
 * had of the inn-yard and its crowd of picturesque figures, all crossing
 * themselves, as they stood round the wide archway, with its background of
 * rich foliage of oleander and orange trees in green tubs clustered in the
 * centre of the yard. Then our driver, whose wide linen drawers covered
 * the whole front of the box-seat--"gotza" they call them--cracked his big
 * whip over his four small horses, which ran abreast, and we set off on
 * our journey.
 *
 * I soon lost sight and recollection of ghostly fears in the beauty of the
 * scene as we drove along, although had I known the language, or rather
 * languages, which my fellow-passengers were speaking, I might not have
 * been able to throw them off so easily. Before us lay a green sloping
 * land full of forests and woods, with here and there steep hills, crowned
 * with clumps of trees or with farmhouses, the blank gable end to the
 * road. There was everywhere a bewildering mass of fruit blossom--apple,
 * plum, pear, cherry; and as we drove by I could see the green grass under
 * the trees spangled with the fallen petals. In and out amongst these
 * green hills of what they call here the "Mittel Land" ran the road,
 * losing itself as it swept round the grassy curve, or was shut out by the
 * straggling ends of pine woods, which here and there ran down the
 * hillsides like tongues of flame. The road was rugged, but still we
 * seemed to fly over it with a feverish haste. I could not understand then
 * what the haste meant, but the driver was evidently bent on losing no
 * time in reaching Borgo Prund. I was told that this road is in summertime
 * excellent, but that it had not yet been put in order after the winter
 * snows. In this respect it is different from the general run of roads in
 * the Carpathians, for it is an old tradition that they are not to be kept
 * in too good order. Of old the Hospadars would not repair them, lest the
 * Turk should think that they were preparing to bring in foreign troops,
 * and so hasten the war which was always really at loading point.
 *
 * Beyond the green swelling hills of the Mittel Land rose mighty slopes
 * of forest up to the lofty steeps of the Carpathians themselves. Right
 * and left of us they towered, with the afternoon sun falling full upon
 * them and bringing out all the glorious colours of this beautiful range,
 * deep blue and purple in the shadows of the peaks, green and brown where
 * grass and rock mingled, and an endless perspective of jagged rock and
 * pointed crags, till these were themselves lost in the distance, where
 * the snowy peaks rose grandly. Here and there seemed mighty rifts in the
 * mountains, through which, as the sun began to sink, we saw now and again
 * the white gleam of falling water. One of my companions touched my arm as
 * we swept round the base of a hill and opened up the lofty, snow-covered
 * peak of a mountain, which seemed, as we wound on our serpentine way, to
 * be right before us:--
 *
 * "Look! Isten szek!"--"God's seat!"--and he crossed himself reverently.
 *
 * As we wound on our endless way, and the sun sank lower and lower behind
 * us, the shadows of the evening began to creep round us. This was
 * emphasised by the fact that the snowy mountain-top still held the
 * sunset, and seemed to glow out with a delicate cool pink. Here and there
 * we passed Cszeks and Slovaks, all in picturesque attire, but I noticed
 * that goitre was painfully prevalent. By the roadside were many crosses,
 * and as we swept by, my companions all crossed themselves. Here and there
 * was a peasant man or woman kneeling before a shrine, who did not even
 * turn round as we approached, but seemed in the self-surrender of
 * devotion to have neither eyes nor ears for the outer world. There were
 * many things new to me: for instance, hay-ricks in the trees, and here
 * and there very beautiful masses of weeping birch, their white stems
 * shining like silver through the delicate green of the leaves. Now and
 * again we passed a leiter-wagon--the ordinary peasant's cart--with its
 * long, snake-like vertebra, calculated to suit the inequalities of the
 * road. On this were sure to be seated quite a group of home-coming
 * peasants, the Cszeks with their white, and the Slovaks with their
 * coloured, sheepskins, the latter carrying lance-fashion their long
 * staves, with axe at end. As the evening fell it began to get very cold,
 * and the growing twilight seemed to merge into one dark mistiness the
 * gloom of the trees, oak, beech, and pine, though in the valleys which
 * ran deep between the spurs of the hills, as we ascended through the
 * Pass, the dark firs stood out here and there against the background of
 * late-lying snow. Sometimes, as the road was cut through the pine woods
 * that seemed in the darkness to be closing down upon us, great masses of
 * greyness, which here and there bestrewed the trees, produced a
 * peculiarly weird and solemn effect, which carried on the thoughts and
 * grim fancies engendered earlier in the evening, when the falling sunset
 * threw into strange relief the ghost-like clouds which amongst the
 * Carpathians seem to wind ceaselessly through the valleys. Sometimes the
 * hills were so steep that, despite our driver's haste, the horses could
 * only go slowly. I wished to get down and walk up them, as we do at home,
 * but the driver would not hear of it. "No, no," he said; "you must not
 * walk here; the dogs are too fierce"; and then he added, with what he
 * evidently meant for grim pleasantry--for he looked round to catch the
 * approving smile of the rest--"and you may have enough of such matters
 * before you go to sleep." The only stop he would make was a moment's
 * pause to light his lamps.
 *
 * When it grew dark there seemed to be some excitement amongst the
 * passengers, and they kept speaking to him, one after the other, as
 * though urging him to further speed. He lashed the horses unmercifully
 * with his long whip, and with wild cries of encouragement urged them on
 * to further exertions. Then through the darkness I could see a sort of
 * patch of grey light ahead of us, as though there were a cleft in the
 * hills. The excitement of the passengers grew greater; the crazy coach
 * rocked on its great leather springs, and swayed like a boat tossed on a
 * stormy sea. I had to hold on. The road grew more level, and we appeared
 * to fly along. Then the mountains seemed to come nearer to us on each
 * side and to frown down upon us; we were entering on the Borgo Pass. One
 * by one several of the passengers offered me gifts, which they pressed
 * upon me with an earnestness which would take no denial; these were
 * certainly of an odd and varied kind, but each was given in simple good
 * faith, with a kindly word, and a blessing, and that strange mixture of
 * fear-meaning movements which I had seen outside the hotel at
 * Bistritz--the sign of the cross and the guard against the evil eye.
 * Then, as we flew along, the driver leaned forward, and on each side the
 * passengers, craning over the edge of the coach, peered eagerly into the
 * darkness. It was evident that something very exciting was either
 * happening or expected, but though I asked each passenger, no one would
 * give me the slightest explanation. This state of excitement kept on for
 * some little time; and at last we saw before us the Pass opening out on
 * the eastern side. There were dark, rolling clouds overhead, and in the
 * air the heavy, oppressive sense of thunder. It seemed as though the
 * mountain range had separated two atmospheres, and that now we had got
 * into the thunderous one. I was now myself looking out for the conveyance
 * which was to take me to the Count. Each moment I expected to see the
 * glare of lamps through the blackness; but all was dark. The only light
 * was the flickering rays of our own lamps, in which the steam from our
 * hard-driven horses rose in a white cloud. We could see now the sandy
 * road lying white before us, but there was on it no sign of a vehicle.
 * The passengers drew back with a sigh of gladness, which seemed to mock
 * my own disappointment. I was already thinking what I had best do, when
 * the driver, looking at his watch, said to the others something which I
 * could hardly hear, it was spoken so quietly and in so low a tone; I
 * thought it was "An hour less than the time." Then turning to me, he said
 * in German worse than my own:--
 *
 * "There is no carriage here. The Herr is not expected after all. He will
 * now come on to Bukovina, and return to-morrow or the next day; better
 * the next day." Whilst he was speaking the horses began to neigh and
 * snort and plunge wildly, so that the driver had to hold them up. Then,
 * amongst a chorus of screams from the peasants and a universal crossing
 * of themselves, a calèche, with four horses, drove up behind us, overtook
 * us, and drew up beside the coach. I could see from the flash of our
 * lamps, as the rays fell on them, that the horses were coal-black and
 * splendid animals. They were driven by a tall man, with a long brown
 * beard and a great black hat, which seemed to hide his face from us. I
 * could only see the gleam of a pair of very bright eyes, which seemed red
 * in the lamplight, as he turned to us. He said to the driver:--
 *
 * "You are early to-night, my friend." The man stammered in reply:--
 *
 * "The English Herr was in a hurry," to which the stranger replied:--
 *
 * "That is why, I suppose, you wished him to go on to Bukovina. You cannot
 * deceive me, my friend; I know too much, and my horses are swift." As he
 * spoke he smiled, and the lamplight fell on a hard-looking mouth, with
 * very red lips and sharp-looking teeth, as white as ivory. One of my
 * companions whispered to another the line from Burger's "Lenore":--
 *
 *     "Denn die Todten reiten schnell"--
 *     ("For the dead travel fast.")
 *
 * The strange driver evidently heard the words, for he looked up with a
 * gleaming smile. The passenger turned his face away, at the same time
 * putting out his two fingers and crossing himself. "Give me the Herr's
 * luggage," said the driver; and with exceeding alacrity my bags were
 * handed out and put in the calèche. Then I descended from the side of the
 * coach, as the calèche was close alongside, the driver helping me with a
 * hand which caught my arm in a grip of steel; his strength must have been
 * prodigious. Without a word he shook his reins, the horses turned, and we
 * swept into the darkness of the Pass. As I looked back I saw the steam
 * from the horses of the coach by the light of the lamps, and projected
 * against it the figures of my late companions crossing themselves. Then
 * the driver cracked his whip and called to his horses, and off they swept
 * on their way to Bukovina. As they sank into the darkness I felt a
 * strange chill, and a lonely feeling came over me; but a cloak was thrown
 * over my shoulders, and a rug across my knees, and the driver said in
 * excellent German:--
 *
 * "The night is chill, mein Herr, and my master the Count bade me take all
 * care of you. There is a flask of slivovitz (the plum brandy of the
 * country) underneath the seat, if you should require it." I did not take
 * any, but it was a comfort to know it was there all the same. I felt a
 * little strangely, and not a little frightened. I think had there been
 * any alternative I should have taken it, instead of prosecuting that
 * unknown night journey. The carriage went at a hard pace straight along,
 * then we made a complete turn and went along another straight road. It
 * seemed to me that we were simply going over and over the same ground
 * again; and so I took note of some salient point, and found that this was
 * so. I would have liked to have asked the driver what this all meant, but
 * I really feared to do so, for I thought that, placed as I was, any
 * protest would have had no effect in case there had been an intention to
 * delay. By-and-by, however, as I was curious to know how time was
 * passing, I struck a match, and by its flame looked at my watch; it was
 * within a few minutes of midnight. This gave me a sort of shock, for I
 * suppose the general superstition about midnight was increased by my
 * recent experiences. I waited with a sick feeling of suspense.
 *
 * Then a dog began to howl somewhere in a farmhouse far down the road--a
 * long, agonised wailing, as if from fear. The sound was taken up by
 * another dog, and then another and another, till, borne on the wind which
 * now sighed softly through the Pass, a wild howling began, which seemed
 * to come from all over the country, as far as the imagination could grasp
 * it through the gloom of the night. At the first howl the horses began to
 * strain and rear, but the driver spoke to them soothingly, and they
 * quieted down, but shivered and sweated as though after a runaway from
 * sudden fright. Then, far off in the distance, from the mountains on each
 * side of us began a louder and a sharper howling--that of wolves--which
 * affected both the horses and myself in the same way--for I was minded to
 * jump from the calèche and run, whilst they reared again and plunged
 * madly, so that the driver had to use all his great strength to keep them
 * from bolting. In a few minutes, however, my own ears got accustomed to
 * the sound, and the horses so far became quiet that the driver was able
 * to descend and to stand before them. He petted and soothed them, and
 * whispered something in their ears, as I have heard of horse-tamers
 * doing, and with extraordinary effect, for under his caresses they became
 * quite manageable again, though they still trembled. The driver again
 * took his seat, and shaking his reins, started off at a great pace. This
 * time, after going to the far side of the Pass, he suddenly turned down a
 * narrow roadway which ran sharply to the right.
 *
 * Soon we were hemmed in with trees, which in places arched right over the
 * roadway till we passed as through a tunnel; and again great frowning
 * rocks guarded us boldly on either side. Though we were in shelter, we
 * could hear the rising wind, for it moaned and whistled through the
 * rocks, and the branches of the trees crashed together as we swept along.
 * It grew colder and colder still, and fine, powdery snow began to fall,
 * so that soon we and all around us were covered with a white blanket. The
 * keen wind still carried the howling of the dogs, though this grew
 * fainter as we went on our way. The baying of the wolves sounded nearer
 * and nearer, as though they were closing round on us from every side. I
 * grew dreadfully afraid, and the horses shared my fear. The driver,
 * however, was not in the least disturbed; he kept turning his head to
 * left and right, but I could not see anything through the darkness.
 *
 * Suddenly, away on our left, I saw a faint flickering blue flame. The
 * driver saw it at the same moment; he at once checked the horses, and,
 * jumping to the ground, disappeared into the darkness. I did not know
 * what to do, the less as the howling of the wolves grew closer; but while
 * I wondered the driver suddenly appeared again, and without a word took
 * his seat, and we resumed our journey. I think I must have fallen asleep
 * and kept dreaming of the incident, for it seemed to be repeated
 * endlessly, and now looking back, it is like a sort of awful nightmare.
 * Once the flame appeared so near the road, that even in the darkness
 * around us I could watch the driver's motions. He went rapidly to where
 * the blue flame arose--it must have been very faint, for it did not seem
 * to illumine the place around it at all--and gathering a few stones,
 * formed them into some device. Once there appeared a strange optical
 * effect: when he stood between me and the flame he did not obstruct it,
 * for I could see its ghostly flicker all the same. This startled me, but
 * as the effect was only momentary, I took it that my eyes deceived me
 * straining through the darkness. Then for a time there were no blue
 * flames, and we sped onwards through the gloom, with the howling of the
 * wolves around us, as though they were following in a moving circle.
 *
 * At last there came a time when the driver went further afield than he
 * had yet gone, and during his absence, the horses began to tremble worse
 * than ever and to snort and scream with fright. I could not see any cause
 * for it, for the howling of the wolves had ceased altogether; but just
 * then the moon, sailing through the black clouds, appeared behind the
 * jagged crest of a beetling, pine-clad rock, and by its light I saw
 * around us a ring of wolves, with white teeth and lolling red tongues,
 * with long, sinewy limbs and shaggy hair. They were a hundred times more
 * terrible in the grim silence which held them than even when they howled.
 * For myself, I felt a sort of paralysis of fear. It is only when a man
 * feels himself face to face with such horrors that he can understand
 * their true import.
 *
 * All at once the wolves began to howl as though the moonlight had had
 * some peculiar effect on them. The horses jumped about and reared, and
 * looked helplessly round with eyes that rolled in a way painful to see;
 * but the living ring of terror encompassed them on every side; and they
 * had perforce to remain within it. I called to the coachman to come, for
 * it seemed to me that our only chance was to try to break out through the
 * ring and to aid his approach. I shouted and beat the side of the
 * calèche, hoping by the noise to scare the wolves from that side, so as
 * to give him a chance of reaching the trap. How he came there, I know
 * not, but I heard his voice raised in a tone of imperious command, and
 * looking towards the sound, saw him stand in the roadway. As he swept his
 * long arms, as though brushing aside some impalpable obstacle, the wolves
 * fell back and back further still. Just then a heavy cloud passed across
 * the face of the moon, so that we were again in darkness.
 *
 * When I could see again the driver was climbing into the calèche, and the
 * wolves had disappeared. This was all so strange and uncanny that a
 * dreadful fear came upon me, and I was afraid to speak or move. The time
 * seemed interminable as we swept on our way, now in almost complete
 * darkness, for the rolling clouds obscured the moon. We kept on
 * ascending, with occasional periods of quick descent, but in the main
 * always ascending. Suddenly, I became conscious of the fact that the
 * driver was in the act of pulling up the horses in the courtyard of a
 * vast ruined castle, from whose tall black windows came no ray of light,
 * and whose broken battlements showed a jagged line against the moonlit
 * sky.
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_II CHAPTER II: Jonathan Harker's Journal
 * _5 May._--I must have been asleep, for certainly if I had been fully
 * awake I must have noticed the approach of such a remarkable place. In
 * the gloom the courtyard looked of considerable size, and as several dark
 * ways led from it under great round arches, it perhaps seemed bigger than
 * it really is. I have not yet been able to see it by daylight.
 *
 * When the calèche stopped, the driver jumped down and held out his hand
 * to assist me to alight. Again I could not but notice his prodigious
 * strength. His hand actually seemed like a steel vice that could have
 * crushed mine if he had chosen. Then he took out my traps, and placed
 * them on the ground beside me as I stood close to a great door, old and
 * studded with large iron nails, and set in a projecting doorway of
 * massive stone. I could see even in the dim light that the stone was
 * massively carved, but that the carving had been much worn by time and
 * weather. As I stood, the driver jumped again into his seat and shook the
 * reins; the horses started forward, and trap and all disappeared down one
 * of the dark openings.
 *
 * I stood in silence where I was, for I did not know what to do. Of bell
 * or knocker there was no sign; through these frowning walls and dark
 * window openings it was not likely that my voice could penetrate. The
 * time I waited seemed endless, and I felt doubts and fears crowding upon
 * me. What sort of place had I come to, and among what kind of people?
 * What sort of grim adventure was it on which I had embarked? Was this a
 * customary incident in the life of a solicitor's clerk sent out to
 * explain the purchase of a London estate to a foreigner? Solicitor's
 * clerk! Mina would not like that. Solicitor--for just before leaving
 * London I got word that my examination was successful; and I am now a
 * full-blown solicitor! I began to rub my eyes and pinch myself to see if
 * I were awake. It all seemed like a horrible nightmare to me, and I
 * expected that I should suddenly awake, and find myself at home, with
 * the dawn struggling in through the windows, as I had now and again felt
 * in the morning after a day of overwork. But my flesh answered the
 * pinching test, and my eyes were not to be deceived. I was indeed awake
 * and among the Carpathians. All I could do now was to be patient, and to
 * wait the coming of the morning.
 *
 * Just as I had come to this conclusion I heard a heavy step approaching
 * behind the great door, and saw through the chinks the gleam of a coming
 * light. Then there was the sound of rattling chains and the clanking of
 * massive bolts drawn back. A key was turned with the loud grating noise
 * of long disuse, and the great door swung back.
 *
 * Within, stood a tall old man, clean shaven save for a long white
 * moustache, and clad in black from head to foot, without a single speck
 * of colour about him anywhere. He held in his hand an antique silver
 * lamp, in which the flame burned without chimney or globe of any kind,
 * throwing long quivering shadows as it flickered in the draught of the
 * open door. The old man motioned me in with his right hand with a courtly
 * gesture, saying in excellent English, but with a strange intonation:--
 *
 * "Welcome to my house! Enter freely and of your own will!" He made no
 * motion of stepping to meet me, but stood like a statue, as though his
 * gesture of welcome had fixed him into stone. The instant, however, that
 * I had stepped over the threshold, he moved impulsively forward, and
 * holding out his hand grasped mine with a strength which made me wince,
 * an effect which was not lessened by the fact that it seemed as cold as
 * ice--more like the hand of a dead than a living man. Again he said:--
 *
 * "Welcome to my house. Come freely. Go safely; and leave something of the
 * happiness you bring!" The strength of the handshake was so much akin to
 * that which I had noticed in the driver, whose face I had not seen, that
 * for a moment I doubted if it were not the same person to whom I was
 * speaking; so to make sure, I said interrogatively:--
 *
 * "Count Dracula?" He bowed in a courtly way as he replied:--
 *
 * "I am Dracula; and I bid you welcome, Mr. Harker, to my house. Come in;
 * the night air is chill, and you must need to eat and rest." As he was
 * speaking, he put the lamp on a bracket on the wall, and stepping out,
 * took my luggage; he had carried it in before I could forestall him. I
 * protested but he insisted:--
 *
 * "Nay, sir, you are my guest. It is late, and my people are not
 * available. Let me see to your comfort myself." He insisted on carrying
 * my traps along the passage, and then up a great winding stair, and
 * along another great passage, on whose stone floor our steps rang
 * heavily. At the end of this he threw open a heavy door, and I rejoiced
 * to see within a well-lit room in which a table was spread for supper,
 * and on whose mighty hearth a great fire of logs, freshly replenished,
 * flamed and flared.
 *
 * The Count halted, putting down my bags, closed the door, and crossing
 * the room, opened another door, which led into a small octagonal room lit
 * by a single lamp, and seemingly without a window of any sort. Passing
 * through this, he opened another door, and motioned me to enter. It was a
 * welcome sight; for here was a great bedroom well lighted and warmed with
 * another log fire,--also added to but lately, for the top logs were
 * fresh--which sent a hollow roar up the wide chimney. The Count himself
 * left my luggage inside and withdrew, saying, before he closed the
 * door:--
 *
 * "You will need, after your journey, to refresh yourself by making your
 * toilet. I trust you will find all you wish. When you are ready, come
 * into the other room, where you will find your supper prepared."
 *
 * The light and warmth and the Count's courteous welcome seemed to have
 * dissipated all my doubts and fears. Having then reached my normal state,
 * I discovered that I was half famished with hunger; so making a hasty
 * toilet, I went into the other room.
 *
 * I found supper already laid out. My host, who stood on one side of the
 * great fireplace, leaning against the stonework, made a graceful wave of
 * his hand to the table, and said:--
 *
 * "I pray you, be seated and sup how you please. You will, I trust, excuse
 * me that I do not join you; but I have dined already, and I do not sup."
 *
 * I handed to him the sealed letter which Mr. Hawkins had entrusted to me.
 * He opened it and read it gravely; then, with a charming smile, he handed
 * it to me to read. One passage of it, at least, gave me a thrill of
 * pleasure.
 *
 * "I must regret that an attack of gout, from which malady I am a constant
 * sufferer, forbids absolutely any travelling on my part for some time to
 * come; but I am happy to say I can send a sufficient substitute, one in
 * whom I have every possible confidence. He is a young man, full of energy
 * and talent in his own way, and of a very faithful disposition. He is
 * discreet and silent, and has grown into manhood in my service. He shall
 * be ready to attend on you when you will during his stay, and shall take
 * your instructions in all matters."
 *
 * The Count himself came forward and took off the cover of a dish, and I
 * fell to at once on an excellent roast chicken. This, with some cheese
 * and a salad and a bottle of old Tokay, of which I had two glasses, was
 * my supper. During the time I was eating it the Count asked me many
 * questions as to my journey, and I told him by degrees all I had
 * experienced.
 *
 * By this time I had finished my supper, and by my host's desire had drawn
 * up a chair by the fire and begun to smoke a cigar which he offered me,
 * at the same time excusing himself that he did not smoke. I had now an
 * opportunity of observing him, and found him of a very marked
 * physiognomy.
 *
 * His face was a strong--a very strong--aquiline, with high bridge of the
 * thin nose and peculiarly arched nostrils; with lofty domed forehead, and
 * hair growing scantily round the temples but profusely elsewhere. His
 * eyebrows were very massive, almost meeting over the nose, and with bushy
 * hair that seemed to curl in its own profusion. The mouth, so far as I
 * could see it under the heavy moustache, was fixed and rather
 * cruel-looking, with peculiarly sharp white teeth; these protruded over
 * the lips, whose remarkable ruddiness showed astonishing vitality in a
 * man of his years. For the rest, his ears were pale, and at the tops
 * extremely pointed; the chin was broad and strong, and the cheeks firm
 * though thin. The general effect was one of extraordinary pallor.
 *
 * Hitherto I had noticed the backs of his hands as they lay on his knees
 * in the firelight, and they had seemed rather white and fine; but seeing
 * them now close to me, I could not but notice that they were rather
 * coarse--broad, with squat fingers. Strange to say, there were hairs in
 * the centre of the palm. The nails were long and fine, and cut to a sharp
 * point. As the Count leaned over me and his hands touched me, I could not
 * repress a shudder. It may have been that his breath was rank, but a
 * horrible feeling of nausea came over me, which, do what I would, I could
 * not conceal. The Count, evidently noticing it, drew back; and with a
 * grim sort of smile, which showed more than he had yet done his
 * protuberant teeth, sat himself down again on his own side of the
 * fireplace. We were both silent for a while; and as I looked towards the
 * window I saw the first dim streak of the coming dawn. There seemed a
 * strange stillness over everything; but as I listened I heard as if from
 * down below in the valley the howling of many wolves. The Count's eyes
 * gleamed, and he said:--
 *
 * "Listen to them--the children of the night. What music they make!"
 * Seeing, I suppose, some expression in my face strange to him, he
 * added:--
 *
 * "Ah, sir, you dwellers in the city cannot enter into the feelings of the
 * hunter." Then he rose and said:--
 *
 * "But you must be tired. Your bedroom is all ready, and to-morrow you
 * shall sleep as late as you will. I have to be away till the afternoon;
 * so sleep well and dream well!" With a courteous bow, he opened for me
 * himself the door to the octagonal room, and I entered my bedroom....
 *
 * I am all in a sea of wonders. I doubt; I fear; I think strange things,
 * which I dare not confess to my own soul. God keep me, if only for the
 * sake of those dear to me!
 *
 *        *       *       *       *       *
 *
 * _7 May._--It is again early morning, but I have rested and enjoyed the
 * last twenty-four hours. I slept till late in the day, and awoke of my
 * own accord. When I had dressed myself I went into the room where we had
 * supped, and found a cold breakfast laid out, with coffee kept hot by the
 * pot being placed on the hearth. There was a card on the table, on which
 * was written:--
 *
 * "I have to be absent for a while. Do not wait for me.--D." I set to and
 * enjoyed a hearty meal. When I had done, I looked for a bell, so that I
 * might let the servants know I had finished; but I could not find one.
 * There are certainly odd deficiencies in the house, considering the
 * extraordinary evidences of wealth which are round me. The table service
 * is of gold, and so beautifully wrought that it must be of immense value.
 * The curtains and upholstery of the chairs and sofas and the hangings of
 * my bed are of the costliest and most beautiful fabrics, and must have
 * been of fabulous value when they were made, for they are centuries old,
 * though in excellent order. I saw something like them in Hampton Court,
 * but there they were worn and frayed and moth-eaten. But still in none of
 * the rooms is there a mirror. There is not even a toilet glass on my
 * table, and I had to get the little shaving glass from my bag before I
 * could either shave or brush my hair. I have not yet seen a servant
 * anywhere, or heard a sound near the castle except the howling of wolves.
 * Some time after I had finished my meal--I do not know whether to call it
 * breakfast or dinner, for it was between five and six o'clock when I had
 * it--I looked about for something to read, for I did not like to go about
 * the castle until I had asked the Count's permission. There was
 * absolutely nothing in the room, book, newspaper, or even writing
 * materials; so I opened another door in the room and found a sort of
 * library. The door opposite mine I tried, but found it locked.
 *
 * In the library I found, to my great delight, a vast number of English
 * books, whole shelves full of them, and bound volumes of magazines and
 * newspapers. A table in the centre was littered with English magazines
 * and newspapers, though none of them were of very recent date. The books
 * were of the most varied kind--history, geography, politics, political
 * economy, botany, geology, law--all relating to England and English life
 * and customs and manners. There were even such books of reference as the
 * London Directory, the "Red" and "Blue" books, Whitaker's Almanac, the
 * Army and Navy Lists, and--it somehow gladdened my heart to see it--the
 * Law List.
 *
 * Whilst I was looking at the books, the door opened, and the Count
 * entered. He saluted me in a hearty way, and hoped that I had had a good
 * night's rest. Then he went on:--
 *
 * "I am glad you found your way in here, for I am sure there is much that
 * will interest you. These companions"--and he laid his hand on some of
 * the books--"have been good friends to me, and for some years past, ever
 * since I had the idea of going to London, have given me many, many hours
 * of pleasure. Through them I have come to know your great England; and to
 * know her is to love her. I long to go through the crowded streets of
 * your mighty London, to be in the midst of the whirl and rush of
 * humanity, to share its life, its change, its death, and all that makes
 * it what it is. But alas! as yet I only know your tongue through books.
 * To you, my friend, I look that I know it to speak."
 *
 * "But, Count," I said, "you know and speak English thoroughly!" He bowed
 * gravely.
 *
 * "I thank you, my friend, for your all too-flattering estimate, but yet I
 * fear that I am but a little way on the road I would travel. True, I know
 * the grammar and the words, but yet I know not how to speak them."
 *
 * "Indeed," I said, "you speak excellently."
 *
 * "Not so," he answered. "Well, I know that, did I move and speak in your
 * London, none there are who would not know me for a stranger. That is not
 * enough for me. Here I am noble; I am _boyar_; the common people know me,
 * and I am master. But a stranger in a strange land, he is no one; men
 * know him not--and to know not is to care not for. I am content if I am
 * like the rest, so that no man stops if he see me, or pause in his
 * speaking if he hear my words, 'Ha, ha! a stranger!' I have been so long
 * master that I would be master still--or at least that none other should
 * be master of me. You come to me not alone as agent of my friend Peter
 * Hawkins, of Exeter, to tell me all about my new estate in London. You
 * shall, I trust, rest here with me awhile, so that by our talking I may
 * learn the English intonation; and I would that you tell me when I make
 * error, even of the smallest, in my speaking. I am sorry that I had to be
 * away so long to-day; but you will, I know, forgive one who has so many
 * important affairs in hand."
 *
 * Of course I said all I could about being willing, and asked if I might
 * come into that room when I chose. He answered: "Yes, certainly," and
 * added:--
 *
 * "You may go anywhere you wish in the castle, except where the doors are
 * locked, where of course you will not wish to go. There is reason that
 * all things are as they are, and did you see with my eyes and know with
 * my knowledge, you would perhaps better understand." I said I was sure of
 * this, and then he went on:--
 *
 * "We are in Transylvania; and Transylvania is not England. Our ways are
 * not your ways, and there shall be to you many strange things. Nay, from
 * what you have told me of your experiences already, you know something of
 * what strange things there may be."
 *
 * This led to much conversation; and as it was evident that he wanted to
 * talk, if only for talking's sake, I asked him many questions regarding
 * things that had already happened to me or come within my notice.
 * Sometimes he sheered off the subject, or turned the conversation by
 * pretending not to understand; but generally he answered all I asked most
 * frankly. Then as time went on, and I had got somewhat bolder, I asked
 * him of some of the strange things of the preceding night, as, for
 * instance, why the coachman went to the places where he had seen the blue
 * flames. He then explained to me that it was commonly believed that on a
 * certain night of the year--last night, in fact, when all evil spirits
 * are supposed to have unchecked sway--a blue flame is seen over any place
 * where treasure has been concealed. "That treasure has been hidden," he
 * went on, "in the region through which you came last night, there can be
 * but little doubt; for it was the ground fought over for centuries by the
 * Wallachian, the Saxon, and the Turk. Why, there is hardly a foot of soil
 * in all this region that has not been enriched by the blood of men,
 * patriots or invaders. In old days there were stirring times, when the
 * Austrian and the Hungarian came up in hordes, and the patriots went out
 * to meet them--men and women, the aged and the children too--and waited
 * their coming on the rocks above the passes, that they might sweep
 * destruction on them with their artificial avalanches. When the invader
 * was triumphant he found but little, for whatever there was had been
 * sheltered in the friendly soil."
 *
 * "But how," said I, "can it have remained so long undiscovered, when
 * there is a sure index to it if men will but take the trouble to look?"
 * The Count smiled, and as his lips ran back over his gums, the long,
 * sharp, canine teeth showed out strangely; he answered:--
 *
 * "Because your peasant is at heart a coward and a fool! Those flames only
 * appear on one night; and on that night no man of this land will, if he
 * can help it, stir without his doors. And, dear sir, even if he did he
 * would not know what to do. Why, even the peasant that you tell me of who
 * marked the place of the flame would not know where to look in daylight
 * even for his own work. Even you would not, I dare be sworn, be able to
 * find these places again?"
 *
 * "There you are right," I said. "I know no more than the dead where even
 * to look for them." Then we drifted into other matters.
 *
 * "Come," he said at last, "tell me of London and of the house which you
 * have procured for me." With an apology for my remissness, I went into my
 * own room to get the papers from my bag. Whilst I was placing them in
 * order I heard a rattling of china and silver in the next room, and as I
 * passed through, noticed that the table had been cleared and the lamp
 * lit, for it was by this time deep into the dark. The lamps were also lit
 * in the study or library, and I found the Count lying on the sofa,
 * reading, of all things in the world, an English Bradshaw's Guide. When I
 * came in he cleared the books and papers from the table; and with him I
 * went into plans and deeds and figures of all sorts. He was interested in
 * everything, and asked me a myriad questions about the place and its
 * surroundings. He clearly had studied beforehand all he could get on the
 * subject of the neighbourhood, for he evidently at the end knew very much
 * more than I did. When I remarked this, he answered:--
 *
 * "Well, but, my friend, is it not needful that I should? When I go there
 * I shall be all alone, and my friend Harker Jonathan--nay, pardon me, I
 * fall into my country's habit of putting your patronymic first--my friend
 * Jonathan Harker will not be by my side to correct and aid me. He will be
 * in Exeter, miles away, probably working at papers of the law with my
 * other friend, Peter Hawkins. So!"
 *
 * We went thoroughly into the business of the purchase of the estate at
 * Purfleet. When I had told him the facts and got his signature to the
 * necessary papers, and had written a letter with them ready to post to
 * Mr. Hawkins, he began to ask me how I had come across so suitable a
 * place. I read to him the notes which I had made at the time, and which I
 * inscribe here:--
 *
 * "At Purfleet, on a by-road, I came across just such a place as seemed to
 * be required, and where was displayed a dilapidated notice that the place
 * was for sale. It is surrounded by a high wall, of ancient structure,
 * built of heavy stones, and has not been repaired for a large number of
 * years. The closed gates are of heavy old oak and iron, all eaten with
 * rust.
 *
 * "The estate is called Carfax, no doubt a corruption of the old _Quatre
 * Face_, as the house is four-sided, agreeing with the cardinal points of
 * the compass. It contains in all some twenty acres, quite surrounded by
 * the solid stone wall above mentioned. There are many trees on it, which
 * make it in places gloomy, and there is a deep, dark-looking pond or
 * small lake, evidently fed by some springs, as the water is clear and
 * flows away in a fair-sized stream. The house is very large and of all
 * periods back, I should say, to mediæval times, for one part is of stone
 * immensely thick, with only a few windows high up and heavily barred with
 * iron. It looks like part of a keep, and is close to an old chapel or
 * church. I could not enter it, as I had not the key of the door leading
 * to it from the house, but I have taken with my kodak views of it from
 * various points. The house has been added to, but in a very straggling
 * way, and I can only guess at the amount of ground it covers, which must
 * be very great. There are but few houses close at hand, one being a very
 * large house only recently added to and formed into a private lunatic
 * asylum. It is not, however, visible from the grounds."
 *
 * When I had finished, he said:--
 *
 * "I am glad that it is old and big. I myself am of an old family, and to
 * live in a new house would kill me. A house cannot be made habitable in a
 * day; and, after all, how few days go to make up a century. I rejoice
 * also that there is a chapel of old times. We Transylvanian nobles love
 * not to think that our bones may lie amongst the common dead. I seek not
 * gaiety nor mirth, not the bright voluptuousness of much sunshine and
 * sparkling waters which please the young and gay. I am no longer young;
 * and my heart, through weary years of mourning over the dead, is not
 * attuned to mirth. Moreover, the walls of my castle are broken; the
 * shadows are many, and the wind breathes cold through the broken
 * battlements and casements. I love the shade and the shadow, and would
 * be alone with my thoughts when I may." Somehow his words and his look
 * did not seem to accord, or else it was that his cast of face made his
 * smile look malignant and saturnine.
 *
 * Presently, with an excuse, he left me, asking me to put all my papers
 * together. He was some little time away, and I began to look at some of
 * the books around me. One was an atlas, which I found opened naturally at
 * England, as if that map had been much used. On looking at it I found in
 * certain places little rings marked, and on examining these I noticed
 * that one was near London on the east side, manifestly where his new
 * estate was situated; the other two were Exeter, and Whitby on the
 * Yorkshire coast.
 *
 * It was the better part of an hour when the Count returned. "Aha!" he
 * said; "still at your books? Good! But you must not work always. Come; I
 * am informed that your supper is ready." He took my arm, and we went into
 * the next room, where I found an excellent supper ready on the table. The
 * Count again excused himself, as he had dined out on his being away from
 * home. But he sat as on the previous night, and chatted whilst I ate.
 * After supper I smoked, as on the last evening, and the Count stayed with
 * me, chatting and asking questions on every conceivable subject, hour
 * after hour. I felt that it was getting very late indeed, but I did not
 * say anything, for I felt under obligation to meet my host's wishes in
 * every way. I was not sleepy, as the long sleep yesterday had fortified
 * me; but I could not help experiencing that chill which comes over one at
 * the coming of the dawn, which is like, in its way, the turn of the tide.
 * They say that people who are near death die generally at the change to
 * the dawn or at the turn of the tide; any one who has when tired, and
 * tied as it were to his post, experienced this change in the atmosphere
 * can well believe it. All at once we heard the crow of a cock coming up
 * with preternatural shrillness through the clear morning air; Count
 * Dracula, jumping to his feet, said:--
 *
 * "Why, there is the morning again! How remiss I am to let you stay up so
 * long. You must make your conversation regarding my dear new country of
 * England less interesting, so that I may not forget how time flies by
 * us," and, with a courtly bow, he quickly left me.
 *
 * I went into my own room and drew the curtains, but there was little to
 * notice; my window opened into the courtyard, all I could see was the
 * warm grey of quickening sky. So I pulled the curtains again, and have
 * written of this day.
 *
 *        *       *       *       *       *
 *
 * _8 May._--I began to fear as I wrote in this book that I was getting too
 * diffuse; but now I am glad that I went into detail from the first, for
 * there is something so strange about this place and all in it that I
 * cannot but feel uneasy. I wish I were safe out of it, or that I had
 * never come. It may be that this strange night-existence is telling on
 * me; but would that that were all! If there were any one to talk to I
 * could bear it, but there is no one. I have only the Count to speak with,
 * and he!--I fear I am myself the only living soul within the place. Let
 * me be prosaic so far as facts can be; it will help me to bear up, and
 * imagination must not run riot with me. If it does I am lost. Let me say
 * at once how I stand--or seem to.
 *
 * I only slept a few hours when I went to bed, and feeling that I could
 * not sleep any more, got up. I had hung my shaving glass by the window,
 * and was just beginning to shave. Suddenly I felt a hand on my shoulder,
 * and heard the Count's voice saying to me, "Good-morning." I started, for
 * it amazed me that I had not seen him, since the reflection of the glass
 * covered the whole room behind me. In starting I had cut myself slightly,
 * but did not notice it at the moment. Having answered the Count's
 * salutation, I turned to the glass again to see how I had been mistaken.
 * This time there could be no error, for the man was close to me, and I
 * could see him over my shoulder. But there was no reflection of him in
 * the mirror! The whole room behind me was displayed; but there was no
 * sign of a man in it, except myself. This was startling, and, coming on
 * the top of so many strange things, was beginning to increase that vague
 * feeling of uneasiness which I always have when the Count is near; but at
 * the instant I saw that the cut had bled a little, and the blood was
 * trickling over my chin. I laid down the razor, turning as I did so half
 * round to look for some sticking plaster. When the Count saw my face, his
 * eyes blazed with a sort of demoniac fury, and he suddenly made a grab at
 * my throat. I drew away, and his hand touched the string of beads which
 * held the crucifix. It made an instant change in him, for the fury passed
 * so quickly that I could hardly believe that it was ever there.
 *
 * "Take care," he said, "take care how you cut yourself. It is more
 * dangerous than you think in this country." Then seizing the shaving
 * glass, he went on: "And this is the wretched thing that has done the
 * mischief. It is a foul bauble of man's vanity. Away with it!" and
 * opening the heavy window with one wrench of his terrible hand, he flung
 * out the glass, which was shattered into a thousand pieces on the stones
 * of the courtyard far below. Then he withdrew without a word. It is very
 * annoying, for I do not see how I am to shave, unless in my watch-case or
 * the bottom of the shaving-pot, which is fortunately of metal.
 *
 * When I went into the dining-room, breakfast was prepared; but I could
 * not find the Count anywhere. So I breakfasted alone. It is strange that
 * as yet I have not seen the Count eat or drink. He must be a very
 * peculiar man! After breakfast I did a little exploring in the castle. I
 * went out on the stairs, and found a room looking towards the South. The
 * view was magnificent, and from where I stood there was every opportunity
 * of seeing it. The castle is on the very edge of a terrible precipice. A
 * stone falling from the window would fall a thousand feet without
 * touching anything! As far as the eye can reach is a sea of green tree
 * tops, with occasionally a deep rift where there is a chasm. Here and
 * there are silver threads where the rivers wind in deep gorges through
 * the forests.
 *
 * But I am not in heart to describe beauty, for when I had seen the view I
 * explored further; doors, doors, doors everywhere, and all locked and
 * bolted. In no place save from the windows in the castle walls is there
 * an available exit.
 *
 * The castle is a veritable prison, and I am a prisoner!
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_III CHAPTER III: Jonathan Harker's Journal
 * When I found that I was a prisoner a sort of wild feeling came over me.
 * I rushed up and down the stairs, trying every door and peering out of
 * every window I could find; but after a little the conviction of my
 * helplessness overpowered all other feelings. When I look back after a
 * few hours I think I must have been mad for the time, for I behaved much
 * as a rat does in a trap. When, however, the conviction had come to me
 * that I was helpless I sat down quietly--as quietly as I have ever done
 * anything in my life--and began to think over what was best to be done. I
 * am thinking still, and as yet have come to no definite conclusion. Of
 * one thing only am I certain; that it is no use making my ideas known to
 * the Count. He knows well that I am imprisoned; and as he has done it
 * himself, and has doubtless his own motives for it, he would only deceive
 * me if I trusted him fully with the facts. So far as I can see, my only
 * plan will be to keep my knowledge and my fears to myself, and my eyes
 * open. I am, I know, either being deceived, like a baby, by my own fears,
 * or else I am in desperate straits; and if the latter be so, I need, and
 * shall need, all my brains to get through.
 *
 * I had hardly come to this conclusion when I heard the great door below
 * shut, and knew that the Count had returned. He did not come at once into
 * the library, so I went cautiously to my own room and found him making
 * the bed. This was odd, but only confirmed what I had all along
 * thought--that there were no servants in the house. When later I saw him
 * through the chink of the hinges of the door laying the table in the
 * dining-room, I was assured of it; for if he does himself all these
 * menial offices, surely it is proof that there is no one else to do them.
 * This gave me a fright, for if there is no one else in the castle, it
 * must have been the Count himself who was the driver of the coach that
 * brought me here. This is a terrible thought; for if so, what does it
 * mean that he could control the wolves, as he did, by only holding up his
 * hand in silence. How was it that all the people at Bistritz and on the
 * coach had some terrible fear for me? What meant the giving of the
 * crucifix, of the garlic, of the wild rose, of the mountain ash? Bless
 * that good, good woman who hung the crucifix round my neck! for it is a
 * comfort and a strength to me whenever I touch it. It is odd that a thing
 * which I have been taught to regard with disfavour and as idolatrous
 * should in a time of loneliness and trouble be of help. Is it that there
 * is something in the essence of the thing itself, or that it is a medium,
 * a tangible help, in conveying memories of sympathy and comfort? Some
 * time, if it may be, I must examine this matter and try to make up my
 * mind about it. In the meantime I must find out all I can about Count
 * Dracula, as it may help me to understand. To-night he may talk of
 * himself, if I turn the conversation that way. I must be very careful,
 * however, not to awake his suspicion.
 *
 *        *       *       *       *       *
 *
 * _Midnight._--I have had a long talk with the Count. I asked him a few
 * questions on Transylvania history, and he warmed up to the subject
 * wonderfully. In his speaking of things and people, and especially of
 * battles, he spoke as if he had been present at them all. This he
 * afterwards explained by saying that to a _boyar_ the pride of his house
 * and name is his own pride, that their glory is his glory, that their
 * fate is his fate. Whenever he spoke of his house he always said "we,"
 * and spoke almost in the plural, like a king speaking. I wish I could put
 * down all he said exactly as he said it, for to me it was most
 * fascinating. It seemed to have in it a whole history of the country. He
 * grew excited as he spoke, and walked about the room pulling his great
 * white moustache and grasping anything on which he laid his hands as
 * though he would crush it by main strength. One thing he said which I
 * shall put down as nearly as I can; for it tells in its way the story of
 * his race:--
 *
 * "We Szekelys have a right to be proud, for in our veins flows the blood
 * of many brave races who fought as the lion fights, for lordship. Here,
 * in the whirlpool of European races, the Ugric tribe bore down from
 * Iceland the fighting spirit which Thor and Wodin gave them, which their
 * Berserkers displayed to such fell intent on the seaboards of Europe, ay,
 * and of Asia and Africa too, till the peoples thought that the
 * were-wolves themselves had come. Here, too, when they came, they found
 * the Huns, whose warlike fury had swept the earth like a living flame,
 * till the dying peoples held that in their veins ran the blood of those
 * old witches, who, expelled from Scythia had mated with the devils in the
 * desert. Fools, fools! What devil or what witch was ever so great as
 * Attila, whose blood is in these veins?" He held up his arms. "Is it a
 * wonder that we were a conquering race; that we were proud; that when the
 * Magyar, the Lombard, the Avar, the Bulgar, or the Turk poured his
 * thousands on our frontiers, we drove them back? Is it strange that when
 * Arpad and his legions swept through the Hungarian fatherland he found us
 * here when he reached the frontier; that the Honfoglalas was completed
 * there? And when the Hungarian flood swept eastward, the Szekelys were
 * claimed as kindred by the victorious Magyars, and to us for centuries
 * was trusted the guarding of the frontier of Turkey-land; ay, and more
 * than that, endless duty of the frontier guard, for, as the Turks say,
 * 'water sleeps, and enemy is sleepless.' Who more gladly than we
 * throughout the Four Nations received the 'bloody sword,' or at its
 * warlike call flocked quicker to the standard of the King? When was
 * redeemed that great shame of my nation, the shame of Cassova, when the
 * flags of the Wallach and the Magyar went down beneath the Crescent? Who
 * was it but one of my own race who as Voivode crossed the Danube and beat
 * the Turk on his own ground? This was a Dracula indeed! Woe was it that
 * his own unworthy brother, when he had fallen, sold his people to the
 * Turk and brought the shame of slavery on them! Was it not this Dracula,
 * indeed, who inspired that other of his race who in a later age again and
 * again brought his forces over the great river into Turkey-land; who,
 * when he was beaten back, came again, and again, and again, though he had
 * to come alone from the bloody field where his troops were being
 * slaughtered, since he knew that he alone could ultimately triumph! They
 * said that he thought only of himself. Bah! what good are peasants
 * without a leader? Where ends the war without a brain and heart to
 * conduct it? Again, when, after the battle of Mohács, we threw off the
 * Hungarian yoke, we of the Dracula blood were amongst their leaders, for
 * our spirit would not brook that we were not free. Ah, young sir, the
 * Szekelys--and the Dracula as their heart's blood, their brains, and
 * their swords--can boast a record that mushroom growths like the
 * Hapsburgs and the Romanoffs can never reach. The warlike days are over.
 * Blood is too precious a thing in these days of dishonourable peace; and
 * the glories of the great races are as a tale that is told."
 *
 * It was by this time close on morning, and we went to bed. (_Mem._, this
 * diary seems horribly like the beginning of the "Arabian Nights," for
 * everything has to break off at cockcrow--or like the ghost of Hamlet's
 * father.)
 *
 *        *       *       *       *       *
 *
 * _12 May._--Let me begin with facts--bare, meagre facts, verified by
 * books and figures, and of which there can be no doubt. I must not
 * confuse them with experiences which will have to rest on my own
 * observation, or my memory of them. Last evening when the Count came from
 * his room he began by asking me questions on legal matters and on the
 * doing of certain kinds of business. I had spent the day wearily over
 * books, and, simply to keep my mind occupied, went over some of the
 * matters I had been examined in at Lincoln's Inn. There was a certain
 * method in the Count's inquiries, so I shall try to put them down in
 * sequence; the knowledge may somehow or some time be useful to me.
 *
 * First, he asked if a man in England might have two solicitors or more. I
 * told him he might have a dozen if he wished, but that it would not be
 * wise to have more than one solicitor engaged in one transaction, as only
 * one could act at a time, and that to change would be certain to militate
 * against his interest. He seemed thoroughly to understand, and went on to
 * ask if there would be any practical difficulty in having one man to
 * attend, say, to banking, and another to look after shipping, in case
 * local help were needed in a place far from the home of the banking
 * solicitor. I asked him to explain more fully, so that I might not by any
 * chance mislead him, so he said:--
 *
 * "I shall illustrate. Your friend and mine, Mr. Peter Hawkins, from under
 * the shadow of your beautiful cathedral at Exeter, which is far from
 * London, buys for me through your good self my place at London. Good! Now
 * here let me say frankly, lest you should think it strange that I have
 * sought the services of one so far off from London instead of some one
 * resident there, that my motive was that no local interest might be
 * served save my wish only; and as one of London residence might, perhaps,
 * have some purpose of himself or friend to serve, I went thus afield to
 * seek my agent, whose labours should be only to my interest. Now, suppose
 * I, who have much of affairs, wish to ship goods, say, to Newcastle, or
 * Durham, or Harwich, or Dover, might it not be that it could with more
 * ease be done by consigning to one in these ports?" I answered that
 * certainly it would be most easy, but that we solicitors had a system of
 * agency one for the other, so that local work could be done locally on
 * instruction from any solicitor, so that the client, simply placing
 * himself in the hands of one man, could have his wishes carried out by
 * him without further trouble.
 *
 * "But," said he, "I could be at liberty to direct myself. Is it not so?"
 *
 * "Of course," I replied; and "such is often done by men of business, who
 * do not like the whole of their affairs to be known by any one person."
 *
 * "Good!" he said, and then went on to ask about the means of making
 * consignments and the forms to be gone through, and of all sorts of
 * difficulties which might arise, but by forethought could be guarded
 * against. I explained all these things to him to the best of my ability,
 * and he certainly left me under the impression that he would have made a
 * wonderful solicitor, for there was nothing that he did not think of or
 * foresee. For a man who was never in the country, and who did not
 * evidently do much in the way of business, his knowledge and acumen were
 * wonderful. When he had satisfied himself on these points of which he had
 * spoken, and I had verified all as well as I could by the books
 * available, he suddenly stood up and said:--
 *
 * "Have you written since your first letter to our friend Mr. Peter
 * Hawkins, or to any other?" It was with some bitterness in my heart that
 * I answered that I had not, that as yet I had not seen any opportunity of
 * sending letters to anybody.
 *
 * "Then write now, my young friend," he said, laying a heavy hand on my
 * shoulder: "write to our friend and to any other; and say, if it will
 * please you, that you shall stay with me until a month from now."
 *
 * "Do you wish me to stay so long?" I asked, for my heart grew cold at the
 * thought.
 *
 * "I desire it much; nay, I will take no refusal. When your master,
 * employer, what you will, engaged that someone should come on his behalf,
 * it was understood that my needs only were to be consulted. I have not
 * stinted. Is it not so?"
 *
 * What could I do but bow acceptance? It was Mr. Hawkins's interest, not
 * mine, and I had to think of him, not myself; and besides, while Count
 * Dracula was speaking, there was that in his eyes and in his bearing
 * which made me remember that I was a prisoner, and that if I wished it I
 * could have no choice. The Count saw his victory in my bow, and his
 * mastery in the trouble of my face, for he began at once to use them, but
 * in his own smooth, resistless way:--
 *
 * "I pray you, my good young friend, that you will not discourse of things
 * other than business in your letters. It will doubtless please your
 * friends to know that you are well, and that you look forward to getting
 * home to them. Is it not so?" As he spoke he handed me three sheets of
 * note-paper and three envelopes. They were all of the thinnest foreign
 * post, and looking at them, then at him, and noticing his quiet smile,
 * with the sharp, canine teeth lying over the red underlip, I understood
 * as well as if he had spoken that I should be careful what I wrote, for
 * he would be able to read it. So I determined to write only formal notes
 * now, but to write fully to Mr. Hawkins in secret, and also to Mina, for
 * to her I could write in shorthand, which would puzzle the Count, if he
 * did see it. When I had written my two letters I sat quiet, reading a
 * book whilst the Count wrote several notes, referring as he wrote them to
 * some books on his table. Then he took up my two and placed them with his
 * own, and put by his writing materials, after which, the instant the door
 * had closed behind him, I leaned over and looked at the letters, which
 * were face down on the table. I felt no compunction in doing so, for
 * under the circumstances I felt that I should protect myself in every way
 * I could.
 *
 * One of the letters was directed to Samuel F. Billington, No. 7, The
 * Crescent, Whitby, another to Herr Leutner, Varna; the third was to
 * Coutts & Co., London, and the fourth to Herren Klopstock & Billreuth,
 * bankers, Buda-Pesth. The second and fourth were unsealed. I was just
 * about to look at them when I saw the door-handle move. I sank back in my
 * seat, having just had time to replace the letters as they had been and
 * to resume my book before the Count, holding still another letter in his
 * hand, entered the room. He took up the letters on the table and stamped
 * them carefully, and then turning to me, said:--
 *
 * "I trust you will forgive me, but I have much work to do in private this
 * evening. You will, I hope, find all things as you wish." At the door he
 * turned, and after a moment's pause said:--
 *
 * "Let me advise you, my dear young friend--nay, let me warn you with all
 * seriousness, that should you leave these rooms you will not by any
 * chance go to sleep in any other part of the castle. It is old, and has
 * many memories, and there are bad dreams for those who sleep unwisely. Be
 * warned! Should sleep now or ever overcome you, or be like to do, then
 * haste to your own chamber or to these rooms, for your rest will then be
 * safe. But if you be not careful in this respect, then"--He finished his
 * speech in a gruesome way, for he motioned with his hands as if he were
 * washing them. I quite understood; my only doubt was as to whether any
 * dream could be more terrible than the unnatural, horrible net of gloom
 * and mystery which seemed closing around me.
 *
 *        *       *       *       *       *
 *
 * _Later._--I endorse the last words written, but this time there is no
 * doubt in question. I shall not fear to sleep in any place where he is
 * not. I have placed the crucifix over the head of my bed--I imagine that
 * my rest is thus freer from dreams; and there it shall remain.
 *
 * When he left me I went to my room. After a little while, not hearing any
 * sound, I came out and went up the stone stair to where I could look out
 * towards the South. There was some sense of freedom in the vast expanse,
 * inaccessible though it was to me, as compared with the narrow darkness
 * of the courtyard. Looking out on this, I felt that I was indeed in
 * prison, and I seemed to want a breath of fresh air, though it were of
 * the night. I am beginning to feel this nocturnal existence tell on me.
 * It is destroying my nerve. I start at my own shadow, and am full of all
 * sorts of horrible imaginings. God knows that there is ground for my
 * terrible fear in this accursed place! I looked out over the beautiful
 * expanse, bathed in soft yellow moonlight till it was almost as light as
 * day. In the soft light the distant hills became melted, and the shadows
 * in the valleys and gorges of velvety blackness. The mere beauty seemed
 * to cheer me; there was peace and comfort in every breath I drew. As I
 * leaned from the window my eye was caught by something moving a storey
 * below me, and somewhat to my left, where I imagined, from the order of
 * the rooms, that the windows of the Count's own room would look out. The
 * window at which I stood was tall and deep, stone-mullioned, and though
 * weatherworn, was still complete; but it was evidently many a day since
 * the case had been there. I drew back behind the stonework, and looked
 * carefully out.
 *
 * What I saw was the Count's head coming out from the window. I did not
 * see the face, but I knew the man by the neck and the movement of his
 * back and arms. In any case I could not mistake the hands which I had had
 * so many opportunities of studying. I was at first interested and
 * somewhat amused, for it is wonderful how small a matter will interest
 * and amuse a man when he is a prisoner. But my very feelings changed to
 * repulsion and terror when I saw the whole man slowly emerge from the
 * window and begin to crawl down the castle wall over that dreadful abyss,
 * _face down_ with his cloak spreading out around him like great wings. At
 * first I could not believe my eyes. I thought it was some trick of the
 * moonlight, some weird effect of shadow; but I kept looking, and it could
 * be no delusion. I saw the fingers and toes grasp the corners of the
 * stones, worn clear of the mortar by the stress of years, and by thus
 * using every projection and inequality move downwards with considerable
 * speed, just as a lizard moves along a wall.
 *
 * What manner of man is this, or what manner of creature is it in the
 * semblance of man? I feel the dread of this horrible place overpowering
 * me; I am in fear--in awful fear--and there is no escape for me; I am
 * encompassed about with terrors that I dare not think of....
 *
 *        *       *       *       *       *
 *
 * _15 May._--Once more have I seen the Count go out in his lizard fashion.
 * He moved downwards in a sidelong way, some hundred feet down, and a good
 * deal to the left. He vanished into some hole or window. When his head
 * had disappeared, I leaned out to try and see more, but without
 * avail--the distance was too great to allow a proper angle of sight. I
 * knew he had left the castle now, and thought to use the opportunity to
 * explore more than I had dared to do as yet. I went back to the room, and
 * taking a lamp, tried all the doors. They were all locked, as I had
 * expected, and the locks were comparatively new; but I went down the
 * stone stairs to the hall where I had entered originally. I found I could
 * pull back the bolts easily enough and unhook the great chains; but the
 * door was locked, and the key was gone! That key must be in the Count's
 * room; I must watch should his door be unlocked, so that I may get it and
 * escape. I went on to make a thorough examination of the various stairs
 * and passages, and to try the doors that opened from them. One or two
 * small rooms near the hall were open, but there was nothing to see in
 * them except old furniture, dusty with age and moth-eaten. At last,
 * however, I found one door at the top of the stairway which, though it
 * seemed to be locked, gave a little under pressure. I tried it harder,
 * and found that it was not really locked, but that the resistance came
 * from the fact that the hinges had fallen somewhat, and the heavy door
 * rested on the floor. Here was an opportunity which I might not have
 * again, so I exerted myself, and with many efforts forced it back so that
 * I could enter. I was now in a wing of the castle further to the right
 * than the rooms I knew and a storey lower down. From the windows I could
 * see that the suite of rooms lay along to the south of the castle, the
 * windows of the end room looking out both west and south. On the latter
 * side, as well as to the former, there was a great precipice. The castle
 * was built on the corner of a great rock, so that on three sides it was
 * quite impregnable, and great windows were placed here where sling, or
 * bow, or culverin could not reach, and consequently light and comfort,
 * impossible to a position which had to be guarded, were secured. To the
 * west was a great valley, and then, rising far away, great jagged
 * mountain fastnesses, rising peak on peak, the sheer rock studded with
 * mountain ash and thorn, whose roots clung in cracks and crevices and
 * crannies of the stone. This was evidently the portion of the castle
 * occupied by the ladies in bygone days, for the furniture had more air of
 * comfort than any I had seen. The windows were curtainless, and the
 * yellow moonlight, flooding in through the diamond panes, enabled one to
 * see even colours, whilst it softened the wealth of dust which lay over
 * all and disguised in some measure the ravages of time and the moth. My
 * lamp seemed to be of little effect in the brilliant moonlight, but I was
 * glad to have it with me, for there was a dread loneliness in the place
 * which chilled my heart and made my nerves tremble. Still, it was better
 * than living alone in the rooms which I had come to hate from the
 * presence of the Count, and after trying a little to school my nerves, I
 * found a soft quietude come over me. Here I am, sitting at a little oak
 * table where in old times possibly some fair lady sat to pen, with much
 * thought and many blushes, her ill-spelt love-letter, and writing in my
 * diary in shorthand all that has happened since I closed it last. It is
 * nineteenth century up-to-date with a vengeance. And yet, unless my
 * senses deceive me, the old centuries had, and have, powers of their own
 * which mere "modernity" cannot kill.
 *
 *        *       *       *       *       *
 *
 * _Later: the Morning of 16 May._--God preserve my sanity, for to this I
 * am reduced. Safety and the assurance of safety are things of the past.
 * Whilst I live on here there is but one thing to hope for, that I may not
 * go mad, if, indeed, I be not mad already. If I be sane, then surely it
 * is maddening to think that of all the foul things that lurk in this
 * hateful place the Count is the least dreadful to me; that to him alone I
 * can look for safety, even though this be only whilst I can serve his
 * purpose. Great God! merciful God! Let me be calm, for out of that way
 * lies madness indeed. I begin to get new lights on certain things which
 * have puzzled me. Up to now I never quite knew what Shakespeare meant
 * when he made Hamlet say:--
 *
 *     "My tablets! quick, my tablets!
 *     'Tis meet that I put it down," etc.,
 *
 * for now, feeling as though my own brain were unhinged or as if the shock
 * had come which must end in its undoing, I turn to my diary for repose.
 * The habit of entering accurately must help to soothe me.
 *
 * The Count's mysterious warning frightened me at the time; it frightens
 * me more now when I think of it, for in future he has a fearful hold upon
 * me. I shall fear to doubt what he may say!
 *
 * When I had written in my diary and had fortunately replaced the book and
 * pen in my pocket I felt sleepy. The Count's warning came into my mind,
 * but I took a pleasure in disobeying it. The sense of sleep was upon me,
 * and with it the obstinacy which sleep brings as outrider. The soft
 * moonlight soothed, and the wide expanse without gave a sense of freedom
 * which refreshed me. I determined not to return to-night to the
 * gloom-haunted rooms, but to sleep here, where, of old, ladies had sat
 * and sung and lived sweet lives whilst their gentle breasts were sad for
 * their menfolk away in the midst of remorseless wars. I drew a great
 * couch out of its place near the corner, so that as I lay, I could look
 * at the lovely view to east and south, and unthinking of and uncaring for
 * the dust, composed myself for sleep. I suppose I must have fallen
 * asleep; I hope so, but I fear, for all that followed was startlingly
 * real--so real that now sitting here in the broad, full sunlight of the
 * morning, I cannot in the least believe that it was all sleep.
 *
 * I was not alone. The room was the same, unchanged in any way since I
 * came into it; I could see along the floor, in the brilliant moonlight,
 * my own footsteps marked where I had disturbed the long accumulation of
 * dust. In the moonlight opposite me were three young women, ladies by
 * their dress and manner. I thought at the time that I must be dreaming
 * when I saw them, for, though the moonlight was behind them, they threw
 * no shadow on the floor. They came close to me, and looked at me for some
 * time, and then whispered together. Two were dark, and had high aquiline
 * noses, like the Count, and great dark, piercing eyes that seemed to be
 * almost red when contrasted with the pale yellow moon. The other was
 * fair, as fair as can be, with great wavy masses of golden hair and eyes
 * like pale sapphires. I seemed somehow to know her face, and to know it
 * in connection with some dreamy fear, but I could not recollect at the
 * moment how or where. All three had brilliant white teeth that shone like
 * pearls against the ruby of their voluptuous lips. There was something
 * about them that made me uneasy, some longing and at the same time some
 * deadly fear. I felt in my heart a wicked, burning desire that they would
 * kiss me with those red lips. It is not good to note this down, lest some
 * day it should meet Mina's eyes and cause her pain; but it is the truth.
 * They whispered together, and then they all three laughed--such a
 * silvery, musical laugh, but as hard as though the sound never could have
 * come through the softness of human lips. It was like the intolerable,
 * tingling sweetness of water-glasses when played on by a cunning hand.
 * The fair girl shook her head coquettishly, and the other two urged her
 * on. One said:--
 *
 * "Go on! You are first, and we shall follow; yours is the right to
 * begin." The other added:--
 *
 * "He is young and strong; there are kisses for us all." I lay quiet,
 * looking out under my eyelashes in an agony of delightful anticipation.
 * The fair girl advanced and bent over me till I could feel the movement
 * of her breath upon me. Sweet it was in one sense, honey-sweet, and sent
 * the same tingling through the nerves as her voice, but with a bitter
 * underlying the sweet, a bitter offensiveness, as one smells in blood.
 *
 * I was afraid to raise my eyelids, but looked out and saw perfectly under
 * the lashes. The girl went on her knees, and bent over me, simply
 * gloating. There was a deliberate voluptuousness which was both thrilling
 * and repulsive, and as she arched her neck she actually licked her lips
 * like an animal, till I could see in the moonlight the moisture shining
 * on the scarlet lips and on the red tongue as it lapped the white sharp
 * teeth. Lower and lower went her head as the lips went below the range of
 * my mouth and chin and seemed about to fasten on my throat. Then she
 * paused, and I could hear the churning sound of her tongue as it licked
 * her teeth and lips, and could feel the hot breath on my neck. Then the
 * skin of my throat began to tingle as one's flesh does when the hand that
 * is to tickle it approaches nearer--nearer. I could feel the soft,
 * shivering touch of the lips on the super-sensitive skin of my throat,
 * and the hard dents of two sharp teeth, just touching and pausing there.
 * I closed my eyes in a languorous ecstasy and waited--waited with beating
 * heart.
 *
 * But at that instant, another sensation swept through me as quick as
 * lightning. I was conscious of the presence of the Count, and of his
 * being as if lapped in a storm of fury. As my eyes opened involuntarily I
 * saw his strong hand grasp the slender neck of the fair woman and with
 * giant's power draw it back, the blue eyes transformed with fury, the
 * white teeth champing with rage, and the fair cheeks blazing red with
 * passion. But the Count! Never did I imagine such wrath and fury, even to
 * the demons of the pit. His eyes were positively blazing. The red light
 * in them was lurid, as if the flames of hell-fire blazed behind them. His
 * face was deathly pale, and the lines of it were hard like drawn wires;
 * the thick eyebrows that met over the nose now seemed like a heaving bar
 * of white-hot metal. With a fierce sweep of his arm, he hurled the woman
 * from him, and then motioned to the others, as though he were beating
 * them back; it was the same imperious gesture that I had seen used to the
 * wolves. In a voice which, though low and almost in a whisper seemed to
 * cut through the air and then ring round the room he said:--
 *
 * "How dare you touch him, any of you? How dare you cast eyes on him when
 * I had forbidden it? Back, I tell you all! This man belongs to me! Beware
 * how you meddle with him, or you'll have to deal with me." The fair girl,
 * with a laugh of ribald coquetry, turned to answer him:--
 *
 * "You yourself never loved; you never love!" On this the other women
 * joined, and such a mirthless, hard, soulless laughter rang through the
 * room that it almost made me faint to hear; it seemed like the pleasure
 * of fiends. Then the Count turned, after looking at my face attentively,
 * and said in a soft whisper:--
 *
 * "Yes, I too can love; you yourselves can tell it from the past. Is it
 * not so? Well, now I promise you that when I am done with him you shall
 * kiss him at your will. Now go! go! I must awaken him, for there is work
 * to be done."
 *
 * "Are we to have nothing to-night?" said one of them, with a low laugh,
 * as she pointed to the bag which he had thrown upon the floor, and which
 * moved as though there were some living thing within it. For answer he
 * nodded his head. One of the women jumped forward and opened it. If my
 * ears did not deceive me there was a gasp and a low wail, as of a
 * half-smothered child. The women closed round, whilst I was aghast with
 * horror; but as I looked they disappeared, and with them the dreadful
 * bag. There was no door near them, and they could not have passed me
 * without my noticing. They simply seemed to fade into the rays of the
 * moonlight and pass out through the window, for I could see outside the
 * dim, shadowy forms for a moment before they entirely faded away.
 *
 * Then the horror overcame me, and I sank down unconscious.
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_IV CHAPTER IV: Jonathan Harker's Journal
 * I awoke in my own bed. If it be that I had not dreamt, the Count must
 * have carried me here. I tried to satisfy myself on the subject, but
 * could not arrive at any unquestionable result. To be sure, there were
 * certain small evidences, such as that my clothes were folded and laid by
 * in a manner which was not my habit. My watch was still unwound, and I am
 * rigorously accustomed to wind it the last thing before going to bed, and
 * many such details. But these things are no proof, for they may have been
 * evidences that my mind was not as usual, and, from some cause or
 * another, I had certainly been much upset. I must watch for proof. Of one
 * thing I am glad: if it was that the Count carried me here and undressed
 * me, he must have been hurried in his task, for my pockets are intact. I
 * am sure this diary would have been a mystery to him which he would not
 * have brooked. He would have taken or destroyed it. As I look round this
 * room, although it has been to me so full of fear, it is now a sort of
 * sanctuary, for nothing can be more dreadful than those awful women, who
 * were--who _are_--waiting to suck my blood.
 *
 *        *       *       *       *       *
 *
 * _18 May._--I have been down to look at that room again in daylight, for
 * I _must_ know the truth. When I got to the doorway at the top of the
 * stairs I found it closed. It had been so forcibly driven against the
 * jamb that part of the woodwork was splintered. I could see that the bolt
 * of the lock had not been shot, but the door is fastened from the inside.
 * I fear it was no dream, and must act on this surmise.
 *
 *        *       *       *       *       *
 *
 * _19 May._--I am surely in the toils. Last night the Count asked me in
 * the suavest tones to write three letters, one saying that my work here
 * was nearly done, and that I should start for home within a few days,
 * another that I was starting on the next morning from the time of the
 * letter, and the third that I had left the castle and arrived at
 * Bistritz. I would fain have rebelled, but felt that in the present state
 * of things it would be madness to quarrel openly with the Count whilst I
 * am so absolutely in his power; and to refuse would be to excite his
 * suspicion and to arouse his anger. He knows that I know too much, and
 * that I must not live, lest I be dangerous to him; my only chance is to
 * prolong my opportunities. Something may occur which will give me a
 * chance to escape. I saw in his eyes something of that gathering wrath
 * which was manifest when he hurled that fair woman from him. He explained
 * to me that posts were few and uncertain, and that my writing now would
 * ensure ease of mind to my friends; and he assured me with so much
 * impressiveness that he would countermand the later letters, which would
 * be held over at Bistritz until due time in case chance would admit of my
 * prolonging my stay, that to oppose him would have been to create new
 * suspicion. I therefore pretended to fall in with his views, and asked
 * him what dates I should put on the letters. He calculated a minute, and
 * then said:--
 *
 * "The first should be June 12, the second June 19, and the third June
 * 29."
 *
 * I know now the span of my life. God help me!
 *
 *        *       *       *       *       *
 *
 * _28 May._--There is a chance of escape, or at any rate of being able to
 * send word home. A band of Szgany have come to the castle, and are
 * encamped in the courtyard. These Szgany are gipsies; I have notes of
 * them in my book. They are peculiar to this part of the world, though
 * allied to the ordinary gipsies all the world over. There are thousands
 * of them in Hungary and Transylvania, who are almost outside all law.
 * They attach themselves as a rule to some great noble or _boyar_, and
 * call themselves by his name. They are fearless and without religion,
 * save superstition, and they talk only their own varieties of the Romany
 * tongue.
 *
 * I shall write some letters home, and shall try to get them to have them
 * posted. I have already spoken them through my window to begin
 * acquaintanceship. They took their hats off and made obeisance and many
 * signs, which, however, I could not understand any more than I could
 * their spoken language....
 *
 *        *       *       *       *       *
 *
 * I have written the letters. Mina's is in shorthand, and I simply ask Mr.
 * Hawkins to communicate with her. To her I have explained my situation,
 * but without the horrors which I may only surmise. It would shock and
 * frighten her to death were I to expose my heart to her. Should the
 * letters not carry, then the Count shall not yet know my secret or the
 * extent of my knowledge....
 *
 *        *       *       *       *       *
 *
 * I have given the letters; I threw them through the bars of my window
 * with a gold piece, and made what signs I could to have them posted. The
 * man who took them pressed them to his heart and bowed, and then put them
 * in his cap. I could do no more. I stole back to the study, and began to
 * read. As the Count did not come in, I have written here....
 *
 *        *       *       *       *       *
 *
 * The Count has come. He sat down beside me, and said in his smoothest
 * voice as he opened two letters:--
 *
 * "The Szgany has given me these, of which, though I know not whence they
 * come, I shall, of course, take care. See!"--he must have looked at
 * it--"one is from you, and to my friend Peter Hawkins; the other"--here
 * he caught sight of the strange symbols as he opened the envelope, and
 * the dark look came into his face, and his eyes blazed wickedly--"the
 * other is a vile thing, an outrage upon friendship and hospitality! It is
 * not signed. Well! so it cannot matter to us." And he calmly held letter
 * and envelope in the flame of the lamp till they were consumed. Then he
 * went on:--
 *
 * "The letter to Hawkins--that I shall, of course, send on, since it is
 * yours. Your letters are sacred to me. Your pardon, my friend, that
 * unknowingly I did break the seal. Will you not cover it again?" He held
 * out the letter to me, and with a courteous bow handed me a clean
 * envelope. I could only redirect it and hand it to him in silence. When
 * he went out of the room I could hear the key turn softly. A minute later
 * I went over and tried it, and the door was locked.
 *
 * When, an hour or two after, the Count came quietly into the room, his
 * coming awakened me, for I had gone to sleep on the sofa. He was very
 * courteous and very cheery in his manner, and seeing that I had been
 * sleeping, he said:--
 *
 * "So, my friend, you are tired? Get to bed. There is the surest rest. I
 * may not have the pleasure to talk to-night, since there are many labours
 * to me; but you will sleep, I pray." I passed to my room and went to bed,
 * and, strange to say, slept without dreaming. Despair has its own calms.
 *
 *        *       *       *       *       *
 *
 * _31 May._--This morning when I woke I thought I would provide myself
 * with some paper and envelopes from my bag and keep them in my pocket, so
 * that I might write in case I should get an opportunity, but again a
 * surprise, again a shock!
 *
 * Every scrap of paper was gone, and with it all my notes, my memoranda,
 * relating to railways and travel, my letter of credit, in fact all that
 * might be useful to me were I once outside the castle. I sat and pondered
 * awhile, and then some thought occurred to me, and I made search of my
 * portmanteau and in the wardrobe where I had placed my clothes.
 *
 * The suit in which I had travelled was gone, and also my overcoat and
 * rug; I could find no trace of them anywhere. This looked like some new
 * scheme of villainy....
 *
 *        *       *       *       *       *
 *
 * _17 June._--This morning, as I was sitting on the edge of my bed
 * cudgelling my brains, I heard without a cracking of whips and pounding
 * and scraping of horses' feet up the rocky path beyond the courtyard.
 * With joy I hurried to the window, and saw drive into the yard two great
 * leiter-wagons, each drawn by eight sturdy horses, and at the head of
 * each pair a Slovak, with his wide hat, great nail-studded belt, dirty
 * sheepskin, and high boots. They had also their long staves in hand. I
 * ran to the door, intending to descend and try and join them through the
 * main hall, as I thought that way might be opened for them. Again a
 * shock: my door was fastened on the outside.
 *
 * Then I ran to the window and cried to them. They looked up at me
 * stupidly and pointed, but just then the "hetman" of the Szgany came out,
 * and seeing them pointing to my window, said something, at which they
 * laughed. Henceforth no effort of mine, no piteous cry or agonised
 * entreaty, would make them even look at me. They resolutely turned away.
 * The leiter-wagons contained great, square boxes, with handles of thick
 * rope; these were evidently empty by the ease with which the Slovaks
 * handled them, and by their resonance as they were roughly moved. When
 * they were all unloaded and packed in a great heap in one corner of the
 * yard, the Slovaks were given some money by the Szgany, and spitting on
 * it for luck, lazily went each to his horse's head. Shortly afterwards, I
 * heard the cracking of their whips die away in the distance.
 *
 *        *       *       *       *       *
 *
 * _24 June, before morning._--Last night the Count left me early, and
 * locked himself into his own room. As soon as I dared I ran up the
 * winding stair, and looked out of the window, which opened south. I
 * thought I would watch for the Count, for there is something going on.
 * The Szgany are quartered somewhere in the castle and are doing work of
 * some kind. I know it, for now and then I hear a far-away muffled sound
 * as of mattock and spade, and, whatever it is, it must be the end of some
 * ruthless villainy.
 *
 * I had been at the window somewhat less than half an hour, when I saw
 * something coming out of the Count's window. I drew back and watched
 * carefully, and saw the whole man emerge. It was a new shock to me to
 * find that he had on the suit of clothes which I had worn whilst
 * travelling here, and slung over his shoulder the terrible bag which I
 * had seen the women take away. There could be no doubt as to his quest,
 * and in my garb, too! This, then, is his new scheme of evil: that he will
 * allow others to see me, as they think, so that he may both leave
 * evidence that I have been seen in the towns or villages posting my own
 * letters, and that any wickedness which he may do shall by the local
 * people be attributed to me.
 *
 * It makes me rage to think that this can go on, and whilst I am shut up
 * here, a veritable prisoner, but without that protection of the law which
 * is even a criminal's right and consolation.
 *
 * I thought I would watch for the Count's return, and for a long time sat
 * doggedly at the window. Then I began to notice that there were some
 * quaint little specks floating in the rays of the moonlight. They were
 * like the tiniest grains of dust, and they whirled round and gathered in
 * clusters in a nebulous sort of way. I watched them with a sense of
 * soothing, and a sort of calm stole over me. I leaned back in the
 * embrasure in a more comfortable position, so that I could enjoy more
 * fully the aërial gambolling.
 *
 * Something made me start up, a low, piteous howling of dogs somewhere far
 * below in the valley, which was hidden from my sight. Louder it seemed to
 * ring in my ears, and the floating motes of dust to take new shapes to
 * the sound as they danced in the moonlight. I felt myself struggling to
 * awake to some call of my instincts; nay, my very soul was struggling,
 * and my half-remembered sensibilities were striving to answer the call. I
 * was becoming hypnotised! Quicker and quicker danced the dust; the
 * moonbeams seemed to quiver as they went by me into the mass of gloom
 * beyond. More and more they gathered till they seemed to take dim phantom
 * shapes. And then I started, broad awake and in full possession of my
 * senses, and ran screaming from the place. The phantom shapes, which were
 * becoming gradually materialised from the moonbeams, were those of the
 * three ghostly women to whom I was doomed. I fled, and felt somewhat
 * safer in my own room, where there was no moonlight and where the lamp
 * was burning brightly.
 *
 * When a couple of hours had passed I heard something stirring in the
 * Count's room, something like a sharp wail quickly suppressed; and then
 * there was silence, deep, awful silence, which chilled me. With a
 * beating heart, I tried the door; but I was locked in my prison, and
 * could do nothing. I sat down and simply cried.
 *
 * As I sat I heard a sound in the courtyard without--the agonised cry of a
 * woman. I rushed to the window, and throwing it up, peered out between
 * the bars. There, indeed, was a woman with dishevelled hair, holding her
 * hands over her heart as one distressed with running. She was leaning
 * against a corner of the gateway. When she saw my face at the window she
 * threw herself forward, and shouted in a voice laden with menace:--
 *
 * "Monster, give me my child!"
 *
 * She threw herself on her knees, and raising up her hands, cried the same
 * words in tones which wrung my heart. Then she tore her hair and beat her
 * breast, and abandoned herself to all the violences of extravagant
 * emotion. Finally, she threw herself forward, and, though I could not see
 * her, I could hear the beating of her naked hands against the door.
 *
 * Somewhere high overhead, probably on the tower, I heard the voice of the
 * Count calling in his harsh, metallic whisper. His call seemed to be
 * answered from far and wide by the howling of wolves. Before many minutes
 * had passed a pack of them poured, like a pent-up dam when liberated,
 * through the wide entrance into the courtyard.
 *
 * There was no cry from the woman, and the howling of the wolves was but
 * short. Before long they streamed away singly, licking their lips.
 *
 * I could not pity her, for I knew now what had become of her child, and
 * she was better dead.
 *
 * What shall I do? what can I do? How can I escape from this dreadful
 * thing of night and gloom and fear?
 *
 *        *       *       *       *       *
 *
 * _25 June, morning._--No man knows till he has suffered from the night
 * how sweet and how dear to his heart and eye the morning can be. When the
 * sun grew so high this morning that it struck the top of the great
 * gateway opposite my window, the high spot which it touched seemed to me
 * as if the dove from the ark had lighted there. My fear fell from me as
 * if it had been a vaporous garment which dissolved in the warmth. I must
 * take action of some sort whilst the courage of the day is upon me. Last
 * night one of my post-dated letters went to post, the first of that fatal
 * series which is to blot out the very traces of my existence from the
 * earth.
 *
 * Let me not think of it. Action!
 *
 * It has always been at night-time that I have been molested or
 * threatened, or in some way in danger or in fear. I have not yet seen the
 * Count in the daylight. Can it be that he sleeps when others wake, that
 * he may be awake whilst they sleep? If I could only get into his room!
 * But there is no possible way. The door is always locked, no way for me.
 *
 * Yes, there is a way, if one dares to take it. Where his body has gone
 * why may not another body go? I have seen him myself crawl from his
 * window. Why should not I imitate him, and go in by his window? The
 * chances are desperate, but my need is more desperate still. I shall risk
 * it. At the worst it can only be death; and a man's death is not a
 * calf's, and the dreaded Hereafter may still be open to me. God help me
 * in my task! Good-bye, Mina, if I fail; good-bye, my faithful friend and
 * second father; good-bye, all, and last of all Mina!
 *
 *        *       *       *       *       *
 *
 * _Same day, later._--I have made the effort, and God, helping me, have
 * come safely back to this room. I must put down every detail in order. I
 * went whilst my courage was fresh straight to the window on the south
 * side, and at once got outside on the narrow ledge of stone which runs
 * around the building on this side. The stones are big and roughly cut,
 * and the mortar has by process of time been washed away between them. I
 * took off my boots, and ventured out on the desperate way. I looked down
 * once, so as to make sure that a sudden glimpse of the awful depth would
 * not overcome me, but after that kept my eyes away from it. I knew pretty
 * well the direction and distance of the Count's window, and made for it
 * as well as I could, having regard to the opportunities available. I did
 * not feel dizzy--I suppose I was too excited--and the time seemed
 * ridiculously short till I found myself standing on the window-sill and
 * trying to raise up the sash. I was filled with agitation, however, when
 * I bent down and slid feet foremost in through the window. Then I looked
 * around for the Count, but, with surprise and gladness, made a discovery.
 * The room was empty! It was barely furnished with odd things, which
 * seemed to have never been used; the furniture was something the same
 * style as that in the south rooms, and was covered with dust. I looked
 * for the key, but it was not in the lock, and I could not find it
 * anywhere. The only thing I found was a great heap of gold in one
 * corner--gold of all kinds, Roman, and British, and Austrian, and
 * Hungarian, and Greek and Turkish money, covered with a film of dust, as
 * though it had lain long in the ground. None of it that I noticed was
 * less than three hundred years old. There were also chains and ornaments,
 * some jewelled, but all of them old and stained.
 *
 * At one corner of the room was a heavy door. I tried it, for, since I
 * could not find the key of the room or the key of the outer door, which
 * was the main object of my search, I must make further examination, or
 * all my efforts would be in vain. It was open, and led through a stone
 * passage to a circular stairway, which went steeply down. I descended,
 * minding carefully where I went, for the stairs were dark, being only lit
 * by loopholes in the heavy masonry. At the bottom there was a dark,
 * tunnel-like passage, through which came a deathly, sickly odour, the
 * odour of old earth newly turned. As I went through the passage the smell
 * grew closer and heavier. At last I pulled open a heavy door which stood
 * ajar, and found myself in an old, ruined chapel, which had evidently
 * been used as a graveyard. The roof was broken, and in two places were
 * steps leading to vaults, but the ground had recently been dug over, and
 * the earth placed in great wooden boxes, manifestly those which had been
 * brought by the Slovaks. There was nobody about, and I made search for
 * any further outlet, but there was none. Then I went over every inch of
 * the ground, so as not to lose a chance. I went down even into the
 * vaults, where the dim light struggled, although to do so was a dread to
 * my very soul. Into two of these I went, but saw nothing except fragments
 * of old coffins and piles of dust; in the third, however, I made a
 * discovery.
 *
 * There, in one of the great boxes, of which there were fifty in all, on a
 * pile of newly dug earth, lay the Count! He was either dead or asleep, I
 * could not say which--for the eyes were open and stony, but without the
 * glassiness of death--and the cheeks had the warmth of life through all
 * their pallor; the lips were as red as ever. But there was no sign of
 * movement, no pulse, no breath, no beating of the heart. I bent over him,
 * and tried to find any sign of life, but in vain. He could not have lain
 * there long, for the earthy smell would have passed away in a few hours.
 * By the side of the box was its cover, pierced with holes here and there.
 * I thought he might have the keys on him, but when I went to search I saw
 * the dead eyes, and in them, dead though they were, such a look of hate,
 * though unconscious of me or my presence, that I fled from the place, and
 * leaving the Count's room by the window, crawled again up the castle
 * wall. Regaining my room, I threw myself panting upon the bed and tried
 * to think....
 *
 *        *       *       *       *       *
 *
 * _29 June._--To-day is the date of my last letter, and the Count has
 * taken steps to prove that it was genuine, for again I saw him leave the
 * castle by the same window, and in my clothes. As he went down the wall,
 * lizard fashion, I wished I had a gun or some lethal weapon, that I might
 * destroy him; but I fear that no weapon wrought alone by man's hand would
 * have any effect on him. I dared not wait to see him return, for I feared
 * to see those weird sisters. I came back to the library, and read there
 * till I fell asleep.
 *
 * I was awakened by the Count, who looked at me as grimly as a man can
 * look as he said:--
 *
 * "To-morrow, my friend, we must part. You return to your beautiful
 * England, I to some work which may have such an end that we may never
 * meet. Your letter home has been despatched; to-morrow I shall not be
 * here, but all shall be ready for your journey. In the morning come the
 * Szgany, who have some labours of their own here, and also come some
 * Slovaks. When they have gone, my carriage shall come for you, and shall
 * bear you to the Borgo Pass to meet the diligence from Bukovina to
 * Bistritz. But I am in hopes that I shall see more of you at Castle
 * Dracula." I suspected him, and determined to test his sincerity.
 * Sincerity! It seems like a profanation of the word to write it in
 * connection with such a monster, so asked him point-blank:--
 *
 * "Why may I not go to-night?"
 *
 * "Because, dear sir, my coachman and horses are away on a mission."
 *
 * "But I would walk with pleasure. I want to get away at once." He smiled,
 * such a soft, smooth, diabolical smile that I knew there was some trick
 * behind his smoothness. He said:--
 *
 * "And your baggage?"
 *
 * "I do not care about it. I can send for it some other time."
 *
 * The Count stood up, and said, with a sweet courtesy which made me rub my
 * eyes, it seemed so real:--
 *
 * "You English have a saying which is close to my heart, for its spirit is
 * that which rules our _boyars_: 'Welcome the coming; speed the parting
 * guest.' Come with me, my dear young friend. Not an hour shall you wait
 * in my house against your will, though sad am I at your going, and that
 * you so suddenly desire it. Come!" With a stately gravity, he, with the
 * lamp, preceded me down the stairs and along the hall. Suddenly he
 * stopped.
 *
 * "Hark!"
 *
 * Close at hand came the howling of many wolves. It was almost as if the
 * sound sprang up at the rising of his hand, just as the music of a great
 * orchestra seems to leap under the bâton of the conductor. After a pause
 * of a moment, he proceeded, in his stately way, to the door, drew back
 * the ponderous bolts, unhooked the heavy chains, and began to draw it
 * open.
 *
 * To my intense astonishment I saw that it was unlocked. Suspiciously, I
 * looked all round, but could see no key of any kind.
 *
 * As the door began to open, the howling of the wolves without grew louder
 * and angrier; their red jaws, with champing teeth, and their blunt-clawed
 * feet as they leaped, came in through the opening door. I knew then that
 * to struggle at the moment against the Count was useless. With such
 * allies as these at his command, I could do nothing. But still the door
 * continued slowly to open, and only the Count's body stood in the gap.
 * Suddenly it struck me that this might be the moment and means of my
 * doom; I was to be given to the wolves, and at my own instigation. There
 * was a diabolical wickedness in the idea great enough for the Count, and
 * as a last chance I cried out:--
 *
 * "Shut the door; I shall wait till morning!" and covered my face with my
 * hands to hide my tears of bitter disappointment. With one sweep of his
 * powerful arm, the Count threw the door shut, and the great bolts clanged
 * and echoed through the hall as they shot back into their places.
 *
 * In silence we returned to the library, and after a minute or two I went
 * to my own room. The last I saw of Count Dracula was his kissing his hand
 * to me; with a red light of triumph in his eyes, and with a smile that
 * Judas in hell might be proud of.
 *
 * When I was in my room and about to lie down, I thought I heard a
 * whispering at my door. I went to it softly and listened. Unless my ears
 * deceived me, I heard the voice of the Count:--
 *
 * "Back, back, to your own place! Your time is not yet come. Wait! Have
 * patience! To-night is mine. To-morrow night is yours!" There was a low,
 * sweet ripple of laughter, and in a rage I threw open the door, and saw
 * without the three terrible women licking their lips. As I appeared they
 * all joined in a horrible laugh, and ran away.
 *
 * I came back to my room and threw myself on my knees. It is then so near
 * the end? To-morrow! to-morrow! Lord, help me, and those to whom I am
 * dear!
 *
 *        *       *       *       *       *
 *
 * _30 June, morning._--These may be the last words I ever write in this
 * diary. I slept till just before the dawn, and when I woke threw myself
 * on my knees, for I determined that if Death came he should find me
 * ready.
 *
 * At last I felt that subtle change in the air, and knew that the morning
 * had come. Then came the welcome cock-crow, and I felt that I was safe.
 * With a glad heart, I opened my door and ran down to the hall. I had seen
 * that the door was unlocked, and now escape was before me. With hands
 * that trembled with eagerness, I unhooked the chains and drew back the
 * massive bolts.
 *
 * But the door would not move. Despair seized me. I pulled, and pulled, at
 * the door, and shook it till, massive as it was, it rattled in its
 * casement. I could see the bolt shot. It had been locked after I left the
 * Count.
 *
 * Then a wild desire took me to obtain that key at any risk, and I
 * determined then and there to scale the wall again and gain the Count's
 * room. He might kill me, but death now seemed the happier choice of
 * evils. Without a pause I rushed up to the east window, and scrambled
 * down the wall, as before, into the Count's room. It was empty, but that
 * was as I expected. I could not see a key anywhere, but the heap of gold
 * remained. I went through the door in the corner and down the winding
 * stair and along the dark passage to the old chapel. I knew now well
 * enough where to find the monster I sought.
 *
 * The great box was in the same place, close against the wall, but the lid
 * was laid on it, not fastened down, but with the nails ready in their
 * places to be hammered home. I knew I must reach the body for the key, so
 * I raised the lid, and laid it back against the wall; and then I saw
 * something which filled my very soul with horror. There lay the Count,
 * but looking as if his youth had been half renewed, for the white hair
 * and moustache were changed to dark iron-grey; the cheeks were fuller,
 * and the white skin seemed ruby-red underneath; the mouth was redder than
 * ever, for on the lips were gouts of fresh blood, which trickled from the
 * corners of the mouth and ran over the chin and neck. Even the deep,
 * burning eyes seemed set amongst swollen flesh, for the lids and pouches
 * underneath were bloated. It seemed as if the whole awful creature were
 * simply gorged with blood. He lay like a filthy leech, exhausted with his
 * repletion. I shuddered as I bent over to touch him, and every sense in
 * me revolted at the contact; but I had to search, or I was lost. The
 * coming night might see my own body a banquet in a similar way to those
 * horrid three. I felt all over the body, but no sign could I find of the
 * key. Then I stopped and looked at the Count. There was a mocking smile
 * on the bloated face which seemed to drive me mad. This was the being I
 * was helping to transfer to London, where, perhaps, for centuries to come
 * he might, amongst its teeming millions, satiate his lust for blood, and
 * create a new and ever-widening circle of semi-demons to batten on the
 * helpless. The very thought drove me mad. A terrible desire came upon me
 * to rid the world of such a monster. There was no lethal weapon at hand,
 * but I seized a shovel which the workmen had been using to fill the
 * cases, and lifting it high, struck, with the edge downward, at the
 * hateful face. But as I did so the head turned, and the eyes fell full
 * upon me, with all their blaze of basilisk horror. The sight seemed to
 * paralyse me, and the shovel turned in my hand and glanced from the face,
 * merely making a deep gash above the forehead. The shovel fell from my
 * hand across the box, and as I pulled it away the flange of the blade
 * caught the edge of the lid which fell over again, and hid the horrid
 * thing from my sight. The last glimpse I had was of the bloated face,
 * blood-stained and fixed with a grin of malice which would have held its
 * own in the nethermost hell.
 *
 * I thought and thought what should be my next move, but my brain seemed
 * on fire, and I waited with a despairing feeling growing over me. As I
 * waited I heard in the distance a gipsy song sung by merry voices coming
 * closer, and through their song the rolling of heavy wheels and the
 * cracking of whips; the Szgany and the Slovaks of whom the Count had
 * spoken were coming. With a last look around and at the box which
 * contained the vile body, I ran from the place and gained the Count's
 * room, determined to rush out at the moment the door should be opened.
 * With strained ears, I listened, and heard downstairs the grinding of the
 * key in the great lock and the falling back of the heavy door. There must
 * have been some other means of entry, or some one had a key for one of
 * the locked doors. Then there came the sound of many feet tramping and
 * dying away in some passage which sent up a clanging echo. I turned to
 * run down again towards the vault, where I might find the new entrance;
 * but at the moment there seemed to come a violent puff of wind, and the
 * door to the winding stair blew to with a shock that set the dust from
 * the lintels flying. When I ran to push it open, I found that it was
 * hopelessly fast. I was again a prisoner, and the net of doom was closing
 * round me more closely.
 *
 * As I write there is in the passage below a sound of many tramping feet
 * and the crash of weights being set down heavily, doubtless the boxes,
 * with their freight of earth. There is a sound of hammering; it is the
 * box being nailed down. Now I can hear the heavy feet tramping again
 * along the hall, with many other idle feet coming behind them.
 *
 * The door is shut, and the chains rattle; there is a grinding of the key
 * in the lock; I can hear the key withdraw: then another door opens and
 * shuts; I hear the creaking of lock and bolt.
 *
 * Hark! in the courtyard and down the rocky way the roll of heavy wheels,
 * the crack of whips, and the chorus of the Szgany as they pass into the
 * distance.
 *
 * I am alone in the castle with those awful women. Faugh! Mina is a woman,
 * and there is nought in common. They are devils of the Pit!
 *
 * I shall not remain alone with them; I shall try to scale the castle wall
 * farther than I have yet attempted. I shall take some of the gold with
 * me, lest I want it later. I may find a way from this dreadful place.
 *
 * And then away for home! away to the quickest and nearest train! away
 * from this cursed spot, from this cursed land, where the devil and his
 * children still walk with earthly feet!
 *
 * At least God's mercy is better than that of these monsters, and the
 * precipice is steep and high. At its foot a man may sleep--as a man.
 * Good-bye, all! Mina!
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_V CHAPTER V: Letters--Lucy and Mina
 * "_9 May._
 *
 * "My dearest Lucy,--
 *
 * "Forgive my long delay in writing, but I have been simply overwhelmed
 * with work. The life of an assistant schoolmistress is sometimes trying.
 * I am longing to be with you, and by the sea, where we can talk together
 * freely and build our castles in the air. I have been working very hard
 * lately, because I want to keep up with Jonathan's studies, and I have
 * been practising shorthand very assiduously. When we are married I shall
 * be able to be useful to Jonathan, and if I can stenograph well enough I
 * can take down what he wants to say in this way and write it out for
 * him on the typewriter, at which also I am practising very hard. He
 * and I sometimes write letters in shorthand, and he is keeping a
 * stenographic journal of his travels abroad. When I am with you I
 * shall keep a diary in the same way. I don't mean one of those
 * two-pages-to-the-week-with-Sunday-squeezed-in-a-corner diaries, but a
 * sort of journal which I can write in whenever I feel inclined. I do not
 * suppose there will be much of interest to other people; but it is not
 * intended for them. I may show it to Jonathan some day if there is in it
 * anything worth sharing, but it is really an exercise book. I shall try
 * to do what I see lady journalists do: interviewing and writing
 * descriptions and trying to remember conversations. I am told that, with
 * a little practice, one can remember all that goes on or that one hears
 * said during a day. However, we shall see. I will tell you of my little
 * plans when we meet. I have just had a few hurried lines from Jonathan
 * from Transylvania. He is well, and will be returning in about a week. I
 * am longing to hear all his news. It must be so nice to see strange
 * countries. I wonder if we--I mean Jonathan and I--shall ever see them
 * together. There is the ten o'clock bell ringing. Good-bye.
 *
 * "Your loving
 *
 * "MINA.
 *
 * "Tell me all the news when you write. You have not told me anything for
 * a long time. I hear rumours, and especially of a tall, handsome,
 * curly-haired man???"
 *
 *
 * _Letter, Lucy Westenra to Mina Murray_.
 *
 * "_17, Chatham Street_,
 *
 * "_Wednesday_.
 *
 * "My dearest Mina,--
 *
 * "I must say you tax me _very_ unfairly with being a bad correspondent. I
 * wrote to you _twice_ since we parted, and your last letter was only your
 * _second_. Besides, I have nothing to tell you. There is really nothing
 * to interest you. Town is very pleasant just now, and we go a good deal
 * to picture-galleries and for walks and rides in the park. As to the
 * tall, curly-haired man, I suppose it was the one who was with me at the
 * last Pop. Some one has evidently been telling tales. That was Mr.
 * Holmwood. He often comes to see us, and he and mamma get on very well
 * together; they have so many things to talk about in common. We met some
 * time ago a man that would just _do for you_, if you were not already
 * engaged to Jonathan. He is an excellent _parti_, being handsome, well
 * off, and of good birth. He is a doctor and really clever. Just fancy! He
 * is only nine-and-twenty, and he has an immense lunatic asylum all under
 * his own care. Mr. Holmwood introduced him to me, and he called here to
 * see us, and often comes now. I think he is one of the most resolute men
 * I ever saw, and yet the most calm. He seems absolutely imperturbable. I
 * can fancy what a wonderful power he must have over his patients. He has
 * a curious habit of looking one straight in the face, as if trying to
 * read one's thoughts. He tries this on very much with me, but I flatter
 * myself he has got a tough nut to crack. I know that from my glass. Do
 * you ever try to read your own face? _I do_, and I can tell you it is not
 * a bad study, and gives you more trouble than you can well fancy if you
 * have never tried it. He says that I afford him a curious psychological
 * study, and I humbly think I do. I do not, as you know, take sufficient
 * interest in dress to be able to describe the new fashions. Dress is a
 * bore. That is slang again, but never mind; Arthur says that every day.
 * There, it is all out. Mina, we have told all our secrets to each other
 * since we were _children_; we have slept together and eaten together, and
 * laughed and cried together; and now, though I have spoken, I would like
 * to speak more. Oh, Mina, couldn't you guess? I love him. I am blushing
 * as I write, for although I _think_ he loves me, he has not told me so in
 * words. But oh, Mina, I love him; I love him; I love him! There, that
 * does me good. I wish I were with you, dear, sitting by the fire
 * undressing, as we used to sit; and I would try to tell you what I feel.
 * I do not know how I am writing this even to you. I am afraid to stop,
 * or I should tear up the letter, and I don't want to stop, for I _do_ so
 * want to tell you all. Let me hear from you _at once_, and tell me all
 * that you think about it. Mina, I must stop. Good-night. Bless me in your
 * prayers; and, Mina, pray for my happiness.
 *
 * "LUCY.
 *
 * "P.S.--I need not tell you this is a secret. Good-night again.
 *
 * "L."
 *
 * _Letter, Lucy Westenra to Mina Murray_.
 *
 * "_24 May_.
 *
 * "My dearest Mina,--
 *
 * "Thanks, and thanks, and thanks again for your sweet letter. It was so
 * nice to be able to tell you and to have your sympathy.
 *
 * "My dear, it never rains but it pours. How true the old proverbs are.
 * Here am I, who shall be twenty in September, and yet I never had a
 * proposal till to-day, not a real proposal, and to-day I have had three.
 * Just fancy! THREE proposals in one day! Isn't it awful! I feel sorry,
 * really and truly sorry, for two of the poor fellows. Oh, Mina, I am so
 * happy that I don't know what to do with myself. And three proposals!
 * But, for goodness' sake, don't tell any of the girls, or they would be
 * getting all sorts of extravagant ideas and imagining themselves injured
 * and slighted if in their very first day at home they did not get six at
 * least. Some girls are so vain! You and I, Mina dear, who are engaged and
 * are going to settle down soon soberly into old married women, can
 * despise vanity. Well, I must tell you about the three, but you must keep
 * it a secret, dear, from _every one_, except, of course, Jonathan. You
 * will tell him, because I would, if I were in your place, certainly tell
 * Arthur. A woman ought to tell her husband everything--don't you think
 * so, dear?--and I must be fair. Men like women, certainly their wives, to
 * be quite as fair as they are; and women, I am afraid, are not always
 * quite as fair as they should be. Well, my dear, number One came just
 * before lunch. I told you of him, Dr. John Seward, the lunatic-asylum
 * man, with the strong jaw and the good forehead. He was very cool
 * outwardly, but was nervous all the same. He had evidently been schooling
 * himself as to all sorts of little things, and remembered them; but he
 * almost managed to sit down on his silk hat, which men don't generally do
 * when they are cool, and then when he wanted to appear at ease he kept
 * playing with a lancet in a way that made me nearly scream. He spoke to
 * me, Mina, very straightforwardly. He told me how dear I was to him,
 * though he had known me so little, and what his life would be with me to
 * help and cheer him. He was going to tell me how unhappy he would be if I
 * did not care for him, but when he saw me cry he said that he was a brute
 * and would not add to my present trouble. Then he broke off and asked if
 * I could love him in time; and when I shook my head his hands trembled,
 * and then with some hesitation he asked me if I cared already for any one
 * else. He put it very nicely, saying that he did not want to wring my
 * confidence from me, but only to know, because if a woman's heart was
 * free a man might have hope. And then, Mina, I felt a sort of duty to
 * tell him that there was some one. I only told him that much, and then he
 * stood up, and he looked very strong and very grave as he took both my
 * hands in his and said he hoped I would be happy, and that if I ever
 * wanted a friend I must count him one of my best. Oh, Mina dear, I can't
 * help crying: and you must excuse this letter being all blotted. Being
 * proposed to is all very nice and all that sort of thing, but it isn't at
 * all a happy thing when you have to see a poor fellow, whom you know
 * loves you honestly, going away and looking all broken-hearted, and to
 * know that, no matter what he may say at the moment, you are passing
 * quite out of his life. My dear, I must stop here at present, I feel so
 * miserable, though I am so happy.
 *
 * "_Evening._
 *
 * "Arthur has just gone, and I feel in better spirits than when I left
 * off, so I can go on telling you about the day. Well, my dear, number Two
 * came after lunch. He is such a nice fellow, an American from Texas, and
 * he looks so young and so fresh that it seems almost impossible that he
 * has been to so many places and has had such adventures. I sympathise
 * with poor Desdemona when she had such a dangerous stream poured in her
 * ear, even by a black man. I suppose that we women are such cowards that
 * we think a man will save us from fears, and we marry him. I know now
 * what I would do if I were a man and wanted to make a girl love me. No, I
 * don't, for there was Mr. Morris telling us his stories, and Arthur never
 * told any, and yet---- My dear, I am somewhat previous. Mr. Quincey P.
 * Morris found me alone. It seems that a man always does find a girl
 * alone. No, he doesn't, for Arthur tried twice to _make_ a chance, and I
 * helping him all I could; I am not ashamed to say it now. I must tell you
 * beforehand that Mr. Morris doesn't always speak slang--that is to say,
 * he never does so to strangers or before them, for he is really well
 * educated and has exquisite manners--but he found out that it amused me
 * to hear him talk American slang, and whenever I was present, and there
 * was no one to be shocked, he said such funny things. I am afraid, my
 * dear, he has to invent it all, for it fits exactly into whatever else he
 * has to say. But this is a way slang has. I do not know myself if I shall
 * ever speak slang; I do not know if Arthur likes it, as I have never
 * heard him use any as yet. Well, Mr. Morris sat down beside me and looked
 * as happy and jolly as he could, but I could see all the same that he was
 * very nervous. He took my hand in his, and said ever so sweetly:--
 *
 * "'Miss Lucy, I know I ain't good enough to regulate the fixin's of your
 * little shoes, but I guess if you wait till you find a man that is you
 * will go join them seven young women with the lamps when you quit. Won't
 * you just hitch up alongside of me and let us go down the long road
 * together, driving in double harness?'
 *
 * "Well, he did look so good-humoured and so jolly that it didn't seem
 * half so hard to refuse him as it did poor Dr. Seward; so I said, as
 * lightly as I could, that I did not know anything of hitching, and that I
 * wasn't broken to harness at all yet. Then he said that he had spoken in
 * a light manner, and he hoped that if he had made a mistake in doing so
 * on so grave, so momentous, an occasion for him, I would forgive him. He
 * really did look serious when he was saying it, and I couldn't help
 * feeling a bit serious too--I know, Mina, you will think me a horrid
 * flirt--though I couldn't help feeling a sort of exultation that he was
 * number two in one day. And then, my dear, before I could say a word he
 * began pouring out a perfect torrent of love-making, laying his very
 * heart and soul at my feet. He looked so earnest over it that I shall
 * never again think that a man must be playful always, and never earnest,
 * because he is merry at times. I suppose he saw something in my face
 * which checked him, for he suddenly stopped, and said with a sort of
 * manly fervour that I could have loved him for if I had been free:--
 *
 * "'Lucy, you are an honest-hearted girl, I know. I should not be here
 * speaking to you as I am now if I did not believe you clean grit, right
 * through to the very depths of your soul. Tell me, like one good fellow
 * to another, is there any one else that you care for? And if there is
 * I'll never trouble you a hair's breadth again, but will be, if you will
 * let me, a very faithful friend.'
 *
 * "My dear Mina, why are men so noble when we women are so little worthy
 * of them? Here was I almost making fun of this great-hearted, true
 * gentleman. I burst into tears--I am afraid, my dear, you will think
 * this a very sloppy letter in more ways than one--and I really felt very
 * badly. Why can't they let a girl marry three men, or as many as want
 * her, and save all this trouble? But this is heresy, and I must not say
 * it. I am glad to say that, though I was crying, I was able to look into
 * Mr. Morris's brave eyes, and I told him out straight:--
 *
 * "'Yes, there is some one I love, though he has not told me yet that he
 * even loves me.' I was right to speak to him so frankly, for quite a
 * light came into his face, and he put out both his hands and took mine--I
 * think I put them into his--and said in a hearty way:--
 *
 * "'That's my brave girl. It's better worth being late for a chance of
 * winning you than being in time for any other girl in the world. Don't
 * cry, my dear. If it's for me, I'm a hard nut to crack; and I take it
 * standing up. If that other fellow doesn't know his happiness, well, he'd
 * better look for it soon, or he'll have to deal with me. Little girl,
 * your honesty and pluck have made me a friend, and that's rarer than a
 * lover; it's more unselfish anyhow. My dear, I'm going to have a pretty
 * lonely walk between this and Kingdom Come. Won't you give me one kiss?
 * It'll be something to keep off the darkness now and then. You can, you
 * know, if you like, for that other good fellow--he must be a good fellow,
 * my dear, and a fine fellow, or you could not love him--hasn't spoken
 * yet.' That quite won me, Mina, for it _was_ brave and sweet of him, and
 * noble, too, to a rival--wasn't it?--and he so sad; so I leant over and
 * kissed him. He stood up with my two hands in his, and as he looked down
 * into my face--I am afraid I was blushing very much--he said:--
 *
 * "'Little girl, I hold your hand, and you've kissed me, and if these
 * things don't make us friends nothing ever will. Thank you for your sweet
 * honesty to me, and good-bye.' He wrung my hand, and taking up his hat,
 * went straight out of the room without looking back, without a tear or a
 * quiver or a pause; and I am crying like a baby. Oh, why must a man like
 * that be made unhappy when there are lots of girls about who would
 * worship the very ground he trod on? I know I would if I were free--only
 * I don't want to be free. My dear, this quite upset me, and I feel I
 * cannot write of happiness just at once, after telling you of it; and I
 * don't wish to tell of the number three until it can be all happy.
 *
 * "Ever your loving
 *
 * "LUCY.
 *
 * "P.S.--Oh, about number Three--I needn't tell you of number Three, need
 * I? Besides, it was all so confused; it seemed only a moment from his
 * coming into the room till both his arms were round me, and he was
 * kissing me. I am very, very happy, and I don't know what I have done to
 * deserve it. I must only try in the future to show that I am not
 * ungrateful to God for all His goodness to me in sending to me such a
 * lover, such a husband, and such a friend.
 *
 * "Good-bye."
 *
 *
 * _Dr. Seward's Diary._
 *
 * (Kept in phonograph)
 *
 * _25 May._--Ebb tide in appetite to-day. Cannot eat, cannot rest, so
 * diary instead. Since my rebuff of yesterday I have a sort of empty
 * feeling; nothing in the world seems of sufficient importance to be worth
 * the doing.... As I knew that the only cure for this sort of thing was
 * work, I went down amongst the patients. I picked out one who has
 * afforded me a study of much interest. He is so quaint that I am
 * determined to understand him as well as I can. To-day I seemed to get
 * nearer than ever before to the heart of his mystery.
 *
 * I questioned him more fully than I had ever done, with a view to making
 * myself master of the facts of his hallucination. In my manner of doing
 * it there was, I now see, something of cruelty. I seemed to wish to keep
 * him to the point of his madness--a thing which I avoid with the patients
 * as I would the mouth of hell.
 *
 * (_Mem._, under what circumstances would I _not_ avoid the pit of hell?)
 * _Omnia Romæ venalia sunt._ Hell has its price! _verb. sap._ If there be
 * anything behind this instinct it will be valuable to trace it afterwards
 * _accurately_, so I had better commence to do so, therefore--
 *
 * R. M. Renfield, ætat 59.--Sanguine temperament; great physical strength;
 * morbidly excitable; periods of gloom, ending in some fixed idea which I
 * cannot make out. I presume that the sanguine temperament itself and the
 * disturbing influence end in a mentally-accomplished finish; a possibly
 * dangerous man, probably dangerous if unselfish. In selfish men caution
 * is as secure an armour for their foes as for themselves. What I think of
 * on this point is, when self is the fixed point the centripetal force is
 * balanced with the centrifugal; when duty, a cause, etc., is the fixed
 * point, the latter force is paramount, and only accident or a series of
 * accidents can balance it.
 *
 *
 * _Letter, Quincey P. Morris to Hon. Arthur Holmwood._
 *
 * "_25 May._
 *
 * "My dear Art,--
 *
 * "We've told yarns by the camp-fire in the prairies; and dressed one
 * another's wounds after trying a landing at the Marquesas; and drunk
 * healths on the shore of Titicaca. There are more yarns to be told, and
 * other wounds to be healed, and another health to be drunk. Won't you let
 * this be at my camp-fire to-morrow night? I have no hesitation in asking
 * you, as I know a certain lady is engaged to a certain dinner-party, and
 * that you are free. There will only be one other, our old pal at the
 * Korea, Jack Seward. He's coming, too, and we both want to mingle our
 * weeps over the wine-cup, and to drink a health with all our hearts to
 * the happiest man in all the wide world, who has won the noblest heart
 * that God has made and the best worth winning. We promise you a hearty
 * welcome, and a loving greeting, and a health as true as your own right
 * hand. We shall both swear to leave you at home if you drink too deep to
 * a certain pair of eyes. Come!
 *
 * "Yours, as ever and always,
 *
 * "QUINCEY P. MORRIS."
 *
 *
 * _Telegram from Arthur Holmwood to Quincey P. Morris._
 *
 * "_26 May._
 *
 * "Count me in every time. I bear messages which will make both your ears
 * tingle.
 *
 * "ART."
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_VI CHAPTER VI: Mina Murray's Journal
 * _24 July. Whitby._--Lucy met me at the station, looking sweeter and
 * lovelier than ever, and we drove up to the house at the Crescent in
 * which they have rooms. This is a lovely place. The little river, the
 * Esk, runs through a deep valley, which broadens out as it comes near the
 * harbour. A great viaduct runs across, with high piers, through which the
 * view seems somehow further away than it really is. The valley is
 * beautifully green, and it is so steep that when you are on the high land
 * on either side you look right across it, unless you are near enough to
 * see down. The houses of the old town--the side away from us--are all
 * red-roofed, and seem piled up one over the other anyhow, like the
 * pictures we see of Nuremberg. Right over the town is the ruin of Whitby
 * Abbey, which was sacked by the Danes, and which is the scene of part of
 * "Marmion," where the girl was built up in the wall. It is a most noble
 * ruin, of immense size, and full of beautiful and romantic bits; there is
 * a legend that a white lady is seen in one of the windows. Between it and
 * the town there is another church, the parish one, round which is a big
 * graveyard, all full of tombstones. This is to my mind the nicest spot in
 * Whitby, for it lies right over the town, and has a full view of the
 * harbour and all up the bay to where the headland called Kettleness
 * stretches out into the sea. It descends so steeply over the harbour that
 * part of the bank has fallen away, and some of the graves have been
 * destroyed. In one place part of the stonework of the graves stretches
 * out over the sandy pathway far below. There are walks, with seats beside
 * them, through the churchyard; and people go and sit there all day long
 * looking at the beautiful view and enjoying the breeze. I shall come and
 * sit here very often myself and work. Indeed, I am writing now, with my
 * book on my knee, and listening to the talk of three old men who are
 * sitting beside me. They seem to do nothing all day but sit up here and
 * talk.
 *
 * The harbour lies below me, with, on the far side, one long granite wall
 * stretching out into the sea, with a curve outwards at the end of it, in
 * the middle of which is a lighthouse. A heavy sea-wall runs along outside
 * of it. On the near side, the sea-wall makes an elbow crooked inversely,
 * and its end too has a lighthouse. Between the two piers there is a
 * narrow opening into the harbour, which then suddenly widens.
 *
 * It is nice at high water; but when the tide is out it shoals away to
 * nothing, and there is merely the stream of the Esk, running between
 * banks of sand, with rocks here and there. Outside the harbour on this
 * side there rises for about half a mile a great reef, the sharp edge of
 * which runs straight out from behind the south lighthouse. At the end of
 * it is a buoy with a bell, which swings in bad weather, and sends in a
 * mournful sound on the wind. They have a legend here that when a ship is
 * lost bells are heard out at sea. I must ask the old man about this; he
 * is coming this way....
 *
 * He is a funny old man. He must be awfully old, for his face is all
 * gnarled and twisted like the bark of a tree. He tells me that he is
 * nearly a hundred, and that he was a sailor in the Greenland fishing
 * fleet when Waterloo was fought. He is, I am afraid, a very sceptical
 * person, for when I asked him about the bells at sea and the White Lady
 * at the abbey he said very brusquely:--
 *
 * "I wouldn't fash masel' about them, miss. Them things be all wore out.
 * Mind, I don't say that they never was, but I do say that they wasn't in
 * my time. They be all very well for comers and trippers, an' the like,
 * but not for a nice young lady like you. Them feet-folks from York and
 * Leeds that be always eatin' cured herrin's an' drinkin' tea an' lookin'
 * out to buy cheap jet would creed aught. I wonder masel' who'd be
 * bothered tellin' lies to them--even the newspapers, which is full of
 * fool-talk." I thought he would be a good person to learn interesting
 * things from, so I asked him if he would mind telling me something about
 * the whale-fishing in the old days. He was just settling himself to begin
 * when the clock struck six, whereupon he laboured to get up, and said:--
 *
 * "I must gang ageeanwards home now, miss. My grand-daughter doesn't like
 * to be kept waitin' when the tea is ready, for it takes me time to
 * crammle aboon the grees, for there be a many of 'em; an', miss, I lack
 * belly-timber sairly by the clock."
 *
 * He hobbled away, and I could see him hurrying, as well as he could, down
 * the steps. The steps are a great feature on the place. They lead from
 * the town up to the church, there are hundreds of them--I do not know how
 * many--and they wind up in a delicate curve; the slope is so gentle that
 * a horse could easily walk up and down them. I think they must originally
 * have had something to do with the abbey. I shall go home too. Lucy went
 * out visiting with her mother, and as they were only duty calls, I did
 * not go. They will be home by this.
 *
 *        *       *       *       *       *
 *
 * _1 August._--I came up here an hour ago with Lucy, and we had a most
 * interesting talk with my old friend and the two others who always come
 * and join him. He is evidently the Sir Oracle of them, and I should think
 * must have been in his time a most dictatorial person. He will not admit
 * anything, and downfaces everybody. If he can't out-argue them he bullies
 * them, and then takes their silence for agreement with his views. Lucy
 * was looking sweetly pretty in her white lawn frock; she has got a
 * beautiful colour since she has been here. I noticed that the old men did
 * not lose any time in coming up and sitting near her when we sat down.
 * She is so sweet with old people; I think they all fell in love with her
 * on the spot. Even my old man succumbed and did not contradict her, but
 * gave me double share instead. I got him on the subject of the legends,
 * and he went off at once into a sort of sermon. I must try to remember it
 * and put it down:--
 *
 * "It be all fool-talk, lock, stock, and barrel; that's what it be, an'
 * nowt else. These bans an' wafts an' boh-ghosts an' barguests an' bogles
 * an' all anent them is only fit to set bairns an' dizzy women
 * a-belderin'. They be nowt but air-blebs. They, an' all grims an' signs
 * an' warnin's, be all invented by parsons an' illsome beuk-bodies an'
 * railway touters to skeer an' scunner hafflin's, an' to get folks to do
 * somethin' that they don't other incline to. It makes me ireful to think
 * o' them. Why, it's them that, not content with printin' lies on paper
 * an' preachin' them out of pulpits, does want to be cuttin' them on the
 * tombstones. Look here all around you in what airt ye will; all them
 * steans, holdin' up their heads as well as they can out of their pride,
 * is acant--simply tumblin' down with the weight o' the lies wrote on
 * them, 'Here lies the body' or 'Sacred to the memory' wrote on all of
 * them, an' yet in nigh half of them there bean't no bodies at all; an'
 * the memories of them bean't cared a pinch of snuff about, much less
 * sacred. Lies all of them, nothin' but lies of one kind or another! My
 * gog, but it'll be a quare scowderment at the Day of Judgment when they
 * come tumblin' up in their death-sarks, all jouped together an' tryin' to
 * drag their tombsteans with them to prove how good they was; some of them
 * trimmlin' and ditherin', with their hands that dozzened an' slippy from
 * lyin' in the sea that they can't even keep their grup o' them."
 *
 * I could see from the old fellow's self-satisfied air and the way in
 * which he looked round for the approval of his cronies that he was
 * "showing off," so I put in a word to keep him going:--
 *
 * "Oh, Mr. Swales, you can't be serious. Surely these tombstones are not
 * all wrong?"
 *
 * "Yabblins! There may be a poorish few not wrong, savin' where they make
 * out the people too good; for there be folk that do think a balm-bowl be
 * like the sea, if only it be their own. The whole thing be only lies. Now
 * look you here; you come here a stranger, an' you see this kirk-garth." I
 * nodded, for I thought it better to assent, though I did not quite
 * understand his dialect. I knew it had something to do with the church.
 * He went on: "And you consate that all these steans be aboon folk that be
 * happed here, snod an' snog?" I assented again. "Then that be just where
 * the lie comes in. Why, there be scores of these lay-beds that be toom as
 * old Dun's 'bacca-box on Friday night." He nudged one of his companions,
 * and they all laughed. "And my gog! how could they be otherwise? Look at
 * that one, the aftest abaft the bier-bank: read it!" I went over and
 * read:--
 *
 * "Edward Spencelagh, master mariner, murdered by pirates off the coast of
 * Andres, April, 1854, æt. 30." When I came back Mr. Swales went on:--
 *
 * "Who brought him home, I wonder, to hap him here? Murdered off the coast
 * of Andres! an' you consated his body lay under! Why, I could name ye a
 * dozen whose bones lie in the Greenland seas above"--he pointed
 * northwards--"or where the currents may have drifted them. There be the
 * steans around ye. Ye can, with your young eyes, read the small-print of
 * the lies from here. This Braithwaite Lowrey--I knew his father, lost in
 * the _Lively_ off Greenland in '20; or Andrew Woodhouse, drowned in the
 * same seas in 1777; or John Paxton, drowned off Cape Farewell a year
 * later; or old John Rawlings, whose grandfather sailed with me, drowned
 * in the Gulf of Finland in '50. Do ye think that all these men will have
 * to make a rush to Whitby when the trumpet sounds? I have me antherums
 * aboot it! I tell ye that when they got here they'd be jommlin' an'
 * jostlin' one another that way that it 'ud be like a fight up on the ice
 * in the old days, when we'd be at one another from daylight to dark, an'
 * tryin' to tie up our cuts by the light of the aurora borealis." This was
 * evidently local pleasantry, for the old man cackled over it, and his
 * cronies joined in with gusto.
 *
 * "But," I said, "surely you are not quite correct, for you start on the
 * assumption that all the poor people, or their spirits, will have to
 * take their tombstones with them on the Day of Judgment. Do you think
 * that will be really necessary?"
 *
 * "Well, what else be they tombstones for? Answer me that, miss!"
 *
 * "To please their relatives, I suppose."
 *
 * "To please their relatives, you suppose!" This he said with intense
 * scorn. "How will it pleasure their relatives to know that lies is wrote
 * over them, and that everybody in the place knows that they be lies?" He
 * pointed to a stone at our feet which had been laid down as a slab, on
 * which the seat was rested, close to the edge of the cliff. "Read the
 * lies on that thruff-stean," he said. The letters were upside down to me
 * from where I sat, but Lucy was more opposite to them, so she leant over
 * and read:--
 *
 * "Sacred to the memory of George Canon, who died, in the hope of a
 * glorious resurrection, on July, 29, 1873, falling from the rocks at
 * Kettleness. This tomb was erected by his sorrowing mother to her dearly
 * beloved son. 'He was the only son of his mother, and she was a widow.'
 * Really, Mr. Swales, I don't see anything very funny in that!" She spoke
 * her comment very gravely and somewhat severely.
 *
 * "Ye don't see aught funny! Ha! ha! But that's because ye don't gawm the
 * sorrowin' mother was a hell-cat that hated him because he was
 * acrewk'd--a regular lamiter he was--an' he hated her so that he
 * committed suicide in order that she mightn't get an insurance she put on
 * his life. He blew nigh the top of his head off with an old musket that
 * they had for scarin' the crows with. 'Twarn't for crows then, for it
 * brought the clegs and the dowps to him. That's the way he fell off the
 * rocks. And, as to hopes of a glorious resurrection, I've often heard him
 * say masel' that he hoped he'd go to hell, for his mother was so pious
 * that she'd be sure to go to heaven, an' he didn't want to addle where
 * she was. Now isn't that stean at any rate"--he hammered it with his
 * stick as he spoke--"a pack of lies? and won't it make Gabriel keckle
 * when Geordie comes pantin' up the grees with the tombstean balanced on
 * his hump, and asks it to be took as evidence!"
 *
 * I did not know what to say, but Lucy turned the conversation as she
 * said, rising up:--
 *
 * "Oh, why did you tell us of this? It is my favourite seat, and I cannot
 * leave it; and now I find I must go on sitting over the grave of a
 * suicide."
 *
 * "That won't harm ye, my pretty; an' it may make poor Geordie gladsome to
 * have so trim a lass sittin' on his lap. That won't hurt ye. Why, I've
 * sat here off an' on for nigh twenty years past, an' it hasn't done me
 * no harm. Don't ye fash about them as lies under ye, or that doesn' lie
 * there either! It'll be time for ye to be getting scart when ye see the
 * tombsteans all run away with, and the place as bare as a stubble-field.
 * There's the clock, an' I must gang. My service to ye, ladies!" And off
 * he hobbled.
 *
 * Lucy and I sat awhile, and it was all so beautiful before us that we
 * took hands as we sat; and she told me all over again about Arthur and
 * their coming marriage. That made me just a little heart-sick, for I
 * haven't heard from Jonathan for a whole month.
 *
 *        *       *       *       *       *
 *
 * _The same day._ I came up here alone, for I am very sad. There was no
 * letter for me. I hope there cannot be anything the matter with Jonathan.
 * The clock has just struck nine. I see the lights scattered all over the
 * town, sometimes in rows where the streets are, and sometimes singly;
 * they run right up the Esk and die away in the curve of the valley. To my
 * left the view is cut off by a black line of roof of the old house next
 * the abbey. The sheep and lambs are bleating in the fields away behind
 * me, and there is a clatter of a donkey's hoofs up the paved road below.
 * The band on the pier is playing a harsh waltz in good time, and further
 * along the quay there is a Salvation Army meeting in a back street.
 * Neither of the bands hears the other, but up here I hear and see them
 * both. I wonder where Jonathan is and if he is thinking of me! I wish he
 * were here.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _5 June._--The case of Renfield grows more interesting the more I get to
 * understand the man. He has certain qualities very largely developed;
 * selfishness, secrecy, and purpose. I wish I could get at what is the
 * object of the latter. He seems to have some settled scheme of his own,
 * but what it is I do not yet know. His redeeming quality is a love of
 * animals, though, indeed, he has such curious turns in it that I
 * sometimes imagine he is only abnormally cruel. His pets are of odd
 * sorts. Just now his hobby is catching flies. He has at present such a
 * quantity that I have had myself to expostulate. To my astonishment, he
 * did not break out into a fury, as I expected, but took the matter in
 * simple seriousness. He thought for a moment, and then said: "May I have
 * three days? I shall clear them away." Of course, I said that would do. I
 * must watch him.
 *
 *        *       *       *       *       *
 *
 * _18 June._--He has turned his mind now to spiders, and has got several
 * very big fellows in a box. He keeps feeding them with his flies, and
 * the number of the latter is becoming sensibly diminished, although he
 * has used half his food in attracting more flies from outside to his
 * room.
 *
 *        *       *       *       *       *
 *
 * _1 July._--His spiders are now becoming as great a nuisance as his
 * flies, and to-day I told him that he must get rid of them. He looked
 * very sad at this, so I said that he must clear out some of them, at all
 * events. He cheerfully acquiesced in this, and I gave him the same time
 * as before for reduction. He disgusted me much while with him, for when a
 * horrid blow-fly, bloated with some carrion food, buzzed into the room,
 * he caught it, held it exultantly for a few moments between his finger
 * and thumb, and, before I knew what he was going to do, put it in his
 * mouth and ate it. I scolded him for it, but he argued quietly that it
 * was very good and very wholesome; that it was life, strong life, and
 * gave life to him. This gave me an idea, or the rudiment of one. I must
 * watch how he gets rid of his spiders. He has evidently some deep problem
 * in his mind, for he keeps a little note-book in which he is always
 * jotting down something. Whole pages of it are filled with masses of
 * figures, generally single numbers added up in batches, and then the
 * totals added in batches again, as though he were "focussing" some
 * account, as the auditors put it.
 *
 *        *       *       *       *       *
 *
 * _8 July._--There is a method in his madness, and the rudimentary idea in
 * my mind is growing. It will be a whole idea soon, and then, oh,
 * unconscious cerebration! you will have to give the wall to your
 * conscious brother. I kept away from my friend for a few days, so that I
 * might notice if there were any change. Things remain as they were except
 * that he has parted with some of his pets and got a new one. He has
 * managed to get a sparrow, and has already partially tamed it. His means
 * of taming is simple, for already the spiders have diminished. Those that
 * do remain, however, are well fed, for he still brings in the flies by
 * tempting them with his food.
 *
 *        *       *       *       *       *
 *
 * _19 July._--We are progressing. My friend has now a whole colony of
 * sparrows, and his flies and spiders are almost obliterated. When I came
 * in he ran to me and said he wanted to ask me a great favour--a very,
 * very great favour; and as he spoke he fawned on me like a dog. I asked
 * him what it was, and he said, with a sort of rapture in his voice and
 * bearing:--
 *
 * "A kitten, a nice little, sleek playful kitten, that I can play with,
 * and teach, and feed--and feed--and feed!" I was not unprepared for this
 * request, for I had noticed how his pets went on increasing in size and
 * vivacity, but I did not care that his pretty family of tame sparrows
 * should be wiped out in the same manner as the flies and the spiders; so
 * I said I would see about it, and asked him if he would not rather have a
 * cat than a kitten. His eagerness betrayed him as he answered:--
 *
 * "Oh, yes, I would like a cat! I only asked for a kitten lest you should
 * refuse me a cat. No one would refuse me a kitten, would they?" I shook
 * my head, and said that at present I feared it would not be possible, but
 * that I would see about it. His face fell, and I could see a warning of
 * danger in it, for there was a sudden fierce, sidelong look which meant
 * killing. The man is an undeveloped homicidal maniac. I shall test him
 * with his present craving and see how it will work out; then I shall know
 * more.
 *
 *        *       *       *       *       *
 *
 * _10 p. m._--I have visited him again and found him sitting in a corner
 * brooding. When I came in he threw himself on his knees before me and
 * implored me to let him have a cat; that his salvation depended upon it.
 * I was firm, however, and told him that he could not have it, whereupon
 * he went without a word, and sat down, gnawing his fingers, in the corner
 * where I had found him. I shall see him in the morning early.
 *
 *        *       *       *       *       *
 *
 * _20 July._--Visited Renfield very early, before the attendant went his
 * rounds. Found him up and humming a tune. He was spreading out his sugar,
 * which he had saved, in the window, and was manifestly beginning his
 * fly-catching again; and beginning it cheerfully and with a good grace. I
 * looked around for his birds, and not seeing them, asked him where they
 * were. He replied, without turning round, that they had all flown away.
 * There were a few feathers about the room and on his pillow a drop of
 * blood. I said nothing, but went and told the keeper to report to me if
 * there were anything odd about him during the day.
 *
 *        *       *       *       *       *
 *
 * _11 a. m._--The attendant has just been to me to say that Renfield has
 * been very sick and has disgorged a whole lot of feathers. "My belief is,
 * doctor," he said, "that he has eaten his birds, and that he just took
 * and ate them raw!"
 *
 *        *       *       *       *       *
 *
 * _11 p. m._--I gave Renfield a strong opiate to-night, enough to make
 * even him sleep, and took away his pocket-book to look at it. The thought
 * that has been buzzing about my brain lately is complete, and the theory
 * proved. My homicidal maniac is of a peculiar kind. I shall have to
 * invent a new classification for him, and call him a zoöphagous
 * (life-eating) maniac; what he desires is to absorb as many lives as he
 * can, and he has laid himself out to achieve it in a cumulative way. He
 * gave many flies to one spider and many spiders to one bird, and then
 * wanted a cat to eat the many birds. What would have been his later
 * steps? It would almost be worth while to complete the experiment. It
 * might be done if there were only a sufficient cause. Men sneered at
 * vivisection, and yet look at its results to-day! Why not advance science
 * in its most difficult and vital aspect--the knowledge of the brain? Had
 * I even the secret of one such mind--did I hold the key to the fancy of
 * even one lunatic--I might advance my own branch of science to a pitch
 * compared with which Burdon-Sanderson's physiology or Ferrier's
 * brain-knowledge would be as nothing. If only there were a sufficient
 * cause! I must not think too much of this, or I may be tempted; a good
 * cause might turn the scale with me, for may not I too be of an
 * exceptional brain, congenitally?
 *
 * How well the man reasoned; lunatics always do within their own scope. I
 * wonder at how many lives he values a man, or if at only one. He has
 * closed the account most accurately, and to-day begun a new record. How
 * many of us begin a new record with each day of our lives?
 *
 * To me it seems only yesterday that my whole life ended with my new hope,
 * and that truly I began a new record. So it will be until the Great
 * Recorder sums me up and closes my ledger account with a balance to
 * profit or loss. Oh, Lucy, Lucy, I cannot be angry with you, nor can I be
 * angry with my friend whose happiness is yours; but I must only wait on
 * hopeless and work. Work! work!
 *
 * If I only could have as strong a cause as my poor mad friend there--a
 * good, unselfish cause to make me work--that would be indeed happiness.
 *
 *
 * _Mina Murray's Journal._
 *
 * _26 July._--I am anxious, and it soothes me to express myself here; it
 * is like whispering to one's self and listening at the same time. And
 * there is also something about the shorthand symbols that makes it
 * different from writing. I am unhappy about Lucy and about Jonathan. I
 * had not heard from Jonathan for some time, and was very concerned; but
 * yesterday dear Mr. Hawkins, who is always so kind, sent me a letter from
 * him. I had written asking him if he had heard, and he said the enclosed
 * had just been received. It is only a line dated from Castle Dracula,
 * and says that he is just starting for home. That is not like Jonathan;
 * I do not understand it, and it makes me uneasy. Then, too, Lucy,
 * although she is so well, has lately taken to her old habit of walking in
 * her sleep. Her mother has spoken to me about it, and we have decided
 * that I am to lock the door of our room every night. Mrs. Westenra has
 * got an idea that sleep-walkers always go out on roofs of houses and
 * along the edges of cliffs and then get suddenly wakened and fall over
 * with a despairing cry that echoes all over the place. Poor dear, she is
 * naturally anxious about Lucy, and she tells me that her husband, Lucy's
 * father, had the same habit; that he would get up in the night and dress
 * himself and go out, if he were not stopped. Lucy is to be married in the
 * autumn, and she is already planning out her dresses and how her house is
 * to be arranged. I sympathise with her, for I do the same, only Jonathan
 * and I will start in life in a very simple way, and shall have to try to
 * make both ends meet. Mr. Holmwood--he is the Hon. Arthur Holmwood, only
 * son of Lord Godalming--is coming up here very shortly--as soon as he can
 * leave town, for his father is not very well, and I think dear Lucy is
 * counting the moments till he comes. She wants to take him up to the seat
 * on the churchyard cliff and show him the beauty of Whitby. I daresay it
 * is the waiting which disturbs her; she will be all right when he
 * arrives.
 *
 *        *       *       *       *       *
 *
 * _27 July._--No news from Jonathan. I am getting quite uneasy about him,
 * though why I should I do not know; but I do wish that he would write, if
 * it were only a single line. Lucy walks more than ever, and each night I
 * am awakened by her moving about the room. Fortunately, the weather is so
 * hot that she cannot get cold; but still the anxiety and the perpetually
 * being wakened is beginning to tell on me, and I am getting nervous and
 * wakeful myself. Thank God, Lucy's health keeps up. Mr. Holmwood has been
 * suddenly called to Ring to see his father, who has been taken seriously
 * ill. Lucy frets at the postponement of seeing him, but it does not touch
 * her looks; she is a trifle stouter, and her cheeks are a lovely
 * rose-pink. She has lost that anæmic look which she had. I pray it will
 * all last.
 *
 *        *       *       *       *       *
 *
 * _3 August._--Another week gone, and no news from Jonathan, not even to
 * Mr. Hawkins, from whom I have heard. Oh, I do hope he is not ill. He
 * surely would have written. I look at that last letter of his, but
 * somehow it does not satisfy me. It does not read like him, and yet it is
 * his writing. There is no mistake of that. Lucy has not walked much in
 * her sleep the last week, but there is an odd concentration about her
 * which I do not understand; even in her sleep she seems to be watching
 * me. She tries the door, and finding it locked, goes about the room
 * searching for the key.
 *
 * _6 August._--Another three days, and no news. This suspense is getting
 * dreadful. If I only knew where to write to or where to go to, I should
 * feel easier; but no one has heard a word of Jonathan since that last
 * letter. I must only pray to God for patience. Lucy is more excitable
 * than ever, but is otherwise well. Last night was very threatening, and
 * the fishermen say that we are in for a storm. I must try to watch it and
 * learn the weather signs. To-day is a grey day, and the sun as I write is
 * hidden in thick clouds, high over Kettleness. Everything is grey--except
 * the green grass, which seems like emerald amongst it; grey earthy rock;
 * grey clouds, tinged with the sunburst at the far edge, hang over the
 * grey sea, into which the sand-points stretch like grey fingers. The sea
 * is tumbling in over the shallows and the sandy flats with a roar,
 * muffled in the sea-mists drifting inland. The horizon is lost in a grey
 * mist. All is vastness; the clouds are piled up like giant rocks, and
 * there is a "brool" over the sea that sounds like some presage of doom.
 * Dark figures are on the beach here and there, sometimes half shrouded in
 * the mist, and seem "men like trees walking." The fishing-boats are
 * racing for home, and rise and dip in the ground swell as they sweep into
 * the harbour, bending to the scuppers. Here comes old Mr. Swales. He is
 * making straight for me, and I can see, by the way he lifts his hat, that
 * he wants to talk....
 *
 * I have been quite touched by the change in the poor old man. When he sat
 * down beside me, he said in a very gentle way:--
 *
 * "I want to say something to you, miss." I could see he was not at ease,
 * so I took his poor old wrinkled hand in mine and asked him to speak
 * fully; so he said, leaving his hand in mine:--
 *
 * "I'm afraid, my deary, that I must have shocked you by all the wicked
 * things I've been sayin' about the dead, and such like, for weeks past;
 * but I didn't mean them, and I want ye to remember that when I'm gone. We
 * aud folks that be daffled, and with one foot abaft the krok-hooal, don't
 * altogether like to think of it, and we don't want to feel scart of it;
 * an' that's why I've took to makin' light of it, so that I'd cheer up my
 * own heart a bit. But, Lord love ye, miss, I ain't afraid of dyin', not a
 * bit; only I don't want to die if I can help it. My time must be nigh at
 * hand now, for I be aud, and a hundred years is too much for any man to
 * expect; and I'm so nigh it that the Aud Man is already whettin' his
 * scythe. Ye see, I can't get out o' the habit of caffin' about it all at
 * once; the chafts will wag as they be used to. Some day soon the Angel of
 * Death will sound his trumpet for me. But don't ye dooal an' greet, my
 * deary!"--for he saw that I was crying--"if he should come this very
 * night I'd not refuse to answer his call. For life be, after all, only a
 * waitin' for somethin' else than what we're doin'; and death be all that
 * we can rightly depend on. But I'm content, for it's comin' to me, my
 * deary, and comin' quick. It may be comin' while we be lookin' and
 * wonderin'. Maybe it's in that wind out over the sea that's bringin' with
 * it loss and wreck, and sore distress, and sad hearts. Look! look!" he
 * cried suddenly. "There's something in that wind and in the hoast beyont
 * that sounds, and looks, and tastes, and smells like death. It's in the
 * air; I feel it comin'. Lord, make me answer cheerful when my call
 * comes!" He held up his arms devoutly, and raised his hat. His mouth
 * moved as though he were praying. After a few minutes' silence, he got
 * up, shook hands with me, and blessed me, and said good-bye, and hobbled
 * off. It all touched me, and upset me very much.
 *
 * I was glad when the coastguard came along, with his spy-glass under his
 * arm. He stopped to talk with me, as he always does, but all the time
 * kept looking at a strange ship.
 *
 * "I can't make her out," he said; "she's a Russian, by the look of her;
 * but she's knocking about in the queerest way. She doesn't know her mind
 * a bit; she seems to see the storm coming, but can't decide whether to
 * run up north in the open, or to put in here. Look there again! She is
 * steered mighty strangely, for she doesn't mind the hand on the wheel;
 * changes about with every puff of wind. We'll hear more of her before
 * this time to-morrow."
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_VII CHAPTER VII: Cutting from "The Dailygraph," 8 August
 * (_Pasted in Mina Murray's Journal._)
 *
 * From a Correspondent.
 *
 * _Whitby_.
 *
 * One of the greatest and suddenest storms on record has just been
 * experienced here, with results both strange and unique. The weather had
 * been somewhat sultry, but not to any degree uncommon in the month of
 * August. Saturday evening was as fine as was ever known, and the great
 * body of holiday-makers laid out yesterday for visits to Mulgrave Woods,
 * Robin Hood's Bay, Rig Mill, Runswick, Staithes, and the various trips in
 * the neighbourhood of Whitby. The steamers _Emma_ and _Scarborough_ made
 * trips up and down the coast, and there was an unusual amount of
 * "tripping" both to and from Whitby. The day was unusually fine till the
 * afternoon, when some of the gossips who frequent the East Cliff
 * churchyard, and from that commanding eminence watch the wide sweep of
 * sea visible to the north and east, called attention to a sudden show of
 * "mares'-tails" high in the sky to the north-west. The wind was then
 * blowing from the south-west in the mild degree which in barometrical
 * language is ranked "No. 2: light breeze." The coastguard on duty at once
 * made report, and one old fisherman, who for more than half a century has
 * kept watch on weather signs from the East Cliff, foretold in an emphatic
 * manner the coming of a sudden storm. The approach of sunset was so very
 * beautiful, so grand in its masses of splendidly-coloured clouds, that
 * there was quite an assemblage on the walk along the cliff in the old
 * churchyard to enjoy the beauty. Before the sun dipped below the black
 * mass of Kettleness, standing boldly athwart the western sky, its
 * downward way was marked by myriad clouds of every sunset-colour--flame,
 * purple, pink, green, violet, and all the tints of gold; with here and
 * there masses not large, but of seemingly absolute blackness, in all
 * sorts of shapes, as well outlined as colossal silhouettes. The
 * experience was not lost on the painters, and doubtless some of the
 * sketches of the "Prelude to the Great Storm" will grace the R. A. and R.
 * I. walls in May next. More than one captain made up his mind then and
 * there that his "cobble" or his "mule," as they term the different
 * classes of boats, would remain in the harbour till the storm had passed.
 * The wind fell away entirely during the evening, and at midnight there
 * was a dead calm, a sultry heat, and that prevailing intensity which, on
 * the approach of thunder, affects persons of a sensitive nature. There
 * were but few lights in sight at sea, for even the coasting steamers,
 * which usually "hug" the shore so closely, kept well to seaward, and but
 * few fishing-boats were in sight. The only sail noticeable was a foreign
 * schooner with all sails set, which was seemingly going westwards. The
 * foolhardiness or ignorance of her officers was a prolific theme for
 * comment whilst she remained in sight, and efforts were made to signal
 * her to reduce sail in face of her danger. Before the night shut down she
 * was seen with sails idly flapping as she gently rolled on the undulating
 * swell of the sea,
 *
 *     "As idle as a painted ship upon a painted ocean."
 *
 * Shortly before ten o'clock the stillness of the air grew quite
 * oppressive, and the silence was so marked that the bleating of a sheep
 * inland or the barking of a dog in the town was distinctly heard, and the
 * band on the pier, with its lively French air, was like a discord in the
 * great harmony of nature's silence. A little after midnight came a
 * strange sound from over the sea, and high overhead the air began to
 * carry a strange, faint, hollow booming.
 *
 * Then without warning the tempest broke. With a rapidity which, at the
 * time, seemed incredible, and even afterwards is impossible to realize,
 * the whole aspect of nature at once became convulsed. The waves rose in
 * growing fury, each overtopping its fellow, till in a very few minutes
 * the lately glassy sea was like a roaring and devouring monster.
 * White-crested waves beat madly on the level sands and rushed up the
 * shelving cliffs; others broke over the piers, and with their spume swept
 * the lanthorns of the lighthouses which rise from the end of either pier
 * of Whitby Harbour. The wind roared like thunder, and blew with such
 * force that it was with difficulty that even strong men kept their feet,
 * or clung with grim clasp to the iron stanchions. It was found necessary
 * to clear the entire piers from the mass of onlookers, or else the
 * fatalities of the night would have been increased manifold. To add to
 * the difficulties and dangers of the time, masses of sea-fog came
 * drifting inland--white, wet clouds, which swept by in ghostly fashion,
 * so dank and damp and cold that it needed but little effort of
 * imagination to think that the spirits of those lost at sea were
 * touching their living brethren with the clammy hands of death, and many
 * a one shuddered as the wreaths of sea-mist swept by. At times the mist
 * cleared, and the sea for some distance could be seen in the glare of the
 * lightning, which now came thick and fast, followed by such sudden peals
 * of thunder that the whole sky overhead seemed trembling under the shock
 * of the footsteps of the storm.
 *
 * Some of the scenes thus revealed were of immeasurable grandeur and of
 * absorbing interest--the sea, running mountains high, threw skywards with
 * each wave mighty masses of white foam, which the tempest seemed to
 * snatch at and whirl away into space; here and there a fishing-boat, with
 * a rag of sail, running madly for shelter before the blast; now and again
 * the white wings of a storm-tossed sea-bird. On the summit of the East
 * Cliff the new searchlight was ready for experiment, but had not yet been
 * tried. The officers in charge of it got it into working order, and in
 * the pauses of the inrushing mist swept with it the surface of the sea.
 * Once or twice its service was most effective, as when a fishing-boat,
 * with gunwale under water, rushed into the harbour, able, by the guidance
 * of the sheltering light, to avoid the danger of dashing against the
 * piers. As each boat achieved the safety of the port there was a shout of
 * joy from the mass of people on shore, a shout which for a moment seemed
 * to cleave the gale and was then swept away in its rush.
 *
 * Before long the searchlight discovered some distance away a schooner
 * with all sails set, apparently the same vessel which had been noticed
 * earlier in the evening. The wind had by this time backed to the east,
 * and there was a shudder amongst the watchers on the cliff as they
 * realized the terrible danger in which she now was. Between her and the
 * port lay the great flat reef on which so many good ships have from time
 * to time suffered, and, with the wind blowing from its present quarter,
 * it would be quite impossible that she should fetch the entrance of the
 * harbour. It was now nearly the hour of high tide, but the waves were so
 * great that in their troughs the shallows of the shore were almost
 * visible, and the schooner, with all sails set, was rushing with such
 * speed that, in the words of one old salt, "she must fetch up somewhere,
 * if it was only in hell." Then came another rush of sea-fog, greater than
 * any hitherto--a mass of dank mist, which seemed to close on all things
 * like a grey pall, and left available to men only the organ of hearing,
 * for the roar of the tempest, and the crash of the thunder, and the
 * booming of the mighty billows came through the damp oblivion even louder
 * than before. The rays of the searchlight were kept fixed on the harbour
 * mouth across the East Pier, where the shock was expected, and men waited
 * breathless. The wind suddenly shifted to the north-east, and the remnant
 * of the sea-fog melted in the blast; and then, _mirabile dictu_, between
 * the piers, leaping from wave to wave as it rushed at headlong speed,
 * swept the strange schooner before the blast, with all sail set, and
 * gained the safety of the harbour. The searchlight followed her, and a
 * shudder ran through all who saw her, for lashed to the helm was a
 * corpse, with drooping head, which swung horribly to and fro at each
 * motion of the ship. No other form could be seen on deck at all. A great
 * awe came on all as they realised that the ship, as if by a miracle, had
 * found the harbour, unsteered save by the hand of a dead man! However,
 * all took place more quickly than it takes to write these words. The
 * schooner paused not, but rushing across the harbour, pitched herself on
 * that accumulation of sand and gravel washed by many tides and many
 * storms into the south-east corner of the pier jutting under the East
 * Cliff, known locally as Tate Hill Pier.
 *
 * There was of course a considerable concussion as the vessel drove up on
 * the sand heap. Every spar, rope, and stay was strained, and some of the
 * "top-hammer" came crashing down. But, strangest of all, the very instant
 * the shore was touched, an immense dog sprang up on deck from below, as
 * if shot up by the concussion, and running forward, jumped from the bow
 * on the sand. Making straight for the steep cliff, where the churchyard
 * hangs over the laneway to the East Pier so steeply that some of the flat
 * tombstones--"thruff-steans" or "through-stones," as they call them in
 * the Whitby vernacular--actually project over where the sustaining cliff
 * has fallen away, it disappeared in the darkness, which seemed
 * intensified just beyond the focus of the searchlight.
 *
 * It so happened that there was no one at the moment on Tate Hill Pier, as
 * all those whose houses are in close proximity were either in bed or were
 * out on the heights above. Thus the coastguard on duty on the eastern
 * side of the harbour, who at once ran down to the little pier, was the
 * first to climb on board. The men working the searchlight, after scouring
 * the entrance of the harbour without seeing anything, then turned the
 * light on the derelict and kept it there. The coastguard ran aft, and
 * when he came beside the wheel, bent over to examine it, and recoiled at
 * once as though under some sudden emotion. This seemed to pique general
 * curiosity, and quite a number of people began to run. It is a good way
 * round from the West Cliff by the Drawbridge to Tate Hill Pier, but your
 * correspondent is a fairly good runner, and came well ahead of the crowd.
 * When I arrived, however, I found already assembled on the pier a crowd,
 * whom the coastguard and police refused to allow to come on board. By the
 * courtesy of the chief boatman, I was, as your correspondent, permitted
 * to climb on deck, and was one of a small group who saw the dead seaman
 * whilst actually lashed to the wheel.
 *
 * It was no wonder that the coastguard was surprised, or even awed, for
 * not often can such a sight have been seen. The man was simply fastened
 * by his hands, tied one over the other, to a spoke of the wheel. Between
 * the inner hand and the wood was a crucifix, the set of beads on which it
 * was fastened being around both wrists and wheel, and all kept fast by
 * the binding cords. The poor fellow may have been seated at one time, but
 * the flapping and buffeting of the sails had worked through the rudder of
 * the wheel and dragged him to and fro, so that the cords with which he
 * was tied had cut the flesh to the bone. Accurate note was made of the
 * state of things, and a doctor--Surgeon J. M. Caffyn, of 33, East Elliot
 * Place--who came immediately after me, declared, after making
 * examination, that the man must have been dead for quite two days. In his
 * pocket was a bottle, carefully corked, empty save for a little roll of
 * paper, which proved to be the addendum to the log. The coastguard said
 * the man must have tied up his own hands, fastening the knots with his
 * teeth. The fact that a coastguard was the first on board may save some
 * complications, later on, in the Admiralty Court; for coastguards cannot
 * claim the salvage which is the right of the first civilian entering on a
 * derelict. Already, however, the legal tongues are wagging, and one young
 * law student is loudly asserting that the rights of the owner are already
 * completely sacrificed, his property being held in contravention of the
 * statutes of mortmain, since the tiller, as emblemship, if not proof, of
 * delegated possession, is held in a _dead hand_. It is needless to say
 * that the dead steersman has been reverently removed from the place where
 * he held his honourable watch and ward till death--a steadfastness as
 * noble as that of the young Casabianca--and placed in the mortuary to
 * await inquest.
 *
 * Already the sudden storm is passing, and its fierceness is abating;
 * crowds are scattering homeward, and the sky is beginning to redden over
 * the Yorkshire wolds. I shall send, in time for your next issue, further
 * details of the derelict ship which found her way so miraculously into
 * harbour in the storm.
 *
 * _Whitby_
 *
 * _9 August._--The sequel to the strange arrival of the derelict in the
 * storm last night is almost more startling than the thing itself. It
 * turns out that the schooner is a Russian from Varna, and is called the
 * _Demeter_. She is almost entirely in ballast of silver sand, with only a
 * small amount of cargo--a number of great wooden boxes filled with mould.
 * This cargo was consigned to a Whitby solicitor, Mr. S. F. Billington, of
 * 7, The Crescent, who this morning went aboard and formally took
 * possession of the goods consigned to him. The Russian consul, too,
 * acting for the charter-party, took formal possession of the ship, and
 * paid all harbour dues, etc. Nothing is talked about here to-day except
 * the strange coincidence; the officials of the Board of Trade have been
 * most exacting in seeing that every compliance has been made with
 * existing regulations. As the matter is to be a "nine days' wonder," they
 * are evidently determined that there shall be no cause of after
 * complaint. A good deal of interest was abroad concerning the dog which
 * landed when the ship struck, and more than a few of the members of the
 * S. P. C. A., which is very strong in Whitby, have tried to befriend the
 * animal. To the general disappointment, however, it was not to be found;
 * it seems to have disappeared entirely from the town. It may be that it
 * was frightened and made its way on to the moors, where it is still
 * hiding in terror. There are some who look with dread on such a
 * possibility, lest later on it should in itself become a danger, for it
 * is evidently a fierce brute. Early this morning a large dog, a half-bred
 * mastiff belonging to a coal merchant close to Tate Hill Pier, was found
 * dead in the roadway opposite to its master's yard. It had been fighting,
 * and manifestly had had a savage opponent, for its throat was torn away,
 * and its belly was slit open as if with a savage claw.
 *
 *        *       *       *       *       *
 *
 * _Later._--By the kindness of the Board of Trade inspector, I have been
 * permitted to look over the log-book of the _Demeter_, which was in order
 * up to within three days, but contained nothing of special interest
 * except as to facts of missing men. The greatest interest, however, is
 * with regard to the paper found in the bottle, which was to-day produced
 * at the inquest; and a more strange narrative than the two between them
 * unfold it has not been my lot to come across. As there is no motive for
 * concealment, I am permitted to use them, and accordingly send you a
 * rescript, simply omitting technical details of seamanship and
 * supercargo. It almost seems as though the captain had been seized with
 * some kind of mania before he had got well into blue water, and that
 * this had developed persistently throughout the voyage. Of course my
 * statement must be taken _cum grano_, since I am writing from the
 * dictation of a clerk of the Russian consul, who kindly translated for
 * me, time being short.
 *
 *                          LOG OF THE "DEMETER."
 *
 *
 * _Varna to Whitby._
 *
 * _Written 18 July, things so strange happening, that I shall keep
 * accurate note henceforth till we land._
 *
 *        *       *       *       *       *
 *
 * On 6 July we finished taking in cargo, silver sand and boxes of earth.
 * At noon set sail. East wind, fresh. Crew, five hands ... two mates,
 * cook, and myself (captain).
 *
 *        *       *       *       *       *
 *
 * On 11 July at dawn entered Bosphorus. Boarded by Turkish Customs
 * officers. Backsheesh. All correct. Under way at 4 p. m.
 *
 *        *       *       *       *       *
 *
 * On 12 July through Dardanelles. More Customs officers and flagboat of
 * guarding squadron. Backsheesh again. Work of officers thorough, but
 * quick. Want us off soon. At dark passed into Archipelago.
 *
 *        *       *       *       *       *
 *
 * On 13 July passed Cape Matapan. Crew dissatisfied about something.
 * Seemed scared, but would not speak out.
 *
 *        *       *       *       *       *
 *
 * On 14 July was somewhat anxious about crew. Men all steady fellows, who
 * sailed with me before. Mate could not make out what was wrong; they only
 * told him there was _something_, and crossed themselves. Mate lost temper
 * with one of them that day and struck him. Expected fierce quarrel, but
 * all was quiet.
 *
 *        *       *       *       *       *
 *
 * On 16 July mate reported in the morning that one of crew, Petrofsky, was
 * missing. Could not account for it. Took larboard watch eight bells last
 * night; was relieved by Abramoff, but did not go to bunk. Men more
 * downcast than ever. All said they expected something of the kind, but
 * would not say more than there was _something_ aboard. Mate getting very
 * impatient with them; feared some trouble ahead.
 *
 *        *       *       *       *       *
 *
 * On 17 July, yesterday, one of the men, Olgaren, came to my cabin, and in
 * an awestruck way confided to me that he thought there was a strange man
 * aboard the ship. He said that in his watch he had been sheltering
 * behind the deck-house, as there was a rain-storm, when he saw a tall,
 * thin man, who was not like any of the crew, come up the companion-way,
 * and go along the deck forward, and disappear. He followed cautiously,
 * but when he got to bows found no one, and the hatchways were all closed.
 * He was in a panic of superstitious fear, and I am afraid the panic may
 * spread. To allay it, I shall to-day search entire ship carefully from
 * stem to stern.
 *
 *        *       *       *       *       *
 *
 * Later in the day I got together the whole crew, and told them, as they
 * evidently thought there was some one in the ship, we would search from
 * stem to stern. First mate angry; said it was folly, and to yield to such
 * foolish ideas would demoralise the men; said he would engage to keep
 * them out of trouble with a handspike. I let him take the helm, while the
 * rest began thorough search, all keeping abreast, with lanterns: we left
 * no corner unsearched. As there were only the big wooden boxes, there
 * were no odd corners where a man could hide. Men much relieved when
 * search over, and went back to work cheerfully. First mate scowled, but
 * said nothing.
 *
 *        *       *       *       *       *
 *
 * _22 July_.--Rough weather last three days, and all hands busy with
 * sails--no time to be frightened. Men seem to have forgotten their dread.
 * Mate cheerful again, and all on good terms. Praised men for work in bad
 * weather. Passed Gibralter and out through Straits. All well.
 *
 *        *       *       *       *       *
 *
 * _24 July_.--There seems some doom over this ship. Already a hand short,
 * and entering on the Bay of Biscay with wild weather ahead, and yet last
 * night another man lost--disappeared. Like the first, he came off his
 * watch and was not seen again. Men all in a panic of fear; sent a round
 * robin, asking to have double watch, as they fear to be alone. Mate
 * angry. Fear there will be some trouble, as either he or the men will do
 * some violence.
 *
 *        *       *       *       *       *
 *
 * _28 July_.--Four days in hell, knocking about in a sort of maelstrom,
 * and the wind a tempest. No sleep for any one. Men all worn out. Hardly
 * know how to set a watch, since no one fit to go on. Second mate
 * volunteered to steer and watch, and let men snatch a few hours' sleep.
 * Wind abating; seas still terrific, but feel them less, as ship is
 * steadier.
 *
 *        *       *       *       *       *
 *
 * _29 July_.--Another tragedy. Had single watch to-night, as crew too
 * tired to double. When morning watch came on deck could find no one
 * except steersman. Raised outcry, and all came on deck. Thorough search,
 * but no one found. Are now without second mate, and crew in a panic. Mate
 * and I agreed to go armed henceforth and wait for any sign of cause.
 *
 *        *       *       *       *       *
 *
 * _30 July_.--Last night. Rejoiced we are nearing England. Weather fine,
 * all sails set. Retired worn out; slept soundly; awaked by mate telling
 * me that both man of watch and steersman missing. Only self and mate and
 * two hands left to work ship.
 *
 *        *       *       *       *       *
 *
 * _1 August_.--Two days of fog, and not a sail sighted. Had hoped when in
 * the English Channel to be able to signal for help or get in somewhere.
 * Not having power to work sails, have to run before wind. Dare not lower,
 * as could not raise them again. We seem to be drifting to some terrible
 * doom. Mate now more demoralised than either of men. His stronger nature
 * seems to have worked inwardly against himself. Men are beyond fear,
 * working stolidly and patiently, with minds made up to worst. They are
 * Russian, he Roumanian.
 *
 *        *       *       *       *       *
 *
 * _2 August, midnight_.--Woke up from few minutes' sleep by hearing a cry,
 * seemingly outside my port. Could see nothing in fog. Rushed on deck, and
 * ran against mate. Tells me heard cry and ran, but no sign of man on
 * watch. One more gone. Lord, help us! Mate says we must be past Straits
 * of Dover, as in a moment of fog lifting he saw North Foreland, just as
 * he heard the man cry out. If so we are now off in the North Sea, and
 * only God can guide us in the fog, which seems to move with us; and God
 * seems to have deserted us.
 *
 *        *       *       *       *       *
 *
 * _3 August_.--At midnight I went to relieve the man at the wheel, and
 * when I got to it found no one there. The wind was steady, and as we ran
 * before it there was no yawing. I dared not leave it, so shouted for the
 * mate. After a few seconds he rushed up on deck in his flannels. He
 * looked wild-eyed and haggard, and I greatly fear his reason has given
 * way. He came close to me and whispered hoarsely, with his mouth to my
 * ear, as though fearing the very air might hear: "_It_ is here; I know
 * it, now. On the watch last night I saw It, like a man, tall and thin,
 * and ghastly pale. It was in the bows, and looking out. I crept behind
 * It, and gave It my knife; but the knife went through It, empty as the
 * air." And as he spoke he took his knife and drove it savagely into
 * space. Then he went on: "But It is here, and I'll find It. It is in the
 * hold, perhaps in one of those boxes. I'll unscrew them one by one and
 * see. You work the helm." And, with a warning look and his finger on his
 * lip, he went below. There was springing up a choppy wind, and I could
 * not leave the helm. I saw him come out on deck again with a tool-chest
 * and a lantern, and go down the forward hatchway. He is mad, stark,
 * raving mad, and it's no use my trying to stop him. He can't hurt those
 * big boxes: they are invoiced as "clay," and to pull them about is as
 * harmless a thing as he can do. So here I stay, and mind the helm, and
 * write these notes. I can only trust in God and wait till the fog clears.
 * Then, if I can't steer to any harbour with the wind that is, I shall cut
 * down sails and lie by, and signal for help....
 *
 *        *       *       *       *       *
 *
 * It is nearly all over now. Just as I was beginning to hope that the mate
 * would come out calmer--for I heard him knocking away at something in the
 * hold, and work is good for him--there came up the hatchway a sudden,
 * startled scream, which made my blood run cold, and up on the deck he
 * came as if shot from a gun--a raging madman, with his eyes rolling and
 * his face convulsed with fear. "Save me! save me!" he cried, and then
 * looked round on the blanket of fog. His horror turned to despair, and in
 * a steady voice he said: "You had better come too, captain, before it is
 * too late. _He_ is there. I know the secret now. The sea will save me
 * from Him, and it is all that is left!" Before I could say a word, or
 * move forward to seize him, he sprang on the bulwark and deliberately
 * threw himself into the sea. I suppose I know the secret too, now. It was
 * this madman who had got rid of the men one by one, and now he has
 * followed them himself. God help me! How am I to account for all these
 * horrors when I get to port? _When_ I get to port! Will that ever be?
 *
 *        *       *       *       *       *
 *
 * _4 August._--Still fog, which the sunrise cannot pierce. I know there is
 * sunrise because I am a sailor, why else I know not. I dared not go
 * below, I dared not leave the helm; so here all night I stayed, and in
 * the dimness of the night I saw It--Him! God forgive me, but the mate was
 * right to jump overboard. It was better to die like a man; to die like a
 * sailor in blue water no man can object. But I am captain, and I must not
 * leave my ship. But I shall baffle this fiend or monster, for I shall tie
 * my hands to the wheel when my strength begins to fail, and along with
 * them I shall tie that which He--It!--dare not touch; and then, come good
 * wind or foul, I shall save my soul, and my honour as a captain. I am
 * growing weaker, and the night is coming on. If He can look me in the
 * face again, I may not have time to act.... If we are wrecked, mayhap
 * this bottle may be found, and those who find it may understand; if not,
 * ... well, then all men shall know that I have been true to my trust. God
 * and the Blessed Virgin and the saints help a poor ignorant soul trying
 * to do his duty....
 *
 *        *       *       *       *       *
 *
 * Of course the verdict was an open one. There is no evidence to adduce;
 * and whether or not the man himself committed the murders there is now
 * none to say. The folk here hold almost universally that the captain is
 * simply a hero, and he is to be given a public funeral. Already it is
 * arranged that his body is to be taken with a train of boats up the Esk
 * for a piece and then brought back to Tate Hill Pier and up the abbey
 * steps; for he is to be buried in the churchyard on the cliff. The owners
 * of more than a hundred boats have already given in their names as
 * wishing to follow him to the grave.
 *
 * No trace has ever been found of the great dog; at which there is much
 * mourning, for, with public opinion in its present state, he would, I
 * believe, be adopted by the town. To-morrow will see the funeral; and so
 * will end this one more "mystery of the sea."
 *
 *
 * _Mina Murray's Journal._
 *
 * _8 August._--Lucy was very restless all night, and I, too, could not
 * sleep. The storm was fearful, and as it boomed loudly among the
 * chimney-pots, it made me shudder. When a sharp puff came it seemed to be
 * like a distant gun. Strangely enough, Lucy did not wake; but she got up
 * twice and dressed herself. Fortunately, each time I awoke in time and
 * managed to undress her without waking her, and got her back to bed. It
 * is a very strange thing, this sleep-walking, for as soon as her will is
 * thwarted in any physical way, her intention, if there be any,
 * disappears, and she yields herself almost exactly to the routine of her
 * life.
 *
 * Early in the morning we both got up and went down to the harbour to see
 * if anything had happened in the night. There were very few people about,
 * and though the sun was bright, and the air clear and fresh, the big,
 * grim-looking waves, that seemed dark themselves because the foam that
 * topped them was like snow, forced themselves in through the narrow mouth
 * of the harbour--like a bullying man going through a crowd. Somehow I
 * felt glad that Jonathan was not on the sea last night, but on land. But,
 * oh, is he on land or sea? Where is he, and how? I am getting fearfully
 * anxious about him. If I only knew what to do, and could do anything!
 *
 *        *       *       *       *       *
 *
 * _10 August._--The funeral of the poor sea-captain to-day was most
 * touching. Every boat in the harbour seemed to be there, and the coffin
 * was carried by captains all the way from Tate Hill Pier up to the
 * churchyard. Lucy came with me, and we went early to our old seat, whilst
 * the cortège of boats went up the river to the Viaduct and came down
 * again. We had a lovely view, and saw the procession nearly all the way.
 * The poor fellow was laid to rest quite near our seat so that we stood on
 * it when the time came and saw everything. Poor Lucy seemed much upset.
 * She was restless and uneasy all the time, and I cannot but think that
 * her dreaming at night is telling on her. She is quite odd in one thing:
 * she will not admit to me that there is any cause for restlessness; or if
 * there be, she does not understand it herself. There is an additional
 * cause in that poor old Mr. Swales was found dead this morning on our
 * seat, his neck being broken. He had evidently, as the doctor said,
 * fallen back in the seat in some sort of fright, for there was a look of
 * fear and horror on his face that the men said made them shudder. Poor
 * dear old man! Perhaps he had seen Death with his dying eyes! Lucy is so
 * sweet and sensitive that she feels influences more acutely than other
 * people do. Just now she was quite upset by a little thing which I did
 * not much heed, though I am myself very fond of animals. One of the men
 * who came up here often to look for the boats was followed by his dog.
 * The dog is always with him. They are both quiet persons, and I never saw
 * the man angry, nor heard the dog bark. During the service the dog would
 * not come to its master, who was on the seat with us, but kept a few
 * yards off, barking and howling. Its master spoke to it gently, and then
 * harshly, and then angrily; but it would neither come nor cease to make a
 * noise. It was in a sort of fury, with its eyes savage, and all its hairs
 * bristling out like a cat's tail when puss is on the war-path. Finally
 * the man, too, got angry, and jumped down and kicked the dog, and then
 * took it by the scruff of the neck and half dragged and half threw it on
 * the tombstone on which the seat is fixed. The moment it touched the
 * stone the poor thing became quiet and fell all into a tremble. It did
 * not try to get away, but crouched down, quivering and cowering, and was
 * in such a pitiable state of terror that I tried, though without effect,
 * to comfort it. Lucy was full of pity, too, but she did not attempt to
 * touch the dog, but looked at it in an agonised sort of way. I greatly
 * fear that she is of too super-sensitive a nature to go through the world
 * without trouble. She will be dreaming of this to-night, I am sure. The
 * whole agglomeration of things--the ship steered into port by a dead
 * man; his attitude, tied to the wheel with a crucifix and beads; the
 * touching funeral; the dog, now furious and now in terror--will all
 * afford material for her dreams.
 *
 * I think it will be best for her to go to bed tired out physically, so I
 * shall take her for a long walk by the cliffs to Robin Hood's Bay and
 * back. She ought not to have much inclination for sleep-walking then.
 */
#endif // DOXYGEN_TEST_PAGES

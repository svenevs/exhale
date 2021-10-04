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
 * \brief This file should be two levels down in the hierarchy.
 */
#pragma once

namespace nested {
    namespace dual_nested {
        /// The first class inside the ``nested::dual_nested`` namespace.
        struct one {
            /// Nesting even further: ``nested::dual_nested::one::params``.
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
}
#if defined(DOXYGEN_TEST_PAGES)
/**
 * \page chapter_XV CHAPTER XV: Dr. Seward's Diary
 * DR. SEWARD'S DIARY--_continued_.
 *
 *
 * For a while sheer anger mastered me; it was as if he had during her life
 * struck Lucy on the face. I smote the table hard and rose up as I said to
 * him:--
 *
 * "Dr. Van Helsing, are you mad?" He raised his head and looked at me, and
 * somehow the tenderness of his face calmed me at once. "Would I were!" he
 * said. "Madness were easy to bear compared with truth like this. Oh, my
 * friend, why, think you, did I go so far round, why take so long to tell
 * you so simple a thing? Was it because I hate you and have hated you all
 * my life? Was it because I wished to give you pain? Was it that I wanted,
 * now so late, revenge for that time when you saved my life, and from a
 * fearful death? Ah no!"
 *
 * "Forgive me," said I. He went on:--
 *
 * "My friend, it was because I wished to be gentle in the breaking to you,
 * for I know you have loved that so sweet lady. But even yet I do not
 * expect you to believe. It is so hard to accept at once any abstract
 * truth, that we may doubt such to be possible when we have always
 * believed the 'no' of it; it is more hard still to accept so sad a
 * concrete truth, and of such a one as Miss Lucy. To-night I go to prove
 * it. Dare you come with me?"
 *
 * This staggered me. A man does not like to prove such a truth; Byron
 * excepted from the category, jealousy.
 *
 *     "And prove the very truth he most abhorred."
 *
 * He saw my hesitation, and spoke:--
 *
 * "The logic is simple, no madman's logic this time, jumping from tussock
 * to tussock in a misty bog. If it be not true, then proof will be relief;
 * at worst it will not harm. If it be true! Ah, there is the dread; yet
 * very dread should help my cause, for in it is some need of belief. Come,
 * I tell you what I propose: first, that we go off now and see that child
 * in the hospital. Dr. Vincent, of the North Hospital, where the papers
 * say the child is, is friend of mine, and I think of yours since you were
 * in class at Amsterdam. He will let two scientists see his case, if he
 * will not let two friends. We shall tell him nothing, but only that we
 * wish to learn. And then----"
 *
 * "And then?" He took a key from his pocket and held it up. "And then we
 * spend the night, you and I, in the churchyard where Lucy lies. This is
 * the key that lock the tomb. I had it from the coffin-man to give to
 * Arthur." My heart sank within me, for I felt that there was some fearful
 * ordeal before us. I could do nothing, however, so I plucked up what
 * heart I could and said that we had better hasten, as the afternoon was
 * passing....
 *
 * We found the child awake. It had had a sleep and taken some food, and
 * altogether was going on well. Dr. Vincent took the bandage from its
 * throat, and showed us the punctures. There was no mistaking the
 * similarity to those which had been on Lucy's throat. They were smaller,
 * and the edges looked fresher; that was all. We asked Vincent to what he
 * attributed them, and he replied that it must have been a bite of some
 * animal, perhaps a rat; but, for his own part, he was inclined to think
 * that it was one of the bats which are so numerous on the northern
 * heights of London. "Out of so many harmless ones," he said, "there may
 * be some wild specimen from the South of a more malignant species. Some
 * sailor may have brought one home, and it managed to escape; or even from
 * the Zoölogical Gardens a young one may have got loose, or one be bred
 * there from a vampire. These things do occur, you know. Only ten days ago
 * a wolf got out, and was, I believe, traced up in this direction. For a
 * week after, the children were playing nothing but Red Riding Hood on the
 * Heath and in every alley in the place until this 'bloofer lady' scare
 * came along, since when it has been quite a gala-time with them. Even
 * this poor little mite, when he woke up to-day, asked the nurse if he
 * might go away. When she asked him why he wanted to go, he said he wanted
 * to play with the 'bloofer lady.'"
 *
 * "I hope," said Van Helsing, "that when you are sending the child home
 * you will caution its parents to keep strict watch over it. These fancies
 * to stray are most dangerous; and if the child were to remain out another
 * night, it would probably be fatal. But in any case I suppose you will
 * not let it away for some days?"
 *
 * "Certainly not, not for a week at least; longer if the wound is not
 * healed."
 *
 * Our visit to the hospital took more time than we had reckoned on, and
 * the sun had dipped before we came out. When Van Helsing saw how dark it
 * was, he said:--
 *
 * "There is no hurry. It is more late than I thought. Come, let us seek
 * somewhere that we may eat, and then we shall go on our way."
 *
 * We dined at "Jack Straw's Castle" along with a little crowd of
 * bicyclists and others who were genially noisy. About ten o'clock we
 * started from the inn. It was then very dark, and the scattered lamps
 * made the darkness greater when we were once outside their individual
 * radius. The Professor had evidently noted the road we were to go, for he
 * went on unhesitatingly; but, as for me, I was in quite a mixup as to
 * locality. As we went further, we met fewer and fewer people, till at
 * last we were somewhat surprised when we met even the patrol of horse
 * police going their usual suburban round. At last we reached the wall of
 * the churchyard, which we climbed over. With some little difficulty--for
 * it was very dark, and the whole place seemed so strange to us--we found
 * the Westenra tomb. The Professor took the key, opened the creaky door,
 * and standing back, politely, but quite unconsciously, motioned me to
 * precede him. There was a delicious irony in the offer, in the
 * courtliness of giving preference on such a ghastly occasion. My
 * companion followed me quickly, and cautiously drew the door to, after
 * carefully ascertaining that the lock was a falling, and not a spring,
 * one. In the latter case we should have been in a bad plight. Then he
 * fumbled in his bag, and taking out a matchbox and a piece of candle,
 * proceeded to make a light. The tomb in the day-time, and when wreathed
 * with fresh flowers, had looked grim and gruesome enough; but now, some
 * days afterwards, when the flowers hung lank and dead, their whites
 * turning to rust and their greens to browns; when the spider and the
 * beetle had resumed their accustomed dominance; when time-discoloured
 * stone, and dust-encrusted mortar, and rusty, dank iron, and tarnished
 * brass, and clouded silver-plating gave back the feeble glimmer of a
 * candle, the effect was more miserable and sordid than could have been
 * imagined. It conveyed irresistibly the idea that life--animal life--was
 * not the only thing which could pass away.
 *
 * Van Helsing went about his work systematically. Holding his candle so
 * that he could read the coffin plates, and so holding it that the sperm
 * dropped in white patches which congealed as they touched the metal, he
 * made assurance of Lucy's coffin. Another search in his bag, and he took
 * out a turnscrew.
 *
 * "What are you going to do?" I asked.
 *
 * "To open the coffin. You shall yet be convinced." Straightway he began
 * taking out the screws, and finally lifted off the lid, showing the
 * casing of lead beneath. The sight was almost too much for me. It seemed
 * to be as much an affront to the dead as it would have been to have
 * stripped off her clothing in her sleep whilst living; I actually took
 * hold of his hand to stop him. He only said: "You shall see," and again
 * fumbling in his bag, took out a tiny fret-saw. Striking the turnscrew
 * through the lead with a swift downward stab, which made me wince, he
 * made a small hole, which was, however, big enough to admit the point of
 * the saw. I had expected a rush of gas from the week-old corpse. We
 * doctors, who have had to study our dangers, have to become accustomed to
 * such things, and I drew back towards the door. But the Professor never
 * stopped for a moment; he sawed down a couple of feet along one side of
 * the lead coffin, and then across, and down the other side. Taking the
 * edge of the loose flange, he bent it back towards the foot of the
 * coffin, and holding up the candle into the aperture, motioned to me to
 * look.
 *
 * I drew near and looked. The coffin was empty.
 *
 * It was certainly a surprise to me, and gave me a considerable shock, but
 * Van Helsing was unmoved. He was now more sure than ever of his ground,
 * and so emboldened to proceed in his task. "Are you satisfied now, friend
 * John?" he asked.
 *
 * I felt all the dogged argumentativeness of my nature awake within me as
 * I answered him:--
 *
 * "I am satisfied that Lucy's body is not in that coffin; but that only
 * proves one thing."
 *
 * "And what is that, friend John?"
 *
 * "That it is not there."
 *
 * "That is good logic," he said, "so far as it goes. But how do you--how
 * can you--account for it not being there?"
 *
 * "Perhaps a body-snatcher," I suggested. "Some of the undertaker's people
 * may have stolen it." I felt that I was speaking folly, and yet it was
 * the only real cause which I could suggest. The Professor sighed. "Ah
 * well!" he said, "we must have more proof. Come with me."
 *
 * He put on the coffin-lid again, gathered up all his things and placed
 * them in the bag, blew out the light, and placed the candle also in the
 * bag. We opened the door, and went out. Behind us he closed the door and
 * locked it. He handed me the key, saying: "Will you keep it? You had
 * better be assured." I laughed--it was not a very cheerful laugh, I am
 * bound to say--as I motioned him to keep it. "A key is nothing," I said;
 * "there may be duplicates; and anyhow it is not difficult to pick a lock
 * of that kind." He said nothing, but put the key in his pocket. Then he
 * told me to watch at one side of the churchyard whilst he would watch at
 * the other. I took up my place behind a yew-tree, and I saw his dark
 * figure move until the intervening headstones and trees hid it from my
 * sight.
 *
 * It was a lonely vigil. Just after I had taken my place I heard a distant
 * clock strike twelve, and in time came one and two. I was chilled and
 * unnerved, and angry with the Professor for taking me on such an errand
 * and with myself for coming. I was too cold and too sleepy to be keenly
 * observant, and not sleepy enough to betray my trust so altogether I had
 * a dreary, miserable time.
 *
 * Suddenly, as I turned round, I thought I saw something like a white
 * streak, moving between two dark yew-trees at the side of the churchyard
 * farthest from the tomb; at the same time a dark mass moved from the
 * Professor's side of the ground, and hurriedly went towards it. Then I
 * too moved; but I had to go round headstones and railed-off tombs, and I
 * stumbled over graves. The sky was overcast, and somewhere far off an
 * early cock crew. A little way off, beyond a line of scattered
 * juniper-trees, which marked the pathway to the church, a white, dim
 * figure flitted in the direction of the tomb. The tomb itself was hidden
 * by trees, and I could not see where the figure disappeared. I heard the
 * rustle of actual movement where I had first seen the white figure, and
 * coming over, found the Professor holding in his arms a tiny child. When
 * he saw me he held it out to me, and said:--
 *
 * "Are you satisfied now?"
 *
 * "No," I said, in a way that I felt was aggressive.
 *
 * "Do you not see the child?"
 *
 * "Yes, it is a child, but who brought it here? And is it wounded?" I
 * asked.
 *
 * "We shall see," said the Professor, and with one impulse we took our way
 * out of the churchyard, he carrying the sleeping child.
 *
 * When we had got some little distance away, we went into a clump of
 * trees, and struck a match, and looked at the child's throat. It was
 * without a scratch or scar of any kind.
 *
 * "Was I right?" I asked triumphantly.
 *
 * "We were just in time," said the Professor thankfully.
 *
 * We had now to decide what we were to do with the child, and so consulted
 * about it. If we were to take it to a police-station we should have to
 * give some account of our movements during the night; at least, we should
 * have had to make some statement as to how we had come to find the child.
 * So finally we decided that we would take it to the Heath, and when we
 * heard a policeman coming, would leave it where he could not fail to find
 * it; we would then seek our way home as quickly as we could. All fell out
 * well. At the edge of Hampstead Heath we heard a policeman's heavy
 * tramp, and laying the child on the pathway, we waited and watched until
 * he saw it as he flashed his lantern to and fro. We heard his exclamation
 * of astonishment, and then we went away silently. By good chance we got a
 * cab near the "Spaniards," and drove to town.
 *
 * I cannot sleep, so I make this entry. But I must try to get a few hours'
 * sleep, as Van Helsing is to call for me at noon. He insists that I shall
 * go with him on another expedition.
 *
 *        *       *       *       *       *
 *
 * _27 September._--It was two o'clock before we found a suitable
 * opportunity for our attempt. The funeral held at noon was all completed,
 * and the last stragglers of the mourners had taken themselves lazily
 * away, when, looking carefully from behind a clump of alder-trees, we saw
 * the sexton lock the gate after him. We knew then that we were safe till
 * morning did we desire it; but the Professor told me that we should not
 * want more than an hour at most. Again I felt that horrid sense of the
 * reality of things, in which any effort of imagination seemed out of
 * place; and I realised distinctly the perils of the law which we were
 * incurring in our unhallowed work. Besides, I felt it was all so useless.
 * Outrageous as it was to open a leaden coffin, to see if a woman dead
 * nearly a week were really dead, it now seemed the height of folly to
 * open the tomb again, when we knew, from the evidence of our own
 * eyesight, that the coffin was empty. I shrugged my shoulders, however,
 * and rested silent, for Van Helsing had a way of going on his own road,
 * no matter who remonstrated. He took the key, opened the vault, and again
 * courteously motioned me to precede. The place was not so gruesome as
 * last night, but oh, how unutterably mean-looking when the sunshine
 * streamed in. Van Helsing walked over to Lucy's coffin, and I followed.
 * He bent over and again forced back the leaden flange; and then a shock
 * of surprise and dismay shot through me.
 *
 * There lay Lucy, seemingly just as we had seen her the night before her
 * funeral. She was, if possible, more radiantly beautiful than ever; and I
 * could not believe that she was dead. The lips were red, nay redder than
 * before; and on the cheeks was a delicate bloom.
 *
 * "Is this a juggle?" I said to him.
 *
 * "Are you convinced now?" said the Professor in response, and as he spoke
 * he put over his hand, and in a way that made me shudder, pulled back the
 * dead lips and showed the white teeth.
 *
 * "See," he went on, "see, they are even sharper than before. With this
 * and this"--and he touched one of the canine teeth and that below
 * it--"the little children can be bitten. Are you of belief now, friend
 * John?" Once more, argumentative hostility woke within me. I _could_ not
 * accept such an overwhelming idea as he suggested; so, with an attempt to
 * argue of which I was even at the moment ashamed, I said:--
 *
 * "She may have been placed here since last night."
 *
 * "Indeed? That is so, and by whom?"
 *
 * "I do not know. Some one has done it."
 *
 * "And yet she has been dead one week. Most peoples in that time would not
 * look so." I had no answer for this, so was silent. Van Helsing did not
 * seem to notice my silence; at any rate, he showed neither chagrin nor
 * triumph. He was looking intently at the face of the dead woman, raising
 * the eyelids and looking at the eyes, and once more opening the lips and
 * examining the teeth. Then he turned to me and said:--
 *
 * "Here, there is one thing which is different from all recorded; here is
 * some dual life that is not as the common. She was bitten by the vampire
 * when she was in a trance, sleep-walking--oh, you start; you do not know
 * that, friend John, but you shall know it all later--and in trance could
 * he best come to take more blood. In trance she died, and in trance she
 * is Un-Dead, too. So it is that she differ from all other. Usually when
 * the Un-Dead sleep at home"--as he spoke he made a comprehensive sweep of
 * his arm to designate what to a vampire was "home"--"their face show what
 * they are, but this so sweet that was when she not Un-Dead she go back to
 * the nothings of the common dead. There is no malign there, see, and so
 * it make hard that I must kill her in her sleep." This turned my blood
 * cold, and it began to dawn upon me that I was accepting Van Helsing's
 * theories; but if she were really dead, what was there of terror in the
 * idea of killing her? He looked up at me, and evidently saw the change in
 * my face, for he said almost joyously:--
 *
 * "Ah, you believe now?"
 *
 * I answered: "Do not press me too hard all at once. I am willing to
 * accept. How will you do this bloody work?"
 *
 * "I shall cut off her head and fill her mouth with garlic, and I shall
 * drive a stake through her body." It made me shudder to think of so
 * mutilating the body of the woman whom I had loved. And yet the feeling
 * was not so strong as I had expected. I was, in fact, beginning to
 * shudder at the presence of this being, this Un-Dead, as Van Helsing
 * called it, and to loathe it. Is it possible that love is all subjective,
 * or all objective?
 *
 * I waited a considerable time for Van Helsing to begin, but he stood as
 * if wrapped in thought. Presently he closed the catch of his bag with a
 * snap, and said:--
 *
 * "I have been thinking, and have made up my mind as to what is best. If I
 * did simply follow my inclining I would do now, at this moment, what is
 * to be done; but there are other things to follow, and things that are
 * thousand times more difficult in that them we do not know. This is
 * simple. She have yet no life taken, though that is of time; and to act
 * now would be to take danger from her for ever. But then we may have to
 * want Arthur, and how shall we tell him of this? If you, who saw the
 * wounds on Lucy's throat, and saw the wounds so similar on the child's at
 * the hospital; if you, who saw the coffin empty last night and full
 * to-day with a woman who have not change only to be more rose and more
 * beautiful in a whole week, after she die--if you know of this and know
 * of the white figure last night that brought the child to the churchyard,
 * and yet of your own senses you did not believe, how, then, can I expect
 * Arthur, who know none of those things, to believe? He doubted me when I
 * took him from her kiss when she was dying. I know he has forgiven me
 * because in some mistaken idea I have done things that prevent him say
 * good-bye as he ought; and he may think that in some more mistaken idea
 * this woman was buried alive; and that in most mistake of all we have
 * killed her. He will then argue back that it is we, mistaken ones, that
 * have killed her by our ideas; and so he will be much unhappy always. Yet
 * he never can be sure; and that is the worst of all. And he will
 * sometimes think that she he loved was buried alive, and that will paint
 * his dreams with horrors of what she must have suffered; and again, he
 * will think that we may be right, and that his so beloved was, after all,
 * an Un-Dead. No! I told him once, and since then I learn much. Now, since
 * I know it is all true, a hundred thousand times more do I know that he
 * must pass through the bitter waters to reach the sweet. He, poor fellow,
 * must have one hour that will make the very face of heaven grow black to
 * him; then we can act for good all round and send him peace. My mind is
 * made up. Let us go. You return home for to-night to your asylum, and see
 * that all be well. As for me, I shall spend the night here in this
 * churchyard in my own way. To-morrow night you will come to me to the
 * Berkeley Hotel at ten of the clock. I shall send for Arthur to come too,
 * and also that so fine young man of America that gave his blood. Later we
 * shall all have work to do. I come with you so far as Piccadilly and
 * there dine, for I must be back here before the sun set."
 *
 * So we locked the tomb and came away, and got over the wall of the
 * churchyard, which was not much of a task, and drove back to Piccadilly.
 *
 *
 * _Note left by Van Helsing in his portmanteau, Berkeley Hotel directed to
 * John Seward, M. D._
 *
 * (Not delivered.)
 *
 * "_27 September._
 *
 * "Friend John,--
 *
 * "I write this in case anything should happen. I go alone to watch in
 * that churchyard. It pleases me that the Un-Dead, Miss Lucy, shall not
 * leave to-night, that so on the morrow night she may be more eager.
 * Therefore I shall fix some things she like not--garlic and a
 * crucifix--and so seal up the door of the tomb. She is young as Un-Dead,
 * and will heed. Moreover, these are only to prevent her coming out; they
 * may not prevail on her wanting to get in; for then the Un-Dead is
 * desperate, and must find the line of least resistance, whatsoever it may
 * be. I shall be at hand all the night from sunset till after the sunrise,
 * and if there be aught that may be learned I shall learn it. For Miss
 * Lucy or from her, I have no fear; but that other to whom is there that
 * she is Un-Dead, he have now the power to seek her tomb and find shelter.
 * He is cunning, as I know from Mr. Jonathan and from the way that all
 * along he have fooled us when he played with us for Miss Lucy's life, and
 * we lost; and in many ways the Un-Dead are strong. He have always the
 * strength in his hand of twenty men; even we four who gave our strength
 * to Miss Lucy it also is all to him. Besides, he can summon his wolf and
 * I know not what. So if it be that he come thither on this night he shall
 * find me; but none other shall--until it be too late. But it may be that
 * he will not attempt the place. There is no reason why he should; his
 * hunting ground is more full of game than the churchyard where the
 * Un-Dead woman sleep, and the one old man watch.
 *
 * "Therefore I write this in case.... Take the papers that are with this,
 * the diaries of Harker and the rest, and read them, and then find this
 * great Un-Dead, and cut off his head and burn his heart or drive a stake
 * through it, so that the world may rest from him.
 *
 * "If it be so, farewell.
 *
 * "VAN HELSING."
 *
 *
 *
 * _Dr. Seward's Diary._
 *
 * _28 September._--It is wonderful what a good night's sleep will do for
 * one. Yesterday I was almost willing to accept Van Helsing's monstrous
 * ideas; but now they seem to start out lurid before me as outrages on
 * common sense. I have no doubt that he believes it all. I wonder if his
 * mind can have become in any way unhinged. Surely there must be _some_
 * rational explanation of all these mysterious things. Is it possible that
 * the Professor can have done it himself? He is so abnormally clever that
 * if he went off his head he would carry out his intent with regard to
 * some fixed idea in a wonderful way. I am loath to think it, and indeed
 * it would be almost as great a marvel as the other to find that Van
 * Helsing was mad; but anyhow I shall watch him carefully. I may get some
 * light on the mystery.
 *
 *        *       *       *       *       *
 *
 * _29 September, morning._.... Last night, at a little before ten o'clock,
 * Arthur and Quincey came into Van Helsing's room; he told us all that he
 * wanted us to do, but especially addressing himself to Arthur, as if all
 * our wills were centred in his. He began by saying that he hoped we would
 * all come with him too, "for," he said, "there is a grave duty to be done
 * there. You were doubtless surprised at my letter?" This query was
 * directly addressed to Lord Godalming.
 *
 * "I was. It rather upset me for a bit. There has been so much trouble
 * around my house of late that I could do without any more. I have been
 * curious, too, as to what you mean. Quincey and I talked it over; but the
 * more we talked, the more puzzled we got, till now I can say for myself
 * that I'm about up a tree as to any meaning about anything."
 *
 * "Me too," said Quincey Morris laconically.
 *
 * "Oh," said the Professor, "then you are nearer the beginning, both of
 * you, than friend John here, who has to go a long way back before he can
 * even get so far as to begin."
 *
 * It was evident that he recognised my return to my old doubting frame of
 * mind without my saying a word. Then, turning to the other two, he said
 * with intense gravity:--
 *
 * "I want your permission to do what I think good this night. It is, I
 * know, much to ask; and when you know what it is I propose to do you will
 * know, and only then, how much. Therefore may I ask that you promise me
 * in the dark, so that afterwards, though you may be angry with me for a
 * time--I must not disguise from myself the possibility that such may
 * be--you shall not blame yourselves for anything."
 *
 * "That's frank anyhow," broke in Quincey. "I'll answer for the Professor.
 * I don't quite see his drift, but I swear he's honest; and that's good
 * enough for me."
 *
 * "I thank you, sir," said Van Helsing proudly. "I have done myself the
 * honour of counting you one trusting friend, and such endorsement is dear
 * to me." He held out a hand, which Quincey took.
 *
 * Then Arthur spoke out:--
 *
 * "Dr. Van Helsing, I don't quite like to 'buy a pig in a poke,' as they
 * say in Scotland, and if it be anything in which my honour as a gentleman
 * or my faith as a Christian is concerned, I cannot make such a promise.
 * If you can assure me that what you intend does not violate either of
 * these two, then I give my consent at once; though for the life of me, I
 * cannot understand what you are driving at."
 *
 * "I accept your limitation," said Van Helsing, "and all I ask of you is
 * that if you feel it necessary to condemn any act of mine, you will first
 * consider it well and be satisfied that it does not violate your
 * reservations."
 *
 * "Agreed!" said Arthur; "that is only fair. And now that the
 * _pourparlers_ are over, may I ask what it is we are to do?"
 *
 * "I want you to come with me, and to come in secret, to the churchyard at
 * Kingstead."
 *
 * Arthur's face fell as he said in an amazed sort of way:--
 *
 * "Where poor Lucy is buried?" The Professor bowed. Arthur went on: "And
 * when there?"
 *
 * "To enter the tomb!" Arthur stood up.
 *
 * "Professor, are you in earnest; or it is some monstrous joke? Pardon me,
 * I see that you are in earnest." He sat down again, but I could see that
 * he sat firmly and proudly, as one who is on his dignity. There was
 * silence until he asked again:--
 *
 * "And when in the tomb?"
 *
 * "To open the coffin."
 *
 * "This is too much!" he said, angrily rising again. "I am willing to be
 * patient in all things that are reasonable; but in this--this desecration
 * of the grave--of one who----" He fairly choked with indignation. The
 * Professor looked pityingly at him.
 *
 * "If I could spare you one pang, my poor friend," he said, "God knows I
 * would. But this night our feet must tread in thorny paths; or later, and
 * for ever, the feet you love must walk in paths of flame!"
 *
 * Arthur looked up with set white face and said:--
 *
 * "Take care, sir, take care!"
 *
 * "Would it not be well to hear what I have to say?" said Van Helsing.
 * "And then you will at least know the limit of my purpose. Shall I go
 * on?"
 *
 * "That's fair enough," broke in Morris.
 *
 * After a pause Van Helsing went on, evidently with an effort:--
 *
 * "Miss Lucy is dead; is it not so? Yes! Then there can be no wrong to
 * her. But if she be not dead----"
 *
 * Arthur jumped to his feet.
 *
 * "Good God!" he cried. "What do you mean? Has there been any mistake; has
 * she been buried alive?" He groaned in anguish that not even hope could
 * soften.
 *
 * "I did not say she was alive, my child; I did not think it. I go no
 * further than to say that she might be Un-Dead."
 *
 * "Un-Dead! Not alive! What do you mean? Is this all a nightmare, or what
 * is it?"
 *
 * "There are mysteries which men can only guess at, which age by age they
 * may solve only in part. Believe me, we are now on the verge of one. But
 * I have not done. May I cut off the head of dead Miss Lucy?"
 *
 * "Heavens and earth, no!" cried Arthur in a storm of passion. "Not for
 * the wide world will I consent to any mutilation of her dead body. Dr.
 * Van Helsing, you try me too far. What have I done to you that you should
 * torture me so? What did that poor, sweet girl do that you should want to
 * cast such dishonour on her grave? Are you mad that speak such things, or
 * am I mad to listen to them? Don't dare to think more of such a
 * desecration; I shall not give my consent to anything you do. I have a
 * duty to do in protecting her grave from outrage; and, by God, I shall do
 * it!"
 *
 * Van Helsing rose up from where he had all the time been seated, and
 * said, gravely and sternly:--
 *
 * "My Lord Godalming, I, too, have a duty to do, a duty to others, a duty
 * to you, a duty to the dead; and, by God, I shall do it! All I ask you
 * now is that you come with me, that you look and listen; and if when
 * later I make the same request you do not be more eager for its
 * fulfilment even than I am, then--then I shall do my duty, whatever it
 * may seem to me. And then, to follow of your Lordship's wishes I shall
 * hold myself at your disposal to render an account to you, when and where
 * you will." His voice broke a little, and he went on with a voice full of
 * pity:--
 *
 * "But, I beseech you, do not go forth in anger with me. In a long life of
 * acts which were often not pleasant to do, and which sometimes did wring
 * my heart, I have never had so heavy a task as now. Believe me that if
 * the time comes for you to change your mind towards me, one look from
 * you will wipe away all this so sad hour, for I would do what a man can
 * to save you from sorrow. Just think. For why should I give myself so
 * much of labour and so much of sorrow? I have come here from my own land
 * to do what I can of good; at the first to please my friend John, and
 * then to help a sweet young lady, whom, too, I came to love. For her--I
 * am ashamed to say so much, but I say it in kindness--I gave what you
 * gave; the blood of my veins; I gave it, I, who was not, like you, her
 * lover, but only her physician and her friend. I gave to her my nights
 * and days--before death, after death; and if my death can do her good
 * even now, when she is the dead Un-Dead, she shall have it freely." He
 * said this with a very grave, sweet pride, and Arthur was much affected
 * by it. He took the old man's hand and said in a broken voice:--
 *
 * "Oh, it is hard to think of it, and I cannot understand; but at least I
 * shall go with you and wait."
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
 * \page chapter_XVI CHAPTER XVI: Dr. Seward's Diary
 * DR. SEWARD'S DIARY--_continued_
 *
 *
 * It was just a quarter before twelve o'clock when we got into the
 * churchyard over the low wall. The night was dark with occasional gleams
 * of moonlight between the rents of the heavy clouds that scudded across
 * the sky. We all kept somehow close together, with Van Helsing slightly
 * in front as he led the way. When we had come close to the tomb I looked
 * well at Arthur, for I feared that the proximity to a place laden with so
 * sorrowful a memory would upset him; but he bore himself well. I took it
 * that the very mystery of the proceeding was in some way a counteractant
 * to his grief. The Professor unlocked the door, and seeing a natural
 * hesitation amongst us for various reasons, solved the difficulty by
 * entering first himself. The rest of us followed, and he closed the door.
 * He then lit a dark lantern and pointed to the coffin. Arthur stepped
 * forward hesitatingly; Van Helsing said to me:--
 *
 * "You were with me here yesterday. Was the body of Miss Lucy in that
 * coffin?"
 *
 * "It was." The Professor turned to the rest saying:--
 *
 * "You hear; and yet there is no one who does not believe with me." He
 * took his screwdriver and again took off the lid of the coffin. Arthur
 * looked on, very pale but silent; when the lid was removed he stepped
 * forward. He evidently did not know that there was a leaden coffin, or,
 * at any rate, had not thought of it. When he saw the rent in the lead,
 * the blood rushed to his face for an instant, but as quickly fell away
 * again, so that he remained of a ghastly whiteness; he was still silent.
 * Van Helsing forced back the leaden flange, and we all looked in and
 * recoiled.
 *
 * The coffin was empty!
 *
 * For several minutes no one spoke a word. The silence was broken by
 * Quincey Morris:--
 *
 * "Professor, I answered for you. Your word is all I want. I wouldn't ask
 * such a thing ordinarily--I wouldn't so dishonour you as to imply a
 * doubt; but this is a mystery that goes beyond any honour or dishonour.
 * Is this your doing?"
 *
 * "I swear to you by all that I hold sacred that I have not removed nor
 * touched her. What happened was this: Two nights ago my friend Seward and
 * I came here--with good purpose, believe me. I opened that coffin, which
 * was then sealed up, and we found it, as now, empty. We then waited, and
 * saw something white come through the trees. The next day we came here in
 * day-time, and she lay there. Did she not, friend John?"
 *
 * "Yes."
 *
 * "That night we were just in time. One more so small child was missing,
 * and we find it, thank God, unharmed amongst the graves. Yesterday I came
 * here before sundown, for at sundown the Un-Dead can move. I waited here
 * all the night till the sun rose, but I saw nothing. It was most probable
 * that it was because I had laid over the clamps of those doors garlic,
 * which the Un-Dead cannot bear, and other things which they shun. Last
 * night there was no exodus, so to-night before the sundown I took away my
 * garlic and other things. And so it is we find this coffin empty. But
 * bear with me. So far there is much that is strange. Wait you with me
 * outside, unseen and unheard, and things much stranger are yet to be.
 * So"--here he shut the dark slide of his lantern--"now to the outside."
 * He opened the door, and we filed out, he coming last and locking the
 * door behind him.
 *
 * Oh! but it seemed fresh and pure in the night air after the terror of
 * that vault. How sweet it was to see the clouds race by, and the passing
 * gleams of the moonlight between the scudding clouds crossing and
 * passing--like the gladness and sorrow of a man's life; how sweet it was
 * to breathe the fresh air, that had no taint of death and decay; how
 * humanising to see the red lighting of the sky beyond the hill, and to
 * hear far away the muffled roar that marks the life of a great city. Each
 * in his own way was solemn and overcome. Arthur was silent, and was, I
 * could see, striving to grasp the purpose and the inner meaning of the
 * mystery. I was myself tolerably patient, and half inclined again to
 * throw aside doubt and to accept Van Helsing's conclusions. Quincey
 * Morris was phlegmatic in the way of a man who accepts all things, and
 * accepts them in the spirit of cool bravery, with hazard of all he has to
 * stake. Not being able to smoke, he cut himself a good-sized plug of
 * tobacco and began to chew. As to Van Helsing, he was employed in a
 * definite way. First he took from his bag a mass of what looked like
 * thin, wafer-like biscuit, which was carefully rolled up in a white
 * napkin; next he took out a double-handful of some whitish stuff, like
 * dough or putty. He crumbled the wafer up fine and worked it into the
 * mass between his hands. This he then took, and rolling it into thin
 * strips, began to lay them into the crevices between the door and its
 * setting in the tomb. I was somewhat puzzled at this, and being close,
 * asked him what it was that he was doing. Arthur and Quincey drew near
 * also, as they too were curious. He answered:--
 *
 * "I am closing the tomb, so that the Un-Dead may not enter."
 *
 * "And is that stuff you have put there going to do it?" asked Quincey.
 * "Great Scott! Is this a game?"
 *
 * "It is."
 *
 * "What is that which you are using?" This time the question was by
 * Arthur. Van Helsing reverently lifted his hat as he answered:--
 *
 * "The Host. I brought it from Amsterdam. I have an Indulgence." It was an
 * answer that appalled the most sceptical of us, and we felt individually
 * that in the presence of such earnest purpose as the Professor's, a
 * purpose which could thus use the to him most sacred of things, it was
 * impossible to distrust. In respectful silence we took the places
 * assigned to us close round the tomb, but hidden from the sight of any
 * one approaching. I pitied the others, especially Arthur. I had myself
 * been apprenticed by my former visits to this watching horror; and yet I,
 * who had up to an hour ago repudiated the proofs, felt my heart sink
 * within me. Never did tombs look so ghastly white; never did cypress, or
 * yew, or juniper so seem the embodiment of funereal gloom; never did tree
 * or grass wave or rustle so ominously; never did bough creak so
 * mysteriously; and never did the far-away howling of dogs send such a
 * woeful presage through the night.
 *
 * There was a long spell of silence, a big, aching void, and then from the
 * Professor a keen "S-s-s-s!" He pointed; and far down the avenue of yews
 * we saw a white figure advance--a dim white figure, which held something
 * dark at its breast. The figure stopped, and at the moment a ray of
 * moonlight fell upon the masses of driving clouds and showed in startling
 * prominence a dark-haired woman, dressed in the cerements of the grave.
 * We could not see the face, for it was bent down over what we saw to be a
 * fair-haired child. There was a pause and a sharp little cry, such as a
 * child gives in sleep, or a dog as it lies before the fire and dreams. We
 * were starting forward, but the Professor's warning hand, seen by us as
 * he stood behind a yew-tree, kept us back; and then as we looked the
 * white figure moved forwards again. It was now near enough for us to see
 * clearly, and the moonlight still held. My own heart grew cold as ice,
 * and I could hear the gasp of Arthur, as we recognised the features of
 * Lucy Westenra. Lucy Westenra, but yet how changed. The sweetness was
 * turned to adamantine, heartless cruelty, and the purity to voluptuous
 * wantonness. Van Helsing stepped out, and, obedient to his gesture, we
 * all advanced too; the four of us ranged in a line before the door of the
 * tomb. Van Helsing raised his lantern and drew the slide; by the
 * concentrated light that fell on Lucy's face we could see that the lips
 * were crimson with fresh blood, and that the stream had trickled over her
 * chin and stained the purity of her lawn death-robe.
 *
 * We shuddered with horror. I could see by the tremulous light that even
 * Van Helsing's iron nerve had failed. Arthur was next to me, and if I had
 * not seized his arm and held him up, he would have fallen.
 *
 * When Lucy--I call the thing that was before us Lucy because it bore her
 * shape--saw us she drew back with an angry snarl, such as a cat gives
 * when taken unawares; then her eyes ranged over us. Lucy's eyes in form
 * and colour; but Lucy's eyes unclean and full of hell-fire, instead of
 * the pure, gentle orbs we knew. At that moment the remnant of my love
 * passed into hate and loathing; had she then to be killed, I could have
 * done it with savage delight. As she looked, her eyes blazed with unholy
 * light, and the face became wreathed with a voluptuous smile. Oh, God,
 * how it made me shudder to see it! With a careless motion, she flung to
 * the ground, callous as a devil, the child that up to now she had
 * clutched strenuously to her breast, growling over it as a dog growls
 * over a bone. The child gave a sharp cry, and lay there moaning. There
 * was a cold-bloodedness in the act which wrung a groan from Arthur; when
 * she advanced to him with outstretched arms and a wanton smile he fell
 * back and hid his face in his hands.
 *
 * She still advanced, however, and with a languorous, voluptuous grace,
 * said:--
 *
 * "Come to me, Arthur. Leave these others and come to me. My arms are
 * hungry for you. Come, and we can rest together. Come, my husband, come!"
 *
 * There was something diabolically sweet in her tones--something of the
 * tingling of glass when struck--which rang through the brains even of us
 * who heard the words addressed to another. As for Arthur, he seemed under
 * a spell; moving his hands from his face, he opened wide his arms. She
 * was leaping for them, when Van Helsing sprang forward and held between
 * them his little golden crucifix. She recoiled from it, and, with a
 * suddenly distorted face, full of rage, dashed past him as if to enter
 * the tomb.
 *
 * When within a foot or two of the door, however, she stopped, as if
 * arrested by some irresistible force. Then she turned, and her face was
 * shown in the clear burst of moonlight and by the lamp, which had now no
 * quiver from Van Helsing's iron nerves. Never did I see such baffled
 * malice on a face; and never, I trust, shall such ever be seen again by
 * mortal eyes. The beautiful colour became livid, the eyes seemed to throw
 * out sparks of hell-fire, the brows were wrinkled as though the folds of
 * the flesh were the coils of Medusa's snakes, and the lovely,
 * blood-stained mouth grew to an open square, as in the passion masks of
 * the Greeks and Japanese. If ever a face meant death--if looks could
 * kill--we saw it at that moment.
 *
 * And so for full half a minute, which seemed an eternity, she remained
 * between the lifted crucifix and the sacred closing of her means of
 * entry. Van Helsing broke the silence by asking Arthur:--
 *
 * "Answer me, oh my friend! Am I to proceed in my work?"
 *
 * Arthur threw himself on his knees, and hid his face in his hands, as he
 * answered:--
 *
 * "Do as you will, friend; do as you will. There can be no horror like
 * this ever any more;" and he groaned in spirit. Quincey and I
 * simultaneously moved towards him, and took his arms. We could hear the
 * click of the closing lantern as Van Helsing held it down; coming close
 * to the tomb, he began to remove from the chinks some of the sacred
 * emblem which he had placed there. We all looked on in horrified
 * amazement as we saw, when he stood back, the woman, with a corporeal
 * body as real at that moment as our own, pass in through the interstice
 * where scarce a knife-blade could have gone. We all felt a glad sense of
 * relief when we saw the Professor calmly restoring the strings of putty
 * to the edges of the door.
 *
 * When this was done, he lifted the child and said:
 *
 * "Come now, my friends; we can do no more till to-morrow. There is a
 * funeral at noon, so here we shall all come before long after that. The
 * friends of the dead will all be gone by two, and when the sexton lock
 * the gate we shall remain. Then there is more to do; but not like this of
 * to-night. As for this little one, he is not much harm, and by to-morrow
 * night he shall be well. We shall leave him where the police will find
 * him, as on the other night; and then to home." Coming close to Arthur,
 * he said:--
 *
 * "My friend Arthur, you have had a sore trial; but after, when you look
 * back, you will see how it was necessary. You are now in the bitter
 * waters, my child. By this time to-morrow you will, please God, have
 * passed them, and have drunk of the sweet waters; so do not mourn
 * overmuch. Till then I shall not ask you to forgive me."
 *
 * Arthur and Quincey came home with me, and we tried to cheer each other
 * on the way. We had left the child in safety, and were tired; so we all
 * slept with more or less reality of sleep.
 *
 *        *       *       *       *       *
 *
 * _29 September, night._--A little before twelve o'clock we three--Arthur,
 * Quincey Morris, and myself--called for the Professor. It was odd to
 * notice that by common consent we had all put on black clothes. Of
 * course, Arthur wore black, for he was in deep mourning, but the rest of
 * us wore it by instinct. We got to the churchyard by half-past one, and
 * strolled about, keeping out of official observation, so that when the
 * gravediggers had completed their task and the sexton under the belief
 * that every one had gone, had locked the gate, we had the place all to
 * ourselves. Van Helsing, instead of his little black bag, had with him a
 * long leather one, something like a cricketing bag; it was manifestly of
 * fair weight.
 *
 * When we were alone and had heard the last of the footsteps die out up
 * the road, we silently, and as if by ordered intention, followed the
 * Professor to the tomb. He unlocked the door, and we entered, closing it
 * behind us. Then he took from his bag the lantern, which he lit, and also
 * two wax candles, which, when lighted, he stuck, by melting their own
 * ends, on other coffins, so that they might give light sufficient to work
 * by. When he again lifted the lid off Lucy's coffin we all looked--Arthur
 * trembling like an aspen--and saw that the body lay there in all its
 * death-beauty. But there was no love in my own heart, nothing but
 * loathing for the foul Thing which had taken Lucy's shape without her
 * soul. I could see even Arthur's face grow hard as he looked. Presently
 * he said to Van Helsing:--
 *
 * "Is this really Lucy's body, or only a demon in her shape?"
 *
 * "It is her body, and yet not it. But wait a while, and you all see her
 * as she was, and is."
 *
 * She seemed like a nightmare of Lucy as she lay there; the pointed teeth,
 * the bloodstained, voluptuous mouth--which it made one shudder to
 * see--the whole carnal and unspiritual appearance, seeming like a
 * devilish mockery of Lucy's sweet purity. Van Helsing, with his usual
 * methodicalness, began taking the various contents from his bag and
 * placing them ready for use. First he took out a soldering iron and some
 * plumbing solder, and then a small oil-lamp, which gave out, when lit in
 * a corner of the tomb, gas which burned at fierce heat with a blue
 * flame; then his operating knives, which he placed to hand; and last a
 * round wooden stake, some two and a half or three inches thick and about
 * three feet long. One end of it was hardened by charring in the fire, and
 * was sharpened to a fine point. With this stake came a heavy hammer, such
 * as in households is used in the coal-cellar for breaking the lumps. To
 * me, a doctor's preparations for work of any kind are stimulating and
 * bracing, but the effect of these things on both Arthur and Quincey was
 * to cause them a sort of consternation. They both, however, kept their
 * courage, and remained silent and quiet.
 *
 * When all was ready, Van Helsing said:--
 *
 * "Before we do anything, let me tell you this; it is out of the lore and
 * experience of the ancients and of all those who have studied the powers
 * of the Un-Dead. When they become such, there comes with the change the
 * curse of immortality; they cannot die, but must go on age after age
 * adding new victims and multiplying the evils of the world; for all that
 * die from the preying of the Un-Dead becomes themselves Un-Dead, and prey
 * on their kind. And so the circle goes on ever widening, like as the
 * ripples from a stone thrown in the water. Friend Arthur, if you had met
 * that kiss which you know of before poor Lucy die; or again, last night
 * when you open your arms to her, you would in time, when you had died,
 * have become _nosferatu_, as they call it in Eastern Europe, and would
 * all time make more of those Un-Deads that so have fill us with horror.
 * The career of this so unhappy dear lady is but just begun. Those
 * children whose blood she suck are not as yet so much the worse; but if
 * she live on, Un-Dead, more and more they lose their blood and by her
 * power over them they come to her; and so she draw their blood with that
 * so wicked mouth. But if she die in truth, then all cease; the tiny
 * wounds of the throats disappear, and they go back to their plays
 * unknowing ever of what has been. But of the most blessed of all, when
 * this now Un-Dead be made to rest as true dead, then the soul of the poor
 * lady whom we love shall again be free. Instead of working wickedness by
 * night and growing more debased in the assimilating of it by day, she
 * shall take her place with the other Angels. So that, my friend, it will
 * be a blessed hand for her that shall strike the blow that sets her free.
 * To this I am willing; but is there none amongst us who has a better
 * right? Will it be no joy to think of hereafter in the silence of the
 * night when sleep is not: 'It was my hand that sent her to the stars; it
 * was the hand of him that loved her best; the hand that of all she would
 * herself have chosen, had it been to her to choose?' Tell me if there be
 * such a one amongst us?"
 *
 * We all looked at Arthur. He saw, too, what we all did, the infinite
 * kindness which suggested that his should be the hand which would restore
 * Lucy to us as a holy, and not an unholy, memory; he stepped forward and
 * said bravely, though his hand trembled, and his face was as pale as
 * snow:--
 *
 * "My true friend, from the bottom of my broken heart I thank you. Tell me
 * what I am to do, and I shall not falter!" Van Helsing laid a hand on his
 * shoulder, and said:--
 *
 * "Brave lad! A moment's courage, and it is done. This stake must be
 * driven through her. It will be a fearful ordeal--be not deceived in
 * that--but it will be only a short time, and you will then rejoice more
 * than your pain was great; from this grim tomb you will emerge as though
 * you tread on air. But you must not falter when once you have begun. Only
 * think that we, your true friends, are round you, and that we pray for
 * you all the time."
 *
 * "Go on," said Arthur hoarsely. "Tell me what I am to do."
 *
 * "Take this stake in your left hand, ready to place the point over the
 * heart, and the hammer in your right. Then when we begin our prayer for
 * the dead--I shall read him, I have here the book, and the others shall
 * follow--strike in God's name, that so all may be well with the dead that
 * we love and that the Un-Dead pass away."
 *
 * Arthur took the stake and the hammer, and when once his mind was set on
 * action his hands never trembled nor even quivered. Van Helsing opened
 * his missal and began to read, and Quincey and I followed as well as we
 * could. Arthur placed the point over the heart, and as I looked I could
 * see its dint in the white flesh. Then he struck with all his might.
 *
 * The Thing in the coffin writhed; and a hideous, blood-curdling screech
 * came from the opened red lips. The body shook and quivered and twisted
 * in wild contortions; the sharp white teeth champed together till the
 * lips were cut, and the mouth was smeared with a crimson foam. But Arthur
 * never faltered. He looked like a figure of Thor as his untrembling arm
 * rose and fell, driving deeper and deeper the mercy-bearing stake, whilst
 * the blood from the pierced heart welled and spurted up around it. His
 * face was set, and high duty seemed to shine through it; the sight of it
 * gave us courage so that our voices seemed to ring through the little
 * vault.
 *
 * And then the writhing and quivering of the body became less, and the
 * teeth seemed to champ, and the face to quiver. Finally it lay still. The
 * terrible task was over.
 *
 * The hammer fell from Arthur's hand. He reeled and would have fallen had
 * we not caught him. The great drops of sweat sprang from his forehead,
 * and his breath came in broken gasps. It had indeed been an awful strain
 * on him; and had he not been forced to his task by more than human
 * considerations he could never have gone through with it. For a few
 * minutes we were so taken up with him that we did not look towards the
 * coffin. When we did, however, a murmur of startled surprise ran from one
 * to the other of us. We gazed so eagerly that Arthur rose, for he had
 * been seated on the ground, and came and looked too; and then a glad,
 * strange light broke over his face and dispelled altogether the gloom of
 * horror that lay upon it.
 *
 * There, in the coffin lay no longer the foul Thing that we had so dreaded
 * and grown to hate that the work of her destruction was yielded as a
 * privilege to the one best entitled to it, but Lucy as we had seen her in
 * her life, with her face of unequalled sweetness and purity. True that
 * there were there, as we had seen them in life, the traces of care and
 * pain and waste; but these were all dear to us, for they marked her truth
 * to what we knew. One and all we felt that the holy calm that lay like
 * sunshine over the wasted face and form was only an earthly token and
 * symbol of the calm that was to reign for ever.
 *
 * Van Helsing came and laid his hand on Arthur's shoulder, and said to
 * him:--
 *
 * "And now, Arthur my friend, dear lad, am I not forgiven?"
 *
 * The reaction of the terrible strain came as he took the old man's hand
 * in his, and raising it to his lips, pressed it, and said:--
 *
 * "Forgiven! God bless you that you have given my dear one her soul again,
 * and me peace." He put his hands on the Professor's shoulder, and laying
 * his head on his breast, cried for a while silently, whilst we stood
 * unmoving. When he raised his head Van Helsing said to him:--
 *
 * "And now, my child, you may kiss her. Kiss her dead lips if you will, as
 * she would have you to, if for her to choose. For she is not a grinning
 * devil now--not any more a foul Thing for all eternity. No longer she is
 * the devil's Un-Dead. She is God's true dead, whose soul is with Him!"
 *
 * Arthur bent and kissed her, and then we sent him and Quincey out of the
 * tomb; the Professor and I sawed the top off the stake, leaving the point
 * of it in the body. Then we cut off the head and filled the mouth with
 * garlic. We soldered up the leaden coffin, screwed on the coffin-lid,
 * and gathering up our belongings, came away. When the Professor locked
 * the door he gave the key to Arthur.
 *
 * Outside the air was sweet, the sun shone, and the birds sang, and it
 * seemed as if all nature were tuned to a different pitch. There was
 * gladness and mirth and peace everywhere, for we were at rest ourselves
 * on one account, and we were glad, though it was with a tempered joy.
 *
 * Before we moved away Van Helsing said:--
 *
 * "Now, my friends, one step of our work is done, one the most harrowing
 * to ourselves. But there remains a greater task: to find out the author
 * of all this our sorrow and to stamp him out. I have clues which we can
 * follow; but it is a long task, and a difficult, and there is danger in
 * it, and pain. Shall you not all help me? We have learned to believe, all
 * of us--is it not so? And since so, do we not see our duty? Yes! And do
 * we not promise to go on to the bitter end?"
 *
 * Each in turn, we took his hand, and the promise was made. Then said the
 * Professor as we moved off:--
 *
 * "Two nights hence you shall meet with me and dine together at seven of
 * the clock with friend John. I shall entreat two others, two that you
 * know not as yet; and I shall be ready to all our work show and our plans
 * unfold. Friend John, you come with me home, for I have much to consult
 * about, and you can help me. To-night I leave for Amsterdam, but shall
 * return to-morrow night. And then begins our great quest. But first I
 * shall have much to say, so that you may know what is to do and to dread.
 * Then our promise shall be made to each other anew; for there is a
 * terrible task before us, and once our feet are on the ploughshare we
 * must not draw back."
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
 * \page chapter_XVII CHAPTER XVII: Dr. Seward's Diary
 * DR. SEWARD'S DIARY--_continued_
 *
 *
 * When we arrived at the Berkeley Hotel, Van Helsing found a telegram
 * waiting for him:--
 *
 *      "Am coming up by train. Jonathan at Whitby. Important news.--MINA
 *      HARKER."
 *
 * The Professor was delighted. "Ah, that wonderful Madam Mina," he said,
 * "pearl among women! She arrive, but I cannot stay. She must go to your
 * house, friend John. You must meet her at the station. Telegraph her _en
 * route_, so that she may be prepared."
 *
 * When the wire was despatched he had a cup of tea; over it he told me of
 * a diary kept by Jonathan Harker when abroad, and gave me a typewritten
 * copy of it, as also of Mrs. Harker's diary at Whitby. "Take these," he
 * said, "and study them well. When I have returned you will be master of
 * all the facts, and we can then better enter on our inquisition. Keep
 * them safe, for there is in them much of treasure. You will need all your
 * faith, even you who have had such an experience as that of to-day. What
 * is here told," he laid his hand heavily and gravely on the packet of
 * papers as he spoke, "may be the beginning of the end to you and me and
 * many another; or it may sound the knell of the Un-Dead who walk the
 * earth. Read all, I pray you, with the open mind; and if you can add in
 * any way to the story here told do so, for it is all-important. You have
 * kept diary of all these so strange things; is it not so? Yes! Then we
 * shall go through all these together when we meet." He then made ready
 * for his departure, and shortly after drove off to Liverpool Street. I
 * took my way to Paddington, where I arrived about fifteen minutes before
 * the train came in.
 *
 * The crowd melted away, after the bustling fashion common to arrival
 * platforms; and I was beginning to feel uneasy, lest I might miss my
 * guest, when a sweet-faced, dainty-looking girl stepped up to me, and,
 * after a quick glance, said: "Dr. Seward, is it not?"
 *
 * "And you are Mrs. Harker!" I answered at once; whereupon she held out
 * her hand.
 *
 * "I knew you from the description of poor dear Lucy; but----" She stopped
 * suddenly, and a quick blush overspread her face.
 *
 * The blush that rose to my own cheeks somehow set us both at ease, for it
 * was a tacit answer to her own. I got her luggage, which included a
 * typewriter, and we took the Underground to Fenchurch Street, after I had
 * sent a wire to my housekeeper to have a sitting-room and bedroom
 * prepared at once for Mrs. Harker.
 *
 * In due time we arrived. She knew, of course, that the place was a
 * lunatic asylum, but I could see that she was unable to repress a shudder
 * when we entered.
 *
 * She told me that, if she might, she would come presently to my study, as
 * she had much to say. So here I am finishing my entry in my phonograph
 * diary whilst I await her. As yet I have not had the chance of looking at
 * the papers which Van Helsing left with me, though they lie open before
 * me. I must get her interested in something, so that I may have an
 * opportunity of reading them. She does not know how precious time is, or
 * what a task we have in hand. I must be careful not to frighten her. Here
 * she is!
 *
 *
 * _Mina Harker's Journal._
 *
 * _29 September._--After I had tidied myself, I went down to Dr. Seward's
 * study. At the door I paused a moment, for I thought I heard him talking
 * with some one. As, however, he had pressed me to be quick, I knocked at
 * the door, and on his calling out, "Come in," I entered.
 *
 * To my intense surprise, there was no one with him. He was quite alone,
 * and on the table opposite him was what I knew at once from the
 * description to be a phonograph. I had never seen one, and was much
 * interested.
 *
 * "I hope I did not keep you waiting," I said; "but I stayed at the door
 * as I heard you talking, and thought there was some one with you."
 *
 * "Oh," he replied with a smile, "I was only entering my diary."
 *
 * "Your diary?" I asked him in surprise.
 *
 * "Yes," he answered. "I keep it in this." As he spoke he laid his hand on
 * the phonograph. I felt quite excited over it, and blurted out:--
 *
 * "Why, this beats even shorthand! May I hear it say something?"
 *
 * "Certainly," he replied with alacrity, and stood up to put it in train
 * for speaking. Then he paused, and a troubled look overspread his face.
 *
 * "The fact is," he began awkwardly, "I only keep my diary in it; and as
 * it is entirely--almost entirely--about my cases, it may be awkward--that
 * is, I mean----" He stopped, and I tried to help him out of his
 * embarrassment:--
 *
 * "You helped to attend dear Lucy at the end. Let me hear how she died;
 * for all that I know of her, I shall be very grateful. She was very, very
 * dear to me."
 *
 * To my surprise, he answered, with a horrorstruck look in his face:--
 *
 * "Tell you of her death? Not for the wide world!"
 *
 * "Why not?" I asked, for some grave, terrible feeling was coming over me.
 * Again he paused, and I could see that he was trying to invent an excuse.
 * At length he stammered out:--
 *
 * "You see, I do not know how to pick out any particular part of the
 * diary." Even while he was speaking an idea dawned upon him, and he said
 * with unconscious simplicity, in a different voice, and with the naïveté
 * of a child: "That's quite true, upon my honour. Honest Indian!" I could
 * not but smile, at which he grimaced. "I gave myself away that time!" he
 * said. "But do you know that, although I have kept the diary for months
 * past, it never once struck me how I was going to find any particular
 * part of it in case I wanted to look it up?" By this time my mind was
 * made up that the diary of a doctor who attended Lucy might have
 * something to add to the sum of our knowledge of that terrible Being, and
 * I said boldly:--
 *
 * "Then, Dr. Seward, you had better let me copy it out for you on my
 * typewriter." He grew to a positively deathly pallor as he said:--
 *
 * "No! no! no! For all the world, I wouldn't let you know that terrible
 * story!"
 *
 * Then it was terrible; my intuition was right! For a moment I thought,
 * and as my eyes ranged the room, unconsciously looking for something or
 * some opportunity to aid me, they lit on a great batch of typewriting on
 * the table. His eyes caught the look in mine, and, without his thinking,
 * followed their direction. As they saw the parcel he realised my meaning.
 *
 * "You do not know me," I said. "When you have read those papers--my own
 * diary and my husband's also, which I have typed--you will know me
 * better. I have not faltered in giving every thought of my own heart in
 * this cause; but, of course, you do not know me--yet; and I must not
 * expect you to trust me so far."
 *
 * He is certainly a man of noble nature; poor dear Lucy was right about
 * him. He stood up and opened a large drawer, in which were arranged in
 * order a number of hollow cylinders of metal covered with dark wax, and
 * said:--
 *
 * "You are quite right. I did not trust you because I did not know you.
 * But I know you now; and let me say that I should have known you long
 * ago. I know that Lucy told you of me; she told me of you too. May I make
 * the only atonement in my power? Take the cylinders and hear them--the
 * first half-dozen of them are personal to me, and they will not horrify
 * you; then you will know me better. Dinner will by then be ready. In the
 * meantime I shall read over some of these documents, and shall be better
 * able to understand certain things." He carried the phonograph himself up
 * to my sitting-room and adjusted it for me. Now I shall learn something
 * pleasant, I am sure; for it will tell me the other side of a true love
 * episode of which I know one side already....
 *
 *
 * _Dr. Seward's Diary._
 *
 * _29 September._--I was so absorbed in that wonderful diary of Jonathan
 * Harker and that other of his wife that I let the time run on without
 * thinking. Mrs. Harker was not down when the maid came to announce
 * dinner, so I said: "She is possibly tired; let dinner wait an hour," and
 * I went on with my work. I had just finished Mrs. Harker's diary, when
 * she came in. She looked sweetly pretty, but very sad, and her eyes were
 * flushed with crying. This somehow moved me much. Of late I have had
 * cause for tears, God knows! but the relief of them was denied me; and
 * now the sight of those sweet eyes, brightened with recent tears, went
 * straight to my heart. So I said as gently as I could:--
 *
 * "I greatly fear I have distressed you."
 *
 * "Oh, no, not distressed me," she replied, "but I have been more touched
 * than I can say by your grief. That is a wonderful machine, but it is
 * cruelly true. It told me, in its very tones, the anguish of your heart.
 * It was like a soul crying out to Almighty God. No one must hear them
 * spoken ever again! See, I have tried to be useful. I have copied out the
 * words on my typewriter, and none other need now hear your heart beat, as
 * I did."
 *
 * "No one need ever know, shall ever know," I said in a low voice. She
 * laid her hand on mine and said very gravely:--
 *
 * "Ah, but they must!"
 *
 * "Must! But why?" I asked.
 *
 * "Because it is a part of the terrible story, a part of poor dear Lucy's
 * death and all that led to it; because in the struggle which we have
 * before us to rid the earth of this terrible monster we must have all
 * the knowledge and all the help which we can get. I think that the
 * cylinders which you gave me contained more than you intended me to know;
 * but I can see that there are in your record many lights to this dark
 * mystery. You will let me help, will you not? I know all up to a certain
 * point; and I see already, though your diary only took me to 7 September,
 * how poor Lucy was beset, and how her terrible doom was being wrought
 * out. Jonathan and I have been working day and night since Professor Van
 * Helsing saw us. He is gone to Whitby to get more information, and he
 * will be here to-morrow to help us. We need have no secrets amongst us;
 * working together and with absolute trust, we can surely be stronger than
 * if some of us were in the dark." She looked at me so appealingly, and at
 * the same time manifested such courage and resolution in her bearing,
 * that I gave in at once to her wishes. "You shall," I said, "do as you
 * like in the matter. God forgive me if I do wrong! There are terrible
 * things yet to learn of; but if you have so far travelled on the road to
 * poor Lucy's death, you will not be content, I know, to remain in the
 * dark. Nay, the end--the very end--may give you a gleam of peace. Come,
 * there is dinner. We must keep one another strong for what is before us;
 * we have a cruel and dreadful task. When you have eaten you shall learn
 * the rest, and I shall answer any questions you ask--if there be anything
 * which you do not understand, though it was apparent to us who were
 * present."
 *
 *
 * _Mina Harker's Journal._
 *
 * _29 September._--After dinner I came with Dr. Seward to his study. He
 * brought back the phonograph from my room, and I took my typewriter. He
 * placed me in a comfortable chair, and arranged the phonograph so that I
 * could touch it without getting up, and showed me how to stop it in case
 * I should want to pause. Then he very thoughtfully took a chair, with his
 * back to me, so that I might be as free as possible, and began to read. I
 * put the forked metal to my ears and listened.
 *
 * When the terrible story of Lucy's death, and--and all that followed, was
 * done, I lay back in my chair powerless. Fortunately I am not of a
 * fainting disposition. When Dr. Seward saw me he jumped up with a
 * horrified exclamation, and hurriedly taking a case-bottle from a
 * cupboard, gave me some brandy, which in a few minutes somewhat restored
 * me. My brain was all in a whirl, and only that there came through all
 * the multitude of horrors, the holy ray of light that my dear, dear Lucy
 * was at last at peace, I do not think I could have borne it without
 * making a scene. It is all so wild, and mysterious, and strange that if I
 * had not known Jonathan's experience in Transylvania I could not have
 * believed. As it was, I didn't know what to believe, and so got out of my
 * difficulty by attending to something else. I took the cover off my
 * typewriter, and said to Dr. Seward:--
 *
 * "Let me write this all out now. We must be ready for Dr. Van Helsing
 * when he comes. I have sent a telegram to Jonathan to come on here when
 * he arrives in London from Whitby. In this matter dates are everything,
 * and I think that if we get all our material ready, and have every item
 * put in chronological order, we shall have done much. You tell me that
 * Lord Godalming and Mr. Morris are coming too. Let us be able to tell him
 * when they come." He accordingly set the phonograph at a slow pace, and I
 * began to typewrite from the beginning of the seventh cylinder. I used
 * manifold, and so took three copies of the diary, just as I had done with
 * all the rest. It was late when I got through, but Dr. Seward went about
 * his work of going his round of the patients; when he had finished he
 * came back and sat near me, reading, so that I did not feel too lonely
 * whilst I worked. How good and thoughtful he is; the world seems full of
 * good men--even if there _are_ monsters in it. Before I left him I
 * remembered what Jonathan put in his diary of the Professor's
 * perturbation at reading something in an evening paper at the station at
 * Exeter; so, seeing that Dr. Seward keeps his newspapers, I borrowed the
 * files of "The Westminster Gazette" and "The Pall Mall Gazette," and took
 * them to my room. I remember how much "The Dailygraph" and "The Whitby
 * Gazette," of which I had made cuttings, helped us to understand the
 * terrible events at Whitby when Count Dracula landed, so I shall look
 * through the evening papers since then, and perhaps I shall get some new
 * light. I am not sleepy, and the work will help to keep me quiet.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _30 September._--Mr. Harker arrived at nine o'clock. He had got his
 * wife's wire just before starting. He is uncommonly clever, if one can
 * judge from his face, and full of energy. If this journal be true--and
 * judging by one's own wonderful experiences, it must be--he is also a man
 * of great nerve. That going down to the vault a second time was a
 * remarkable piece of daring. After reading his account of it I was
 * prepared to meet a good specimen of manhood, but hardly the quiet,
 * business-like gentleman who came here to-day.
 *
 *        *       *       *       *       *
 *
 * _Later._--After lunch Harker and his wife went back to their own room,
 * and as I passed a while ago I heard the click of the typewriter. They
 * are hard at it. Mrs. Harker says that they are knitting together in
 * chronological order every scrap of evidence they have. Harker has got
 * the letters between the consignee of the boxes at Whitby and the
 * carriers in London who took charge of them. He is now reading his wife's
 * typescript of my diary. I wonder what they make out of it. Here it
 * is....
 *
 *      Strange that it never struck me that the very next house might be
 *      the Count's hiding-place! Goodness knows that we had enough clues
 *      from the conduct of the patient Renfield! The bundle of letters
 *      relating to the purchase of the house were with the typescript. Oh,
 *      if we had only had them earlier we might have saved poor Lucy!
 *      Stop; that way madness lies! Harker has gone back, and is again
 *      collating his material. He says that by dinner-time they will be
 *      able to show a whole connected narrative. He thinks that in the
 *      meantime I should see Renfield, as hitherto he has been a sort of
 *      index to the coming and going of the Count. I hardly see this yet,
 *      but when I get at the dates I suppose I shall. What a good thing
 *      that Mrs. Harker put my cylinders into type! We never could have
 *      found the dates otherwise....
 *
 *      I found Renfield sitting placidly in his room with his hands
 *      folded, smiling benignly. At the moment he seemed as sane as any
 *      one I ever saw. I sat down and talked with him on a lot of
 *      subjects, all of which he treated naturally. He then, of his own
 *      accord, spoke of going home, a subject he has never mentioned to my
 *      knowledge during his sojourn here. In fact, he spoke quite
 *      confidently of getting his discharge at once. I believe that, had I
 *      not had the chat with Harker and read the letters and the dates of
 *      his outbursts, I should have been prepared to sign for him after a
 *      brief time of observation. As it is, I am darkly suspicious. All
 *      those outbreaks were in some way linked with the proximity of the
 *      Count. What then does this absolute content mean? Can it be that
 *      his instinct is satisfied as to the vampire's ultimate triumph?
 *      Stay; he is himself zoöphagous, and in his wild ravings outside the
 *      chapel door of the deserted house he always spoke of "master." This
 *      all seems confirmation of our idea. However, after a while I came
 *      away; my friend is just a little too sane at present to make it
 *      safe to probe him too deep with questions. He might begin to think,
 *      and then--! So I came away. I mistrust these quiet moods of his; so
 *      I have given the attendant a hint to look closely after him, and to
 *      have a strait-waistcoat ready in case of need.
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _29 September, in train to London._--When I received Mr. Billington's
 * courteous message that he would give me any information in his power I
 * thought it best to go down to Whitby and make, on the spot, such
 * inquiries as I wanted. It was now my object to trace that horrid cargo
 * of the Count's to its place in London. Later, we may be able to deal
 * with it. Billington junior, a nice lad, met me at the station, and
 * brought me to his father's house, where they had decided that I must
 * stay the night. They are hospitable, with true Yorkshire hospitality:
 * give a guest everything, and leave him free to do as he likes. They all
 * knew that I was busy, and that my stay was short, and Mr. Billington had
 * ready in his office all the papers concerning the consignment of boxes.
 * It gave me almost a turn to see again one of the letters which I had
 * seen on the Count's table before I knew of his diabolical plans.
 * Everything had been carefully thought out, and done systematically and
 * with precision. He seemed to have been prepared for every obstacle which
 * might be placed by accident in the way of his intentions being carried
 * out. To use an Americanism, he had "taken no chances," and the absolute
 * accuracy with which his instructions were fulfilled, was simply the
 * logical result of his care. I saw the invoice, and took note of it:
 * "Fifty cases of common earth, to be used for experimental purposes."
 * Also the copy of letter to Carter Paterson, and their reply; of both of
 * these I got copies. This was all the information Mr. Billington could
 * give me, so I went down to the port and saw the coastguards, the Customs
 * officers and the harbour-master. They had all something to say of the
 * strange entry of the ship, which is already taking its place in local
 * tradition; but no one could add to the simple description "Fifty cases
 * of common earth." I then saw the station-master, who kindly put me in
 * communication with the men who had actually received the boxes. Their
 * tally was exact with the list, and they had nothing to add except that
 * the boxes were "main and mortal heavy," and that shifting them was dry
 * work. One of them added that it was hard lines that there wasn't any
 * gentleman "such-like as yourself, squire," to show some sort of
 * appreciation of their efforts in a liquid form; another put in a rider
 * that the thirst then generated was such that even the time which had
 * elapsed had not completely allayed it. Needless to add, I took care
 * before leaving to lift, for ever and adequately, this source of
 * reproach.
 *
 *        *       *       *       *       *
 *
 * _30 September._--The station-master was good enough to give me a line to
 * his old companion the station-master at King's Cross, so that when I
 * arrived there in the morning I was able to ask him about the arrival of
 * the boxes. He, too, put me at once in communication with the proper
 * officials, and I saw that their tally was correct with the original
 * invoice. The opportunities of acquiring an abnormal thirst had been here
 * limited; a noble use of them had, however, been made, and again I was
 * compelled to deal with the result in an _ex post facto_ manner.
 *
 * From thence I went on to Carter Paterson's central office, where I met
 * with the utmost courtesy. They looked up the transaction in their
 * day-book and letter-book, and at once telephoned to their King's Cross
 * office for more details. By good fortune, the men who did the teaming
 * were waiting for work, and the official at once sent them over, sending
 * also by one of them the way-bill and all the papers connected with the
 * delivery of the boxes at Carfax. Here again I found the tally agreeing
 * exactly; the carriers' men were able to supplement the paucity of the
 * written words with a few details. These were, I shortly found, connected
 * almost solely with the dusty nature of the job, and of the consequent
 * thirst engendered in the operators. On my affording an opportunity,
 * through the medium of the currency of the realm, of the allaying, at a
 * later period, this beneficial evil, one of the men remarked:--
 *
 * "That 'ere 'ouse, guv'nor, is the rummiest I ever was in. Blyme! but it
 * ain't been touched sence a hundred years. There was dust that thick in
 * the place that you might have slep' on it without 'urtin' of yer bones;
 * an' the place was that neglected that yer might 'ave smelled ole
 * Jerusalem in it. But the ole chapel--that took the cike, that did! Me
 * and my mate, we thort we wouldn't never git out quick enough. Lor', I
 * wouldn't take less nor a quid a moment to stay there arter dark."
 *
 * Having been in the house, I could well believe him; but if he knew what
 * I know, he would, I think, have raised his terms.
 *
 * Of one thing I am now satisfied: that _all_ the boxes which arrived at
 * Whitby from Varna in the _Demeter_ were safely deposited in the old
 * chapel at Carfax. There should be fifty of them there, unless any have
 * since been removed--as from Dr. Seward's diary I fear.
 *
 * I shall try to see the carter who took away the boxes from Carfax when
 * Renfield attacked them. By following up this clue we may learn a good
 * deal.
 *
 *        *       *       *       *       *
 *
 * _Later._--Mina and I have worked all day, and we have put all the papers
 * into order.
 *
 *
 * _Mina Harker's Journal_
 *
 * _30 September._--I am so glad that I hardly know how to contain myself.
 * It is, I suppose, the reaction from the haunting fear which I have had:
 * that this terrible affair and the reopening of his old wound might act
 * detrimentally on Jonathan. I saw him leave for Whitby with as brave a
 * face as I could, but I was sick with apprehension. The effort has,
 * however, done him good. He was never so resolute, never so strong, never
 * so full of volcanic energy, as at present. It is just as that dear, good
 * Professor Van Helsing said: he is true grit, and he improves under
 * strain that would kill a weaker nature. He came back full of life and
 * hope and determination; we have got everything in order for to-night. I
 * feel myself quite wild with excitement. I suppose one ought to pity any
 * thing so hunted as is the Count. That is just it: this Thing is not
 * human--not even beast. To read Dr. Seward's account of poor Lucy's
 * death, and what followed, is enough to dry up the springs of pity in
 * one's heart.
 *
 *        *       *       *       *       *
 *
 * _Later._--Lord Godalming and Mr. Morris arrived earlier than we
 * expected. Dr. Seward was out on business, and had taken Jonathan with
 * him, so I had to see them. It was to me a painful meeting, for it
 * brought back all poor dear Lucy's hopes of only a few months ago. Of
 * course they had heard Lucy speak of me, and it seemed that Dr. Van
 * Helsing, too, has been quite "blowing my trumpet," as Mr. Morris
 * expressed it. Poor fellows, neither of them is aware that I know all
 * about the proposals they made to Lucy. They did not quite know what to
 * say or do, as they were ignorant of the amount of my knowledge; so they
 * had to keep on neutral subjects. However, I thought the matter over, and
 * came to the conclusion that the best thing I could do would be to post
 * them in affairs right up to date. I knew from Dr. Seward's diary that
 * they had been at Lucy's death--her real death--and that I need not fear
 * to betray any secret before the time. So I told them, as well as I
 * could, that I had read all the papers and diaries, and that my husband
 * and I, having typewritten them, had just finished putting them in order.
 * I gave them each a copy to read in the library. When Lord Godalming got
 * his and turned it over--it does make a pretty good pile--he said:--
 *
 * "Did you write all this, Mrs. Harker?"
 *
 * I nodded, and he went on:--
 *
 * "I don't quite see the drift of it; but you people are all so good and
 * kind, and have been working so earnestly and so energetically, that all
 * I can do is to accept your ideas blindfold and try to help you. I have
 * had one lesson already in accepting facts that should make a man humble
 * to the last hour of his life. Besides, I know you loved my poor Lucy--"
 * Here he turned away and covered his face with his hands. I could hear
 * the tears in his voice. Mr. Morris, with instinctive delicacy, just laid
 * a hand for a moment on his shoulder, and then walked quietly out of the
 * room. I suppose there is something in woman's nature that makes a man
 * free to break down before her and express his feelings on the tender or
 * emotional side without feeling it derogatory to his manhood; for when
 * Lord Godalming found himself alone with me he sat down on the sofa and
 * gave way utterly and openly. I sat down beside him and took his hand. I
 * hope he didn't think it forward of me, and that if he ever thinks of it
 * afterwards he never will have such a thought. There I wrong him; I
 * _know_ he never will--he is too true a gentleman. I said to him, for I
 * could see that his heart was breaking:--
 *
 * "I loved dear Lucy, and I know what she was to you, and what you were to
 * her. She and I were like sisters; and now she is gone, will you not let
 * me be like a sister to you in your trouble? I know what sorrows you have
 * had, though I cannot measure the depth of them. If sympathy and pity can
 * help in your affliction, won't you let me be of some little service--for
 * Lucy's sake?"
 *
 * In an instant the poor dear fellow was overwhelmed with grief. It seemed
 * to me that all that he had of late been suffering in silence found a
 * vent at once. He grew quite hysterical, and raising his open hands, beat
 * his palms together in a perfect agony of grief. He stood up and then sat
 * down again, and the tears rained down his cheeks. I felt an infinite
 * pity for him, and opened my arms unthinkingly. With a sob he laid his
 * head on my shoulder and cried like a wearied child, whilst he shook with
 * emotion.
 *
 * We women have something of the mother in us that makes us rise above
 * smaller matters when the mother-spirit is invoked; I felt this big
 * sorrowing man's head resting on me, as though it were that of the baby
 * that some day may lie on my bosom, and I stroked his hair as though he
 * were my own child. I never thought at the time how strange it all was.
 *
 * After a little bit his sobs ceased, and he raised himself with an
 * apology, though he made no disguise of his emotion. He told me that for
 * days and nights past--weary days and sleepless nights--he had been
 * unable to speak with any one, as a man must speak in his time of
 * sorrow. There was no woman whose sympathy could be given to him, or with
 * whom, owing to the terrible circumstance with which his sorrow was
 * surrounded, he could speak freely. "I know now how I suffered," he said,
 * as he dried his eyes, "but I do not know even yet--and none other can
 * ever know--how much your sweet sympathy has been to me to-day. I shall
 * know better in time; and believe me that, though I am not ungrateful
 * now, my gratitude will grow with my understanding. You will let me be
 * like a brother, will you not, for all our lives--for dear Lucy's sake?"
 *
 * "For dear Lucy's sake," I said as we clasped hands. "Ay, and for your
 * own sake," he added, "for if a man's esteem and gratitude are ever worth
 * the winning, you have won mine to-day. If ever the future should bring
 * to you a time when you need a man's help, believe me, you will not call
 * in vain. God grant that no such time may ever come to you to break the
 * sunshine of your life; but if it should ever come, promise me that you
 * will let me know." He was so earnest, and his sorrow was so fresh, that
 * I felt it would comfort him, so I said:--
 *
 * "I promise."
 *
 * As I came along the corridor I saw Mr. Morris looking out of a window.
 * He turned as he heard my footsteps. "How is Art?" he said. Then noticing
 * my red eyes, he went on: "Ah, I see you have been comforting him. Poor
 * old fellow! he needs it. No one but a woman can help a man when he is in
 * trouble of the heart; and he had no one to comfort him."
 *
 * He bore his own trouble so bravely that my heart bled for him. I saw the
 * manuscript in his hand, and I knew that when he read it he would realise
 * how much I knew; so I said to him:--
 *
 * "I wish I could comfort all who suffer from the heart. Will you let me
 * be your friend, and will you come to me for comfort if you need it? You
 * will know, later on, why I speak." He saw that I was in earnest, and
 * stooping, took my hand, and raising it to his lips, kissed it. It seemed
 * but poor comfort to so brave and unselfish a soul, and impulsively I
 * bent over and kissed him. The tears rose in his eyes, and there was a
 * momentary choking in his throat; he said quite calmly:--
 *
 * "Little girl, you will never regret that true-hearted kindness, so long
 * as ever you live!" Then he went into the study to his friend.
 *
 * "Little girl!"--the very words he had used to Lucy, and oh, but he
 * proved himself a friend!
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
 * \page chapter_XVIII CHAPTER XVIII: Dr. Seward's Diary
 * DR. SEWARD'S DIARY
 *
 *
 * _30 September._--I got home at five o'clock, and found that Godalming
 * and Morris had not only arrived, but had already studied the transcript
 * of the various diaries and letters which Harker and his wonderful wife
 * had made and arranged. Harker had not yet returned from his visit to the
 * carriers' men, of whom Dr. Hennessey had written to me. Mrs. Harker gave
 * us a cup of tea, and I can honestly say that, for the first time since I
 * have lived in it, this old house seemed like _home_. When we had
 * finished, Mrs. Harker said:--
 *
 * "Dr. Seward, may I ask a favour? I want to see your patient, Mr.
 * Renfield. Do let me see him. What you have said of him in your diary
 * interests me so much!" She looked so appealing and so pretty that I
 * could not refuse her, and there was no possible reason why I should; so
 * I took her with me. When I went into the room, I told the man that a
 * lady would like to see him; to which he simply answered: "Why?"
 *
 * "She is going through the house, and wants to see every one in it," I
 * answered. "Oh, very well," he said; "let her come in, by all means; but
 * just wait a minute till I tidy up the place." His method of tidying was
 * peculiar: he simply swallowed all the flies and spiders in the boxes
 * before I could stop him. It was quite evident that he feared, or was
 * jealous of, some interference. When he had got through his disgusting
 * task, he said cheerfully: "Let the lady come in," and sat down on the
 * edge of his bed with his head down, but with his eyelids raised so that
 * he could see her as she entered. For a moment I thought that he might
 * have some homicidal intent; I remembered how quiet he had been just
 * before he attacked me in my own study, and I took care to stand where I
 * could seize him at once if he attempted to make a spring at her. She
 * came into the room with an easy gracefulness which would at once command
 * the respect of any lunatic--for easiness is one of the qualities mad
 * people most respect. She walked over to him, smiling pleasantly, and
 * held out her hand.
 *
 * "Good-evening, Mr. Renfield," said she. "You see, I know you, for Dr.
 * Seward has told me of you." He made no immediate reply, but eyed her all
 * over intently with a set frown on his face. This look gave way to one
 * of wonder, which merged in doubt; then, to my intense astonishment, he
 * said:--
 *
 * "You're not the girl the doctor wanted to marry, are you? You can't be,
 * you know, for she's dead." Mrs. Harker smiled sweetly as she replied:--
 *
 * "Oh no! I have a husband of my own, to whom I was married before I ever
 * saw Dr. Seward, or he me. I am Mrs. Harker."
 *
 * "Then what are you doing here?"
 *
 * "My husband and I are staying on a visit with Dr. Seward."
 *
 * "Then don't stay."
 *
 * "But why not?" I thought that this style of conversation might not be
 * pleasant to Mrs. Harker, any more than it was to me, so I joined in:--
 *
 * "How did you know I wanted to marry any one?" His reply was simply
 * contemptuous, given in a pause in which he turned his eyes from Mrs.
 * Harker to me, instantly turning them back again:--
 *
 * "What an asinine question!"
 *
 * "I don't see that at all, Mr. Renfield," said Mrs. Harker, at once
 * championing me. He replied to her with as much courtesy and respect as
 * he had shown contempt to me:--
 *
 * "You will, of course, understand, Mrs. Harker, that when a man is so
 * loved and honoured as our host is, everything regarding him is of
 * interest in our little community. Dr. Seward is loved not only by his
 * household and his friends, but even by his patients, who, being some of
 * them hardly in mental equilibrium, are apt to distort causes and
 * effects. Since I myself have been an inmate of a lunatic asylum, I
 * cannot but notice that the sophistic tendencies of some of its inmates
 * lean towards the errors of _non causa_ and _ignoratio elenchi_." I
 * positively opened my eyes at this new development. Here was my own pet
 * lunatic--the most pronounced of his type that I had ever met
 * with--talking elemental philosophy, and with the manner of a polished
 * gentleman. I wonder if it was Mrs. Harker's presence which had touched
 * some chord in his memory. If this new phase was spontaneous, or in any
 * way due to her unconscious influence, she must have some rare gift or
 * power.
 *
 * We continued to talk for some time; and, seeing that he was seemingly
 * quite reasonable, she ventured, looking at me questioningly as she
 * began, to lead him to his favourite topic. I was again astonished, for
 * he addressed himself to the question with the impartiality of the
 * completest sanity; he even took himself as an example when he mentioned
 * certain things.
 *
 * "Why, I myself am an instance of a man who had a strange belief. Indeed,
 * it was no wonder that my friends were alarmed, and insisted on my being
 * put under control. I used to fancy that life was a positive and
 * perpetual entity, and that by consuming a multitude of live things, no
 * matter how low in the scale of creation, one might indefinitely prolong
 * life. At times I held the belief so strongly that I actually tried to
 * take human life. The doctor here will bear me out that on one occasion I
 * tried to kill him for the purpose of strengthening my vital powers by
 * the assimilation with my own body of his life through the medium of his
 * blood--relying, of course, upon the Scriptural phrase, 'For the blood is
 * the life.' Though, indeed, the vendor of a certain nostrum has
 * vulgarised the truism to the very point of contempt. Isn't that true,
 * doctor?" I nodded assent, for I was so amazed that I hardly knew what to
 * either think or say; it was hard to imagine that I had seen him eat up
 * his spiders and flies not five minutes before. Looking at my watch, I
 * saw that I should go to the station to meet Van Helsing, so I told Mrs.
 * Harker that it was time to leave. She came at once, after saying
 * pleasantly to Mr. Renfield: "Good-bye, and I hope I may see you often,
 * under auspices pleasanter to yourself," to which, to my astonishment, he
 * replied:--
 *
 * "Good-bye, my dear. I pray God I may never see your sweet face again.
 * May He bless and keep you!"
 *
 * When I went to the station to meet Van Helsing I left the boys behind
 * me. Poor Art seemed more cheerful than he has been since Lucy first took
 * ill, and Quincey is more like his own bright self than he has been for
 * many a long day.
 *
 * Van Helsing stepped from the carriage with the eager nimbleness of a
 * boy. He saw me at once, and rushed up to me, saying:--
 *
 * "Ah, friend John, how goes all? Well? So! I have been busy, for I come
 * here to stay if need be. All affairs are settled with me, and I have
 * much to tell. Madam Mina is with you? Yes. And her so fine husband? And
 * Arthur and my friend Quincey, they are with you, too? Good!"
 *
 * As I drove to the house I told him of what had passed, and of how my own
 * diary had come to be of some use through Mrs. Harker's suggestion; at
 * which the Professor interrupted me:--
 *
 * "Ah, that wonderful Madam Mina! She has man's brain--a brain that a man
 * should have were he much gifted--and a woman's heart. The good God
 * fashioned her for a purpose, believe me, when He made that so good
 * combination. Friend John, up to now fortune has made that woman of help
 * to us; after to-night she must not have to do with this so terrible
 * affair. It is not good that she run a risk so great. We men are
 * determined--nay, are we not pledged?--to destroy this monster; but it is
 * no part for a woman. Even if she be not harmed, her heart may fail her
 * in so much and so many horrors; and hereafter she may suffer--both in
 * waking, from her nerves, and in sleep, from her dreams. And, besides,
 * she is young woman and not so long married; there may be other things to
 * think of some time, if not now. You tell me she has wrote all, then she
 * must consult with us; but to-morrow she say good-bye to this work, and
 * we go alone." I agreed heartily with him, and then I told him what we
 * had found in his absence: that the house which Dracula had bought was
 * the very next one to my own. He was amazed, and a great concern seemed
 * to come on him. "Oh that we had known it before!" he said, "for then we
 * might have reached him in time to save poor Lucy. However, 'the milk
 * that is spilt cries not out afterwards,' as you say. We shall not think
 * of that, but go on our way to the end." Then he fell into a silence that
 * lasted till we entered my own gateway. Before we went to prepare for
 * dinner he said to Mrs. Harker:--
 *
 * "I am told, Madam Mina, by my friend John that you and your husband have
 * put up in exact order all things that have been, up to this moment."
 *
 * "Not up to this moment, Professor," she said impulsively, "but up to
 * this morning."
 *
 * "But why not up to now? We have seen hitherto how good light all the
 * little things have made. We have told our secrets, and yet no one who
 * has told is the worse for it."
 *
 * Mrs. Harker began to blush, and taking a paper from her pockets, she
 * said:--
 *
 * "Dr. Van Helsing, will you read this, and tell me if it must go in. It
 * is my record of to-day. I too have seen the need of putting down at
 * present everything, however trivial; but there is little in this except
 * what is personal. Must it go in?" The Professor read it over gravely,
 * and handed it back, saying:--
 *
 * "It need not go in if you do not wish it; but I pray that it may. It can
 * but make your husband love you the more, and all us, your friends, more
 * honour you--as well as more esteem and love." She took it back with
 * another blush and a bright smile.
 *
 * And so now, up to this very hour, all the records we have are complete
 * and in order. The Professor took away one copy to study after dinner,
 * and before our meeting, which is fixed for nine o'clock. The rest of us
 * have already read everything; so when we meet in the study we shall all
 * be informed as to facts, and can arrange our plan of battle with this
 * terrible and mysterious enemy.
 *
 *
 * _Mina Harker's Journal._
 *
 * _30 September._--When we met in Dr. Seward's study two hours after
 * dinner, which had been at six o'clock, we unconsciously formed a sort of
 * board or committee. Professor Van Helsing took the head of the table, to
 * which Dr. Seward motioned him as he came into the room. He made me sit
 * next to him on his right, and asked me to act as secretary; Jonathan sat
 * next to me. Opposite us were Lord Godalming, Dr. Seward, and Mr.
 * Morris--Lord Godalming being next the Professor, and Dr. Seward in the
 * centre. The Professor said:--
 *
 * "I may, I suppose, take it that we are all acquainted with the facts
 * that are in these papers." We all expressed assent, and he went on:--
 *
 * "Then it were, I think good that I tell you something of the kind of
 * enemy with which we have to deal. I shall then make known to you
 * something of the history of this man, which has been ascertained for me.
 * So we then can discuss how we shall act, and can take our measure
 * according.
 *
 * "There are such beings as vampires; some of us have evidence that they
 * exist. Even had we not the proof of our own unhappy experience, the
 * teachings and the records of the past give proof enough for sane
 * peoples. I admit that at the first I was sceptic. Were it not that
 * through long years I have train myself to keep an open mind, I could not
 * have believe until such time as that fact thunder on my ear. 'See! see!
 * I prove; I prove.' Alas! Had I known at the first what now I know--nay,
 * had I even guess at him--one so precious life had been spared to many of
 * us who did love her. But that is gone; and we must so work, that other
 * poor souls perish not, whilst we can save. The _nosferatu_ do not die
 * like the bee when he sting once. He is only stronger; and being
 * stronger, have yet more power to work evil. This vampire which is
 * amongst us is of himself so strong in person as twenty men; he is of
 * cunning more than mortal, for his cunning be the growth of ages; he have
 * still the aids of necromancy, which is, as his etymology imply, the
 * divination by the dead, and all the dead that he can come nigh to are
 * for him at command; he is brute, and more than brute; he is devil in
 * callous, and the heart of him is not; he can, within limitations, appear
 * at will when, and where, and in any of the forms that are to him; he
 * can, within his range, direct the elements; the storm, the fog, the
 * thunder; he can command all the meaner things: the rat, and the owl, and
 * the bat--the moth, and the fox, and the wolf; he can grow and become
 * small; and he can at times vanish and come unknown. How then are we to
 * begin our strike to destroy him? How shall we find his where; and having
 * found it, how can we destroy? My friends, this is much; it is a terrible
 * task that we undertake, and there may be consequence to make the brave
 * shudder. For if we fail in this our fight he must surely win; and then
 * where end we? Life is nothings; I heed him not. But to fail here, is not
 * mere life or death. It is that we become as him; that we henceforward
 * become foul things of the night like him--without heart or conscience,
 * preying on the bodies and the souls of those we love best. To us for
 * ever are the gates of heaven shut; for who shall open them to us again?
 * We go on for all time abhorred by all; a blot on the face of God's
 * sunshine; an arrow in the side of Him who died for man. But we are face
 * to face with duty; and in such case must we shrink? For me, I say, no;
 * but then I am old, and life, with his sunshine, his fair places, his
 * song of birds, his music and his love, lie far behind. You others are
 * young. Some have seen sorrow; but there are fair days yet in store. What
 * say you?"
 *
 * Whilst he was speaking, Jonathan had taken my hand. I feared, oh so
 * much, that the appalling nature of our danger was overcoming him when I
 * saw his hand stretch out; but it was life to me to feel its touch--so
 * strong, so self-reliant, so resolute. A brave man's hand can speak for
 * itself; it does not even need a woman's love to hear its music.
 *
 * When the Professor had done speaking my husband looked in my eyes, and I
 * in his; there was no need for speaking between us.
 *
 * "I answer for Mina and myself," he said.
 *
 * "Count me in, Professor," said Mr. Quincey Morris, laconically as usual.
 *
 * "I am with you," said Lord Godalming, "for Lucy's sake, if for no other
 * reason."
 *
 * Dr. Seward simply nodded. The Professor stood up and, after laying his
 * golden crucifix on the table, held out his hand on either side. I took
 * his right hand, and Lord Godalming his left; Jonathan held my right with
 * his left and stretched across to Mr. Morris. So as we all took hands our
 * solemn compact was made. I felt my heart icy cold, but it did not even
 * occur to me to draw back. We resumed our places, and Dr. Van Helsing
 * went on with a sort of cheerfulness which showed that the serious work
 * had begun. It was to be taken as gravely, and in as businesslike a way,
 * as any other transaction of life:--
 *
 * "Well, you know what we have to contend against; but we, too, are not
 * without strength. We have on our side power of combination--a power
 * denied to the vampire kind; we have sources of science; we are free to
 * act and think; and the hours of the day and the night are ours equally.
 * In fact, so far as our powers extend, they are unfettered, and we are
 * free to use them. We have self-devotion in a cause, and an end to
 * achieve which is not a selfish one. These things are much.
 *
 * "Now let us see how far the general powers arrayed against us are
 * restrict, and how the individual cannot. In fine, let us consider the
 * limitations of the vampire in general, and of this one in particular.
 *
 * "All we have to go upon are traditions and superstitions. These do not
 * at the first appear much, when the matter is one of life and death--nay
 * of more than either life or death. Yet must we be satisfied; in the
 * first place because we have to be--no other means is at our control--and
 * secondly, because, after all, these things--tradition and
 * superstition--are everything. Does not the belief in vampires rest for
 * others--though not, alas! for us--on them? A year ago which of us would
 * have received such a possibility, in the midst of our scientific,
 * sceptical, matter-of-fact nineteenth century? We even scouted a belief
 * that we saw justified under our very eyes. Take it, then, that the
 * vampire, and the belief in his limitations and his cure, rest for the
 * moment on the same base. For, let me tell you, he is known everywhere
 * that men have been. In old Greece, in old Rome; he flourish in Germany
 * all over, in France, in India, even in the Chernosese; and in China, so
 * far from us in all ways, there even is he, and the peoples fear him at
 * this day. He have follow the wake of the berserker Icelander, the
 * devil-begotten Hun, the Slav, the Saxon, the Magyar. So far, then, we
 * have all we may act upon; and let me tell you that very much of the
 * beliefs are justified by what we have seen in our own so unhappy
 * experience. The vampire live on, and cannot die by mere passing of the
 * time; he can flourish when that he can fatten on the blood of the
 * living. Even more, we have seen amongst us that he can even grow
 * younger; that his vital faculties grow strenuous, and seem as though
 * they refresh themselves when his special pabulum is plenty. But he
 * cannot flourish without this diet; he eat not as others. Even friend
 * Jonathan, who lived with him for weeks, did never see him to eat, never!
 * He throws no shadow; he make in the mirror no reflect, as again
 * Jonathan observe. He has the strength of many of his hand--witness again
 * Jonathan when he shut the door against the wolfs, and when he help him
 * from the diligence too. He can transform himself to wolf, as we gather
 * from the ship arrival in Whitby, when he tear open the dog; he can be as
 * bat, as Madam Mina saw him on the window at Whitby, and as friend John
 * saw him fly from this so near house, and as my friend Quincey saw him at
 * the window of Miss Lucy. He can come in mist which he create--that noble
 * ship's captain proved him of this; but, from what we know, the distance
 * he can make this mist is limited, and it can only be round himself. He
 * come on moonlight rays as elemental dust--as again Jonathan saw those
 * sisters in the castle of Dracula. He become so small--we ourselves saw
 * Miss Lucy, ere she was at peace, slip through a hairbreadth space at the
 * tomb door. He can, when once he find his way, come out from anything or
 * into anything, no matter how close it be bound or even fused up with
 * fire--solder you call it. He can see in the dark--no small power this,
 * in a world which is one half shut from the light. Ah, but hear me
 * through. He can do all these things, yet he is not free. Nay; he is even
 * more prisoner than the slave of the galley, than the madman in his cell.
 * He cannot go where he lists; he who is not of nature has yet to obey
 * some of nature's laws--why we know not. He may not enter anywhere at the
 * first, unless there be some one of the household who bid him to come;
 * though afterwards he can come as he please. His power ceases, as does
 * that of all evil things, at the coming of the day. Only at certain times
 * can he have limited freedom. If he be not at the place whither he is
 * bound, he can only change himself at noon or at exact sunrise or sunset.
 * These things are we told, and in this record of ours we have proof by
 * inference. Thus, whereas he can do as he will within his limit, when he
 * have his earth-home, his coffin-home, his hell-home, the place
 * unhallowed, as we saw when he went to the grave of the suicide at
 * Whitby; still at other time he can only change when the time come. It is
 * said, too, that he can only pass running water at the slack or the flood
 * of the tide. Then there are things which so afflict him that he has no
 * power, as the garlic that we know of; and as for things sacred, as this
 * symbol, my crucifix, that was amongst us even now when we resolve, to
 * them he is nothing, but in their presence he take his place far off and
 * silent with respect. There are others, too, which I shall tell you of,
 * lest in our seeking we may need them. The branch of wild rose on his
 * coffin keep him that he move not from it; a sacred bullet fired into the
 * coffin kill him so that he be true dead; and as for the stake through
 * him, we know already of its peace; or the cut-off head that giveth rest.
 * We have seen it with our eyes.
 *
 * "Thus when we find the habitation of this man-that-was, we can confine
 * him to his coffin and destroy him, if we obey what we know. But he is
 * clever. I have asked my friend Arminius, of Buda-Pesth University, to
 * make his record; and, from all the means that are, he tell me of what he
 * has been. He must, indeed, have been that Voivode Dracula who won his
 * name against the Turk, over the great river on the very frontier of
 * Turkey-land. If it be so, then was he no common man; for in that time,
 * and for centuries after, he was spoken of as the cleverest and the most
 * cunning, as well as the bravest of the sons of the 'land beyond the
 * forest.' That mighty brain and that iron resolution went with him to his
 * grave, and are even now arrayed against us. The Draculas were, says
 * Arminius, a great and noble race, though now and again were scions who
 * were held by their coevals to have had dealings with the Evil One. They
 * learned his secrets in the Scholomance, amongst the mountains over Lake
 * Hermanstadt, where the devil claims the tenth scholar as his due. In the
 * records are such words as 'stregoica'--witch, 'ordog,' and
 * 'pokol'--Satan and hell; and in one manuscript this very Dracula is
 * spoken of as 'wampyr,' which we all understand too well. There have been
 * from the loins of this very one great men and good women, and their
 * graves make sacred the earth where alone this foulness can dwell. For it
 * is not the least of its terrors that this evil thing is rooted deep in
 * all good; in soil barren of holy memories it cannot rest."
 *
 * Whilst they were talking Mr. Morris was looking steadily at the window,
 * and he now got up quietly, and went out of the room. There was a little
 * pause, and then the Professor went on:--
 *
 * "And now we must settle what we do. We have here much data, and we must
 * proceed to lay out our campaign. We know from the inquiry of Jonathan
 * that from the castle to Whitby came fifty boxes of earth, all of which
 * were delivered at Carfax; we also know that at least some of these boxes
 * have been removed. It seems to me, that our first step should be to
 * ascertain whether all the rest remain in the house beyond that wall
 * where we look to-day; or whether any more have been removed. If the
 * latter, we must trace----"
 *
 * Here we were interrupted in a very startling way. Outside the house came
 * the sound of a pistol-shot; the glass of the window was shattered with a
 * bullet, which, ricochetting from the top of the embrasure, struck the
 * far wall of the room. I am afraid I am at heart a coward, for I shrieked
 * out. The men all jumped to their feet; Lord Godalming flew over to the
 * window and threw up the sash. As he did so we heard Mr. Morris's voice
 * without:--
 *
 * "Sorry! I fear I have alarmed you. I shall come in and tell you about
 * it." A minute later he came in and said:--
 *
 * "It was an idiotic thing of me to do, and I ask your pardon, Mrs.
 * Harker, most sincerely; I fear I must have frightened you terribly. But
 * the fact is that whilst the Professor was talking there came a big bat
 * and sat on the window-sill. I have got such a horror of the damned
 * brutes from recent events that I cannot stand them, and I went out to
 * have a shot, as I have been doing of late of evenings, whenever I have
 * seen one. You used to laugh at me for it then, Art."
 *
 * "Did you hit it?" asked Dr. Van Helsing.
 *
 * "I don't know; I fancy not, for it flew away into the wood." Without
 * saying any more he took his seat, and the Professor began to resume his
 * statement:--
 *
 * "We must trace each of these boxes; and when we are ready, we must
 * either capture or kill this monster in his lair; or we must, so to
 * speak, sterilise the earth, so that no more he can seek safety in it.
 * Thus in the end we may find him in his form of man between the hours of
 * noon and sunset, and so engage with him when he is at his most weak.
 *
 * "And now for you, Madam Mina, this night is the end until all be well.
 * You are too precious to us to have such risk. When we part to-night, you
 * no more must question. We shall tell you all in good time. We are men
 * and are able to bear; but you must be our star and our hope, and we
 * shall act all the more free that you are not in the danger, such as we
 * are."
 *
 * All the men, even Jonathan, seemed relieved; but it did not seem to me
 * good that they should brave danger and, perhaps, lessen their
 * safety--strength being the best safety--through care of me; but their
 * minds were made up, and, though it was a bitter pill for me to swallow,
 * I could say nothing, save to accept their chivalrous care of me.
 *
 * Mr. Morris resumed the discussion:--
 *
 * "As there is no time to lose, I vote we have a look at his house right
 * now. Time is everything with him; and swift action on our part may save
 * another victim."
 *
 * I own that my heart began to fail me when the time for action came so
 * close, but I did not say anything, for I had a greater fear that if I
 * appeared as a drag or a hindrance to their work, they might even leave
 * me out of their counsels altogether. They have now gone off to Carfax,
 * with means to get into the house.
 *
 * Manlike, they had told me to go to bed and sleep; as if a woman can
 * sleep when those she loves are in danger! I shall lie down and pretend
 * to sleep, lest Jonathan have added anxiety about me when he returns.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _1 October, 4 a. m._--Just as we were about to leave the house, an
 * urgent message was brought to me from Renfield to know if I would see
 * him at once, as he had something of the utmost importance to say to me.
 * I told the messenger to say that I would attend to his wishes in the
 * morning; I was busy just at the moment. The attendant added:--
 *
 * "He seems very importunate, sir. I have never seen him so eager. I don't
 * know but what, if you don't see him soon, he will have one of his
 * violent fits." I knew the man would not have said this without some
 * cause, so I said: "All right; I'll go now"; and I asked the others to
 * wait a few minutes for me, as I had to go and see my "patient."
 *
 * "Take me with you, friend John," said the Professor. "His case in your
 * diary interest me much, and it had bearing, too, now and again on _our_
 * case. I should much like to see him, and especial when his mind is
 * disturbed."
 *
 * "May I come also?" asked Lord Godalming.
 *
 * "Me too?" said Quincey Morris. "May I come?" said Harker. I nodded, and
 * we all went down the passage together.
 *
 * We found him in a state of considerable excitement, but far more
 * rational in his speech and manner than I had ever seen him. There was an
 * unusual understanding of himself, which was unlike anything I had ever
 * met with in a lunatic; and he took it for granted that his reasons would
 * prevail with others entirely sane. We all four went into the room, but
 * none of the others at first said anything. His request was that I would
 * at once release him from the asylum and send him home. This he backed up
 * with arguments regarding his complete recovery, and adduced his own
 * existing sanity. "I appeal to your friends," he said, "they will,
 * perhaps, not mind sitting in judgment on my case. By the way, you have
 * not introduced me." I was so much astonished, that the oddness of
 * introducing a madman in an asylum did not strike me at the moment; and,
 * besides, there was a certain dignity in the man's manner, so much of
 * the habit of equality, that I at once made the introduction: "Lord
 * Godalming; Professor Van Helsing; Mr. Quincey Morris, of Texas; Mr.
 * Renfield." He shook hands with each of them, saying in turn:--
 *
 * "Lord Godalming, I had the honour of seconding your father at the
 * Windham; I grieve to know, by your holding the title, that he is no
 * more. He was a man loved and honoured by all who knew him; and in his
 * youth was, I have heard, the inventor of a burnt rum punch, much
 * patronised on Derby night. Mr. Morris, you should be proud of your great
 * state. Its reception into the Union was a precedent which may have
 * far-reaching effects hereafter, when the Pole and the Tropics may hold
 * alliance to the Stars and Stripes. The power of Treaty may yet prove a
 * vast engine of enlargement, when the Monroe doctrine takes its true
 * place as a political fable. What shall any man say of his pleasure at
 * meeting Van Helsing? Sir, I make no apology for dropping all forms of
 * conventional prefix. When an individual has revolutionised therapeutics
 * by his discovery of the continuous evolution of brain-matter,
 * conventional forms are unfitting, since they would seem to limit him to
 * one of a class. You, gentlemen, who by nationality, by heredity, or by
 * the possession of natural gifts, are fitted to hold your respective
 * places in the moving world, I take to witness that I am as sane as at
 * least the majority of men who are in full possession of their liberties.
 * And I am sure that you, Dr. Seward, humanitarian and medico-jurist as
 * well as scientist, will deem it a moral duty to deal with me as one to
 * be considered as under exceptional circumstances." He made this last
 * appeal with a courtly air of conviction which was not without its own
 * charm.
 *
 * I think we were all staggered. For my own part, I was under the
 * conviction, despite my knowledge of the man's character and history,
 * that his reason had been restored; and I felt under a strong impulse to
 * tell him that I was satisfied as to his sanity, and would see about the
 * necessary formalities for his release in the morning. I thought it
 * better to wait, however, before making so grave a statement, for of old
 * I knew the sudden changes to which this particular patient was liable.
 * So I contented myself with making a general statement that he appeared
 * to be improving very rapidly; that I would have a longer chat with him
 * in the morning, and would then see what I could do in the direction of
 * meeting his wishes. This did not at all satisfy him, for he said
 * quickly:--
 *
 * "But I fear, Dr. Seward, that you hardly apprehend my wish. I desire to
 * go at once--here--now--this very hour--this very moment, if I may. Time
 * presses, and in our implied agreement with the old scytheman it is of
 * the essence of the contract. I am sure it is only necessary to put
 * before so admirable a practitioner as Dr. Seward so simple, yet so
 * momentous a wish, to ensure its fulfilment." He looked at me keenly, and
 * seeing the negative in my face, turned to the others, and scrutinised
 * them closely. Not meeting any sufficient response, he went on:--
 *
 * "Is it possible that I have erred in my supposition?"
 *
 * "You have," I said frankly, but at the same time, as I felt, brutally.
 * There was a considerable pause, and then he said slowly:--
 *
 * "Then I suppose I must only shift my ground of request. Let me ask for
 * this concession--boon, privilege, what you will. I am content to implore
 * in such a case, not on personal grounds, but for the sake of others. I
 * am not at liberty to give you the whole of my reasons; but you may, I
 * assure you, take it from me that they are good ones, sound and
 * unselfish, and spring from the highest sense of duty. Could you look,
 * sir, into my heart, you would approve to the full the sentiments which
 * animate me. Nay, more, you would count me amongst the best and truest of
 * your friends." Again he looked at us all keenly. I had a growing
 * conviction that this sudden change of his entire intellectual method was
 * but yet another form or phase of his madness, and so determined to let
 * him go on a little longer, knowing from experience that he would, like
 * all lunatics, give himself away in the end. Van Helsing was gazing at
 * him with a look of utmost intensity, his bushy eyebrows almost meeting
 * with the fixed concentration of his look. He said to Renfield in a tone
 * which did not surprise me at the time, but only when I thought of it
 * afterwards--for it was as of one addressing an equal:--
 *
 * "Can you not tell frankly your real reason for wishing to be free
 * to-night? I will undertake that if you will satisfy even me--a stranger,
 * without prejudice, and with the habit of keeping an open mind--Dr.
 * Seward will give you, at his own risk and on his own responsibility, the
 * privilege you seek." He shook his head sadly, and with a look of
 * poignant regret on his face. The Professor went on:--
 *
 * "Come, sir, bethink yourself. You claim the privilege of reason in the
 * highest degree, since you seek to impress us with your complete
 * reasonableness. You do this, whose sanity we have reason to doubt, since
 * you are not yet released from medical treatment for this very defect. If
 * you will not help us in our effort to choose the wisest course, how can
 * we perform the duty which you yourself put upon us? Be wise, and help
 * us; and if we can we shall aid you to achieve your wish." He still shook
 * his head as he said:--
 *
 * "Dr. Van Helsing, I have nothing to say. Your argument is complete, and
 * if I were free to speak I should not hesitate a moment; but I am not my
 * own master in the matter. I can only ask you to trust me. If I am
 * refused, the responsibility does not rest with me." I thought it was now
 * time to end the scene, which was becoming too comically grave, so I went
 * towards the door, simply saying:--
 *
 * "Come, my friends, we have work to do. Good-night."
 *
 * As, however, I got near the door, a new change came over the patient. He
 * moved towards me so quickly that for the moment I feared that he was
 * about to make another homicidal attack. My fears, however, were
 * groundless, for he held up his two hands imploringly, and made his
 * petition in a moving manner. As he saw that the very excess of his
 * emotion was militating against him, by restoring us more to our old
 * relations, he became still more demonstrative. I glanced at Van Helsing,
 * and saw my conviction reflected in his eyes; so I became a little more
 * fixed in my manner, if not more stern, and motioned to him that his
 * efforts were unavailing. I had previously seen something of the same
 * constantly growing excitement in him when he had to make some request of
 * which at the time he had thought much, such, for instance, as when he
 * wanted a cat; and I was prepared to see the collapse into the same
 * sullen acquiescence on this occasion. My expectation was not realised,
 * for, when he found that his appeal would not be successful, he got into
 * quite a frantic condition. He threw himself on his knees, and held up
 * his hands, wringing them in plaintive supplication, and poured forth a
 * torrent of entreaty, with the tears rolling down his cheeks, and his
 * whole face and form expressive of the deepest emotion:--
 *
 * "Let me entreat you, Dr. Seward, oh, let me implore you, to let me out
 * of this house at once. Send me away how you will and where you will;
 * send keepers with me with whips and chains; let them take me in a
 * strait-waistcoat, manacled and leg-ironed, even to a gaol; but let me go
 * out of this. You don't know what you do by keeping me here. I am
 * speaking from the depths of my heart--of my very soul. You don't know
 * whom you wrong, or how; and I may not tell. Woe is me! I may not tell.
 * By all you hold sacred--by all you hold dear--by your love that is
 * lost--by your hope that lives--for the sake of the Almighty, take me out
 * of this and save my soul from guilt! Can't you hear me, man? Can't you
 * understand? Will you never learn? Don't you know that I am sane and
 * earnest now; that I am no lunatic in a mad fit, but a sane man fighting
 * for his soul? Oh, hear me! hear me! Let me go! let me go! let me go!"
 *
 * I thought that the longer this went on the wilder he would get, and so
 * would bring on a fit; so I took him by the hand and raised him up.
 *
 * "Come," I said sternly, "no more of this; we have had quite enough
 * already. Get to your bed and try to behave more discreetly."
 *
 * He suddenly stopped and looked at me intently for several moments. Then,
 * without a word, he rose and moving over, sat down on the side of the
 * bed. The collapse had come, as on former occasion, just as I had
 * expected.
 *
 * When I was leaving the room, last of our party, he said to me in a
 * quiet, well-bred voice:--
 *
 * "You will, I trust, Dr. Seward, do me the justice to bear in mind, later
 * on, that I did what I could to convince you to-night."
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
 * \page chapter_XIX CHAPTER XIX: Jonathan Harker's Journal
 * JONATHAN HARKER'S JOURNAL
 *
 *
 * _1 October, 5 a. m._--I went with the party to the search with an easy
 * mind, for I think I never saw Mina so absolutely strong and well. I am
 * so glad that she consented to hold back and let us men do the work.
 * Somehow, it was a dread to me that she was in this fearful business at
 * all; but now that her work is done, and that it is due to her energy and
 * brains and foresight that the whole story is put together in such a way
 * that every point tells, she may well feel that her part is finished, and
 * that she can henceforth leave the rest to us. We were, I think, all a
 * little upset by the scene with Mr. Renfield. When we came away from his
 * room we were silent till we got back to the study. Then Mr. Morris said
 * to Dr. Seward:--
 *
 * "Say, Jack, if that man wasn't attempting a bluff, he is about the
 * sanest lunatic I ever saw. I'm not sure, but I believe that he had some
 * serious purpose, and if he had, it was pretty rough on him not to get a
 * chance." Lord Godalming and I were silent, but Dr. Van Helsing added:--
 *
 * "Friend John, you know more of lunatics than I do, and I'm glad of it,
 * for I fear that if it had been to me to decide I would before that last
 * hysterical outburst have given him free. But we live and learn, and in
 * our present task we must take no chance, as my friend Quincey would say.
 * All is best as they are." Dr. Seward seemed to answer them both in a
 * dreamy kind of way:--
 *
 * "I don't know but that I agree with you. If that man had been an
 * ordinary lunatic I would have taken my chance of trusting him; but he
 * seems so mixed up with the Count in an indexy kind of way that I am
 * afraid of doing anything wrong by helping his fads. I can't forget how
 * he prayed with almost equal fervour for a cat, and then tried to tear my
 * throat out with his teeth. Besides, he called the Count 'lord and
 * master,' and he may want to get out to help him in some diabolical way.
 * That horrid thing has the wolves and the rats and his own kind to help
 * him, so I suppose he isn't above trying to use a respectable lunatic. He
 * certainly did seem earnest, though. I only hope we have done what is
 * best. These things, in conjunction with the wild work we have in hand,
 * help to unnerve a man." The Professor stepped over, and laying his hand
 * on his shoulder, said in his grave, kindly way:--
 *
 * "Friend John, have no fear. We are trying to do our duty in a very sad
 * and terrible case; we can only do as we deem best. What else have we to
 * hope for, except the pity of the good God?" Lord Godalming had slipped
 * away for a few minutes, but now he returned. He held up a little silver
 * whistle, as he remarked:--
 *
 * "That old place may be full of rats, and if so, I've got an antidote on
 * call." Having passed the wall, we took our way to the house, taking care
 * to keep in the shadows of the trees on the lawn when the moonlight shone
 * out. When we got to the porch the Professor opened his bag and took out
 * a lot of things, which he laid on the step, sorting them into four
 * little groups, evidently one for each. Then he spoke:--
 *
 * "My friends, we are going into a terrible danger, and we need arms of
 * many kinds. Our enemy is not merely spiritual. Remember that he has the
 * strength of twenty men, and that, though our necks or our windpipes are
 * of the common kind--and therefore breakable or crushable--his are not
 * amenable to mere strength. A stronger man, or a body of men more strong
 * in all than him, can at certain times hold him; but they cannot hurt him
 * as we can be hurt by him. We must, therefore, guard ourselves from his
 * touch. Keep this near your heart"--as he spoke he lifted a little silver
 * crucifix and held it out to me, I being nearest to him--"put these
 * flowers round your neck"--here he handed to me a wreath of withered
 * garlic blossoms--"for other enemies more mundane, this revolver and this
 * knife; and for aid in all, these so small electric lamps, which you can
 * fasten to your breast; and for all, and above all at the last, this,
 * which we must not desecrate needless." This was a portion of Sacred
 * Wafer, which he put in an envelope and handed to me. Each of the others
 * was similarly equipped. "Now," he said, "friend John, where are the
 * skeleton keys? If so that we can open the door, we need not break house
 * by the window, as before at Miss Lucy's."
 *
 * Dr. Seward tried one or two skeleton keys, his mechanical dexterity as a
 * surgeon standing him in good stead. Presently he got one to suit; after
 * a little play back and forward the bolt yielded, and, with a rusty
 * clang, shot back. We pressed on the door, the rusty hinges creaked, and
 * it slowly opened. It was startlingly like the image conveyed to me in
 * Dr. Seward's diary of the opening of Miss Westenra's tomb; I fancy that
 * the same idea seemed to strike the others, for with one accord they
 * shrank back. The Professor was the first to move forward, and stepped
 * into the open door.
 *
 * "_In manus tuas, Domine!_" he said, crossing himself as he passed over
 * the threshold. We closed the door behind us, lest when we should have
 * lit our lamps we should possibly attract attention from the road. The
 * Professor carefully tried the lock, lest we might not be able to open it
 * from within should we be in a hurry making our exit. Then we all lit our
 * lamps and proceeded on our search.
 *
 * The light from the tiny lamps fell in all sorts of odd forms, as the
 * rays crossed each other, or the opacity of our bodies threw great
 * shadows. I could not for my life get away from the feeling that there
 * was some one else amongst us. I suppose it was the recollection, so
 * powerfully brought home to me by the grim surroundings, of that terrible
 * experience in Transylvania. I think the feeling was common to us all,
 * for I noticed that the others kept looking over their shoulders at every
 * sound and every new shadow, just as I felt myself doing.
 *
 * The whole place was thick with dust. The floor was seemingly inches
 * deep, except where there were recent footsteps, in which on holding down
 * my lamp I could see marks of hobnails where the dust was cracked. The
 * walls were fluffy and heavy with dust, and in the corners were masses of
 * spider's webs, whereon the dust had gathered till they looked like old
 * tattered rags as the weight had torn them partly down. On a table in the
 * hall was a great bunch of keys, with a time-yellowed label on each. They
 * had been used several times, for on the table were several similar rents
 * in the blanket of dust, similar to that exposed when the Professor
 * lifted them. He turned to me and said:--
 *
 * "You know this place, Jonathan. You have copied maps of it, and you know
 * it at least more than we do. Which is the way to the chapel?" I had an
 * idea of its direction, though on my former visit I had not been able to
 * get admission to it; so I led the way, and after a few wrong turnings
 * found myself opposite a low, arched oaken door, ribbed with iron bands.
 * "This is the spot," said the Professor as he turned his lamp on a small
 * map of the house, copied from the file of my original correspondence
 * regarding the purchase. With a little trouble we found the key on the
 * bunch and opened the door. We were prepared for some unpleasantness, for
 * as we were opening the door a faint, malodorous air seemed to exhale
 * through the gaps, but none of us ever expected such an odour as we
 * encountered. None of the others had met the Count at all at close
 * quarters, and when I had seen him he was either in the fasting stage of
 * his existence in his rooms or, when he was gloated with fresh blood, in
 * a ruined building open to the air; but here the place was small and
 * close, and the long disuse had made the air stagnant and foul. There was
 * an earthy smell, as of some dry miasma, which came through the fouler
 * air. But as to the odour itself, how shall I describe it? It was not
 * alone that it was composed of all the ills of mortality and with the
 * pungent, acrid smell of blood, but it seemed as though corruption had
 * become itself corrupt. Faugh! it sickens me to think of it. Every breath
 * exhaled by that monster seemed to have clung to the place and
 * intensified its loathsomeness.
 *
 * Under ordinary circumstances such a stench would have brought our
 * enterprise to an end; but this was no ordinary case, and the high and
 * terrible purpose in which we were involved gave us a strength which rose
 * above merely physical considerations. After the involuntary shrinking
 * consequent on the first nauseous whiff, we one and all set about our
 * work as though that loathsome place were a garden of roses.
 *
 * We made an accurate examination of the place, the Professor saying as we
 * began:--
 *
 * "The first thing is to see how many of the boxes are left; we must then
 * examine every hole and corner and cranny and see if we cannot get some
 * clue as to what has become of the rest." A glance was sufficient to show
 * how many remained, for the great earth chests were bulky, and there was
 * no mistaking them.
 *
 * There were only twenty-nine left out of the fifty! Once I got a fright,
 * for, seeing Lord Godalming suddenly turn and look out of the vaulted
 * door into the dark passage beyond, I looked too, and for an instant my
 * heart stood still. Somewhere, looking out from the shadow, I seemed to
 * see the high lights of the Count's evil face, the ridge of the nose, the
 * red eyes, the red lips, the awful pallor. It was only for a moment, for,
 * as Lord Godalming said, "I thought I saw a face, but it was only the
 * shadows," and resumed his inquiry, I turned my lamp in the direction,
 * and stepped into the passage. There was no sign of any one; and as there
 * were no corners, no doors, no aperture of any kind, but only the solid
 * walls of the passage, there could be no hiding-place even for _him_. I
 * took it that fear had helped imagination, and said nothing.
 *
 * A few minutes later I saw Morris step suddenly back from a corner, which
 * he was examining. We all followed his movements with our eyes, for
 * undoubtedly some nervousness was growing on us, and we saw a whole mass
 * of phosphorescence, which twinkled like stars. We all instinctively drew
 * back. The whole place was becoming alive with rats.
 *
 * For a moment or two we stood appalled, all save Lord Godalming, who was
 * seemingly prepared for such an emergency. Rushing over to the great
 * iron-bound oaken door, which Dr. Seward had described from the outside,
 * and which I had seen myself, he turned the key in the lock, drew the
 * huge bolts, and swung the door open. Then, taking his little silver
 * whistle from his pocket, he blew a low, shrill call. It was answered
 * from behind Dr. Seward's house by the yelping of dogs, and after about a
 * minute three terriers came dashing round the corner of the house.
 * Unconsciously we had all moved towards the door, and as we moved I
 * noticed that the dust had been much disturbed: the boxes which had been
 * taken out had been brought this way. But even in the minute that had
 * elapsed the number of the rats had vastly increased. They seemed to
 * swarm over the place all at once, till the lamplight, shining on their
 * moving dark bodies and glittering, baleful eyes, made the place look
 * like a bank of earth set with fireflies. The dogs dashed on, but at the
 * threshold suddenly stopped and snarled, and then, simultaneously lifting
 * their noses, began to howl in most lugubrious fashion. The rats were
 * multiplying in thousands, and we moved out.
 *
 * Lord Godalming lifted one of the dogs, and carrying him in, placed him
 * on the floor. The instant his feet touched the ground he seemed to
 * recover his courage, and rushed at his natural enemies. They fled before
 * him so fast that before he had shaken the life out of a score, the other
 * dogs, who had by now been lifted in the same manner, had but small prey
 * ere the whole mass had vanished.
 *
 * With their going it seemed as if some evil presence had departed, for
 * the dogs frisked about and barked merrily as they made sudden darts at
 * their prostrate foes, and turned them over and over and tossed them in
 * the air with vicious shakes. We all seemed to find our spirits rise.
 * Whether it was the purifying of the deadly atmosphere by the opening of
 * the chapel door, or the relief which we experienced by finding ourselves
 * in the open I know not; but most certainly the shadow of dread seemed to
 * slip from us like a robe, and the occasion of our coming lost something
 * of its grim significance, though we did not slacken a whit in our
 * resolution. We closed the outer door and barred and locked it, and
 * bringing the dogs with us, began our search of the house. We found
 * nothing throughout except dust in extraordinary proportions, and all
 * untouched save for my own footsteps when I had made my first visit.
 * Never once did the dogs exhibit any symptom of uneasiness, and even when
 * we returned to the chapel they frisked about as though they had been
 * rabbit-hunting in a summer wood.
 *
 * The morning was quickening in the east when we emerged from the front.
 * Dr. Van Helsing had taken the key of the hall-door from the bunch, and
 * locked the door in orthodox fashion, putting the key into his pocket
 * when he had done.
 *
 * "So far," he said, "our night has been eminently successful. No harm has
 * come to us such as I feared might be and yet we have ascertained how
 * many boxes are missing. More than all do I rejoice that this, our
 * first--and perhaps our most difficult and dangerous--step has been
 * accomplished without the bringing thereinto our most sweet Madam Mina or
 * troubling her waking or sleeping thoughts with sights and sounds and
 * smells of horror which she might never forget. One lesson, too, we have
 * learned, if it be allowable to argue _a particulari_: that the brute
 * beasts which are to the Count's command are yet themselves not amenable
 * to his spiritual power; for look, these rats that would come to his
 * call, just as from his castle top he summon the wolves to your going and
 * to that poor mother's cry, though they come to him, they run pell-mell
 * from the so little dogs of my friend Arthur. We have other matters
 * before us, other dangers, other fears; and that monster--he has not used
 * his power over the brute world for the only or the last time to-night.
 * So be it that he has gone elsewhere. Good! It has given us opportunity
 * to cry 'check' in some ways in this chess game, which we play for the
 * stake of human souls. And now let us go home. The dawn is close at hand,
 * and we have reason to be content with our first night's work. It may be
 * ordained that we have many nights and days to follow, if full of peril;
 * but we must go on, and from no danger shall we shrink."
 *
 * The house was silent when we got back, save for some poor creature who
 * was screaming away in one of the distant wards, and a low, moaning sound
 * from Renfield's room. The poor wretch was doubtless torturing himself,
 * after the manner of the insane, with needless thoughts of pain.
 *
 * I came tiptoe into our own room, and found Mina asleep, breathing so
 * softly that I had to put my ear down to hear it. She looks paler than
 * usual. I hope the meeting to-night has not upset her. I am truly
 * thankful that she is to be left out of our future work, and even of our
 * deliberations. It is too great a strain for a woman to bear. I did not
 * think so at first, but I know better now. Therefore I am glad that it is
 * settled. There may be things which would frighten her to hear; and yet
 * to conceal them from her might be worse than to tell her if once she
 * suspected that there was any concealment. Henceforth our work is to be a
 * sealed book to her, till at least such time as we can tell her that all
 * is finished, and the earth free from a monster of the nether world. I
 * daresay it will be difficult to begin to keep silence after such
 * confidence as ours; but I must be resolute, and to-morrow I shall keep
 * dark over to-night's doings, and shall refuse to speak of anything that
 * has happened. I rest on the sofa, so as not to disturb her.
 *
 *        *       *       *       *       *
 *
 * _1 October, later._--I suppose it was natural that we should have all
 * overslept ourselves, for the day was a busy one, and the night had no
 * rest at all. Even Mina must have felt its exhaustion, for though I slept
 * till the sun was high, I was awake before her, and had to call two or
 * three times before she awoke. Indeed, she was so sound asleep that for a
 * few seconds she did not recognize me, but looked at me with a sort of
 * blank terror, as one looks who has been waked out of a bad dream. She
 * complained a little of being tired, and I let her rest till later in the
 * day. We now know of twenty-one boxes having been removed, and if it be
 * that several were taken in any of these removals we may be able to trace
 * them all. Such will, of course, immensely simplify our labour, and the
 * sooner the matter is attended to the better. I shall look up Thomas
 * Snelling to-day.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _1 October._--It was towards noon when I was awakened by the Professor
 * walking into my room. He was more jolly and cheerful than usual, and it
 * is quite evident that last night's work has helped to take some of the
 * brooding weight off his mind. After going over the adventure of the
 * night he suddenly said:--
 *
 * "Your patient interests me much. May it be that with you I visit him
 * this morning? Or if that you are too occupy, I can go alone if it may
 * be. It is a new experience to me to find a lunatic who talk philosophy,
 * and reason so sound." I had some work to do which pressed, so I told him
 * that if he would go alone I would be glad, as then I should not have to
 * keep him waiting; so I called an attendant and gave him the necessary
 * instructions. Before the Professor left the room I cautioned him against
 * getting any false impression from my patient. "But," he answered, "I
 * want him to talk of himself and of his delusion as to consuming live
 * things. He said to Madam Mina, as I see in your diary of yesterday, that
 * he had once had such a belief. Why do you smile, friend John?"
 *
 * "Excuse me," I said, "but the answer is here." I laid my hand on the
 * type-written matter. "When our sane and learned lunatic made that very
 * statement of how he _used_ to consume life, his mouth was actually
 * nauseous with the flies and spiders which he had eaten just before Mrs.
 * Harker entered the room." Van Helsing smiled in turn. "Good!" he said.
 * "Your memory is true, friend John. I should have remembered. And yet it
 * is this very obliquity of thought and memory which makes mental disease
 * such a fascinating study. Perhaps I may gain more knowledge out of the
 * folly of this madman than I shall from the teaching of the most wise.
 * Who knows?" I went on with my work, and before long was through that in
 * hand. It seemed that the time had been very short indeed, but there was
 * Van Helsing back in the study. "Do I interrupt?" he asked politely as he
 * stood at the door.
 *
 * "Not at all," I answered. "Come in. My work is finished, and I am free.
 * I can go with you now, if you like.
 *
 * "It is needless; I have seen him!"
 *
 * "Well?"
 *
 * "I fear that he does not appraise me at much. Our interview was short.
 * When I entered his room he was sitting on a stool in the centre, with
 * his elbows on his knees, and his face was the picture of sullen
 * discontent. I spoke to him as cheerfully as I could, and with such a
 * measure of respect as I could assume. He made no reply whatever. "Don't
 * you know me?" I asked. His answer was not reassuring: "I know you well
 * enough; you are the old fool Van Helsing. I wish you would take yourself
 * and your idiotic brain theories somewhere else. Damn all thick-headed
 * Dutchmen!" Not a word more would he say, but sat in his implacable
 * sullenness as indifferent to me as though I had not been in the room at
 * all. Thus departed for this time my chance of much learning from this so
 * clever lunatic; so I shall go, if I may, and cheer myself with a few
 * happy words with that sweet soul Madam Mina. Friend John, it does
 * rejoice me unspeakable that she is no more to be pained, no more to be
 * worried with our terrible things. Though we shall much miss her help, it
 * is better so."
 *
 * "I agree with you with all my heart," I answered earnestly, for I did
 * not want him to weaken in this matter. "Mrs. Harker is better out of it.
 * Things are quite bad enough for us, all men of the world, and who have
 * been in many tight places in our time; but it is no place for a woman,
 * and if she had remained in touch with the affair, it would in time
 * infallibly have wrecked her."
 *
 * So Van Helsing has gone to confer with Mrs. Harker and Harker; Quincey
 * and Art are all out following up the clues as to the earth-boxes. I
 * shall finish my round of work and we shall meet to-night.
 *
 *
 * _Mina Harker's Journal._
 *
 * _1 October._--It is strange to me to be kept in the dark as I am to-day;
 * after Jonathan's full confidence for so many years, to see him
 * manifestly avoid certain matters, and those the most vital of all. This
 * morning I slept late after the fatigues of yesterday, and though
 * Jonathan was late too, he was the earlier. He spoke to me before he went
 * out, never more sweetly or tenderly, but he never mentioned a word of
 * what had happened in the visit to the Count's house. And yet he must
 * have known how terribly anxious I was. Poor dear fellow! I suppose it
 * must have distressed him even more than it did me. They all agreed that
 * it was best that I should not be drawn further into this awful work, and
 * I acquiesced. But to think that he keeps anything from me! And now I am
 * crying like a silly fool, when I _know_ it comes from my husband's great
 * love and from the good, good wishes of those other strong men.
 *
 * That has done me good. Well, some day Jonathan will tell me all; and
 * lest it should ever be that he should think for a moment that I kept
 * anything from him, I still keep my journal as usual. Then if he has
 * feared of my trust I shall show it to him, with every thought of my
 * heart put down for his dear eyes to read. I feel strangely sad and
 * low-spirited to-day. I suppose it is the reaction from the terrible
 * excitement.
 *
 * Last night I went to bed when the men had gone, simply because they told
 * me to. I didn't feel sleepy, and I did feel full of devouring anxiety. I
 * kept thinking over everything that has been ever since Jonathan came to
 * see me in London, and it all seems like a horrible tragedy, with fate
 * pressing on relentlessly to some destined end. Everything that one does
 * seems, no matter how right it may be, to bring on the very thing which
 * is most to be deplored. If I hadn't gone to Whitby, perhaps poor dear
 * Lucy would be with us now. She hadn't taken to visiting the churchyard
 * till I came, and if she hadn't come there in the day-time with me she
 * wouldn't have walked there in her sleep; and if she hadn't gone there at
 * night and asleep, that monster couldn't have destroyed her as he did.
 * Oh, why did I ever go to Whitby? There now, crying again! I wonder what
 * has come over me to-day. I must hide it from Jonathan, for if he knew
 * that I had been crying twice in one morning--I, who never cried on my
 * own account, and whom he has never caused to shed a tear--the dear
 * fellow would fret his heart out. I shall put a bold face on, and if I do
 * feel weepy, he shall never see it. I suppose it is one of the lessons
 * that we poor women have to learn....
 *
 * I can't quite remember how I fell asleep last night. I remember hearing
 * the sudden barking of the dogs and a lot of queer sounds, like praying
 * on a very tumultuous scale, from Mr. Renfield's room, which is somewhere
 * under this. And then there was silence over everything, silence so
 * profound that it startled me, and I got up and looked out of the window.
 * All was dark and silent, the black shadows thrown by the moonlight
 * seeming full of a silent mystery of their own. Not a thing seemed to be
 * stirring, but all to be grim and fixed as death or fate; so that a thin
 * streak of white mist, that crept with almost imperceptible slowness
 * across the grass towards the house, seemed to have a sentience and a
 * vitality of its own. I think that the digression of my thoughts must
 * have done me good, for when I got back to bed I found a lethargy
 * creeping over me. I lay a while, but could not quite sleep, so I got out
 * and looked out of the window again. The mist was spreading, and was now
 * close up to the house, so that I could see it lying thick against the
 * wall, as though it were stealing up to the windows. The poor man was
 * more loud than ever, and though I could not distinguish a word he said,
 * I could in some way recognise in his tones some passionate entreaty on
 * his part. Then there was the sound of a struggle, and I knew that the
 * attendants were dealing with him. I was so frightened that I crept into
 * bed, and pulled the clothes over my head, putting my fingers in my ears.
 * I was not then a bit sleepy, at least so I thought; but I must have
 * fallen asleep, for, except dreams, I do not remember anything until the
 * morning, when Jonathan woke me. I think that it took me an effort and a
 * little time to realise where I was, and that it was Jonathan who was
 * bending over me. My dream was very peculiar, and was almost typical of
 * the way that waking thoughts become merged in, or continued in, dreams.
 *
 * I thought that I was asleep, and waiting for Jonathan to come back. I
 * was very anxious about him, and I was powerless to act; my feet, and my
 * hands, and my brain were weighted, so that nothing could proceed at the
 * usual pace. And so I slept uneasily and thought. Then it began to dawn
 * upon me that the air was heavy, and dank, and cold. I put back the
 * clothes from my face, and found, to my surprise, that all was dim
 * around. The gaslight which I had left lit for Jonathan, but turned down,
 * came only like a tiny red spark through the fog, which had evidently
 * grown thicker and poured into the room. Then it occurred to me that I
 * had shut the window before I had come to bed. I would have got out to
 * make certain on the point, but some leaden lethargy seemed to chain my
 * limbs and even my will. I lay still and endured; that was all. I closed
 * my eyes, but could still see through my eyelids. (It is wonderful what
 * tricks our dreams play us, and how conveniently we can imagine.) The
 * mist grew thicker and thicker and I could see now how it came in, for I
 * could see it like smoke--or with the white energy of boiling
 * water--pouring in, not through the window, but through the joinings of
 * the door. It got thicker and thicker, till it seemed as if it became
 * concentrated into a sort of pillar of cloud in the room, through the top
 * of which I could see the light of the gas shining like a red eye. Things
 * began to whirl through my brain just as the cloudy column was now
 * whirling in the room, and through it all came the scriptural words "a
 * pillar of cloud by day and of fire by night." Was it indeed some such
 * spiritual guidance that was coming to me in my sleep? But the pillar was
 * composed of both the day and the night-guiding, for the fire was in the
 * red eye, which at the thought got a new fascination for me; till, as I
 * looked, the fire divided, and seemed to shine on me through the fog like
 * two red eyes, such as Lucy told me of in her momentary mental wandering
 * when, on the cliff, the dying sunlight struck the windows of St. Mary's
 * Church. Suddenly the horror burst upon me that it was thus that Jonathan
 * had seen those awful women growing into reality through the whirling mist
 * in the moonlight, and in my dream I must have fainted, for all became
 * black darkness. The last conscious effort which imagination made was to
 * show me a livid white face bending over me out of the mist. I must be
 * careful of such dreams, for they would unseat one's reason if there were
 * too much of them. I would get Dr. Van Helsing or Dr. Seward to prescribe
 * something for me which would make me sleep, only that I fear to alarm
 * them. Such a dream at the present time would become woven into their
 * fears for me. To-night I shall strive hard to sleep naturally. If I do
 * not, I shall to-morrow night get them to give me a dose of chloral; that
 * cannot hurt me for once, and it will give me a good night's sleep. Last
 * night tired me more than if I had not slept at all.
 *
 *        *       *       *       *       *
 *
 * _2 October 10 p. m._--Last night I slept, but did not dream. I must have
 * slept soundly, for I was not waked by Jonathan coming to bed; but the
 * sleep has not refreshed me, for to-day I feel terribly weak and
 * spiritless. I spent all yesterday trying to read, or lying down dozing.
 * In the afternoon Mr. Renfield asked if he might see me. Poor man, he was
 * very gentle, and when I came away he kissed my hand and bade God bless
 * me. Some way it affected me much; I am crying when I think of him. This
 * is a new weakness, of which I must be careful. Jonathan would be
 * miserable if he knew I had been crying. He and the others were out till
 * dinner-time, and they all came in tired. I did what I could to brighten
 * them up, and I suppose that the effort did me good, for I forgot how
 * tired I was. After dinner they sent me to bed, and all went off to smoke
 * together, as they said, but I knew that they wanted to tell each other
 * of what had occurred to each during the day; I could see from Jonathan's
 * manner that he had something important to communicate. I was not so
 * sleepy as I should have been; so before they went I asked Dr. Seward to
 * give me a little opiate of some kind, as I had not slept well the night
 * before. He very kindly made me up a sleeping draught, which he gave to
 * me, telling me that it would do me no harm, as it was very mild.... I
 * have taken it, and am waiting for sleep, which still keeps aloof. I hope
 * I have not done wrong, for as sleep begins to flirt with me, a new fear
 * comes: that I may have been foolish in thus depriving myself of the
 * power of waking. I might want it. Here comes sleep. Good-night.
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
 * \page chapter_XX CHAPTER XX: Jonathan Harker's Journal
 * JONATHAN HARKER'S JOURNAL
 *
 *
 * _1 October, evening._--I found Thomas Snelling in his house at Bethnal
 * Green, but unhappily he was not in a condition to remember anything. The
 * very prospect of beer which my expected coming had opened to him had
 * proved too much, and he had begun too early on his expected debauch. I
 * learned, however, from his wife, who seemed a decent, poor soul, that he
 * was only the assistant to Smollet, who of the two mates was the
 * responsible person. So off I drove to Walworth, and found Mr. Joseph
 * Smollet at home and in his shirtsleeves, taking a late tea out of a
 * saucer. He is a decent, intelligent fellow, distinctly a good, reliable
 * type of workman, and with a headpiece of his own. He remembered all
 * about the incident of the boxes, and from a wonderful dog's-eared
 * notebook, which he produced from some mysterious receptacle about the
 * seat of his trousers, and which had hieroglyphical entries in thick,
 * half-obliterated pencil, he gave me the destinations of the boxes. There
 * were, he said, six in the cartload which he took from Carfax and left at
 * 197, Chicksand Street, Mile End New Town, and another six which he
 * deposited at Jamaica Lane, Bermondsey. If then the Count meant to
 * scatter these ghastly refuges of his over London, these places were
 * chosen as the first of delivery, so that later he might distribute more
 * fully. The systematic manner in which this was done made me think that
 * he could not mean to confine himself to two sides of London. He was now
 * fixed on the far east of the northern shore, on the east of the southern
 * shore, and on the south. The north and west were surely never meant to
 * be left out of his diabolical scheme--let alone the City itself and the
 * very heart of fashionable London in the south-west and west. I went back
 * to Smollet, and asked him if he could tell us if any other boxes had
 * been taken from Carfax.
 *
 * He replied:--
 *
 * "Well, guv'nor, you've treated me wery 'an'some"--I had given him half a
 * sovereign--"an' I'll tell yer all I know. I heard a man by the name of
 * Bloxam say four nights ago in the 'Are an' 'Ounds, in Pincher's Alley,
 * as 'ow he an' his mate 'ad 'ad a rare dusty job in a old 'ouse at
 * Purfect. There ain't a-many such jobs as this 'ere, an' I'm thinkin'
 * that maybe Sam Bloxam could tell ye summut." I asked if he could tell me
 * where to find him. I told him that if he could get me the address it
 * would be worth another half-sovereign to him. So he gulped down the rest
 * of his tea and stood up, saying that he was going to begin the search
 * then and there. At the door he stopped, and said:--
 *
 * "Look 'ere, guv'nor, there ain't no sense in me a-keepin' you 'ere. I
 * may find Sam soon, or I mayn't; but anyhow he ain't like to be in a way
 * to tell ye much to-night. Sam is a rare one when he starts on the booze.
 * If you can give me a envelope with a stamp on it, and put yer address on
 * it, I'll find out where Sam is to be found and post it ye to-night. But
 * ye'd better be up arter 'im soon in the mornin', or maybe ye won't ketch
 * 'im; for Sam gets off main early, never mind the booze the night afore."
 *
 * This was all practical, so one of the children went off with a penny to
 * buy an envelope and a sheet of paper, and to keep the change. When she
 * came back, I addressed the envelope and stamped it, and when Smollet had
 * again faithfully promised to post the address when found, I took my way
 * to home. We're on the track anyhow. I am tired to-night, and want sleep.
 * Mina is fast asleep, and looks a little too pale; her eyes look as
 * though she had been crying. Poor dear, I've no doubt it frets her to be
 * kept in the dark, and it may make her doubly anxious about me and the
 * others. But it is best as it is. It is better to be disappointed and
 * worried in such a way now than to have her nerve broken. The doctors
 * were quite right to insist on her being kept out of this dreadful
 * business. I must be firm, for on me this particular burden of silence
 * must rest. I shall not ever enter on the subject with her under any
 * circumstances. Indeed, it may not be a hard task, after all, for she
 * herself has become reticent on the subject, and has not spoken of the
 * Count or his doings ever since we told her of our decision.
 *
 *        *       *       *       *       *
 *
 * _2 October, evening._--A long and trying and exciting day. By the first
 * post I got my directed envelope with a dirty scrap of paper enclosed, on
 * which was written with a carpenter's pencil in a sprawling hand:--
 *
 * "Sam Bloxam, Korkrans, 4, Poters Cort, Bartel Street, Walworth. Arsk for
 * the depite."
 *
 * I got the letter in bed, and rose without waking Mina. She looked heavy
 * and sleepy and pale, and far from well. I determined not to wake her,
 * but that, when I should return from this new search, I would arrange for
 * her going back to Exeter. I think she would be happier in our own home,
 * with her daily tasks to interest her, than in being here amongst us and
 * in ignorance. I only saw Dr. Seward for a moment, and told him where I
 * was off to, promising to come back and tell the rest so soon as I should
 * have found out anything. I drove to Walworth and found, with some
 * difficulty, Potter's Court. Mr. Smollet's spelling misled me, as I asked
 * for Poter's Court instead of Potter's Court. However, when I had found
 * the court, I had no difficulty in discovering Corcoran's lodging-house.
 * When I asked the man who came to the door for the "depite," he shook his
 * head, and said: "I dunno 'im. There ain't no such a person 'ere; I never
 * 'eard of 'im in all my bloomin' days. Don't believe there ain't nobody
 * of that kind livin' ere or anywheres." I took out Smollet's letter, and
 * as I read it it seemed to me that the lesson of the spelling of the name
 * of the court might guide me. "What are you?" I asked.
 *
 * "I'm the depity," he answered. I saw at once that I was on the right
 * track; phonetic spelling had again misled me. A half-crown tip put the
 * deputy's knowledge at my disposal, and I learned that Mr. Bloxam, who
 * had slept off the remains of his beer on the previous night at
 * Corcoran's, had left for his work at Poplar at five o'clock that
 * morning. He could not tell me where the place of work was situated, but
 * he had a vague idea that it was some kind of a "new-fangled ware'us";
 * and with this slender clue I had to start for Poplar. It was twelve
 * o'clock before I got any satisfactory hint of such a building, and this
 * I got at a coffee-shop, where some workmen were having their dinner. One
 * of these suggested that there was being erected at Cross Angel Street a
 * new "cold storage" building; and as this suited the condition of a
 * "new-fangled ware'us," I at once drove to it. An interview with a surly
 * gatekeeper and a surlier foreman, both of whom were appeased with the
 * coin of the realm, put me on the track of Bloxam; he was sent for on my
 * suggesting that I was willing to pay his day's wages to his foreman for
 * the privilege of asking him a few questions on a private matter. He was
 * a smart enough fellow, though rough of speech and bearing. When I had
 * promised to pay for his information and given him an earnest, he told me
 * that he had made two journeys between Carfax and a house in Piccadilly,
 * and had taken from this house to the latter nine great boxes--"main
 * heavy ones"--with a horse and cart hired by him for this purpose. I
 * asked him if he could tell me the number of the house in Piccadilly, to
 * which he replied:--
 *
 * "Well, guv'nor, I forgits the number, but it was only a few doors from a
 * big white church or somethink of the kind, not long built. It was a
 * dusty old 'ouse, too, though nothin' to the dustiness of the 'ouse we
 * tooked the bloomin' boxes from."
 *
 * "How did you get into the houses if they were both empty?"
 *
 * "There was the old party what engaged me a-waitin' in the 'ouse at
 * Purfleet. He 'elped me to lift the boxes and put them in the dray. Curse
 * me, but he was the strongest chap I ever struck, an' him a old feller,
 * with a white moustache, one that thin you would think he couldn't throw
 * a shadder."
 *
 * How this phrase thrilled through me!
 *
 * "Why, 'e took up 'is end o' the boxes like they was pounds of tea, and
 * me a-puffin' an' a-blowin' afore I could up-end mine anyhow--an' I'm no
 * chicken, neither."
 *
 * "How did you get into the house in Piccadilly?" I asked.
 *
 * "He was there too. He must 'a' started off and got there afore me, for
 * when I rung of the bell he kem an' opened the door 'isself an' 'elped me
 * to carry the boxes into the 'all."
 *
 * "The whole nine?" I asked.
 *
 * "Yus; there was five in the first load an' four in the second. It was
 * main dry work, an' I don't so well remember 'ow I got 'ome." I
 * interrupted him:--
 *
 * "Were the boxes left in the hall?"
 *
 * "Yus; it was a big 'all, an' there was nothin' else in it." I made one
 * more attempt to further matters:--
 *
 * "You didn't have any key?"
 *
 * "Never used no key nor nothink. The old gent, he opened the door 'isself
 * an' shut it again when I druv off. I don't remember the last time--but
 * that was the beer."
 *
 * "And you can't remember the number of the house?"
 *
 * "No, sir. But ye needn't have no difficulty about that. It's a 'igh 'un
 * with a stone front with a bow on it, an' 'igh steps up to the door. I
 * know them steps, 'avin' 'ad to carry the boxes up with three loafers
 * what come round to earn a copper. The old gent give them shillin's, an'
 * they seein' they got so much, they wanted more; but 'e took one of them
 * by the shoulder and was like to throw 'im down the steps, till the lot
 * of them went away cussin'." I thought that with this description I could
 * find the house, so, having paid my friend for his information, I started
 * off for Piccadilly. I had gained a new painful experience; the Count
 * could, it was evident, handle the earth-boxes himself. If so, time was
 * precious; for, now that he had achieved a certain amount of
 * distribution, he could, by choosing his own time, complete the task
 * unobserved. At Piccadilly Circus I discharged my cab, and walked
 * westward; beyond the Junior Constitutional I came across the house
 * described, and was satisfied that this was the next of the lairs
 * arranged by Dracula. The house looked as though it had been long
 * untenanted. The windows were encrusted with dust, and the shutters were
 * up. All the framework was black with time, and from the iron the paint
 * had mostly scaled away. It was evident that up to lately there had been
 * a large notice-board in front of the balcony; it had, however, been
 * roughly torn away, the uprights which had supported it still remaining.
 * Behind the rails of the balcony I saw there were some loose boards,
 * whose raw edges looked white. I would have given a good deal to have
 * been able to see the notice-board intact, as it would, perhaps, have
 * given some clue to the ownership of the house. I remembered my
 * experience of the investigation and purchase of Carfax, and I could not
 * but feel that if I could find the former owner there might be some means
 * discovered of gaining access to the house.
 *
 * There was at present nothing to be learned from the Piccadilly side, and
 * nothing could be done; so I went round to the back to see if anything
 * could be gathered from this quarter. The mews were active, the
 * Piccadilly houses being mostly in occupation. I asked one or two of the
 * grooms and helpers whom I saw around if they could tell me anything
 * about the empty house. One of them said that he heard it had lately been
 * taken, but he couldn't say from whom. He told me, however, that up to
 * very lately there had been a notice-board of "For Sale" up, and that
 * perhaps Mitchell, Sons, & Candy, the house agents, could tell me
 * something, as he thought he remembered seeing the name of that firm on
 * the board. I did not wish to seem too eager, or to let my informant know
 * or guess too much, so, thanking him in the usual manner, I strolled
 * away. It was now growing dusk, and the autumn night was closing in, so I
 * did not lose any time. Having learned the address of Mitchell, Sons, &
 * Candy from a directory at the Berkeley, I was soon at their office in
 * Sackville Street.
 *
 * The gentleman who saw me was particularly suave in manner, but
 * uncommunicative in equal proportion. Having once told me that the
 * Piccadilly house--which throughout our interview he called a
 * "mansion"--was sold, he considered my business as concluded. When I
 * asked who had purchased it, he opened his eyes a thought wider, and
 * paused a few seconds before replying:--
 *
 * "It is sold, sir."
 *
 * "Pardon me," I said, with equal politeness, "but I have a special reason
 * for wishing to know who purchased it."
 *
 * Again he paused longer, and raised his eyebrows still more. "It is sold,
 * sir," was again his laconic reply.
 *
 * "Surely," I said, "you do not mind letting me know so much."
 *
 * "But I do mind," he answered. "The affairs of their clients are
 * absolutely safe in the hands of Mitchell, Sons, & Candy." This was
 * manifestly a prig of the first water, and there was no use arguing with
 * him. I thought I had best meet him on his own ground, so I said:--
 *
 * "Your clients, sir, are happy in having so resolute a guardian of their
 * confidence. I am myself a professional man." Here I handed him my card.
 * "In this instance I am not prompted by curiosity; I act on the part of
 * Lord Godalming, who wishes to know something of the property which was,
 * he understood, lately for sale." These words put a different complexion
 * on affairs. He said:--
 *
 * "I would like to oblige you if I could, Mr. Harker, and especially would
 * I like to oblige his lordship. We once carried out a small matter of
 * renting some chambers for him when he was the Honourable Arthur
 * Holmwood. If you will let me have his lordship's address I will consult
 * the House on the subject, and will, in any case, communicate with his
 * lordship by to-night's post. It will be a pleasure if we can so far
 * deviate from our rules as to give the required information to his
 * lordship."
 *
 * I wanted to secure a friend, and not to make an enemy, so I thanked him,
 * gave the address at Dr. Seward's and came away. It was now dark, and I
 * was tired and hungry. I got a cup of tea at the Aërated Bread Company
 * and came down to Purfleet by the next train.
 *
 * I found all the others at home. Mina was looking tired and pale, but she
 * made a gallant effort to be bright and cheerful, it wrung my heart to
 * think that I had had to keep anything from her and so caused her
 * inquietude. Thank God, this will be the last night of her looking on at
 * our conferences, and feeling the sting of our not showing our
 * confidence. It took all my courage to hold to the wise resolution of
 * keeping her out of our grim task. She seems somehow more reconciled; or
 * else the very subject seems to have become repugnant to her, for when
 * any accidental allusion is made she actually shudders. I am glad we
 * made our resolution in time, as with such a feeling as this, our growing
 * knowledge would be torture to her.
 *
 * I could not tell the others of the day's discovery till we were alone;
 * so after dinner--followed by a little music to save appearances even
 * amongst ourselves--I took Mina to her room and left her to go to bed.
 * The dear girl was more affectionate with me than ever, and clung to me
 * as though she would detain me; but there was much to be talked of and I
 * came away. Thank God, the ceasing of telling things has made no
 * difference between us.
 *
 * When I came down again I found the others all gathered round the fire in
 * the study. In the train I had written my diary so far, and simply read
 * it off to them as the best means of letting them get abreast of my own
 * information; when I had finished Van Helsing said:--
 *
 * "This has been a great day's work, friend Jonathan. Doubtless we are on
 * the track of the missing boxes. If we find them all in that house, then
 * our work is near the end. But if there be some missing, we must search
 * until we find them. Then shall we make our final _coup_, and hunt the
 * wretch to his real death." We all sat silent awhile and all at once Mr.
 * Morris spoke:--
 *
 * "Say! how are we going to get into that house?"
 *
 * "We got into the other," answered Lord Godalming quickly.
 *
 * "But, Art, this is different. We broke house at Carfax, but we had night
 * and a walled park to protect us. It will be a mighty different thing to
 * commit burglary in Piccadilly, either by day or night. I confess I don't
 * see how we are going to get in unless that agency duck can find us a key
 * of some sort; perhaps we shall know when you get his letter in the
 * morning." Lord Godalming's brows contracted, and he stood up and walked
 * about the room. By-and-by he stopped and said, turning from one to
 * another of us:--
 *
 * "Quincey's head is level. This burglary business is getting serious; we
 * got off once all right; but we have now a rare job on hand--unless we
 * can find the Count's key basket."
 *
 * As nothing could well be done before morning, and as it would be at
 * least advisable to wait till Lord Godalming should hear from Mitchell's,
 * we decided not to take any active step before breakfast time. For a good
 * while we sat and smoked, discussing the matter in its various lights and
 * bearings; I took the opportunity of bringing this diary right up to the
 * moment. I am very sleepy and shall go to bed....
 *
 * Just a line. Mina sleeps soundly and her breathing is regular. Her
 * forehead is puckered up into little wrinkles, as though she thinks even
 * in her sleep. She is still too pale, but does not look so haggard as she
 * did this morning. To-morrow will, I hope, mend all this; she will be
 * herself at home in Exeter. Oh, but I am sleepy!
 *
 *
 * _Dr. Seward's Diary._
 *
 * _1 October._--I am puzzled afresh about Renfield. His moods change so
 * rapidly that I find it difficult to keep touch of them, and as they
 * always mean something more than his own well-being, they form a more
 * than interesting study. This morning, when I went to see him after his
 * repulse of Van Helsing, his manner was that of a man commanding destiny.
 * He was, in fact, commanding destiny--subjectively. He did not really
 * care for any of the things of mere earth; he was in the clouds and
 * looked down on all the weaknesses and wants of us poor mortals. I
 * thought I would improve the occasion and learn something, so I asked
 * him:--
 *
 * "What about the flies these times?" He smiled on me in quite a superior
 * sort of way--such a smile as would have become the face of Malvolio--as
 * he answered me:--
 *
 * "The fly, my dear sir, has one striking feature; its wings are typical
 * of the aërial powers of the psychic faculties. The ancients did well
 * when they typified the soul as a butterfly!"
 *
 * I thought I would push his analogy to its utmost logically, so I said
 * quickly:--
 *
 * "Oh, it is a soul you are after now, is it?" His madness foiled his
 * reason, and a puzzled look spread over his face as, shaking his head
 * with a decision which I had but seldom seen in him, he said:--
 *
 * "Oh, no, oh no! I want no souls. Life is all I want." Here he brightened
 * up; "I am pretty indifferent about it at present. Life is all right; I
 * have all I want. You must get a new patient, doctor, if you wish to
 * study zoöphagy!"
 *
 * This puzzled me a little, so I drew him on:--
 *
 * "Then you command life; you are a god, I suppose?" He smiled with an
 * ineffably benign superiority.
 *
 * "Oh no! Far be it from me to arrogate to myself the attributes of the
 * Deity. I am not even concerned in His especially spiritual doings. If I
 * may state my intellectual position I am, so far as concerns things
 * purely terrestrial, somewhat in the position which Enoch occupied
 * spiritually!" This was a poser to me. I could not at the moment recall
 * Enoch's appositeness; so I had to ask a simple question, though I felt
 * that by so doing I was lowering myself in the eyes of the lunatic:--
 *
 * "And why with Enoch?"
 *
 * "Because he walked with God." I could not see the analogy, but did not
 * like to admit it; so I harked back to what he had denied:--
 *
 * "So you don't care about life and you don't want souls. Why not?" I put
 * my question quickly and somewhat sternly, on purpose to disconcert him.
 * The effort succeeded; for an instant he unconsciously relapsed into his
 * old servile manner, bent low before me, and actually fawned upon me as
 * he replied:--
 *
 * "I don't want any souls, indeed, indeed! I don't. I couldn't use them if
 * I had them; they would be no manner of use to me. I couldn't eat them
 * or----" He suddenly stopped and the old cunning look spread over his
 * face, like a wind-sweep on the surface of the water. "And doctor, as to
 * life, what is it after all? When you've got all you require, and you
 * know that you will never want, that is all. I have friends--good
 * friends--like you, Dr. Seward"; this was said with a leer of
 * inexpressible cunning. "I know that I shall never lack the means of
 * life!"
 *
 * I think that through the cloudiness of his insanity he saw some
 * antagonism in me, for he at once fell back on the last refuge of such as
 * he--a dogged silence. After a short time I saw that for the present it
 * was useless to speak to him. He was sulky, and so I came away.
 *
 * Later in the day he sent for me. Ordinarily I would not have come
 * without special reason, but just at present I am so interested in him
 * that I would gladly make an effort. Besides, I am glad to have anything
 * to help to pass the time. Harker is out, following up clues; and so are
 * Lord Godalming and Quincey. Van Helsing sits in my study poring over the
 * record prepared by the Harkers; he seems to think that by accurate
 * knowledge of all details he will light upon some clue. He does not wish
 * to be disturbed in the work, without cause. I would have taken him with
 * me to see the patient, only I thought that after his last repulse he
 * might not care to go again. There was also another reason: Renfield
 * might not speak so freely before a third person as when he and I were
 * alone.
 *
 * I found him sitting out in the middle of the floor on his stool, a pose
 * which is generally indicative of some mental energy on his part. When I
 * came in, he said at once, as though the question had been waiting on his
 * lips:--
 *
 * "What about souls?" It was evident then that my surmise had been
 * correct. Unconscious cerebration was doing its work, even with the
 * lunatic. I determined to have the matter out. "What about them
 * yourself?" I asked. He did not reply for a moment but looked all round
 * him, and up and down, as though he expected to find some inspiration for
 * an answer.
 *
 * "I don't want any souls!" he said in a feeble, apologetic way. The
 * matter seemed preying on his mind, and so I determined to use it--to "be
 * cruel only to be kind." So I said:--
 *
 * "You like life, and you want life?"
 *
 * "Oh yes! but that is all right; you needn't worry about that!"
 *
 * "But," I asked, "how are we to get the life without getting the soul
 * also?" This seemed to puzzle him, so I followed it up:--
 *
 * "A nice time you'll have some time when you're flying out there, with
 * the souls of thousands of flies and spiders and birds and cats buzzing
 * and twittering and miauing all round you. You've got their lives, you
 * know, and you must put up with their souls!" Something seemed to affect
 * his imagination, for he put his fingers to his ears and shut his eyes,
 * screwing them up tightly just as a small boy does when his face is being
 * soaped. There was something pathetic in it that touched me; it also gave
 * me a lesson, for it seemed that before me was a child--only a child,
 * though the features were worn, and the stubble on the jaws was white. It
 * was evident that he was undergoing some process of mental disturbance,
 * and, knowing how his past moods had interpreted things seemingly foreign
 * to himself, I thought I would enter into his mind as well as I could and
 * go with him. The first step was to restore confidence, so I asked him,
 * speaking pretty loud so that he would hear me through his closed ears:--
 *
 * "Would you like some sugar to get your flies round again?" He seemed to
 * wake up all at once, and shook his head. With a laugh he replied:--
 *
 * "Not much! flies are poor things, after all!" After a pause he added,
 * "But I don't want their souls buzzing round me, all the same."
 *
 * "Or spiders?" I went on.
 *
 * "Blow spiders! What's the use of spiders? There isn't anything in them
 * to eat or"--he stopped suddenly, as though reminded of a forbidden
 * topic.
 *
 * "So, so!" I thought to myself, "this is the second time he has suddenly
 * stopped at the word 'drink'; what does it mean?" Renfield seemed himself
 * aware of having made a lapse, for he hurried on, as though to distract
 * my attention from it:--
 *
 * "I don't take any stock at all in such matters. 'Rats and mice and such
 * small deer,' as Shakespeare has it, 'chicken-feed of the larder' they
 * might be called. I'm past all that sort of nonsense. You might as well
 * ask a man to eat molecules with a pair of chop-sticks, as to try to
 * interest me about the lesser carnivora, when I know of what is before
 * me."
 *
 * "I see," I said. "You want big things that you can make your teeth meet
 * in? How would you like to breakfast on elephant?"
 *
 * "What ridiculous nonsense you are talking!" He was getting too wide
 * awake, so I thought I would press him hard. "I wonder," I said
 * reflectively, "what an elephant's soul is like!"
 *
 * The effect I desired was obtained, for he at once fell from his
 * high-horse and became a child again.
 *
 * "I don't want an elephant's soul, or any soul at all!" he said. For a
 * few moments he sat despondently. Suddenly he jumped to his feet, with
 * his eyes blazing and all the signs of intense cerebral excitement. "To
 * hell with you and your souls!" he shouted. "Why do you plague me about
 * souls? Haven't I got enough to worry, and pain, and distract me already,
 * without thinking of souls!" He looked so hostile that I thought he was
 * in for another homicidal fit, so I blew my whistle. The instant,
 * however, that I did so he became calm, and said apologetically:--
 *
 * "Forgive me, Doctor; I forgot myself. You do not need any help. I am so
 * worried in my mind that I am apt to be irritable. If you only knew the
 * problem I have to face, and that I am working out, you would pity, and
 * tolerate, and pardon me. Pray do not put me in a strait-waistcoat. I
 * want to think and I cannot think freely when my body is confined. I am
 * sure you will understand!" He had evidently self-control; so when the
 * attendants came I told them not to mind, and they withdrew. Renfield
 * watched them go; when the door was closed he said, with considerable
 * dignity and sweetness:--
 *
 * "Dr. Seward, you have been very considerate towards me. Believe me that
 * I am very, very grateful to you!" I thought it well to leave him in this
 * mood, and so I came away. There is certainly something to ponder over in
 * this man's state. Several points seem to make what the American
 * interviewer calls "a story," if one could only get them in proper order.
 * Here they are:--
 *
 * Will not mention "drinking."
 *
 * Fears the thought of being burdened with the "soul" of anything.
 *
 * Has no dread of wanting "life" in the future.
 *
 * Despises the meaner forms of life altogether, though he dreads being
 * haunted by their souls.
 *
 * Logically all these things point one way! he has assurance of some kind
 * that he will acquire some higher life. He dreads the consequence--the
 * burden of a soul. Then it is a human life he looks to!
 *
 * And the assurance--?
 *
 * Merciful God! the Count has been to him, and there is some new scheme of
 * terror afoot!
 *
 *        *       *       *       *       *
 *
 * _Later._--I went after my round to Van Helsing and told him my
 * suspicion. He grew very grave; and, after thinking the matter over for a
 * while asked me to take him to Renfield. I did so. As we came to the door
 * we heard the lunatic within singing gaily, as he used to do in the time
 * which now seems so long ago. When we entered we saw with amazement that
 * he had spread out his sugar as of old; the flies, lethargic with the
 * autumn, were beginning to buzz into the room. We tried to make him talk
 * of the subject of our previous conversation, but he would not attend. He
 * went on with his singing, just as though we had not been present. He had
 * got a scrap of paper and was folding it into a note-book. We had to come
 * away as ignorant as we went in.
 *
 * His is a curious case indeed; we must watch him to-night.
 *
 *
 * _Letter, Mitchell, Sons and Candy to Lord Godalming._
 *
 * _"1 October._
 *
 * "My Lord,
 *
 * "We are at all times only too happy to meet your wishes. We beg, with
 * regard to the desire of your Lordship, expressed by Mr. Harker on your
 * behalf, to supply the following information concerning the sale and
 * purchase of No. 347, Piccadilly. The original vendors are the executors
 * of the late Mr. Archibald Winter-Suffield. The purchaser is a foreign
 * nobleman, Count de Ville, who effected the purchase himself paying the
 * purchase money in notes 'over the counter,' if your Lordship will pardon
 * us using so vulgar an expression. Beyond this we know nothing whatever
 * of him.
 *
 * "We are, my Lord,
 *
 * "Your Lordship's humble servants,
 *
 * "MITCHELL, SONS & CANDY."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _2 October._--I placed a man in the corridor last night, and told him to
 * make an accurate note of any sound he might hear from Renfield's room,
 * and gave him instructions that if there should be anything strange he
 * was to call me. After dinner, when we had all gathered round the fire
 * in the study--Mrs. Harker having gone to bed--we discussed the attempts
 * and discoveries of the day. Harker was the only one who had any result,
 * and we are in great hopes that his clue may be an important one.
 *
 * Before going to bed I went round to the patient's room and looked in
 * through the observation trap. He was sleeping soundly, and his heart
 * rose and fell with regular respiration.
 *
 * This morning the man on duty reported to me that a little after midnight
 * he was restless and kept saying his prayers somewhat loudly. I asked him
 * if that was all; he replied that it was all he heard. There was
 * something about his manner so suspicious that I asked him point blank if
 * he had been asleep. He denied sleep, but admitted to having "dozed" for
 * a while. It is too bad that men cannot be trusted unless they are
 * watched.
 *
 * To-day Harker is out following up his clue, and Art and Quincey are
 * looking after horses. Godalming thinks that it will be well to have
 * horses always in readiness, for when we get the information which we
 * seek there will be no time to lose. We must sterilise all the imported
 * earth between sunrise and sunset; we shall thus catch the Count at his
 * weakest, and without a refuge to fly to. Van Helsing is off to the
 * British Museum looking up some authorities on ancient medicine. The old
 * physicians took account of things which their followers do not accept,
 * and the Professor is searching for witch and demon cures which may be
 * useful to us later.
 *
 * I sometimes think we must be all mad and that we shall wake to sanity in
 * strait-waistcoats.
 *
 *        *       *       *       *       *
 *
 * _Later._--We have met again. We seem at last to be on the track, and our
 * work of to-morrow may be the beginning of the end. I wonder if
 * Renfield's quiet has anything to do with this. His moods have so
 * followed the doings of the Count, that the coming destruction of the
 * monster may be carried to him in some subtle way. If we could only get
 * some hint as to what passed in his mind, between the time of my argument
 * with him to-day and his resumption of fly-catching, it might afford us a
 * valuable clue. He is now seemingly quiet for a spell.... Is he?---- That
 * wild yell seemed to come from his room....
 *
 *        *       *       *       *       *
 *
 * The attendant came bursting into my room and told me that Renfield had
 * somehow met with some accident. He had heard him yell; and when he went
 * to him found him lying on his face on the floor, all covered with blood.
 * I must go at once....
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
 * \page chapter_XXI CHAPTER XXI: Dr. Seward's Diary
 * DR. SEWARD'S DIARY
 *
 *
 * _3 October._--Let me put down with exactness all that happened, as well
 * as I can remember it, since last I made an entry. Not a detail that I
 * can recall must be forgotten; in all calmness I must proceed.
 *
 * When I came to Renfield's room I found him lying on the floor on his
 * left side in a glittering pool of blood. When I went to move him, it
 * became at once apparent that he had received some terrible injuries;
 * there seemed none of that unity of purpose between the parts of the body
 * which marks even lethargic sanity. As the face was exposed I could see
 * that it was horribly bruised, as though it had been beaten against the
 * floor--indeed it was from the face wounds that the pool of blood
 * originated. The attendant who was kneeling beside the body said to me as
 * we turned him over:--
 *
 * "I think, sir, his back is broken. See, both his right arm and leg and
 * the whole side of his face are paralysed." How such a thing could have
 * happened puzzled the attendant beyond measure. He seemed quite
 * bewildered, and his brows were gathered in as he said:--
 *
 * "I can't understand the two things. He could mark his face like that by
 * beating his own head on the floor. I saw a young woman do it once at the
 * Eversfield Asylum before anyone could lay hands on her. And I suppose he
 * might have broke his neck by falling out of bed, if he got in an awkward
 * kink. But for the life of me I can't imagine how the two things
 * occurred. If his back was broke, he couldn't beat his head; and if his
 * face was like that before the fall out of bed, there would be marks of
 * it." I said to him:--
 *
 * "Go to Dr. Van Helsing, and ask him to kindly come here at once. I want
 * him without an instant's delay." The man ran off, and within a few
 * minutes the Professor, in his dressing gown and slippers, appeared. When
 * he saw Renfield on the ground, he looked keenly at him a moment, and
 * then turned to me. I think he recognised my thought in my eyes, for he
 * said very quietly, manifestly for the ears of the attendant:--
 *
 * "Ah, a sad accident! He will need very careful watching, and much
 * attention. I shall stay with you myself; but I shall first dress myself.
 * If you will remain I shall in a few minutes join you."
 *
 * The patient was now breathing stertorously and it was easy to see that
 * he had suffered some terrible injury. Van Helsing returned with
 * extraordinary celerity, bearing with him a surgical case. He had
 * evidently been thinking and had his mind made up; for, almost before he
 * looked at the patient, he whispered to me:--
 *
 * "Send the attendant away. We must be alone with him when he becomes
 * conscious, after the operation." So I said:--
 *
 * "I think that will do now, Simmons. We have done all that we can at
 * present. You had better go your round, and Dr. Van Helsing will operate.
 * Let me know instantly if there be anything unusual anywhere."
 *
 * The man withdrew, and we went into a strict examination of the patient.
 * The wounds of the face was superficial; the real injury was a depressed
 * fracture of the skull, extending right up through the motor area. The
 * Professor thought a moment and said:--
 *
 * "We must reduce the pressure and get back to normal conditions, as far
 * as can be; the rapidity of the suffusion shows the terrible nature of
 * his injury. The whole motor area seems affected. The suffusion of the
 * brain will increase quickly, so we must trephine at once or it may be
 * too late." As he was speaking there was a soft tapping at the door. I
 * went over and opened it and found in the corridor without, Arthur and
 * Quincey in pajamas and slippers: the former spoke:--
 *
 * "I heard your man call up Dr. Van Helsing and tell him of an accident.
 * So I woke Quincey or rather called for him as he was not asleep. Things
 * are moving too quickly and too strangely for sound sleep for any of us
 * these times. I've been thinking that to-morrow night will not see things
 * as they have been. We'll have to look back--and forward a little more
 * than we have done. May we come in?" I nodded, and held the door open
 * till they had entered; then I closed it again. When Quincey saw the
 * attitude and state of the patient, and noted the horrible pool on the
 * floor, he said softly:--
 *
 * "My God! what has happened to him? Poor, poor devil!" I told him
 * briefly, and added that we expected he would recover consciousness after
 * the operation--for a short time, at all events. He went at once and sat
 * down on the edge of the bed, with Godalming beside him; we all watched
 * in patience.
 *
 * "We shall wait," said Van Helsing, "just long enough to fix the best
 * spot for trephining, so that we may most quickly and perfectly remove
 * the blood clot; for it is evident that the hæmorrhage is increasing."
 *
 * The minutes during which we waited passed with fearful slowness. I had a
 * horrible sinking in my heart, and from Van Helsing's face I gathered
 * that he felt some fear or apprehension as to what was to come. I dreaded
 * the words that Renfield might speak. I was positively afraid to think;
 * but the conviction of what was coming was on me, as I have read of men
 * who have heard the death-watch. The poor man's breathing came in
 * uncertain gasps. Each instant he seemed as though he would open his eyes
 * and speak; but then would follow a prolonged stertorous breath, and he
 * would relapse into a more fixed insensibility. Inured as I was to sick
 * beds and death, this suspense grew, and grew upon me. I could almost
 * hear the beating of my own heart; and the blood surging through my
 * temples sounded like blows from a hammer. The silence finally became
 * agonising. I looked at my companions, one after another, and saw from
 * their flushed faces and damp brows that they were enduring equal
 * torture. There was a nervous suspense over us all, as though overhead
 * some dread bell would peal out powerfully when we should least expect
 * it.
 *
 * At last there came a time when it was evident that the patient was
 * sinking fast; he might die at any moment. I looked up at the Professor
 * and caught his eyes fixed on mine. His face was sternly set as he
 * spoke:--
 *
 * "There is no time to lose. His words may be worth many lives; I have
 * been thinking so, as I stood here. It may be there is a soul at stake!
 * We shall operate just above the ear."
 *
 * Without another word he made the operation. For a few moments the
 * breathing continued to be stertorous. Then there came a breath so
 * prolonged that it seemed as though it would tear open his chest.
 * Suddenly his eyes opened, and became fixed in a wild, helpless stare.
 * This was continued for a few moments; then it softened into a glad
 * surprise, and from the lips came a sigh of relief. He moved
 * convulsively, and as he did so, said:--
 *
 * "I'll be quiet, Doctor. Tell them to take off the strait-waistcoat. I
 * have had a terrible dream, and it has left me so weak that I cannot
 * move. What's wrong with my face? it feels all swollen, and it smarts
 * dreadfully." He tried to turn his head; but even with the effort his
 * eyes seemed to grow glassy again so I gently put it back. Then Van
 * Helsing said in a quiet grave tone:--
 *
 * "Tell us your dream, Mr. Renfield." As he heard the voice his face
 * brightened, through its mutilation, and he said:--
 *
 * "That is Dr. Van Helsing. How good it is of you to be here. Give me some
 * water, my lips are dry; and I shall try to tell you. I dreamed"--he
 * stopped and seemed fainting, I called quietly to Quincey--"The
 * brandy--it is in my study--quick!" He flew and returned with a glass,
 * the decanter of brandy and a carafe of water. We moistened the parched
 * lips, and the patient quickly revived. It seemed, however, that his poor
 * injured brain had been working in the interval, for, when he was quite
 * conscious, he looked at me piercingly with an agonised confusion which I
 * shall never forget, and said:--
 *
 * "I must not deceive myself; it was no dream, but all a grim reality."
 * Then his eyes roved round the room; as they caught sight of the two
 * figures sitting patiently on the edge of the bed he went on:--
 *
 * "If I were not sure already, I would know from them." For an instant his
 * eyes closed--not with pain or sleep but voluntarily, as though he were
 * bringing all his faculties to bear; when he opened them he said,
 * hurriedly, and with more energy than he had yet displayed:--
 *
 * "Quick, Doctor, quick. I am dying! I feel that I have but a few minutes;
 * and then I must go back to death--or worse! Wet my lips with brandy
 * again. I have something that I must say before I die; or before my poor
 * crushed brain dies anyhow. Thank you! It was that night after you left
 * me, when I implored you to let me go away. I couldn't speak then, for I
 * felt my tongue was tied; but I was as sane then, except in that way, as
 * I am now. I was in an agony of despair for a long time after you left
 * me; it seemed hours. Then there came a sudden peace to me. My brain
 * seemed to become cool again, and I realised where I was. I heard the
 * dogs bark behind our house, but not where He was!" As he spoke, Van
 * Helsing's eyes never blinked, but his hand came out and met mine and
 * gripped it hard. He did not, however, betray himself; he nodded slightly
 * and said: "Go on," in a low voice. Renfield proceeded:--
 *
 * "He came up to the window in the mist, as I had seen him often before;
 * but he was solid then--not a ghost, and his eyes were fierce like a
 * man's when angry. He was laughing with his red mouth; the sharp white
 * teeth glinted in the moonlight when he turned to look back over the belt
 * of trees, to where the dogs were barking. I wouldn't ask him to come in
 * at first, though I knew he wanted to--just as he had wanted all along.
 * Then he began promising me things--not in words but by doing them." He
 * was interrupted by a word from the Professor:--
 *
 * "How?"
 *
 * "By making them happen; just as he used to send in the flies when the
 * sun was shining. Great big fat ones with steel and sapphire on their
 * wings; and big moths, in the night, with skull and cross-bones on their
 * backs." Van Helsing nodded to him as he whispered to me unconsciously:--
 *
 * "The _Acherontia Aitetropos of the Sphinges_--what you call the
 * 'Death's-head Moth'?" The patient went on without stopping.
 *
 * "Then he began to whisper: 'Rats, rats, rats! Hundreds, thousands,
 * millions of them, and every one a life; and dogs to eat them, and cats
 * too. All lives! all red blood, with years of life in it; and not merely
 * buzzing flies!' I laughed at him, for I wanted to see what he could do.
 * Then the dogs howled, away beyond the dark trees in His house. He
 * beckoned me to the window. I got up and looked out, and He raised his
 * hands, and seemed to call out without using any words. A dark mass
 * spread over the grass, coming on like the shape of a flame of fire; and
 * then He moved the mist to the right and left, and I could see that there
 * were thousands of rats with their eyes blazing red--like His, only
 * smaller. He held up his hand, and they all stopped; and I thought he
 * seemed to be saying: 'All these lives will I give you, ay, and many more
 * and greater, through countless ages, if you will fall down and worship
 * me!' And then a red cloud, like the colour of blood, seemed to close
 * over my eyes; and before I knew what I was doing, I found myself opening
 * the sash and saying to Him: 'Come in, Lord and Master!' The rats were
 * all gone, but He slid into the room through the sash, though it was only
 * open an inch wide--just as the Moon herself has often come in through
 * the tiniest crack and has stood before me in all her size and
 * splendour."
 *
 * His voice was weaker, so I moistened his lips with the brandy again, and
 * he continued; but it seemed as though his memory had gone on working in
 * the interval for his story was further advanced. I was about to call him
 * back to the point, but Van Helsing whispered to me: "Let him go on. Do
 * not interrupt him; he cannot go back, and maybe could not proceed at all
 * if once he lost the thread of his thought." He proceeded:--
 *
 * "All day I waited to hear from him, but he did not send me anything, not
 * even a blow-fly, and when the moon got up I was pretty angry with him.
 * When he slid in through the window, though it was shut, and did not even
 * knock, I got mad with him. He sneered at me, and his white face looked
 * out of the mist with his red eyes gleaming, and he went on as though he
 * owned the whole place, and I was no one. He didn't even smell the same
 * as he went by me. I couldn't hold him. I thought that, somehow, Mrs.
 * Harker had come into the room."
 *
 * The two men sitting on the bed stood up and came over, standing behind
 * him so that he could not see them, but where they could hear better.
 * They were both silent, but the Professor started and quivered; his face,
 * however, grew grimmer and sterner still. Renfield went on without
 * noticing:--
 *
 * "When Mrs. Harker came in to see me this afternoon she wasn't the same;
 * it was like tea after the teapot had been watered." Here we all moved,
 * but no one said a word; he went on:--
 *
 * "I didn't know that she was here till she spoke; and she didn't look the
 * same. I don't care for the pale people; I like them with lots of blood
 * in them, and hers had all seemed to have run out. I didn't think of it
 * at the time; but when she went away I began to think, and it made me mad
 * to know that He had been taking the life out of her." I could feel that
 * the rest quivered, as I did, but we remained otherwise still. "So when
 * He came to-night I was ready for Him. I saw the mist stealing in, and I
 * grabbed it tight. I had heard that madmen have unnatural strength; and
 * as I knew I was a madman--at times anyhow--I resolved to use my power.
 * Ay, and He felt it too, for He had to come out of the mist to struggle
 * with me. I held tight; and I thought I was going to win, for I didn't
 * mean Him to take any more of her life, till I saw His eyes. They burned
 * into me, and my strength became like water. He slipped through it, and
 * when I tried to cling to Him, He raised me up and flung me down. There
 * was a red cloud before me, and a noise like thunder, and the mist seemed
 * to steal away under the door." His voice was becoming fainter and his
 * breath more stertorous. Van Helsing stood up instinctively.
 *
 * "We know the worst now," he said. "He is here, and we know his purpose.
 * It may not be too late. Let us be armed--the same as we were the other
 * night, but lose no time; there is not an instant to spare." There was no
 * need to put our fear, nay our conviction, into words--we shared them in
 * common. We all hurried and took from our rooms the same things that we
 * had when we entered the Count's house. The Professor had his ready, and
 * as we met in the corridor he pointed to them significantly as he said:--
 *
 * "They never leave me; and they shall not till this unhappy business is
 * over. Be wise also, my friends. It is no common enemy that we deal with.
 * Alas! alas! that that dear Madam Mina should suffer!" He stopped; his
 * voice was breaking, and I do not know if rage or terror predominated in
 * my own heart.
 *
 * Outside the Harkers' door we paused. Art and Quincey held back, and the
 * latter said:--
 *
 * "Should we disturb her?"
 *
 * "We must," said Van Helsing grimly. "If the door be locked, I shall
 * break it in."
 *
 * "May it not frighten her terribly? It is unusual to break into a lady's
 * room!"
 *
 * Van Helsing said solemnly, "You are always right; but this is life and
 * death. All chambers are alike to the doctor; and even were they not they
 * are all as one to me to-night. Friend John, when I turn the handle, if
 * the door does not open, do you put your shoulder down and shove; and you
 * too, my friends. Now!"
 *
 * He turned the handle as he spoke, but the door did not yield. We threw
 * ourselves against it; with a crash it burst open, and we almost fell
 * headlong into the room. The Professor did actually fall, and I saw
 * across him as he gathered himself up from hands and knees. What I saw
 * appalled me. I felt my hair rise like bristles on the back of my neck,
 * and my heart seemed to stand still.
 *
 * The moonlight was so bright that through the thick yellow blind the room
 * was light enough to see. On the bed beside the window lay Jonathan
 * Harker, his face flushed and breathing heavily as though in a stupor.
 * Kneeling on the near edge of the bed facing outwards was the white-clad
 * figure of his wife. By her side stood a tall, thin man, clad in black.
 * His face was turned from us, but the instant we saw we all recognised
 * the Count--in every way, even to the scar on his forehead. With his left
 * hand he held both Mrs. Harker's hands, keeping them away with her arms
 * at full tension; his right hand gripped her by the back of the neck,
 * forcing her face down on his bosom. Her white nightdress was smeared
 * with blood, and a thin stream trickled down the man's bare breast which
 * was shown by his torn-open dress. The attitude of the two had a terrible
 * resemblance to a child forcing a kitten's nose into a saucer of milk to
 * compel it to drink. As we burst into the room, the Count turned his
 * face, and the hellish look that I had heard described seemed to leap
 * into it. His eyes flamed red with devilish passion; the great nostrils
 * of the white aquiline nose opened wide and quivered at the edge; and the
 * white sharp teeth, behind the full lips of the blood-dripping mouth,
 * champed together like those of a wild beast. With a wrench, which threw
 * his victim back upon the bed as though hurled from a height, he turned
 * and sprang at us. But by this time the Professor had gained his feet,
 * and was holding towards him the envelope which contained the Sacred
 * Wafer. The Count suddenly stopped, just as poor Lucy had done outside
 * the tomb, and cowered back. Further and further back he cowered, as we,
 * lifting our crucifixes, advanced. The moonlight suddenly failed, as a
 * great black cloud sailed across the sky; and when the gaslight sprang up
 * under Quincey's match, we saw nothing but a faint vapour. This, as we
 * looked, trailed under the door, which with the recoil from its bursting
 * open, had swung back to its old position. Van Helsing, Art, and I moved
 * forward to Mrs. Harker, who by this time had drawn her breath and with
 * it had given a scream so wild, so ear-piercing, so despairing that it
 * seems to me now that it will ring in my ears till my dying day. For a
 * few seconds she lay in her helpless attitude and disarray. Her face was
 * ghastly, with a pallor which was accentuated by the blood which smeared
 * her lips and cheeks and chin; from her throat trickled a thin stream of
 * blood; her eyes were mad with terror. Then she put before her face her
 * poor crushed hands, which bore on their whiteness the red mark of the
 * Count's terrible grip, and from behind them came a low desolate wail
 * which made the terrible scream seem only the quick expression of an
 * endless grief. Van Helsing stepped forward and drew the coverlet gently
 * over her body, whilst Art, after looking at her face for an instant
 * despairingly, ran out of the room. Van Helsing whispered to me:--
 *
 * "Jonathan is in a stupor such as we know the Vampire can produce. We can
 * do nothing with poor Madam Mina for a few moments till she recovers
 * herself; I must wake him!" He dipped the end of a towel in cold water
 * and with it began to flick him on the face, his wife all the while
 * holding her face between her hands and sobbing in a way that was
 * heart-breaking to hear. I raised the blind, and looked out of the
 * window. There was much moonshine; and as I looked I could see Quincey
 * Morris run across the lawn and hide himself in the shadow of a great
 * yew-tree. It puzzled me to think why he was doing this; but at the
 * instant I heard Harker's quick exclamation as he woke to partial
 * consciousness, and turned to the bed. On his face, as there might well
 * be, was a look of wild amazement. He seemed dazed for a few seconds, and
 * then full consciousness seemed to burst upon him all at once, and he
 * started up. His wife was aroused by the quick movement, and turned to
 * him with her arms stretched out, as though to embrace him; instantly,
 * however, she drew them in again, and putting her elbows together, held
 * her hands before her face, and shuddered till the bed beneath her shook.
 *
 * "In God's name what does this mean?" Harker cried out. "Dr. Seward, Dr.
 * Van Helsing, what is it? What has happened? What is wrong? Mina, dear,
 * what is it? What does that blood mean? My God, my God! has it come to
 * this!" and, raising himself to his knees, he beat his hands wildly
 * together. "Good God help us! help her! oh, help her!" With a quick
 * movement he jumped from bed, and began to pull on his clothes,--all the
 * man in him awake at the need for instant exertion. "What has happened?
 * Tell me all about it!" he cried without pausing. "Dr. Van Helsing, you
 * love Mina, I know. Oh, do something to save her. It cannot have gone too
 * far yet. Guard her while I look for _him_!" His wife, through her terror
 * and horror and distress, saw some sure danger to him: instantly
 * forgetting her own grief, she seized hold of him and cried out:--
 *
 * "No! no! Jonathan, you must not leave me. I have suffered enough
 * to-night, God knows, without the dread of his harming you. You must stay
 * with me. Stay with these friends who will watch over you!" Her
 * expression became frantic as she spoke; and, he yielding to her, she
 * pulled him down sitting on the bed side, and clung to him fiercely.
 *
 * Van Helsing and I tried to calm them both. The Professor held up his
 * little golden crucifix, and said with wonderful calmness:--
 *
 * "Do not fear, my dear. We are here; and whilst this is close to you no
 * foul thing can approach. You are safe for to-night; and we must be calm
 * and take counsel together." She shuddered and was silent, holding down
 * her head on her husband's breast. When she raised it, his white
 * night-robe was stained with blood where her lips had touched, and where
 * the thin open wound in her neck had sent forth drops. The instant she
 * saw it she drew back, with a low wail, and whispered, amidst choking
 * sobs:--
 *
 * "Unclean, unclean! I must touch him or kiss him no more. Oh, that it
 * should be that it is I who am now his worst enemy, and whom he may have
 * most cause to fear." To this he spoke out resolutely:--
 *
 * "Nonsense, Mina. It is a shame to me to hear such a word. I would not
 * hear it of you; and I shall not hear it from you. May God judge me by my
 * deserts, and punish me with more bitter suffering than even this hour,
 * if by any act or will of mine anything ever come between us!" He put out
 * his arms and folded her to his breast; and for a while she lay there
 * sobbing. He looked at us over her bowed head, with eyes that blinked
 * damply above his quivering nostrils; his mouth was set as steel. After a
 * while her sobs became less frequent and more faint, and then he said to
 * me, speaking with a studied calmness which I felt tried his nervous
 * power to the utmost:--
 *
 * "And now, Dr. Seward, tell me all about it. Too well I know the broad
 * fact; tell me all that has been." I told him exactly what had happened,
 * and he listened with seeming impassiveness; but his nostrils twitched
 * and his eyes blazed as I told how the ruthless hands of the Count had
 * held his wife in that terrible and horrid position, with her mouth to
 * the open wound in his breast. It interested me, even at that moment, to
 * see, that, whilst the face of white set passion worked convulsively over
 * the bowed head, the hands tenderly and lovingly stroked the ruffled
 * hair. Just as I had finished, Quincey and Godalming knocked at the door.
 * They entered in obedience to our summons. Van Helsing looked at me
 * questioningly. I understood him to mean if we were to take advantage of
 * their coming to divert if possible the thoughts of the unhappy husband
 * and wife from each other and from themselves; so on nodding acquiescence
 * to him he asked them what they had seen or done. To which Lord Godalming
 * answered:--
 *
 * "I could not see him anywhere in the passage, or in any of our rooms. I
 * looked in the study but, though he had been there, he had gone. He had,
 * however----" He stopped suddenly, looking at the poor drooping figure on
 * the bed. Van Helsing said gravely:--
 *
 * "Go on, friend Arthur. We want here no more concealments. Our hope now
 * is in knowing all. Tell freely!" So Art went on:--
 *
 * "He had been there, and though it could only have been for a few
 * seconds, he made rare hay of the place. All the manuscript had been
 * burned, and the blue flames were flickering amongst the white ashes; the
 * cylinders of your phonograph too were thrown on the fire, and the wax
 * had helped the flames." Here I interrupted. "Thank God there is the
 * other copy in the safe!" His face lit for a moment, but fell again as he
 * went on: "I ran downstairs then, but could see no sign of him. I looked
 * into Renfield's room; but there was no trace there except----!" Again he
 * paused. "Go on," said Harker hoarsely; so he bowed his head and
 * moistening his lips with his tongue, added: "except that the poor fellow
 * is dead." Mrs. Harker raised her head, looking from one to the other of
 * us she said solemnly:--
 *
 * "God's will be done!" I could not but feel that Art was keeping back
 * something; but, as I took it that it was with a purpose, I said nothing.
 * Van Helsing turned to Morris and asked:--
 *
 * "And you, friend Quincey, have you any to tell?"
 *
 * "A little," he answered. "It may be much eventually, but at present I
 * can't say. I thought it well to know if possible where the Count would
 * go when he left the house. I did not see him; but I saw a bat rise from
 * Renfield's window, and flap westward. I expected to see him in some
 * shape go back to Carfax; but he evidently sought some other lair. He
 * will not be back to-night; for the sky is reddening in the east, and the
 * dawn is close. We must work to-morrow!"
 *
 * He said the latter words through his shut teeth. For a space of perhaps
 * a couple of minutes there was silence, and I could fancy that I could
 * hear the sound of our hearts beating; then Van Helsing said, placing his
 * hand very tenderly on Mrs. Harker's head:--
 *
 * "And now, Madam Mina--poor, dear, dear Madam Mina--tell us exactly what
 * happened. God knows that I do not want that you be pained; but it is
 * need that we know all. For now more than ever has all work to be done
 * quick and sharp, and in deadly earnest. The day is close to us that must
 * end all, if it may be so; and now is the chance that we may live and
 * learn."
 *
 * The poor, dear lady shivered, and I could see the tension of her nerves
 * as she clasped her husband closer to her and bent her head lower and
 * lower still on his breast. Then she raised her head proudly, and held
 * out one hand to Van Helsing who took it in his, and, after stooping and
 * kissing it reverently, held it fast. The other hand was locked in that
 * of her husband, who held his other arm thrown round her protectingly.
 * After a pause in which she was evidently ordering her thoughts, she
 * began:--
 *
 * "I took the sleeping draught which you had so kindly given me, but for a
 * long time it did not act. I seemed to become more wakeful, and myriads
 * of horrible fancies began to crowd in upon my mind--all of them
 * connected with death, and vampires; with blood, and pain, and trouble."
 * Her husband involuntarily groaned as she turned to him and said
 * lovingly: "Do not fret, dear. You must be brave and strong, and help me
 * through the horrible task. If you only knew what an effort it is to me
 * to tell of this fearful thing at all, you would understand how much I
 * need your help. Well, I saw I must try to help the medicine to its work
 * with my will, if it was to do me any good, so I resolutely set myself to
 * sleep. Sure enough sleep must soon have come to me, for I remember no
 * more. Jonathan coming in had not waked me, for he lay by my side when
 * next I remember. There was in the room the same thin white mist that I
 * had before noticed. But I forget now if you know of this; you will find
 * it in my diary which I shall show you later. I felt the same vague
 * terror which had come to me before and the same sense of some presence.
 * I turned to wake Jonathan, but found that he slept so soundly that it
 * seemed as if it was he who had taken the sleeping draught, and not I. I
 * tried, but I could not wake him. This caused me a great fear, and I
 * looked around terrified. Then indeed, my heart sank within me: beside
 * the bed, as if he had stepped out of the mist--or rather as if the mist
 * had turned into his figure, for it had entirely disappeared--stood a
 * tall, thin man, all in black. I knew him at once from the description of
 * the others. The waxen face; the high aquiline nose, on which the light
 * fell in a thin white line; the parted red lips, with the sharp white
 * teeth showing between; and the red eyes that I had seemed to see in the
 * sunset on the windows of St. Mary's Church at Whitby. I knew, too, the
 * red scar on his forehead where Jonathan had struck him. For an instant
 * my heart stood still, and I would have screamed out, only that I was
 * paralysed. In the pause he spoke in a sort of keen, cutting whisper,
 * pointing as he spoke to Jonathan:--
 *
 * "'Silence! If you make a sound I shall take him and dash his brains out
 * before your very eyes.' I was appalled and was too bewildered to do or
 * say anything. With a mocking smile, he placed one hand upon my shoulder
 * and, holding me tight, bared my throat with the other, saying as he did
 * so, 'First, a little refreshment to reward my exertions. You may as well
 * be quiet; it is not the first time, or the second, that your veins have
 * appeased my thirst!' I was bewildered, and, strangely enough, I did not
 * want to hinder him. I suppose it is a part of the horrible curse that
 * such is, when his touch is on his victim. And oh, my God, my God, pity
 * me! He placed his reeking lips upon my throat!" Her husband groaned
 * again. She clasped his hand harder, and looked at him pityingly, as if
 * he were the injured one, and went on:--
 *
 * "I felt my strength fading away, and I was in a half swoon. How long
 * this horrible thing lasted I know not; but it seemed that a long time
 * must have passed before he took his foul, awful, sneering mouth away. I
 * saw it drip with the fresh blood!" The remembrance seemed for a while to
 * overpower her, and she drooped and would have sunk down but for her
 * husband's sustaining arm. With a great effort she recovered herself and
 * went on:--
 *
 * "Then he spoke to me mockingly, 'And so you, like the others, would play
 * your brains against mine. You would help these men to hunt me and
 * frustrate me in my designs! You know now, and they know in part already,
 * and will know in full before long, what it is to cross my path. They
 * should have kept their energies for use closer to home. Whilst they
 * played wits against me--against me who commanded nations, and intrigued
 * for them, and fought for them, hundreds of years before they were
 * born--I was countermining them. And you, their best beloved one, are now
 * to me, flesh of my flesh; blood of my blood; kin of my kin; my bountiful
 * wine-press for a while; and shall be later on my companion and my
 * helper. You shall be avenged in turn; for not one of them but shall
 * minister to your needs. But as yet you are to be punished for what you
 * have done. You have aided in thwarting me; now you shall come to my
 * call. When my brain says "Come!" to you, you shall cross land or sea to
 * do my bidding; and to that end this!' With that he pulled open his
 * shirt, and with his long sharp nails opened a vein in his breast. When
 * the blood began to spurt out, he took my hands in one of his, holding
 * them tight, and with the other seized my neck and pressed my mouth to
 * the wound, so that I must either suffocate or swallow some of the---- Oh
 * my God! my God! what have I done? What have I done to deserve such a
 * fate, I who have tried to walk in meekness and righteousness all my
 * days. God pity me! Look down on a poor soul in worse than mortal peril;
 * and in mercy pity those to whom she is dear!" Then she began to rub her
 * lips as though to cleanse them from pollution.
 *
 * As she was telling her terrible story, the eastern sky began to quicken,
 * and everything became more and more clear. Harker was still and quiet;
 * but over his face, as the awful narrative went on, came a grey look
 * which deepened and deepened in the morning light, till when the first
 * red streak of the coming dawn shot up, the flesh stood darkly out
 * against the whitening hair.
 *
 * We have arranged that one of us is to stay within call of the unhappy
 * pair till we can meet together and arrange about taking action.
 *
 * Of this I am sure: the sun rises to-day on no more miserable house in
 * all the great round of its daily course.
 */
#endif // DOXYGEN_TEST_PAGES

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
        /// The second class inside the ``nested::dual_nested`` namespace.
        struct two {
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
 * \page chapter_XXII CHAPTER XXII: Jonathan Harker's Journal
 * JONATHAN HARKER'S JOURNAL
 *
 *
 * _3 October._--As I must do something or go mad, I write this diary. It
 * is now six o'clock, and we are to meet in the study in half an hour and
 * take something to eat; for Dr. Van Helsing and Dr. Seward are agreed
 * that if we do not eat we cannot work our best. Our best will be, God
 * knows, required to-day. I must keep writing at every chance, for I dare
 * not stop to think. All, big and little, must go down; perhaps at the end
 * the little things may teach us most. The teaching, big or little, could
 * not have landed Mina or me anywhere worse than we are to-day. However,
 * we must trust and hope. Poor Mina told me just now, with the tears
 * running down her dear cheeks, that it is in trouble and trial that our
 * faith is tested--that we must keep on trusting; and that God will aid us
 * up to the end. The end! oh my God! what end?... To work! To work!
 *
 * When Dr. Van Helsing and Dr. Seward had come back from seeing poor
 * Renfield, we went gravely into what was to be done. First, Dr. Seward
 * told us that when he and Dr. Van Helsing had gone down to the room below
 * they had found Renfield lying on the floor, all in a heap. His face was
 * all bruised and crushed in, and the bones of the neck were broken.
 *
 * Dr. Seward asked the attendant who was on duty in the passage if he had
 * heard anything. He said that he had been sitting down--he confessed to
 * half dozing--when he heard loud voices in the room, and then Renfield
 * had called out loudly several times, "God! God! God!" after that there
 * was a sound of falling, and when he entered the room he found him lying
 * on the floor, face down, just as the doctors had seen him. Van Helsing
 * asked if he had heard "voices" or "a voice," and he said he could not
 * say; that at first it had seemed to him as if there were two, but as
 * there was no one in the room it could have been only one. He could swear
 * to it, if required, that the word "God" was spoken by the patient. Dr.
 * Seward said to us, when we were alone, that he did not wish to go into
 * the matter; the question of an inquest had to be considered, and it
 * would never do to put forward the truth, as no one would believe it. As
 * it was, he thought that on the attendant's evidence he could give a
 * certificate of death by misadventure in falling from bed. In case the
 * coroner should demand it, there would be a formal inquest, necessarily
 * to the same result.
 *
 * When the question began to be discussed as to what should be our next
 * step, the very first thing we decided was that Mina should be in full
 * confidence; that nothing of any sort--no matter how painful--should be
 * kept from her. She herself agreed as to its wisdom, and it was pitiful
 * to see her so brave and yet so sorrowful, and in such a depth of
 * despair. "There must be no concealment," she said, "Alas! we have had
 * too much already. And besides there is nothing in all the world that can
 * give me more pain than I have already endured--than I suffer now!
 * Whatever may happen, it must be of new hope or of new courage to me!"
 * Van Helsing was looking at her fixedly as she spoke, and said, suddenly
 * but quietly:--
 *
 * "But dear Madam Mina, are you not afraid; not for yourself, but for
 * others from yourself, after what has happened?" Her face grew set in its
 * lines, but her eyes shone with the devotion of a martyr as she
 * answered:--
 *
 * "Ah no! for my mind is made up!"
 *
 * "To what?" he asked gently, whilst we were all very still; for each in
 * our own way we had a sort of vague idea of what she meant. Her answer
 * came with direct simplicity, as though she were simply stating a fact:--
 *
 * "Because if I find in myself--and I shall watch keenly for it--a sign of
 * harm to any that I love, I shall die!"
 *
 * "You would not kill yourself?" he asked, hoarsely.
 *
 * "I would; if there were no friend who loved me, who would save me such a
 * pain, and so desperate an effort!" She looked at him meaningly as she
 * spoke. He was sitting down; but now he rose and came close to her and
 * put his hand on her head as he said solemnly:
 *
 * "My child, there is such an one if it were for your good. For myself I
 * could hold it in my account with God to find such an euthanasia for you,
 * even at this moment if it were best. Nay, were it safe! But my
 * child----" For a moment he seemed choked, and a great sob rose in his
 * throat; he gulped it down and went on:--
 *
 * "There are here some who would stand between you and death. You must not
 * die. You must not die by any hand; but least of all by your own. Until
 * the other, who has fouled your sweet life, is true dead you must not
 * die; for if he is still with the quick Un-Dead, your death would make
 * you even as he is. No, you must live! You must struggle and strive to
 * live, though death would seem a boon unspeakable. You must fight Death
 * himself, though he come to you in pain or in joy; by the day, or the
 * night; in safety or in peril! On your living soul I charge you that you
 * do not die--nay, nor think of death--till this great evil be past." The
 * poor dear grew white as death, and shock and shivered, as I have seen a
 * quicksand shake and shiver at the incoming of the tide. We were all
 * silent; we could do nothing. At length she grew more calm and turning to
 * him said, sweetly, but oh! so sorrowfully, as she held out her hand:--
 *
 * "I promise you, my dear friend, that if God will let me live, I shall
 * strive to do so; till, if it may be in His good time, this horror may
 * have passed away from me." She was so good and brave that we all felt
 * that our hearts were strengthened to work and endure for her, and we
 * began to discuss what we were to do. I told her that she was to have all
 * the papers in the safe, and all the papers or diaries and phonographs we
 * might hereafter use; and was to keep the record as she had done before.
 * She was pleased with the prospect of anything to do--if "pleased" could
 * be used in connection with so grim an interest.
 *
 * As usual Van Helsing had thought ahead of everyone else, and was
 * prepared with an exact ordering of our work.
 *
 * "It is perhaps well," he said, "that at our meeting after our visit to
 * Carfax we decided not to do anything with the earth-boxes that lay
 * there. Had we done so, the Count must have guessed our purpose, and
 * would doubtless have taken measures in advance to frustrate such an
 * effort with regard to the others; but now he does not know our
 * intentions. Nay, more, in all probability, he does not know that such a
 * power exists to us as can sterilise his lairs, so that he cannot use
 * them as of old. We are now so much further advanced in our knowledge as
 * to their disposition that, when we have examined the house in
 * Piccadilly, we may track the very last of them. To-day, then, is ours;
 * and in it rests our hope. The sun that rose on our sorrow this morning
 * guards us in its course. Until it sets to-night, that monster must
 * retain whatever form he now has. He is confined within the limitations
 * of his earthly envelope. He cannot melt into thin air nor disappear
 * through cracks or chinks or crannies. If he go through a doorway, he
 * must open the door like a mortal. And so we have this day to hunt out
 * all his lairs and sterilise them. So we shall, if we have not yet catch
 * him and destroy him, drive him to bay in some place where the catching
 * and the destroying shall be, in time, sure." Here I started up for I
 * could not contain myself at the thought that the minutes and seconds so
 * preciously laden with Mina's life and happiness were flying from us,
 * since whilst we talked action was impossible. But Van Helsing held up
 * his hand warningly. "Nay, friend Jonathan," he said, "in this, the
 * quickest way home is the longest way, so your proverb say. We shall all
 * act and act with desperate quick, when the time has come. But think, in
 * all probable the key of the situation is in that house in Piccadilly.
 * The Count may have many houses which he has bought. Of them he will have
 * deeds of purchase, keys and other things. He will have paper that he
 * write on; he will have his book of cheques. There are many belongings
 * that he must have somewhere; why not in this place so central, so quiet,
 * where he come and go by the front or the back at all hour, when in the
 * very vast of the traffic there is none to notice. We shall go there and
 * search that house; and when we learn what it holds, then we do what our
 * friend Arthur call, in his phrases of hunt 'stop the earths' and so we
 * run down our old fox--so? is it not?"
 *
 * "Then let us come at once," I cried, "we are wasting the precious,
 * precious time!" The Professor did not move, but simply said:--
 *
 * "And how are we to get into that house in Piccadilly?"
 *
 * "Any way!" I cried. "We shall break in if need be."
 *
 * "And your police; where will they be, and what will they say?"
 *
 * I was staggered; but I knew that if he wished to delay he had a good
 * reason for it. So I said, as quietly as I could:--
 *
 * "Don't wait more than need be; you know, I am sure, what torture I am
 * in."
 *
 * "Ah, my child, that I do; and indeed there is no wish of me to add to
 * your anguish. But just think, what can we do, until all the world be at
 * movement. Then will come our time. I have thought and thought, and it
 * seems to me that the simplest way is the best of all. Now we wish to get
 * into the house, but we have no key; is it not so?" I nodded.
 *
 * "Now suppose that you were, in truth, the owner of that house, and could
 * not still get it; and think there was to you no conscience of the
 * housebreaker, what would you do?"
 *
 * "I should get a respectable locksmith, and set him to work to pick the
 * lock for me."
 *
 * "And your police, they would interfere, would they not?"
 *
 * "Oh, no! not if they knew the man was properly employed."
 *
 * "Then," he looked at me as keenly as he spoke, "all that is in doubt is
 * the conscience of the employer, and the belief of your policemen as to
 * whether or no that employer has a good conscience or a bad one. Your
 * police must indeed be zealous men and clever--oh, so clever!--in reading
 * the heart, that they trouble themselves in such matter. No, no, my
 * friend Jonathan, you go take the lock off a hundred empty house in this
 * your London, or of any city in the world; and if you do it as such
 * things are rightly done, and at the time such things are rightly done,
 * no one will interfere. I have read of a gentleman who owned a so fine
 * house in London, and when he went for months of summer to Switzerland
 * and lock up his house, some burglar came and broke window at back and
 * got in. Then he went and made open the shutters in front and walk out
 * and in through the door, before the very eyes of the police. Then he
 * have an auction in that house, and advertise it, and put up big notice;
 * and when the day come he sell off by a great auctioneer all the goods of
 * that other man who own them. Then he go to a builder, and he sell him
 * that house, making an agreement that he pull it down and take all away
 * within a certain time. And your police and other authority help him all
 * they can. And when that owner come back from his holiday in Switzerland
 * he find only an empty hole where his house had been. This was all done
 * _en règle_; and in our work we shall be _en règle_ too. We shall not go
 * so early that the policemen who have then little to think of, shall deem
 * it strange; but we shall go after ten o'clock, when there are many
 * about, and such things would be done were we indeed owners of the
 * house."
 *
 * I could not but see how right he was and the terrible despair of Mina's
 * face became relaxed a thought; there was hope in such good counsel. Van
 * Helsing went on:--
 *
 * "When once within that house we may find more clues; at any rate some of
 * us can remain there whilst the rest find the other places where there be
 * more earth-boxes--at Bermondsey and Mile End."
 *
 * Lord Godalming stood up. "I can be of some use here," he said. "I shall
 * wire to my people to have horses and carriages where they will be most
 * convenient."
 *
 * "Look here, old fellow," said Morris, "it is a capital idea to have all
 * ready in case we want to go horsebacking; but don't you think that one
 * of your snappy carriages with its heraldic adornments in a byway of
 * Walworth or Mile End would attract too much attention for our purposes?
 * It seems to me that we ought to take cabs when we go south or east; and
 * even leave them somewhere near the neighbourhood we are going to."
 *
 * "Friend Quincey is right!" said the Professor. "His head is what you
 * call in plane with the horizon. It is a difficult thing that we go to
 * do, and we do not want no peoples to watch us if so it may."
 *
 * Mina took a growing interest in everything and I was rejoiced to see
 * that the exigency of affairs was helping her to forget for a time the
 * terrible experience of the night. She was very, very pale--almost
 * ghastly, and so thin that her lips were drawn away, showing her teeth in
 * somewhat of prominence. I did not mention this last, lest it should give
 * her needless pain; but it made my blood run cold in my veins to think of
 * what had occurred with poor Lucy when the Count had sucked her blood. As
 * yet there was no sign of the teeth growing sharper; but the time as yet
 * was short, and there was time for fear.
 *
 * When we came to the discussion of the sequence of our efforts and of the
 * disposition of our forces, there were new sources of doubt. It was
 * finally agreed that before starting for Piccadilly we should destroy the
 * Count's lair close at hand. In case he should find it out too soon, we
 * should thus be still ahead of him in our work of destruction; and his
 * presence in his purely material shape, and at his weakest, might give us
 * some new clue.
 *
 * As to the disposal of forces, it was suggested by the Professor that,
 * after our visit to Carfax, we should all enter the house in Piccadilly;
 * that the two doctors and I should remain there, whilst Lord Godalming
 * and Quincey found the lairs at Walworth and Mile End and destroyed them.
 * It was possible, if not likely, the Professor urged, that the Count
 * might appear in Piccadilly during the day, and that if so we might be
 * able to cope with him then and there. At any rate, we might be able to
 * follow him in force. To this plan I strenuously objected, and so far as
 * my going was concerned, for I said that I intended to stay and protect
 * Mina, I thought that my mind was made up on the subject; but Mina would
 * not listen to my objection. She said that there might be some law matter
 * in which I could be useful; that amongst the Count's papers might be
 * some clue which I could understand out of my experience in Transylvania;
 * and that, as it was, all the strength we could muster was required to
 * cope with the Count's extraordinary power. I had to give in, for Mina's
 * resolution was fixed; she said that it was the last hope for _her_ that
 * we should all work together. "As for me," she said, "I have no fear.
 * Things have been as bad as they can be; and whatever may happen must
 * have in it some element of hope or comfort. Go, my husband! God can, if
 * He wishes it, guard me as well alone as with any one present." So I
 * started up crying out: "Then in God's name let us come at once, for we
 * are losing time. The Count may come to Piccadilly earlier than we
 * think."
 *
 * "Not so!" said Van Helsing, holding up his hand.
 *
 * "But why?" I asked.
 *
 * "Do you forget," he said, with actually a smile, "that last night he
 * banqueted heavily, and will sleep late?"
 *
 * Did I forget! shall I ever--can I ever! Can any of us ever forget that
 * terrible scene! Mina struggled hard to keep her brave countenance; but
 * the pain overmastered her and she put her hands before her face, and
 * shuddered whilst she moaned. Van Helsing had not intended to recall her
 * frightful experience. He had simply lost sight of her and her part in
 * the affair in his intellectual effort. When it struck him what he said,
 * he was horrified at his thoughtlessness and tried to comfort her. "Oh,
 * Madam Mina," he said, "dear, dear Madam Mina, alas! that I of all who so
 * reverence you should have said anything so forgetful. These stupid old
 * lips of mine and this stupid old head do not deserve so; but you will
 * forget it, will you not?" He bent low beside her as he spoke; she took
 * his hand, and looking at him through her tears, said hoarsely:--
 *
 * "No, I shall not forget, for it is well that I remember; and with it I
 * have so much in memory of you that is sweet, that I take it all
 * together. Now, you must all be going soon. Breakfast is ready, and we
 * must all eat that we may be strong."
 *
 * Breakfast was a strange meal to us all. We tried to be cheerful and
 * encourage each other, and Mina was the brightest and most cheerful of
 * us. When it was over, Van Helsing stood up and said:--
 *
 * "Now, my dear friends, we go forth to our terrible enterprise. Are we
 * all armed, as we were on that night when first we visited our enemy's
 * lair; armed against ghostly as well as carnal attack?" We all assured
 * him. "Then it is well. Now, Madam Mina, you are in any case _quite_ safe
 * here until the sunset; and before then we shall return--if---- We shall
 * return! But before we go let me see you armed against personal attack. I
 * have myself, since you came down, prepared your chamber by the placing
 * of things of which we know, so that He may not enter. Now let me guard
 * yourself. On your forehead I touch this piece of Sacred Wafer in the
 * name of the Father, the Son, and----"
 *
 * There was a fearful scream which almost froze our hearts to hear. As he
 * had placed the Wafer on Mina's forehead, it had seared it--had burned
 * into the flesh as though it had been a piece of white-hot metal. My poor
 * darling's brain had told her the significance of the fact as quickly as
 * her nerves received the pain of it; and the two so overwhelmed her that
 * her overwrought nature had its voice in that dreadful scream. But the
 * words to her thought came quickly; the echo of the scream had not ceased
 * to ring on the air when there came the reaction, and she sank on her
 * knees on the floor in an agony of abasement. Pulling her beautiful hair
 * over her face, as the leper of old his mantle, she wailed out:--
 *
 * "Unclean! Unclean! Even the Almighty shuns my polluted flesh! I must
 * bear this mark of shame upon my forehead until the Judgment Day." They
 * all paused. I had thrown myself beside her in an agony of helpless
 * grief, and putting my arms around held her tight. For a few minutes our
 * sorrowful hearts beat together, whilst the friends around us turned away
 * their eyes that ran tears silently. Then Van Helsing turned and said
 * gravely; so gravely that I could not help feeling that he was in some
 * way inspired, and was stating things outside himself:--
 *
 * "It may be that you may have to bear that mark till God himself see fit,
 * as He most surely shall, on the Judgment Day, to redress all wrongs of
 * the earth and of His children that He has placed thereon. And oh, Madam
 * Mina, my dear, my dear, may we who love you be there to see, when that
 * red scar, the sign of God's knowledge of what has been, shall pass away,
 * and leave your forehead as pure as the heart we know. For so surely as
 * we live, that scar shall pass away when God sees right to lift the
 * burden that is hard upon us. Till then we bear our Cross, as His Son did
 * in obedience to His Will. It may be that we are chosen instruments of
 * His good pleasure, and that we ascend to His bidding as that other
 * through stripes and shame; through tears and blood; through doubts and
 * fears, and all that makes the difference between God and man."
 *
 * There was hope in his words, and comfort; and they made for resignation.
 * Mina and I both felt so, and simultaneously we each took one of the old
 * man's hands and bent over and kissed it. Then without a word we all
 * knelt down together, and, all holding hands, swore to be true to each
 * other. We men pledged ourselves to raise the veil of sorrow from the
 * head of her whom, each in his own way, we loved; and we prayed for help
 * and guidance in the terrible task which lay before us.
 *
 * It was then time to start. So I said farewell to Mina, a parting which
 * neither of us shall forget to our dying day; and we set out.
 *
 * To one thing I have made up my mind: if we find out that Mina must be a
 * vampire in the end, then she shall not go into that unknown and terrible
 * land alone. I suppose it is thus that in old times one vampire meant
 * many; just as their hideous bodies could only rest in sacred earth, so
 * the holiest love was the recruiting sergeant for their ghastly ranks.
 *
 * We entered Carfax without trouble and found all things the same as on
 * the first occasion. It was hard to believe that amongst so prosaic
 * surroundings of neglect and dust and decay there was any ground for such
 * fear as already we knew. Had not our minds been made up, and had there
 * not been terrible memories to spur us on, we could hardly have proceeded
 * with our task. We found no papers, or any sign of use in the house; and
 * in the old chapel the great boxes looked just as we had seen them last.
 * Dr. Van Helsing said to us solemnly as we stood before them:--
 *
 * "And now, my friends, we have a duty here to do. We must sterilise this
 * earth, so sacred of holy memories, that he has brought from a far
 * distant land for such fell use. He has chosen this earth because it has
 * been holy. Thus we defeat him with his own weapon, for we make it more
 * holy still. It was sanctified to such use of man, now we sanctify it to
 * God." As he spoke he took from his bag a screwdriver and a wrench, and
 * very soon the top of one of the cases was thrown open. The earth smelled
 * musty and close; but we did not somehow seem to mind, for our attention
 * was concentrated on the Professor. Taking from his box a piece of the
 * Sacred Wafer he laid it reverently on the earth, and then shutting down
 * the lid began to screw it home, we aiding him as he worked.
 *
 * One by one we treated in the same way each of the great boxes, and left
 * them as we had found them to all appearance; but in each was a portion
 * of the Host.
 *
 * When we closed the door behind us, the Professor said solemnly:--
 *
 * "So much is already done. If it may be that with all the others we can
 * be so successful, then the sunset of this evening may shine on Madam
 * Mina's forehead all white as ivory and with no stain!"
 *
 * As we passed across the lawn on our way to the station to catch our
 * train we could see the front of the asylum. I looked eagerly, and in the
 * window of my own room saw Mina. I waved my hand to her, and nodded to
 * tell that our work there was successfully accomplished. She nodded in
 * reply to show that she understood. The last I saw, she was waving her
 * hand in farewell. It was with a heavy heart that we sought the station
 * and just caught the train, which was steaming in as we reached the
 * platform.
 *
 * I have written this in the train.
 *
 *        *       *       *       *       *
 *
 * _Piccadilly, 12:30 o'clock._--Just before we reached Fenchurch Street
 * Lord Godalming said to me:--
 *
 * "Quincey and I will find a locksmith. You had better not come with us in
 * case there should be any difficulty; for under the circumstances it
 * wouldn't seem so bad for us to break into an empty house. But you are a
 * solicitor and the Incorporated Law Society might tell you that you
 * should have known better." I demurred as to my not sharing any danger
 * even of odium, but he went on: "Besides, it will attract less attention
 * if there are not too many of us. My title will make it all right with
 * the locksmith, and with any policeman that may come along. You had
 * better go with Jack and the Professor and stay in the Green Park,
 * somewhere in sight of the house; and when you see the door opened and
 * the smith has gone away, do you all come across. We shall be on the
 * lookout for you, and shall let you in."
 *
 * "The advice is good!" said Van Helsing, so we said no more. Godalming
 * and Morris hurried off in a cab, we following in another. At the corner
 * of Arlington Street our contingent got out and strolled into the Green
 * Park. My heart beat as I saw the house on which so much of our hope was
 * centred, looming up grim and silent in its deserted condition amongst
 * its more lively and spruce-looking neighbours. We sat down on a bench
 * within good view, and began to smoke cigars so as to attract as little
 * attention as possible. The minutes seemed to pass with leaden feet as we
 * waited for the coming of the others.
 *
 * At length we saw a four-wheeler drive up. Out of it, in leisurely
 * fashion, got Lord Godalming and Morris; and down from the box descended
 * a thick-set working man with his rush-woven basket of tools. Morris paid
 * the cabman, who touched his hat and drove away. Together the two
 * ascended the steps, and Lord Godalming pointed out what he wanted done.
 * The workman took off his coat leisurely and hung it on one of the spikes
 * of the rail, saying something to a policeman who just then sauntered
 * along. The policeman nodded acquiescence, and the man kneeling down
 * placed his bag beside him. After searching through it, he took out a
 * selection of tools which he produced to lay beside him in orderly
 * fashion. Then he stood up, looked into the keyhole, blew into it, and
 * turning to his employers, made some remark. Lord Godalming smiled, and
 * the man lifted a good-sized bunch of keys; selecting one of them, he
 * began to probe the lock, as if feeling his way with it. After fumbling
 * about for a bit he tried a second, and then a third. All at once the
 * door opened under a slight push from him, and he and the two others
 * entered the hall. We sat still; my own cigar burnt furiously, but Van
 * Helsing's went cold altogether. We waited patiently as we saw the
 * workman come out and bring in his bag. Then he held the door partly
 * open, steadying it with his knees, whilst he fitted a key to the lock.
 * This he finally handed to Lord Godalming, who took out his purse and
 * gave him something. The man touched his hat, took his bag, put on his
 * coat and departed; not a soul took the slightest notice of the whole
 * transaction.
 *
 * When the man had fairly gone, we three crossed the street and knocked at
 * the door. It was immediately opened by Quincey Morris, beside whom stood
 * Lord Godalming lighting a cigar.
 *
 * "The place smells so vilely," said the latter as we came in. It did
 * indeed smell vilely--like the old chapel at Carfax--and with our
 * previous experience it was plain to us that the Count had been using the
 * place pretty freely. We moved to explore the house, all keeping together
 * in case of attack; for we knew we had a strong and wily enemy to deal
 * with, and as yet we did not know whether the Count might not be in the
 * house. In the dining-room, which lay at the back of the hall, we found
 * eight boxes of earth. Eight boxes only out of the nine, which we sought!
 * Our work was not over, and would never be until we should have found the
 * missing box. First we opened the shutters of the window which looked out
 * across a narrow stone-flagged yard at the blank face of a stable,
 * pointed to look like the front of a miniature house. There were no
 * windows in it, so we were not afraid of being over-looked. We did not
 * lose any time in examining the chests. With the tools which we had
 * brought with us we opened them, one by one, and treated them as we had
 * treated those others in the old chapel. It was evident to us that the
 * Count was not at present in the house, and we proceeded to search for
 * any of his effects.
 *
 * After a cursory glance at the rest of the rooms, from basement to attic,
 * we came to the conclusion that the dining-room contained any effects
 * which might belong to the Count; and so we proceeded to minutely examine
 * them. They lay in a sort of orderly disorder on the great dining-room
 * table. There were title deeds of the Piccadilly house in a great bundle;
 * deeds of the purchase of the houses at Mile End and Bermondsey;
 * note-paper, envelopes, and pens and ink. All were covered up in thin
 * wrapping paper to keep them from the dust. There were also a clothes
 * brush, a brush and comb, and a jug and basin--the latter containing
 * dirty water which was reddened as if with blood. Last of all was a
 * little heap of keys of all sorts and sizes, probably those belonging to
 * the other houses. When we had examined this last find, Lord Godalming
 * and Quincey Morris taking accurate notes of the various addresses of the
 * houses in the East and the South, took with them the keys in a great
 * bunch, and set out to destroy the boxes in these places. The rest of us
 * are, with what patience we can, waiting their return--or the coming of
 * the Count.
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
 * \page chapter_XXIII CHAPTER XXIII: Dr. Seward's Diary
 * DR. SEWARD'S DIARY
 *
 *
 * _3 October._--The time seemed terrible long whilst we were waiting for
 * the coming of Godalming and Quincey Morris. The Professor tried to keep
 * our minds active by using them all the time. I could see his beneficent
 * purpose, by the side glances which he threw from time to time at Harker.
 * The poor fellow is overwhelmed in a misery that is appalling to see.
 * Last night he was a frank, happy-looking man, with strong, youthful
 * face, full of energy, and with dark brown hair. To-day he is a drawn,
 * haggard old man, whose white hair matches well with the hollow burning
 * eyes and grief-written lines of his face. His energy is still intact; in
 * fact, he is like a living flame. This may yet be his salvation, for, if
 * all go well, it will tide him over the despairing period; he will then,
 * in a kind of way, wake again to the realities of life. Poor fellow, I
 * thought my own trouble was bad enough, but his----! The Professor knows
 * this well enough, and is doing his best to keep his mind active. What he
 * has been saying was, under the circumstances, of absorbing interest. So
 * well as I can remember, here it is:--
 *
 * "I have studied, over and over again since they came into my hands, all
 * the papers relating to this monster; and the more I have studied, the
 * greater seems the necessity to utterly stamp him out. All through there
 * are signs of his advance; not only of his power, but of his knowledge of
 * it. As I learned from the researches of my friend Arminus of Buda-Pesth,
 * he was in life a most wonderful man. Soldier, statesman, and
 * alchemist--which latter was the highest development of the
 * science-knowledge of his time. He had a mighty brain, a learning beyond
 * compare, and a heart that knew no fear and no remorse. He dared even to
 * attend the Scholomance, and there was no branch of knowledge of his time
 * that he did not essay. Well, in him the brain powers survived the
 * physical death; though it would seem that memory was not all complete.
 * In some faculties of mind he has been, and is, only a child; but he is
 * growing, and some things that were childish at the first are now of
 * man's stature. He is experimenting, and doing it well; and if it had not
 * been that we have crossed his path he would be yet--he may be yet if we
 * fail--the father or furtherer of a new order of beings, whose road must
 * lead through Death, not Life."
 *
 * Harker groaned and said, "And this is all arrayed against my darling!
 * But how is he experimenting? The knowledge may help us to defeat him!"
 *
 * "He has all along, since his coming, been trying his power, slowly but
 * surely; that big child-brain of his is working. Well for us, it is, as
 * yet, a child-brain; for had he dared, at the first, to attempt certain
 * things he would long ago have been beyond our power. However, he means
 * to succeed, and a man who has centuries before him can afford to wait
 * and to go slow. _Festina lente_ may well be his motto."
 *
 * "I fail to understand," said Harker wearily. "Oh, do be more plain to
 * me! Perhaps grief and trouble are dulling my brain."
 *
 * The Professor laid his hand tenderly on his shoulder as he spoke:--
 *
 * "Ah, my child, I will be plain. Do you not see how, of late, this
 * monster has been creeping into knowledge experimentally. How he has been
 * making use of the zoöphagous patient to effect his entry into friend
 * John's home; for your Vampire, though in all afterwards he can come when
 * and how he will, must at the first make entry only when asked thereto by
 * an inmate. But these are not his most important experiments. Do we not
 * see how at the first all these so great boxes were moved by others. He
 * knew not then but that must be so. But all the time that so great
 * child-brain of his was growing, and he began to consider whether he
 * might not himself move the box. So he began to help; and then, when he
 * found that this be all-right, he try to move them all alone. And so he
 * progress, and he scatter these graves of him; and none but he know where
 * they are hidden. He may have intend to bury them deep in the ground. So
 * that he only use them in the night, or at such time as he can change his
 * form, they do him equal well; and none may know these are his
 * hiding-place! But, my child, do not despair; this knowledge come to him
 * just too late! Already all of his lairs but one be sterilise as for him;
 * and before the sunset this shall be so. Then he have no place where he
 * can move and hide. I delayed this morning that so we might be sure. Is
 * there not more at stake for us than for him? Then why we not be even
 * more careful than him? By my clock it is one hour and already, if all be
 * well, friend Arthur and Quincey are on their way to us. To-day is our
 * day, and we must go sure, if slow, and lose no chance. See! there are
 * five of us when those absent ones return."
 *
 * Whilst he was speaking we were startled by a knock at the hall door, the
 * double postman's knock of the telegraph boy. We all moved out to the
 * hall with one impulse, and Van Helsing, holding up his hand to us to
 * keep silence, stepped to the door and opened it. The boy handed in a
 * despatch. The Professor closed the door again, and, after looking at the
 * direction, opened it and read aloud.
 *
 * "Look out for D. He has just now, 12:45, come from Carfax hurriedly and
 * hastened towards the South. He seems to be going the round and may want
 * to see you: Mina."
 *
 * There was a pause, broken by Jonathan Harker's voice:--
 *
 * "Now, God be thanked, we shall soon meet!" Van Helsing turned to him
 * quickly and said:--
 *
 * "God will act in His own way and time. Do not fear, and do not rejoice
 * as yet; for what we wish for at the moment may be our undoings."
 *
 * "I care for nothing now," he answered hotly, "except to wipe out this
 * brute from the face of creation. I would sell my soul to do it!"
 *
 * "Oh, hush, hush, my child!" said Van Helsing. "God does not purchase
 * souls in this wise; and the Devil, though he may purchase, does not keep
 * faith. But God is merciful and just, and knows your pain and your
 * devotion to that dear Madam Mina. Think you, how her pain would be
 * doubled, did she but hear your wild words. Do not fear any of us, we are
 * all devoted to this cause, and to-day shall see the end. The time is
 * coming for action; to-day this Vampire is limit to the powers of man,
 * and till sunset he may not change. It will take him time to arrive
 * here--see, it is twenty minutes past one--and there are yet some times
 * before he can hither come, be he never so quick. What we must hope for
 * is that my Lord Arthur and Quincey arrive first."
 *
 * About half an hour after we had received Mrs. Harker's telegram, there
 * came a quiet, resolute knock at the hall door. It was just an ordinary
 * knock, such as is given hourly by thousands of gentlemen, but it made
 * the Professor's heart and mine beat loudly. We looked at each other, and
 * together moved out into the hall; we each held ready to use our various
 * armaments--the spiritual in the left hand, the mortal in the right. Van
 * Helsing pulled back the latch, and, holding the door half open, stood
 * back, having both hands ready for action. The gladness of our hearts
 * must have shown upon our faces when on the step, close to the door, we
 * saw Lord Godalming and Quincey Morris. They came quickly in and closed
 * the door behind them, the former saying, as they moved along the
 * hall:--
 *
 * "It is all right. We found both places; six boxes in each and we
 * destroyed them all!"
 *
 * "Destroyed?" asked the Professor.
 *
 * "For him!" We were silent for a minute, and then Quincey said:--
 *
 * "There's nothing to do but to wait here. If, however, he doesn't turn up
 * by five o'clock, we must start off; for it won't do to leave Mrs. Harker
 * alone after sunset."
 *
 * "He will be here before long now," said Van Helsing, who had been
 * consulting his pocket-book. "_Nota bene_, in Madam's telegram he went
 * south from Carfax, that means he went to cross the river, and he could
 * only do so at slack of tide, which should be something before one
 * o'clock. That he went south has a meaning for us. He is as yet only
 * suspicious; and he went from Carfax first to the place where he would
 * suspect interference least. You must have been at Bermondsey only a
 * short time before him. That he is not here already shows that he went to
 * Mile End next. This took him some time; for he would then have to be
 * carried over the river in some way. Believe me, my friends, we shall not
 * have long to wait now. We should have ready some plan of attack, so that
 * we may throw away no chance. Hush, there is no time now. Have all your
 * arms! Be ready!" He held up a warning hand as he spoke, for we all could
 * hear a key softly inserted in the lock of the hall door.
 *
 * I could not but admire, even at such a moment, the way in which a
 * dominant spirit asserted itself. In all our hunting parties and
 * adventures in different parts of the world, Quincey Morris had always
 * been the one to arrange the plan of action, and Arthur and I had been
 * accustomed to obey him implicitly. Now, the old habit seemed to be
 * renewed instinctively. With a swift glance around the room, he at once
 * laid out our plan of attack, and, without speaking a word, with a
 * gesture, placed us each in position. Van Helsing, Harker, and I were
 * just behind the door, so that when it was opened the Professor could
 * guard it whilst we two stepped between the incomer and the door.
 * Godalming behind and Quincey in front stood just out of sight ready to
 * move in front of the window. We waited in a suspense that made the
 * seconds pass with nightmare slowness. The slow, careful steps came along
 * the hall; the Count was evidently prepared for some surprise--at least
 * he feared it.
 *
 * Suddenly with a single bound he leaped into the room, winning a way past
 * us before any of us could raise a hand to stay him. There was something
 * so panther-like in the movement--something so unhuman, that it seemed
 * to sober us all from the shock of his coming. The first to act was
 * Harker, who, with a quick movement, threw himself before the door
 * leading into the room in the front of the house. As the Count saw us, a
 * horrible sort of snarl passed over his face, showing the eye-teeth long
 * and pointed; but the evil smile as quickly passed into a cold stare of
 * lion-like disdain. His expression again changed as, with a single
 * impulse, we all advanced upon him. It was a pity that we had not some
 * better organised plan of attack, for even at the moment I wondered what
 * we were to do. I did not myself know whether our lethal weapons would
 * avail us anything. Harker evidently meant to try the matter, for he had
 * ready his great Kukri knife and made a fierce and sudden cut at him. The
 * blow was a powerful one; only the diabolical quickness of the Count's
 * leap back saved him. A second less and the trenchant blade had shorne
 * through his heart. As it was, the point just cut the cloth of his coat,
 * making a wide gap whence a bundle of bank-notes and a stream of gold
 * fell out. The expression of the Count's face was so hellish, that for a
 * moment I feared for Harker, though I saw him throw the terrible knife
 * aloft again for another stroke. Instinctively I moved forward with a
 * protective impulse, holding the Crucifix and Wafer in my left hand. I
 * felt a mighty power fly along my arm; and it was without surprise that I
 * saw the monster cower back before a similar movement made spontaneously
 * by each one of us. It would be impossible to describe the expression of
 * hate and baffled malignity--of anger and hellish rage--which came over
 * the Count's face. His waxen hue became greenish-yellow by the contrast
 * of his burning eyes, and the red scar on the forehead showed on the
 * pallid skin like a palpitating wound. The next instant, with a sinuous
 * dive he swept under Harker's arm, ere his blow could fall, and, grasping
 * a handful of the money from the floor, dashed across the room, threw
 * himself at the window. Amid the crash and glitter of the falling glass,
 * he tumbled into the flagged area below. Through the sound of the
 * shivering glass I could hear the "ting" of the gold, as some of the
 * sovereigns fell on the flagging.
 *
 * We ran over and saw him spring unhurt from the ground. He, rushing up
 * the steps, crossed the flagged yard, and pushed open the stable door.
 * There he turned and spoke to us:--
 *
 * "You think to baffle me, you--with your pale faces all in a row, like
 * sheep in a butcher's. You shall be sorry yet, each one of you! You think
 * you have left me without a place to rest; but I have more. My revenge is
 * just begun! I spread it over centuries, and time is on my side. Your
 * girls that you all love are mine already; and through them you and
 * others shall yet be mine--my creatures, to do my bidding and to be my
 * jackals when I want to feed. Bah!" With a contemptuous sneer, he passed
 * quickly through the door, and we heard the rusty bolt creak as he
 * fastened it behind him. A door beyond opened and shut. The first of us
 * to speak was the Professor, as, realising the difficulty of following
 * him through the stable, we moved toward the hall.
 *
 * "We have learnt something--much! Notwithstanding his brave words, he
 * fears us; he fear time, he fear want! For if not, why he hurry so? His
 * very tone betray him, or my ears deceive. Why take that money? You
 * follow quick. You are hunters of wild beast, and understand it so. For
 * me, I make sure that nothing here may be of use to him, if so that he
 * return." As he spoke he put the money remaining into his pocket; took
 * the title-deeds in the bundle as Harker had left them, and swept the
 * remaining things into the open fireplace, where he set fire to them with
 * a match.
 *
 * Godalming and Morris had rushed out into the yard, and Harker had
 * lowered himself from the window to follow the Count. He had, however,
 * bolted the stable door; and by the time they had forced it open there
 * was no sign of him. Van Helsing and I tried to make inquiry at the back
 * of the house; but the mews was deserted and no one had seen him depart.
 *
 * It was now late in the afternoon, and sunset was not far off. We had to
 * recognise that our game was up; with heavy hearts we agreed with the
 * Professor when he said:--
 *
 * "Let us go back to Madam Mina--poor, poor dear Madam Mina. All we can do
 * just now is done; and we can there, at least, protect her. But we need
 * not despair. There is but one more earth-box, and we must try to find
 * it; when that is done all may yet be well." I could see that he spoke as
 * bravely as he could to comfort Harker. The poor fellow was quite broken
 * down; now and again he gave a low groan which he could not suppress--he
 * was thinking of his wife.
 *
 * With sad hearts we came back to my house, where we found Mrs. Harker
 * waiting us, with an appearance of cheerfulness which did honour to her
 * bravery and unselfishness. When she saw our faces, her own became as
 * pale as death: for a second or two her eyes were closed as if she were
 * in secret prayer; and then she said cheerfully:--
 *
 * "I can never thank you all enough. Oh, my poor darling!" As she spoke,
 * she took her husband's grey head in her hands and kissed it--"Lay your
 * poor head here and rest it. All will yet be well, dear! God will protect
 * us if He so will it in His good intent." The poor fellow groaned. There
 * was no place for words in his sublime misery.
 *
 * We had a sort of perfunctory supper together, and I think it cheered us
 * all up somewhat. It was, perhaps, the mere animal heat of food to hungry
 * people--for none of us had eaten anything since breakfast--or the sense
 * of companionship may have helped us; but anyhow we were all less
 * miserable, and saw the morrow as not altogether without hope. True to
 * our promise, we told Mrs. Harker everything which had passed; and
 * although she grew snowy white at times when danger had seemed to
 * threaten her husband, and red at others when his devotion to her was
 * manifested, she listened bravely and with calmness. When we came to the
 * part where Harker had rushed at the Count so recklessly, she clung to
 * her husband's arm, and held it tight as though her clinging could
 * protect him from any harm that might come. She said nothing, however,
 * till the narration was all done, and matters had been brought right up
 * to the present time. Then without letting go her husband's hand she
 * stood up amongst us and spoke. Oh, that I could give any idea of the
 * scene; of that sweet, sweet, good, good woman in all the radiant beauty
 * of her youth and animation, with the red scar on her forehead, of which
 * she was conscious, and which we saw with grinding of our
 * teeth--remembering whence and how it came; her loving kindness against
 * our grim hate; her tender faith against all our fears and doubting; and
 * we, knowing that so far as symbols went, she with all her goodness and
 * purity and faith, was outcast from God.
 *
 * "Jonathan," she said, and the word sounded like music on her lips it was
 * so full of love and tenderness, "Jonathan dear, and you all my true,
 * true friends, I want you to bear something in mind through all this
 * dreadful time. I know that you must fight--that you must destroy even as
 * you destroyed the false Lucy so that the true Lucy might live hereafter;
 * but it is not a work of hate. That poor soul who has wrought all this
 * misery is the saddest case of all. Just think what will be his joy when
 * he, too, is destroyed in his worser part that his better part may have
 * spiritual immortality. You must be pitiful to him, too, though it may
 * not hold your hands from his destruction."
 *
 * As she spoke I could see her husband's face darken and draw together, as
 * though the passion in him were shrivelling his being to its core.
 * Instinctively the clasp on his wife's hand grew closer, till his
 * knuckles looked white. She did not flinch from the pain which I knew she
 * must have suffered, but looked at him with eyes that were more appealing
 * than ever. As she stopped speaking he leaped to his feet, almost tearing
 * his hand from hers as he spoke:--
 *
 * "May God give him into my hand just for long enough to destroy that
 * earthly life of him which we are aiming at. If beyond it I could send
 * his soul for ever and ever to burning hell I would do it!"
 *
 * "Oh, hush! oh, hush! in the name of the good God. Don't say such things,
 * Jonathan, my husband; or you will crush me with fear and horror. Just
 * think, my dear--I have been thinking all this long, long day of it--that
 * ... perhaps ... some day ... I, too, may need such pity; and that some
 * other like you--and with equal cause for anger--may deny it to me! Oh,
 * my husband! my husband, indeed I would have spared you such a thought
 * had there been another way; but I pray that God may not have treasured
 * your wild words, except as the heart-broken wail of a very loving and
 * sorely stricken man. Oh, God, let these poor white hairs go in evidence
 * of what he has suffered, who all his life has done no wrong, and on whom
 * so many sorrows have come."
 *
 * We men were all in tears now. There was no resisting them, and we wept
 * openly. She wept, too, to see that her sweeter counsels had prevailed.
 * Her husband flung himself on his knees beside her, and putting his arms
 * round her, hid his face in the folds of her dress. Van Helsing beckoned
 * to us and we stole out of the room, leaving the two loving hearts alone
 * with their God.
 *
 * Before they retired the Professor fixed up the room against any coming
 * of the Vampire, and assured Mrs. Harker that she might rest in peace.
 * She tried to school herself to the belief, and, manifestly for her
 * husband's sake, tried to seem content. It was a brave struggle; and was,
 * I think and believe, not without its reward. Van Helsing had placed at
 * hand a bell which either of them was to sound in case of any emergency.
 * When they had retired, Quincey, Godalming, and I arranged that we should
 * sit up, dividing the night between us, and watch over the safety of the
 * poor stricken lady. The first watch falls to Quincey, so the rest of us
 * shall be off to bed as soon as we can. Godalming has already turned in,
 * for his is the second watch. Now that my work is done I, too, shall go
 * to bed.
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _3-4 October, close to midnight._--I thought yesterday would never end.
 * There was over me a yearning for sleep, in some sort of blind belief
 * that to wake would be to find things changed, and that any change must
 * now be for the better. Before we parted, we discussed what our next step
 * was to be, but we could arrive at no result. All we knew was that one
 * earth-box remained, and that the Count alone knew where it was. If he
 * chooses to lie hidden, he may baffle us for years; and in the
 * meantime!--the thought is too horrible, I dare not think of it even now.
 * This I know: that if ever there was a woman who was all perfection, that
 * one is my poor wronged darling. I love her a thousand times more for her
 * sweet pity of last night, a pity that made my own hate of the monster
 * seem despicable. Surely God will not permit the world to be the poorer
 * by the loss of such a creature. This is hope to me. We are all drifting
 * reefwards now, and faith is our only anchor. Thank God! Mina is
 * sleeping, and sleeping without dreams. I fear what her dreams might be
 * like, with such terrible memories to ground them in. She has not been so
 * calm, within my seeing, since the sunset. Then, for a while, there came
 * over her face a repose which was like spring after the blasts of March.
 * I thought at the time that it was the softness of the red sunset on her
 * face, but somehow now I think it has a deeper meaning. I am not sleepy
 * myself, though I am weary--weary to death. However, I must try to sleep;
 * for there is to-morrow to think of, and there is no rest for me
 * until....
 *
 *        *       *       *       *       *
 *
 * _Later._--I must have fallen asleep, for I was awaked by Mina, who was
 * sitting up in bed, with a startled look on her face. I could see easily,
 * for we did not leave the room in darkness; she had placed a warning hand
 * over my mouth, and now she whispered in my ear:--
 *
 * "Hush! there is someone in the corridor!" I got up softly, and crossing
 * the room, gently opened the door.
 *
 * Just outside, stretched on a mattress, lay Mr. Morris, wide awake. He
 * raised a warning hand for silence as he whispered to me:--
 *
 * "Hush! go back to bed; it is all right. One of us will be here all
 * night. We don't mean to take any chances!"
 *
 * His look and gesture forbade discussion, so I came back and told Mina.
 * She sighed and positively a shadow of a smile stole over her poor, pale
 * face as she put her arms round me and said softly:--
 *
 * "Oh, thank God for good brave men!" With a sigh she sank back again to
 * sleep. I write this now as I am not sleepy, though I must try again.
 *
 *        *       *       *       *       *
 *
 * _4 October, morning._--Once again during the night I was wakened by
 * Mina. This time we had all had a good sleep, for the grey of the coming
 * dawn was making the windows into sharp oblongs, and the gas flame was
 * like a speck rather than a disc of light. She said to me hurriedly:--
 *
 * "Go, call the Professor. I want to see him at once."
 *
 * "Why?" I asked.
 *
 * "I have an idea. I suppose it must have come in the night, and matured
 * without my knowing it. He must hypnotise me before the dawn, and then I
 * shall be able to speak. Go quick, dearest; the time is getting close." I
 * went to the door. Dr. Seward was resting on the mattress, and, seeing
 * me, he sprang to his feet.
 *
 * "Is anything wrong?" he asked, in alarm.
 *
 * "No," I replied; "but Mina wants to see Dr. Van Helsing at once."
 *
 * "I will go," he said, and hurried into the Professor's room.
 *
 * In two or three minutes later Van Helsing was in the room in his
 * dressing-gown, and Mr. Morris and Lord Godalming were with Dr. Seward at
 * the door asking questions. When the Professor saw Mina a smile--a
 * positive smile ousted the anxiety of his face; he rubbed his hands as he
 * said:--
 *
 * "Oh, my dear Madam Mina, this is indeed a change. See! friend Jonathan,
 * we have got our dear Madam Mina, as of old, back to us to-day!" Then
 * turning to her, he said, cheerfully: "And what am I do for you? For at
 * this hour you do not want me for nothings."
 *
 * "I want you to hypnotise me!" she said. "Do it before the dawn, for I
 * feel that then I can speak, and speak freely. Be quick, for the time is
 * short!" Without a word he motioned her to sit up in bed.
 *
 * Looking fixedly at her, he commenced to make passes in front of her,
 * from over the top of her head downward, with each hand in turn. Mina
 * gazed at him fixedly for a few minutes, during which my own heart beat
 * like a trip hammer, for I felt that some crisis was at hand. Gradually
 * her eyes closed, and she sat, stock still; only by the gentle heaving of
 * her bosom could one know that she was alive. The Professor made a few
 * more passes and then stopped, and I could see that his forehead was
 * covered with great beads of perspiration. Mina opened her eyes; but she
 * did not seem the same woman. There was a far-away look in her eyes, and
 * her voice had a sad dreaminess which was new to me. Raising his hand to
 * impose silence, the Professor motioned to me to bring the others in.
 * They came on tip-toe, closing the door behind them, and stood at the
 * foot of the bed, looking on. Mina appeared not to see them. The
 * stillness was broken by Van Helsing's voice speaking in a low level tone
 * which would not break the current of her thoughts:--
 *
 * "Where are you?" The answer came in a neutral way:--
 *
 * "I do not know. Sleep has no place it can call its own." For several
 * minutes there was silence. Mina sat rigid, and the Professor stood
 * staring at her fixedly; the rest of us hardly dared to breathe. The room
 * was growing lighter; without taking his eyes from Mina's face, Dr. Van
 * Helsing motioned me to pull up the blind. I did so, and the day seemed
 * just upon us. A red streak shot up, and a rosy light seemed to diffuse
 * itself through the room. On the instant the Professor spoke again:--
 *
 * "Where are you now?" The answer came dreamily, but with intention; it
 * were as though she were interpreting something. I have heard her use the
 * same tone when reading her shorthand notes.
 *
 * "I do not know. It is all strange to me!"
 *
 * "What do you see?"
 *
 * "I can see nothing; it is all dark."
 *
 * "What do you hear?" I could detect the strain in the Professor's patient
 * voice.
 *
 * "The lapping of water. It is gurgling by, and little waves leap. I can
 * hear them on the outside."
 *
 * "Then you are on a ship?" We all looked at each other, trying to glean
 * something each from the other. We were afraid to think. The answer came
 * quick:--
 *
 * "Oh, yes!"
 *
 * "What else do you hear?"
 *
 * "The sound of men stamping overhead as they run about. There is the
 * creaking of a chain, and the loud tinkle as the check of the capstan
 * falls into the rachet."
 *
 * "What are you doing?"
 *
 * "I am still--oh, so still. It is like death!" The voice faded away into
 * a deep breath as of one sleeping, and the open eyes closed again.
 *
 * By this time the sun had risen, and we were all in the full light of
 * day. Dr. Van Helsing placed his hands on Mina's shoulders, and laid her
 * head down softly on her pillow. She lay like a sleeping child for a few
 * moments, and then, with a long sigh, awoke and stared in wonder to see
 * us all around her. "Have I been talking in my sleep?" was all she said.
 * She seemed, however, to know the situation without telling, though she
 * was eager to know what she had told. The Professor repeated the
 * conversation, and she said:--
 *
 * "Then there is not a moment to lose: it may not be yet too late!" Mr.
 * Morris and Lord Godalming started for the door but the Professor's calm
 * voice called them back:--
 *
 * "Stay, my friends. That ship, wherever it was, was weighing anchor
 * whilst she spoke. There are many ships weighing anchor at the moment in
 * your so great Port of London. Which of them is it that you seek? God be
 * thanked that we have once again a clue, though whither it may lead us we
 * know not. We have been blind somewhat; blind after the manner of men,
 * since when we can look back we see what we might have seen looking
 * forward if we had been able to see what we might have seen! Alas, but
 * that sentence is a puddle; is it not? We can know now what was in the
 * Count's mind, when he seize that money, though Jonathan's so fierce
 * knife put him in the danger that even he dread. He meant escape. Hear
 * me, ESCAPE! He saw that with but one earth-box left, and a pack of men
 * following like dogs after a fox, this London was no place for him. He
 * have take his last earth-box on board a ship, and he leave the land. He
 * think to escape, but no! we follow him. Tally Ho! as friend Arthur would
 * say when he put on his red frock! Our old fox is wily; oh! so wily, and
 * we must follow with wile. I, too, am wily and I think his mind in a
 * little while. In meantime we may rest and in peace, for there are waters
 * between us which he do not want to pass, and which he could not if he
 * would--unless the ship were to touch the land, and then only at full or
 * slack tide. See, and the sun is just rose, and all day to sunset is to
 * us. Let us take bath, and dress, and have breakfast which we all need,
 * and which we can eat comfortably since he be not in the same land with
 * us." Mina looked at him appealingly as she asked:--
 *
 * "But why need we seek him further, when he is gone away from us?" He
 * took her hand and patted it as he replied:--
 *
 * "Ask me nothings as yet. When we have breakfast, then I answer all
 * questions." He would say no more, and we separated to dress.
 *
 * After breakfast Mina repeated her question. He looked at her gravely for
 * a minute and then said sorrowfully:--
 *
 * "Because my dear, dear Madam Mina, now more than ever must we find him
 * even if we have to follow him to the jaws of Hell!" She grew paler as
 * she asked faintly:--
 *
 * "Why?"
 *
 * "Because," he answered solemnly, "he can live for centuries, and you are
 * but mortal woman. Time is now to be dreaded--since once he put that mark
 * upon your throat."
 *
 * I was just in time to catch her as she fell forward in a faint.
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
 * \page chapter_XXIV CHAPTER XXIV: Dr. Seward's Phonograph Diary, spoken by Van Helsing
 * DR. SEWARD'S PHONOGRAPH DIARY, SPOKEN BY VAN HELSING
 *
 *
 * This to Jonathan Harker.
 *
 * You are to stay with your dear Madam Mina. We shall go to make our
 * search--if I can call it so, for it is not search but knowing, and we
 * seek confirmation only. But do you stay and take care of her to-day.
 * This is your best and most holiest office. This day nothing can find him
 * here. Let me tell you that so you will know what we four know already,
 * for I have tell them. He, our enemy, have gone away; he have gone back
 * to his Castle in Transylvania. I know it so well, as if a great hand of
 * fire wrote it on the wall. He have prepare for this in some way, and
 * that last earth-box was ready to ship somewheres. For this he took the
 * money; for this he hurry at the last, lest we catch him before the sun
 * go down. It was his last hope, save that he might hide in the tomb that
 * he think poor Miss Lucy, being as he thought like him, keep open to him.
 * But there was not of time. When that fail he make straight for his last
 * resource--his last earth-work I might say did I wish _double entente_.
 * He is clever, oh, so clever! he know that his game here was finish; and
 * so he decide he go back home. He find ship going by the route he came,
 * and he go in it. We go off now to find what ship, and whither bound;
 * when we have discover that, we come back and tell you all. Then we will
 * comfort you and poor dear Madam Mina with new hope. For it will be hope
 * when you think it over: that all is not lost. This very creature that we
 * pursue, he take hundreds of years to get so far as London; and yet in
 * one day, when we know of the disposal of him we drive him out. He is
 * finite, though he is powerful to do much harm and suffers not as we do.
 * But we are strong, each in our purpose; and we are all more strong
 * together. Take heart afresh, dear husband of Madam Mina. This battle is
 * but begun, and in the end we shall win--so sure as that God sits on high
 * to watch over His children. Therefore be of much comfort till we return.
 *
 * VAN HELSING.
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _4 October._--When I read to Mina, Van Helsing's message in the
 * phonograph, the poor girl brightened up considerably. Already the
 * certainty that the Count is out of the country has given her comfort;
 * and comfort is strength to her. For my own part, now that his horrible
 * danger is not face to face with us, it seems almost impossible to
 * believe in it. Even my own terrible experiences in Castle Dracula seem
 * like a long-forgotten dream. Here in the crisp autumn air in the bright
 * sunlight----
 *
 * Alas! how can I disbelieve! In the midst of my thought my eye fell on
 * the red scar on my poor darling's white forehead. Whilst that lasts,
 * there can be no disbelief. And afterwards the very memory of it will
 * keep faith crystal clear. Mina and I fear to be idle, so we have been
 * over all the diaries again and again. Somehow, although the reality
 * seems greater each time, the pain and the fear seem less. There is
 * something of a guiding purpose manifest throughout, which is comforting.
 * Mina says that perhaps we are the instruments of ultimate good. It may
 * be! I shall try to think as she does. We have never spoken to each other
 * yet of the future. It is better to wait till we see the Professor and
 * the others after their investigations.
 *
 * The day is running by more quickly than I ever thought a day could run
 * for me again. It is now three o'clock.
 *
 *
 * _Mina Harker's Journal._
 *
 * _5 October, 5 p. m._--Our meeting for report. Present: Professor Van
 * Helsing, Lord Godalming, Dr. Seward, Mr. Quincey Morris, Jonathan
 * Harker, Mina Harker.
 *
 * Dr. Van Helsing described what steps were taken during the day to
 * discover on what boat and whither bound Count Dracula made his escape:--
 *
 * "As I knew that he wanted to get back to Transylvania, I felt sure that
 * he must go by the Danube mouth; or by somewhere in the Black Sea, since
 * by that way he come. It was a dreary blank that was before us. _Omne
 * ignotum pro magnifico_; and so with heavy hearts we start to find what
 * ships leave for the Black Sea last night. He was in sailing ship, since
 * Madam Mina tell of sails being set. These not so important as to go in
 * your list of the shipping in the _Times_, and so we go, by suggestion of
 * Lord Godalming, to your Lloyd's, where are note of all ships that sail,
 * however so small. There we find that only one Black-Sea-bound ship go
 * out with the tide. She is the _Czarina Catherine_, and she sail from
 * Doolittle's Wharf for Varna, and thence on to other parts and up the
 * Danube. 'Soh!' said I, 'this is the ship whereon is the Count.' So off
 * we go to Doolittle's Wharf, and there we find a man in an office of wood
 * so small that the man look bigger than the office. From him we inquire
 * of the goings of the _Czarina Catherine_. He swear much, and he red face
 * and loud of voice, but he good fellow all the same; and when Quincey
 * give him something from his pocket which crackle as he roll it up, and
 * put it in a so small bag which he have hid deep in his clothing, he
 * still better fellow and humble servant to us. He come with us, and ask
 * many men who are rough and hot; these be better fellows too when they
 * have been no more thirsty. They say much of blood and bloom, and of
 * others which I comprehend not, though I guess what they mean; but
 * nevertheless they tell us all things which we want to know.
 *
 * "They make known to us among them, how last afternoon at about five
 * o'clock comes a man so hurry. A tall man, thin and pale, with high nose
 * and teeth so white, and eyes that seem to be burning. That he be all in
 * black, except that he have a hat of straw which suit not him or the
 * time. That he scatter his money in making quick inquiry as to what ship
 * sails for the Black Sea and for where. Some took him to the office and
 * then to the ship, where he will not go aboard but halt at shore end of
 * gang-plank, and ask that the captain come to him. The captain come, when
 * told that he will be pay well; and though he swear much at the first he
 * agree to term. Then the thin man go and some one tell him where horse
 * and cart can be hired. He go there and soon he come again, himself
 * driving cart on which a great box; this he himself lift down, though it
 * take several to put it on truck for the ship. He give much talk to
 * captain as to how and where his box is to be place; but the captain like
 * it not and swear at him in many tongues, and tell him that if he like he
 * can come and see where it shall be. But he say 'no'; that he come not
 * yet, for that he have much to do. Whereupon the captain tell him that he
 * had better be quick--with blood--for that his ship will leave the
 * place--of blood--before the turn of the tide--with blood. Then the thin
 * man smile and say that of course he must go when he think fit; but he
 * will be surprise if he go quite so soon. The captain swear again,
 * polyglot, and the thin man make him bow, and thank him, and say that he
 * will so far intrude on his kindness as to come aboard before the
 * sailing. Final the captain, more red than ever, and in more tongues tell
 * him that he doesn't want no Frenchmen--with bloom upon them and also
 * with blood--in his ship--with blood on her also. And so, after asking
 * where there might be close at hand a ship where he might purchase ship
 * forms, he departed.
 *
 * "No one knew where he went 'or bloomin' well cared,' as they said, for
 * they had something else to think of--well with blood again; for it soon
 * became apparent to all that the _Czarina Catherine_ would not sail as
 * was expected. A thin mist began to creep up from the river, and it grew,
 * and grew; till soon a dense fog enveloped the ship and all around her.
 * The captain swore polyglot--very polyglot--polyglot with bloom and
 * blood; but he could do nothing. The water rose and rose; and he began to
 * fear that he would lose the tide altogether. He was in no friendly mood,
 * when just at full tide, the thin man came up the gang-plank again and
 * asked to see where his box had been stowed. Then the captain replied
 * that he wished that he and his box--old and with much bloom and
 * blood--were in hell. But the thin man did not be offend, and went down
 * with the mate and saw where it was place, and came up and stood awhile
 * on deck in fog. He must have come off by himself, for none notice him.
 * Indeed they thought not of him; for soon the fog begin to melt away, and
 * all was clear again. My friends of the thirst and the language that was
 * of bloom and blood laughed, as they told how the captain's swears
 * exceeded even his usual polyglot, and was more than ever full of
 * picturesque, when on questioning other mariners who were on movement up
 * and down on the river that hour, he found that few of them had seen any
 * of fog at all, except where it lay round the wharf. However, the ship
 * went out on the ebb tide; and was doubtless by morning far down the
 * river mouth. She was by then, when they told us, well out to sea.
 *
 * "And so, my dear Madam Mina, it is that we have to rest for a time, for
 * our enemy is on the sea, with the fog at his command, on his way to the
 * Danube mouth. To sail a ship takes time, go she never so quick; and when
 * we start we go on land more quick, and we meet him there. Our best hope
 * is to come on him when in the box between sunrise and sunset; for then
 * he can make no struggle, and we may deal with him as we should. There
 * are days for us, in which we can make ready our plan. We know all about
 * where he go; for we have seen the owner of the ship, who have shown us
 * invoices and all papers that can be. The box we seek is to be landed in
 * Varna, and to be given to an agent, one Ristics who will there present
 * his credentials; and so our merchant friend will have done his part.
 * When he ask if there be any wrong, for that so, he can telegraph and
 * have inquiry made at Varna, we say 'no'; for what is to be done is not
 * for police or of the customs. It must be done by us alone and in our own
 * way."
 *
 * When Dr. Van Helsing had done speaking, I asked him if he were certain
 * that the Count had remained on board the ship. He replied: "We have the
 * best proof of that: your own evidence, when in the hypnotic trance this
 * morning." I asked him again if it were really necessary that they should
 * pursue the Count, for oh! I dread Jonathan leaving me, and I know that
 * he would surely go if the others went. He answered in growing passion,
 * at first quietly. As he went on, however, he grew more angry and more
 * forceful, till in the end we could not but see wherein was at least some
 * of that personal dominance which made him so long a master amongst
 * men:--
 *
 * "Yes, it is necessary--necessary--necessary! For your sake in the first,
 * and then for the sake of humanity. This monster has done much harm
 * already, in the narrow scope where he find himself, and in the short
 * time when as yet he was only as a body groping his so small measure in
 * darkness and not knowing. All this have I told these others; you, my
 * dear Madam Mina, will learn it in the phonograph of my friend John, or
 * in that of your husband. I have told them how the measure of leaving his
 * own barren land--barren of peoples--and coming to a new land where life
 * of man teems till they are like the multitude of standing corn, was the
 * work of centuries. Were another of the Un-Dead, like him, to try to do
 * what he has done, perhaps not all the centuries of the world that have
 * been, or that will be, could aid him. With this one, all the forces of
 * nature that are occult and deep and strong must have worked together in
 * some wondrous way. The very place, where he have been alive, Un-Dead for
 * all these centuries, is full of strangeness of the geologic and chemical
 * world. There are deep caverns and fissures that reach none know whither.
 * There have been volcanoes, some of whose openings still send out waters
 * of strange properties, and gases that kill or make to vivify. Doubtless,
 * there is something magnetic or electric in some of these combinations of
 * occult forces which work for physical life in strange way; and in
 * himself were from the first some great qualities. In a hard and warlike
 * time he was celebrate that he have more iron nerve, more subtle brain,
 * more braver heart, than any man. In him some vital principle have in
 * strange way found their utmost; and as his body keep strong and grow and
 * thrive, so his brain grow too. All this without that diabolic aid which
 * is surely to him; for it have to yield to the powers that come from,
 * and are, symbolic of good. And now this is what he is to us. He have
 * infect you--oh, forgive me, my dear, that I must say such; but it is for
 * good of you that I speak. He infect you in such wise, that even if he do
 * no more, you have only to live--to live in your own old, sweet way; and
 * so in time, death, which is of man's common lot and with God's sanction,
 * shall make you like to him. This must not be! We have sworn together
 * that it must not. Thus are we ministers of God's own wish: that the
 * world, and men for whom His Son die, will not be given over to monsters,
 * whose very existence would defame Him. He have allowed us to redeem one
 * soul already, and we go out as the old knights of the Cross to redeem
 * more. Like them we shall travel towards the sunrise; and like them, if
 * we fall, we fall in good cause." He paused and I said:--
 *
 * "But will not the Count take his rebuff wisely? Since he has been driven
 * from England, will he not avoid it, as a tiger does the village from
 * which he has been hunted?"
 *
 * "Aha!" he said, "your simile of the tiger good, for me, and I shall
 * adopt him. Your man-eater, as they of India call the tiger who has once
 * tasted blood of the human, care no more for the other prey, but prowl
 * unceasing till he get him. This that we hunt from our village is a
 * tiger, too, a man-eater, and he never cease to prowl. Nay, in himself he
 * is not one to retire and stay afar. In his life, his living life, he go
 * over the Turkey frontier and attack his enemy on his own ground; he be
 * beaten back, but did he stay? No! He come again, and again, and again.
 * Look at his persistence and endurance. With the child-brain that was to
 * him he have long since conceive the idea of coming to a great city. What
 * does he do? He find out the place of all the world most of promise for
 * him. Then he deliberately set himself down to prepare for the task. He
 * find in patience just how is his strength, and what are his powers. He
 * study new tongues. He learn new social life; new environment of old
 * ways, the politic, the law, the finance, the science, the habit of a new
 * land and a new people who have come to be since he was. His glimpse that
 * he have had, whet his appetite only and enkeen his desire. Nay, it help
 * him to grow as to his brain; for it all prove to him how right he was at
 * the first in his surmises. He have done this alone; all alone! from a
 * ruin tomb in a forgotten land. What more may he not do when the greater
 * world of thought is open to him. He that can smile at death, as we know
 * him; who can flourish in the midst of diseases that kill off whole
 * peoples. Oh, if such an one was to come from God, and not the Devil,
 * what a force for good might he not be in this old world of ours. But we
 * are pledged to set the world free. Our toil must be in silence, and our
 * efforts all in secret; for in this enlightened age, when men believe not
 * even what they see, the doubting of wise men would be his greatest
 * strength. It would be at once his sheath and his armour, and his weapons
 * to destroy us, his enemies, who are willing to peril even our own souls
 * for the safety of one we love--for the good of mankind, and for the
 * honour and glory of God."
 *
 * After a general discussion it was determined that for to-night nothing
 * be definitely settled; that we should all sleep on the facts, and try to
 * think out the proper conclusions. To-morrow, at breakfast, we are to
 * meet again, and, after making our conclusions known to one another, we
 * shall decide on some definite cause of action.
 *
 *        *       *       *       *       *
 *
 * I feel a wonderful peace and rest to-night. It is as if some haunting
 * presence were removed from me. Perhaps ...
 *
 * My surmise was not finished, could not be; for I caught sight in the
 * mirror of the red mark upon my forehead; and I knew that I was still
 * unclean.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _5 October._--We all rose early, and I think that sleep did much for
 * each and all of us. When we met at early breakfast there was more
 * general cheerfulness than any of us had ever expected to experience
 * again.
 *
 * It is really wonderful how much resilience there is in human nature. Let
 * any obstructing cause, no matter what, be removed in any way--even by
 * death--and we fly back to first principles of hope and enjoyment. More
 * than once as we sat around the table, my eyes opened in wonder whether
 * the whole of the past days had not been a dream. It was only when I
 * caught sight of the red blotch on Mrs. Harker's forehead that I was
 * brought back to reality. Even now, when I am gravely revolving the
 * matter, it is almost impossible to realise that the cause of all our
 * trouble is still existent. Even Mrs. Harker seems to lose sight of her
 * trouble for whole spells; it is only now and again, when something
 * recalls it to her mind, that she thinks of her terrible scar. We are to
 * meet here in my study in half an hour and decide on our course of
 * action. I see only one immediate difficulty, I know it by instinct
 * rather than reason: we shall all have to speak frankly; and yet I fear
 * that in some mysterious way poor Mrs. Harker's tongue is tied. I _know_
 * that she forms conclusions of her own, and from all that has been I can
 * guess how brilliant and how true they must be; but she will not, or
 * cannot, give them utterance. I have mentioned this to Van Helsing, and
 * he and I are to talk it over when we are alone. I suppose it is some of
 * that horrid poison which has got into her veins beginning to work. The
 * Count had his own purposes when he gave her what Van Helsing called "the
 * Vampire's baptism of blood." Well, there may be a poison that distils
 * itself out of good things; in an age when the existence of ptomaines is
 * a mystery we should not wonder at anything! One thing I know: that if my
 * instinct be true regarding poor Mrs. Harker's silences, then there is a
 * terrible difficulty--an unknown danger--in the work before us. The same
 * power that compels her silence may compel her speech. I dare not think
 * further; for so I should in my thoughts dishonour a noble woman!
 *
 * Van Helsing is coming to my study a little before the others. I shall
 * try to open the subject with him.
 *
 *        *       *       *       *       *
 *
 * _Later._--When the Professor came in, we talked over the state of
 * things. I could see that he had something on his mind which he wanted to
 * say, but felt some hesitancy about broaching the subject. After beating
 * about the bush a little, he said suddenly:--
 *
 * "Friend John, there is something that you and I must talk of alone, just
 * at the first at any rate. Later, we may have to take the others into our
 * confidence"; then he stopped, so I waited; he went on:--
 *
 * "Madam Mina, our poor, dear Madam Mina is changing." A cold shiver ran
 * through me to find my worst fears thus endorsed. Van Helsing
 * continued:--
 *
 * "With the sad experience of Miss Lucy, we must this time be warned
 * before things go too far. Our task is now in reality more difficult than
 * ever, and this new trouble makes every hour of the direst importance. I
 * can see the characteristics of the vampire coming in her face. It is now
 * but very, very slight; but it is to be seen if we have eyes to notice
 * without to prejudge. Her teeth are some sharper, and at times her eyes
 * are more hard. But these are not all, there is to her the silence now
 * often; as so it was with Miss Lucy. She did not speak, even when she
 * wrote that which she wished to be known later. Now my fear is this. If
 * it be that she can, by our hypnotic trance, tell what the Count see and
 * hear, is it not more true that he who have hypnotise her first, and who
 * have drink of her very blood and make her drink of his, should, if he
 * will, compel her mind to disclose to him that which she know?" I nodded
 * acquiescence; he went on:--
 *
 * "Then, what we must do is to prevent this; we must keep her ignorant of
 * our intent, and so she cannot tell what she know not. This is a painful
 * task! Oh, so painful that it heart-break me to think of; but it must be.
 * When to-day we meet, I must tell her that for reason which we will not
 * to speak she must not more be of our council, but be simply guarded by
 * us." He wiped his forehead, which had broken out in profuse perspiration
 * at the thought of the pain which he might have to inflict upon the poor
 * soul already so tortured. I knew that it would be some sort of comfort
 * to him if I told him that I also had come to the same conclusion; for at
 * any rate it would take away the pain of doubt. I told him, and the
 * effect was as I expected.
 *
 * It is now close to the time of our general gathering. Van Helsing has
 * gone away to prepare for the meeting, and his painful part of it. I
 * really believe his purpose is to be able to pray alone.
 *
 *        *       *       *       *       *
 *
 * _Later._--At the very outset of our meeting a great personal relief was
 * experienced by both Van Helsing and myself. Mrs. Harker had sent a
 * message by her husband to say that she would not join us at present, as
 * she thought it better that we should be free to discuss our movements
 * without her presence to embarrass us. The Professor and I looked at each
 * other for an instant, and somehow we both seemed relieved. For my own
 * part, I thought that if Mrs. Harker realised the danger herself, it was
 * much pain as well as much danger averted. Under the circumstances we
 * agreed, by a questioning look and answer, with finger on lip, to
 * preserve silence in our suspicions, until we should have been able to
 * confer alone again. We went at once into our Plan of Campaign. Van
 * Helsing roughly put the facts before us first:--
 *
 * "The _Czarina Catherine_ left the Thames yesterday morning. It will take
 * her at the quickest speed she has ever made at least three weeks to
 * reach Varna; but we can travel overland to the same place in three days.
 * Now, if we allow for two days less for the ship's voyage, owing to such
 * weather influences as we know that the Count can bring to bear; and if
 * we allow a whole day and night for any delays which may occur to us,
 * then we have a margin of nearly two weeks. Thus, in order to be quite
 * safe, we must leave here on 17th at latest. Then we shall at any rate
 * be in Varna a day before the ship arrives, and able to make such
 * preparations as may be necessary. Of course we shall all go armed--armed
 * against evil things, spiritual as well as physical." Here Quincey Morris
 * added:--
 *
 * "I understand that the Count comes from a wolf country, and it may be
 * that he shall get there before us. I propose that we add Winchesters to
 * our armament. I have a kind of belief in a Winchester when there is any
 * trouble of that sort around. Do you remember, Art, when we had the pack
 * after us at Tobolsk? What wouldn't we have given then for a repeater
 * apiece!"
 *
 * "Good!" said Van Helsing, "Winchesters it shall be. Quincey's head is
 * level at all times, but most so when there is to hunt, metaphor be more
 * dishonour to science than wolves be of danger to man. In the meantime we
 * can do nothing here; and as I think that Varna is not familiar to any of
 * us, why not go there more soon? It is as long to wait here as there.
 * To-night and to-morrow we can get ready, and then, if all be well, we
 * four can set out on our journey."
 *
 * "We four?" said Harker interrogatively, looking from one to another of
 * us.
 *
 * "Of course!" answered the Professor quickly, "you must remain to take
 * care of your so sweet wife!" Harker was silent for awhile and then said
 * in a hollow voice:--
 *
 * "Let us talk of that part of it in the morning. I want to consult with
 * Mina." I thought that now was the time for Van Helsing to warn him not
 * to disclose our plans to her; but he took no notice. I looked at him
 * significantly and coughed. For answer he put his finger on his lips and
 * turned away.
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _5 October, afternoon._--For some time after our meeting this morning I
 * could not think. The new phases of things leave my mind in a state of
 * wonder which allows no room for active thought. Mina's determination not
 * to take any part in the discussion set me thinking; and as I could not
 * argue the matter with her, I could only guess. I am as far as ever from
 * a solution now. The way the others received it, too, puzzled me; the
 * last time we talked of the subject we agreed that there was to be no
 * more concealment of anything amongst us. Mina is sleeping now, calmly
 * and sweetly like a little child. Her lips are curved and her face beams
 * with happiness. Thank God, there are such moments still for her.
 *
 *        *       *       *       *       *
 *
 * _Later._--How strange it all is. I sat watching Mina's happy sleep, and
 * came as near to being happy myself as I suppose I shall ever be. As the
 * evening drew on, and the earth took its shadows from the sun sinking
 * lower, the silence of the room grew more and more solemn to me. All at
 * once Mina opened her eyes, and looking at me tenderly, said:--
 *
 * "Jonathan, I want you to promise me something on your word of honour. A
 * promise made to me, but made holily in God's hearing, and not to be
 * broken though I should go down on my knees and implore you with bitter
 * tears. Quick, you must make it to me at once."
 *
 * "Mina," I said, "a promise like that, I cannot make at once. I may have
 * no right to make it."
 *
 * "But, dear one," she said, with such spiritual intensity that her eyes
 * were like pole stars, "it is I who wish it; and it is not for myself.
 * You can ask Dr. Van Helsing if I am not right; if he disagrees you may
 * do as you will. Nay, more, if you all agree, later, you are absolved
 * from the promise."
 *
 * "I promise!" I said, and for a moment she looked supremely happy; though
 * to me all happiness for her was denied by the red scar on her forehead.
 * She said:--
 *
 * "Promise me that you will not tell me anything of the plans formed for
 * the campaign against the Count. Not by word, or inference, or
 * implication; not at any time whilst this remains to me!" and she
 * solemnly pointed to the scar. I saw that she was in earnest, and said
 * solemnly:--
 *
 * "I promise!" and as I said it I felt that from that instant a door had
 * been shut between us.
 *
 *        *       *       *       *       *
 *
 * _Later, midnight._--Mina has been bright and cheerful all the evening.
 * So much so that all the rest seemed to take courage, as if infected
 * somewhat with her gaiety; as a result even I myself felt as if the pall
 * of gloom which weighs us down were somewhat lifted. We all retired
 * early. Mina is now sleeping like a little child; it is a wonderful thing
 * that her faculty of sleep remains to her in the midst of her terrible
 * trouble. Thank God for it, for then at least she can forget her care.
 * Perhaps her example may affect me as her gaiety did to-night. I shall
 * try it. Oh! for a dreamless sleep.
 *
 *        *       *       *       *       *
 *
 * _6 October, morning._--Another surprise. Mina woke me early, about the
 * same time as yesterday, and asked me to bring Dr. Van Helsing. I thought
 * that it was another occasion for hypnotism, and without question went
 * for the Professor. He had evidently expected some such call, for I found
 * him dressed in his room. His door was ajar, so that he could hear the
 * opening of the door of our room. He came at once; as he passed into the
 * room, he asked Mina if the others might come, too.
 *
 * "No," she said quite simply, "it will not be necessary. You can tell
 * them just as well. I must go with you on your journey."
 *
 * Dr. Van Helsing was as startled as I was. After a moment's pause he
 * asked:--
 *
 * "But why?"
 *
 * "You must take me with you. I am safer with you, and you shall be safer,
 * too."
 *
 * "But why, dear Madam Mina? You know that your safety is our solemnest
 * duty. We go into danger, to which you are, or may be, more liable than
 * any of us from--from circumstances--things that have been." He paused,
 * embarrassed.
 *
 * As she replied, she raised her finger and pointed to her forehead:--
 *
 * "I know. That is why I must go. I can tell you now, whilst the sun is
 * coming up; I may not be able again. I know that when the Count wills me
 * I must go. I know that if he tells me to come in secret, I must come by
 * wile; by any device to hoodwink--even Jonathan." God saw the look that
 * she turned on me as she spoke, and if there be indeed a Recording Angel
 * that look is noted to her everlasting honour. I could only clasp her
 * hand. I could not speak; my emotion was too great for even the relief of
 * tears. She went on:--
 *
 * "You men are brave and strong. You are strong in your numbers, for you
 * can defy that which would break down the human endurance of one who had
 * to guard alone. Besides, I may be of service, since you can hypnotise me
 * and so learn that which even I myself do not know." Dr. Van Helsing said
 * very gravely:--
 *
 * "Madam Mina, you are, as always, most wise. You shall with us come; and
 * together we shall do that which we go forth to achieve." When he had
 * spoken, Mina's long spell of silence made me look at her. She had fallen
 * back on her pillow asleep; she did not even wake when I had pulled up
 * the blind and let in the sunlight which flooded the room. Van Helsing
 * motioned to me to come with him quietly. We went to his room, and within
 * a minute Lord Godalming, Dr. Seward, and Mr. Morris were with us also.
 * He told them what Mina had said, and went on:--
 *
 * "In the morning we shall leave for Varna. We have now to deal with a
 * new factor: Madam Mina. Oh, but her soul is true. It is to her an agony
 * to tell us so much as she has done; but it is most right, and we are
 * warned in time. There must be no chance lost, and in Varna we must be
 * ready to act the instant when that ship arrives."
 *
 * "What shall we do exactly?" asked Mr. Morris laconically. The Professor
 * paused before replying:--
 *
 * "We shall at the first board that ship; then, when we have identified
 * the box, we shall place a branch of the wild rose on it. This we shall
 * fasten, for when it is there none can emerge; so at least says the
 * superstition. And to superstition must we trust at the first; it was
 * man's faith in the early, and it have its root in faith still. Then,
 * when we get the opportunity that we seek, when none are near to see, we
 * shall open the box, and--and all will be well."
 *
 * "I shall not wait for any opportunity," said Morris. "When I see the box
 * I shall open it and destroy the monster, though there were a thousand
 * men looking on, and if I am to be wiped out for it the next moment!" I
 * grasped his hand instinctively and found it as firm as a piece of steel.
 * I think he understood my look; I hope he did.
 *
 * "Good boy," said Dr. Van Helsing. "Brave boy. Quincey is all man. God
 * bless him for it. My child, believe me none of us shall lag behind or
 * pause from any fear. I do but say what we may do--what we must do. But,
 * indeed, indeed we cannot say what we shall do. There are so many things
 * which may happen, and their ways and their ends are so various that
 * until the moment we may not say. We shall all be armed, in all ways; and
 * when the time for the end has come, our effort shall not be lack. Now
 * let us to-day put all our affairs in order. Let all things which touch
 * on others dear to us, and who on us depend, be complete; for none of us
 * can tell what, or when, or how, the end may be. As for me, my own
 * affairs are regulate; and as I have nothing else to do, I shall go make
 * arrangements for the travel. I shall have all tickets and so forth for
 * our journey."
 *
 * There was nothing further to be said, and we parted. I shall now settle
 * up all my affairs of earth, and be ready for whatever may come....
 *
 *        *       *       *       *       *
 *
 * _Later._--It is all done; my will is made, and all complete. Mina if she
 * survive is my sole heir. If it should not be so, then the others who
 * have been so good to us shall have remainder.
 *
 * It is now drawing towards the sunset; Mina's uneasiness calls my
 * attention to it. I am sure that there is something on her mind which the
 * time of exact sunset will reveal. These occasions are becoming harrowing
 * times for us all, for each sunrise and sunset opens up some new
 * danger--some new pain, which, however, may in God's will be means to a
 * good end. I write all these things in the diary since my darling must
 * not hear them now; but if it may be that she can see them again, they
 * shall be ready.
 *
 * She is calling to me.
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
 * \page chapter_XXV CHAPTER XXV: Dr. Seward's Diary
 * DR. SEWARD'S DIARY
 *
 *
 * _11 October, Evening._--Jonathan Harker has asked me to note this, as he
 * says he is hardly equal to the task, and he wants an exact record kept.
 *
 * I think that none of us were surprised when we were asked to see Mrs.
 * Harker a little before the time of sunset. We have of late come to
 * understand that sunrise and sunset are to her times of peculiar freedom;
 * when her old self can be manifest without any controlling force subduing
 * or restraining her, or inciting her to action. This mood or condition
 * begins some half hour or more before actual sunrise or sunset, and lasts
 * till either the sun is high, or whilst the clouds are still aglow with
 * the rays streaming above the horizon. At first there is a sort of
 * negative condition, as if some tie were loosened, and then the absolute
 * freedom quickly follows; when, however, the freedom ceases the
 * change-back or relapse comes quickly, preceded only by a spell of
 * warning silence.
 *
 * To-night, when we met, she was somewhat constrained, and bore all the
 * signs of an internal struggle. I put it down myself to her making a
 * violent effort at the earliest instant she could do so. A very few
 * minutes, however, gave her complete control of herself; then, motioning
 * her husband to sit beside her on the sofa where she was half reclining,
 * she made the rest of us bring chairs up close. Taking her husband's hand
 * in hers began:--
 *
 * "We are all here together in freedom, for perhaps the last time! I know,
 * dear; I know that you will always be with me to the end." This was to
 * her husband whose hand had, as we could see, tightened upon hers. "In
 * the morning we go out upon our task, and God alone knows what may be in
 * store for any of us. You are going to be so good to me as to take me
 * with you. I know that all that brave earnest men can do for a poor weak
 * woman, whose soul perhaps is lost--no, no, not yet, but is at any rate
 * at stake--you will do. But you must remember that I am not as you are.
 * There is a poison in my blood, in my soul, which may destroy me; which
 * must destroy me, unless some relief comes to us. Oh, my friends, you
 * know as well as I do, that my soul is at stake; and though I know there
 * is one way out for me, you must not and I must not take it!" She looked
 * appealingly to us all in turn, beginning and ending with her husband.
 *
 * "What is that way?" asked Van Helsing in a hoarse voice. "What is that
 * way, which we must not--may not--take?"
 *
 * "That I may die now, either by my own hand or that of another, before
 * the greater evil is entirely wrought. I know, and you know, that were I
 * once dead you could and would set free my immortal spirit, even as you
 * did my poor Lucy's. Were death, or the fear of death, the only thing
 * that stood in the way I would not shrink to die here, now, amidst the
 * friends who love me. But death is not all. I cannot believe that to die
 * in such a case, when there is hope before us and a bitter task to be
 * done, is God's will. Therefore, I, on my part, give up here the
 * certainty of eternal rest, and go out into the dark where may be the
 * blackest things that the world or the nether world holds!" We were all
 * silent, for we knew instinctively that this was only a prelude. The
 * faces of the others were set and Harker's grew ashen grey; perhaps he
 * guessed better than any of us what was coming. She continued:--
 *
 * "This is what I can give into the hotch-pot." I could not but note the
 * quaint legal phrase which she used in such a place, and with all
 * seriousness. "What will each of you give? Your lives I know," she went
 * on quickly, "that is easy for brave men. Your lives are God's, and you
 * can give them back to Him; but what will you give to me?" She looked
 * again questioningly, but this time avoided her husband's face. Quincey
 * seemed to understand; he nodded, and her face lit up. "Then I shall tell
 * you plainly what I want, for there must be no doubtful matter in this
 * connection between us now. You must promise me, one and all--even you,
 * my beloved husband--that, should the time come, you will kill me."
 *
 * "What is that time?" The voice was Quincey's, but it was low and
 * strained.
 *
 * "When you shall be convinced that I am so changed that it is better that
 * I die that I may live. When I am thus dead in the flesh, then you will,
 * without a moment's delay, drive a stake through me and cut off my head;
 * or do whatever else may be wanting to give me rest!"
 *
 * Quincey was the first to rise after the pause. He knelt down before her
 * and taking her hand in his said solemnly:--
 *
 * "I'm only a rough fellow, who hasn't, perhaps, lived as a man should to
 * win such a distinction, but I swear to you by all that I hold sacred and
 * dear that, should the time ever come, I shall not flinch from the duty
 * that you have set us. And I promise you, too, that I shall make all
 * certain, for if I am only doubtful I shall take it that the time has
 * come!"
 *
 * "My true friend!" was all she could say amid her fast-falling tears, as,
 * bending over, she kissed his hand.
 *
 * "I swear the same, my dear Madam Mina!" said Van Helsing.
 *
 * "And I!" said Lord Godalming, each of them in turn kneeling to her to
 * take the oath. I followed, myself. Then her husband turned to her
 * wan-eyed and with a greenish pallor which subdued the snowy whiteness of
 * his hair, and asked:--
 *
 * "And must I, too, make such a promise, oh, my wife?"
 *
 * "You too, my dearest," she said, with infinite yearning of pity in her
 * voice and eyes. "You must not shrink. You are nearest and dearest and
 * all the world to me; our souls are knit into one, for all life and all
 * time. Think, dear, that there have been times when brave men have killed
 * their wives and their womenkind, to keep them from falling into the
 * hands of the enemy. Their hands did not falter any the more because
 * those that they loved implored them to slay them. It is men's duty
 * towards those whom they love, in such times of sore trial! And oh, my
 * dear, if it is to be that I must meet death at any hand, let it be at
 * the hand of him that loves me best. Dr. Van Helsing, I have not
 * forgotten your mercy in poor Lucy's case to him who loved"--she stopped
 * with a flying blush, and changed her phrase--"to him who had best right
 * to give her peace. If that time shall come again, I look to you to make
 * it a happy memory of my husband's life that it was his loving hand which
 * set me free from the awful thrall upon me."
 *
 * "Again I swear!" came the Professor's resonant voice. Mrs. Harker
 * smiled, positively smiled, as with a sigh of relief she leaned back and
 * said:--
 *
 * "And now one word of warning, a warning which you must never forget:
 * this time, if it ever come, may come quickly and unexpectedly, and in
 * such case you must lose no time in using your opportunity. At such a
 * time I myself might be--nay! if the time ever comes, _shall be_--leagued
 * with your enemy against you."
 *
 * "One more request;" she became very solemn as she said this, "it is not
 * vital and necessary like the other, but I want you to do one thing for
 * me, if you will." We all acquiesced, but no one spoke; there was no need
 * to speak:--
 *
 * "I want you to read the Burial Service." She was interrupted by a deep
 * groan from her husband; taking his hand in hers, she held it over her
 * heart, and continued: "You must read it over me some day. Whatever may
 * be the issue of all this fearful state of things, it will be a sweet
 * thought to all or some of us. You, my dearest, will I hope read it, for
 * then it will be in your voice in my memory for ever--come what may!"
 *
 * "But oh, my dear one," he pleaded, "death is afar off from you."
 *
 * "Nay," she said, holding up a warning hand. "I am deeper in death at
 * this moment than if the weight of an earthly grave lay heavy upon me!"
 *
 * "Oh, my wife, must I read it?" he said, before he began.
 *
 * "It would comfort me, my husband!" was all she said; and he began to
 * read when she had got the book ready.
 *
 * "How can I--how could any one--tell of that strange scene, its
 * solemnity, its gloom, its sadness, its horror; and, withal, its
 * sweetness. Even a sceptic, who can see nothing but a travesty of bitter
 * truth in anything holy or emotional, would have been melted to the heart
 * had he seen that little group of loving and devoted friends kneeling
 * round that stricken and sorrowing lady; or heard the tender passion of
 * her husband's voice, as in tones so broken with emotion that often he
 * had to pause, he read the simple and beautiful service from the Burial
 * of the Dead. I--I cannot go on--words--and--v-voice--f-fail m-me!"
 *
 *        *       *       *       *       *
 *
 * She was right in her instinct. Strange as it all was, bizarre as it may
 * hereafter seem even to us who felt its potent influence at the time, it
 * comforted us much; and the silence, which showed Mrs. Harker's coming
 * relapse from her freedom of soul, did not seem so full of despair to any
 * of us as we had dreaded.
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _15 October, Varna._--We left Charing Cross on the morning of the 12th,
 * got to Paris the same night, and took the places secured for us in the
 * Orient Express. We travelled night and day, arriving here at about five
 * o'clock. Lord Godalming went to the Consulate to see if any telegram had
 * arrived for him, whilst the rest of us came on to this hotel--"the
 * Odessus." The journey may have had incidents; I was, however, too eager
 * to get on, to care for them. Until the _Czarina Catherine_ comes into
 * port there will be no interest for me in anything in the wide world.
 * Thank God! Mina is well, and looks to be getting stronger; her colour is
 * coming back. She sleeps a great deal; throughout the journey she slept
 * nearly all the time. Before sunrise and sunset, however, she is very
 * wakeful and alert; and it has become a habit for Van Helsing to
 * hypnotise her at such times. At first, some effort was needed, and he
 * had to make many passes; but now, she seems to yield at once, as if by
 * habit, and scarcely any action is needed. He seems to have power at
 * these particular moments to simply will, and her thoughts obey him. He
 * always asks her what she can see and hear. She answers to the first:--
 *
 * "Nothing; all is dark." And to the second:--
 *
 * "I can hear the waves lapping against the ship, and the water rushing
 * by. Canvas and cordage strain and masts and yards creak. The wind is
 * high--I can hear it in the shrouds, and the bow throws back the foam."
 * It is evident that the _Czarina Catherine_ is still at sea, hastening on
 * her way to Varna. Lord Godalming has just returned. He had four
 * telegrams, one each day since we started, and all to the same effect:
 * that the _Czarina Catherine_ had not been reported to Lloyd's from
 * anywhere. He had arranged before leaving London that his agent should
 * send him every day a telegram saying if the ship had been reported. He
 * was to have a message even if she were not reported, so that he might be
 * sure that there was a watch being kept at the other end of the wire.
 *
 * We had dinner and went to bed early. To-morrow we are to see the
 * Vice-Consul, and to arrange, if we can, about getting on board the ship
 * as soon as she arrives. Van Helsing says that our chance will be to get
 * on the boat between sunrise and sunset. The Count, even if he takes the
 * form of a bat, cannot cross the running water of his own volition, and
 * so cannot leave the ship. As he dare not change to man's form without
 * suspicion--which he evidently wishes to avoid--he must remain in the
 * box. If, then, we can come on board after sunrise, he is at our mercy;
 * for we can open the box and make sure of him, as we did of poor Lucy,
 * before he wakes. What mercy he shall get from us will not count for
 * much. We think that we shall not have much trouble with officials or the
 * seamen. Thank God! this is the country where bribery can do anything,
 * and we are well supplied with money. We have only to make sure that the
 * ship cannot come into port between sunset and sunrise without our being
 * warned, and we shall be safe. Judge Moneybag will settle this case, I
 * think!
 *
 *        *       *       *       *       *
 *
 * _16 October._--Mina's report still the same: lapping waves and rushing
 * water, darkness and favouring winds. We are evidently in good time, and
 * when we hear of the _Czarina Catherine_ we shall be ready. As she must
 * pass the Dardanelles we are sure to have some report.
 *
 *        *       *       *       *       *
 *
 * _17 October._--Everything is pretty well fixed now, I think, to welcome
 * the Count on his return from his tour. Godalming told the shippers that
 * he fancied that the box sent aboard might contain something stolen from
 * a friend of his, and got a half consent that he might open it at his own
 * risk. The owner gave him a paper telling the Captain to give him every
 * facility in doing whatever he chose on board the ship, and also a
 * similar authorisation to his agent at Varna. We have seen the agent, who
 * was much impressed with Godalming's kindly manner to him, and we are all
 * satisfied that whatever he can do to aid our wishes will be done. We
 * have already arranged what to do in case we get the box open. If the
 * Count is there, Van Helsing and Seward will cut off his head at once and
 * drive a stake through his heart. Morris and Godalming and I shall
 * prevent interference, even if we have to use the arms which we shall
 * have ready. The Professor says that if we can so treat the Count's body,
 * it will soon after fall into dust. In such case there would be no
 * evidence against us, in case any suspicion of murder were aroused. But
 * even if it were not, we should stand or fall by our act, and perhaps
 * some day this very script may be evidence to come between some of us and
 * a rope. For myself, I should take the chance only too thankfully if it
 * were to come. We mean to leave no stone unturned to carry out our
 * intent. We have arranged with certain officials that the instant the
 * _Czarina Catherine_ is seen, we are to be informed by a special
 * messenger.
 *
 *        *       *       *       *       *
 *
 * _24 October._--A whole week of waiting. Daily telegrams to Godalming,
 * but only the same story: "Not yet reported." Mina's morning and evening
 * hypnotic answer is unvaried: lapping waves, rushing water, and creaking
 * masts.
 *
 * _Telegram, October 24th._
 *
 * _Rufus Smith, Lloyd's, London, to Lord Godalming, care of H. B. M.
 * Vice-Consul, Varna._
 *
 * "_Czarina Catherine_ reported this morning from Dardanelles."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _25 October._--How I miss my phonograph! To write diary with a pen is
 * irksome to me; but Van Helsing says I must. We were all wild with
 * excitement yesterday when Godalming got his telegram from Lloyd's. I
 * know now what men feel in battle when the call to action is heard. Mrs.
 * Harker, alone of our party, did not show any signs of emotion. After
 * all, it is not strange that she did not; for we took special care not to
 * let her know anything about it, and we all tried not to show any
 * excitement when we were in her presence. In old days she would, I am
 * sure, have noticed, no matter how we might have tried to conceal it; but
 * in this way she is greatly changed during the past three weeks. The
 * lethargy grows upon her, and though she seems strong and well, and is
 * getting back some of her colour, Van Helsing and I are not satisfied. We
 * talk of her often; we have not, however, said a word to the others. It
 * would break poor Harker's heart--certainly his nerve--if he knew that we
 * had even a suspicion on the subject. Van Helsing examines, he tells me,
 * her teeth very carefully, whilst she is in the hypnotic condition, for
 * he says that so long as they do not begin to sharpen there is no active
 * danger of a change in her. If this change should come, it would be
 * necessary to take steps!... We both know what those steps would have to
 * be, though we do not mention our thoughts to each other. We should
 * neither of us shrink from the task--awful though it be to contemplate.
 * "Euthanasia" is an excellent and a comforting word! I am grateful to
 * whoever invented it.
 *
 * It is only about 24 hours' sail from the Dardanelles to here, at the
 * rate the _Czarina Catherine_ has come from London. She should therefore
 * arrive some time in the morning; but as she cannot possibly get in
 * before then, we are all about to retire early. We shall get up at one
 * o'clock, so as to be ready.
 *
 *        *       *       *       *       *
 *
 * _25 October, Noon_.--No news yet of the ship's arrival. Mrs. Harker's
 * hypnotic report this morning was the same as usual, so it is possible
 * that we may get news at any moment. We men are all in a fever of
 * excitement, except Harker, who is calm; his hands are cold as ice, and
 * an hour ago I found him whetting the edge of the great Ghoorka knife
 * which he now always carries with him. It will be a bad lookout for the
 * Count if the edge of that "Kukri" ever touches his throat, driven by
 * that stern, ice-cold hand!
 *
 * Van Helsing and I were a little alarmed about Mrs. Harker to-day. About
 * noon she got into a sort of lethargy which we did not like; although we
 * kept silence to the others, we were neither of us happy about it. She
 * had been restless all the morning, so that we were at first glad to know
 * that she was sleeping. When, however, her husband mentioned casually
 * that she was sleeping so soundly that he could not wake her, we went to
 * her room to see for ourselves. She was breathing naturally and looked so
 * well and peaceful that we agreed that the sleep was better for her than
 * anything else. Poor girl, she has so much to forget that it is no wonder
 * that sleep, if it brings oblivion to her, does her good.
 *
 *        *       *       *       *       *
 *
 * _Later._--Our opinion was justified, for when after a refreshing sleep
 * of some hours she woke up, she seemed brighter and better than she had
 * been for days. At sunset she made the usual hypnotic report. Wherever he
 * may be in the Black Sea, the Count is hurrying to his destination. To
 * his doom, I trust!
 *
 *        *       *       *       *       *
 *
 * _26 October._--Another day and no tidings of the _Czarina Catherine_.
 * She ought to be here by now. That she is still journeying _somewhere_ is
 * apparent, for Mrs. Harker's hypnotic report at sunrise was still the
 * same. It is possible that the vessel may be lying by, at times, for fog;
 * some of the steamers which came in last evening reported patches of fog
 * both to north and south of the port. We must continue our watching, as
 * the ship may now be signalled any moment.
 *
 *        *       *       *       *       *
 *
 * _27 October, Noon._--Most strange; no news yet of the ship we wait for.
 * Mrs. Harker reported last night and this morning as usual: "lapping
 * waves and rushing water," though she added that "the waves were very
 * faint." The telegrams from London have been the same: "no further
 * report." Van Helsing is terribly anxious, and told me just now that he
 * fears the Count is escaping us. He added significantly:--
 *
 * "I did not like that lethargy of Madam Mina's. Souls and memories can do
 * strange things during trance." I was about to ask him more, but Harker
 * just then came in, and he held up a warning hand. We must try to-night
 * at sunset to make her speak more fully when in her hypnotic state.
 *
 *        *       *       *       *       *
 *
 *      _28 October._--Telegram. _Rufus Smith, London, to Lord Godalming,
 *      care H. B. M. Vice Consul, Varna._
 *
 *      "_Czarina Catherine_ reported entering Galatz at one o'clock
 *      to-day."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _28 October._--When the telegram came announcing the arrival in Galatz I
 * do not think it was such a shock to any of us as might have been
 * expected. True, we did not know whence, or how, or when, the bolt would
 * come; but I think we all expected that something strange would happen.
 * The delay of arrival at Varna made us individually satisfied that things
 * would not be just as we had expected; we only waited to learn where the
 * change would occur. None the less, however, was it a surprise. I suppose
 * that nature works on such a hopeful basis that we believe against
 * ourselves that things will be as they ought to be, not as we should know
 * that they will be. Transcendentalism is a beacon to the angels, even if
 * it be a will-o'-the-wisp to man. It was an odd experience and we all
 * took it differently. Van Helsing raised his hand over his head for a
 * moment, as though in remonstrance with the Almighty; but he said not a
 * word, and in a few seconds stood up with his face sternly set. Lord
 * Godalming grew very pale, and sat breathing heavily. I was myself half
 * stunned and looked in wonder at one after another. Quincey Morris
 * tightened his belt with that quick movement which I knew so well; in our
 * old wandering days it meant "action." Mrs. Harker grew ghastly white, so
 * that the scar on her forehead seemed to burn, but she folded her hands
 * meekly and looked up in prayer. Harker smiled--actually smiled--the
 * dark, bitter smile of one who is without hope; but at the same time his
 * action belied his words, for his hands instinctively sought the hilt of
 * the great Kukri knife and rested there. "When does the next train start
 * for Galatz?" said Van Helsing to us generally.
 *
 * "At 6:30 to-morrow morning!" We all started, for the answer came from
 * Mrs. Harker.
 *
 * "How on earth do you know?" said Art.
 *
 * "You forget--or perhaps you do not know, though Jonathan does and so
 * does Dr. Van Helsing--that I am the train fiend. At home in Exeter I
 * always used to make up the time-tables, so as to be helpful to my
 * husband. I found it so useful sometimes, that I always make a study of
 * the time-tables now. I knew that if anything were to take us to Castle
 * Dracula we should go by Galatz, or at any rate through Bucharest, so I
 * learned the times very carefully. Unhappily there are not many to learn,
 * as the only train to-morrow leaves as I say."
 *
 * "Wonderful woman!" murmured the Professor.
 *
 * "Can't we get a special?" asked Lord Godalming. Van Helsing shook his
 * head: "I fear not. This land is very different from yours or mine; even
 * if we did have a special, it would probably not arrive as soon as our
 * regular train. Moreover, we have something to prepare. We must think.
 * Now let us organize. You, friend Arthur, go to the train and get the
 * tickets and arrange that all be ready for us to go in the morning. Do
 * you, friend Jonathan, go to the agent of the ship and get from him
 * letters to the agent in Galatz, with authority to make search the ship
 * just as it was here. Morris Quincey, you see the Vice-Consul, and get
 * his aid with his fellow in Galatz and all he can do to make our way
 * smooth, so that no times be lost when over the Danube. John will stay
 * with Madam Mina and me, and we shall consult. For so if time be long you
 * may be delayed; and it will not matter when the sun set, since I am here
 * with Madam to make report."
 *
 * "And I," said Mrs. Harker brightly, and more like her old self than she
 * had been for many a long day, "shall try to be of use in all ways, and
 * shall think and write for you as I used to do. Something is shifting
 * from me in some strange way, and I feel freer than I have been of late!"
 * The three younger men looked happier at the moment as they seemed to
 * realise the significance of her words; but Van Helsing and I, turning to
 * each other, met each a grave and troubled glance. We said nothing at the
 * time, however.
 *
 * When the three men had gone out to their tasks Van Helsing asked Mrs.
 * Harker to look up the copy of the diaries and find him the part of
 * Harker's journal at the Castle. She went away to get it; when the door
 * was shut upon her he said to me:--
 *
 * "We mean the same! speak out!"
 *
 * "There is some change. It is a hope that makes me sick, for it may
 * deceive us."
 *
 * "Quite so. Do you know why I asked her to get the manuscript?"
 *
 * "No!" said I, "unless it was to get an opportunity of seeing me alone."
 *
 * "You are in part right, friend John, but only in part. I want to tell
 * you something. And oh, my friend, I am taking a great--a terrible--risk;
 * but I believe it is right. In the moment when Madam Mina said those
 * words that arrest both our understanding, an inspiration came to me. In
 * the trance of three days ago the Count sent her his spirit to read her
 * mind; or more like he took her to see him in his earth-box in the ship
 * with water rushing, just as it go free at rise and set of sun. He learn
 * then that we are here; for she have more to tell in her open life with
 * eyes to see and ears to hear than he, shut, as he is, in his coffin-box.
 * Now he make his most effort to escape us. At present he want her not.
 *
 * "He is sure with his so great knowledge that she will come at his call;
 * but he cut her off--take her, as he can do, out of his own power, that
 * so she come not to him. Ah! there I have hope that our man-brains that
 * have been of man so long and that have not lost the grace of God, will
 * come higher than his child-brain that lie in his tomb for centuries,
 * that grow not yet to our stature, and that do only work selfish and
 * therefore small. Here comes Madam Mina; not a word to her of her trance!
 * She know it not; and it would overwhelm her and make despair just when
 * we want all her hope, all her courage; when most we want all her great
 * brain which is trained like man's brain, but is of sweet woman and have
 * a special power which the Count give her, and which he may not take away
 * altogether--though he think not so. Hush! let me speak, and you shall
 * learn. Oh, John, my friend, we are in awful straits. I fear, as I never
 * feared before. We can only trust the good God. Silence! here she comes!"
 *
 * I thought that the Professor was going to break down and have hysterics,
 * just as he had when Lucy died, but with a great effort he controlled
 * himself and was at perfect nervous poise when Mrs. Harker tripped into
 * the room, bright and happy-looking and, in the doing of work, seemingly
 * forgetful of her misery. As she came in, she handed a number of sheets
 * of typewriting to Van Helsing. He looked over them gravely, his face
 * brightening up as he read. Then holding the pages between his finger and
 * thumb he said:--
 *
 * "Friend John, to you with so much of experience already--and you, too,
 * dear Madam Mina, that are young--here is a lesson: do not fear ever to
 * think. A half-thought has been buzzing often in my brain, but I fear to
 * let him loose his wings. Here now, with more knowledge, I go back to
 * where that half-thought come from and I find that he be no half-thought
 * at all; that be a whole thought, though so young that he is not yet
 * strong to use his little wings. Nay, like the "Ugly Duck" of my friend
 * Hans Andersen, he be no duck-thought at all, but a big swan-thought that
 * sail nobly on big wings, when the time come for him to try them. See I
 * read here what Jonathan have written:--
 *
 * "That other of his race who, in a later age, again and again, brought
 * his forces over The Great River into Turkey Land; who, when he was
 * beaten back, came again, and again, and again, though he had to come
 * alone from the bloody field where his troops were being slaughtered,
 * since he knew that he alone could ultimately triumph."
 *
 * "What does this tell us? Not much? no! The Count's child-thought see
 * nothing; therefore he speak so free. Your man-thought see nothing; my
 * man-thought see nothing, till just now. No! But there comes another word
 * from some one who speak without thought because she, too, know not what
 * it mean--what it _might_ mean. Just as there are elements which rest,
 * yet when in nature's course they move on their way and they touch--then
 * pouf! and there comes a flash of light, heaven wide, that blind and kill
 * and destroy some; but that show up all earth below for leagues and
 * leagues. Is it not so? Well, I shall explain. To begin, have you ever
 * study the philosophy of crime? 'Yes' and 'No.' You, John, yes; for it is
 * a study of insanity. You, no, Madam Mina; for crime touch you not--not
 * but once. Still, your mind works true, and argues not _a particulari ad
 * universale_. There is this peculiarity in criminals. It is so constant,
 * in all countries and at all times, that even police, who know not much
 * from philosophy, come to know it empirically, that _it is_. That is to
 * be empiric. The criminal always work at one crime--that is the true
 * criminal who seems predestinate to crime, and who will of none other.
 * This criminal has not full man-brain. He is clever and cunning and
 * resourceful; but he be not of man-stature as to brain. He be of
 * child-brain in much. Now this criminal of ours is predestinate to crime
 * also; he, too, have child-brain, and it is of the child to do what he
 * have done. The little bird, the little fish, the little animal learn not
 * by principle, but empirically; and when he learn to do, then there is to
 * him the ground to start from to do more. '_Dos pou sto_,' said
 * Archimedes. 'Give me a fulcrum, and I shall move the world!' To do once,
 * is the fulcrum whereby child-brain become man-brain; and until he have
 * the purpose to do more, he continue to do the same again every time,
 * just as he have done before! Oh, my dear, I see that your eyes are
 * opened, and that to you the lightning flash show all the leagues," for
 * Mrs. Harker began to clap her hands and her eyes sparkled. He went on:--
 *
 * "Now you shall speak. Tell us two dry men of science what you see with
 * those so bright eyes." He took her hand and held it whilst she spoke.
 * His finger and thumb closed on her pulse, as I thought instinctively and
 * unconsciously, as she spoke:--
 *
 * "The Count is a criminal and of criminal type. Nordau and Lombroso would
 * so classify him, and _quâ_ criminal he is of imperfectly formed mind.
 * Thus, in a difficulty he has to seek resource in habit. His past is a
 * clue, and the one page of it that we know--and that from his own
 * lips--tells that once before, when in what Mr. Morris would call a
 * 'tight place,' he went back to his own country from the land he had
 * tried to invade, and thence, without losing purpose, prepared himself
 * for a new effort. He came again better equipped for his work; and won.
 * So he came to London to invade a new land. He was beaten, and when all
 * hope of success was lost, and his existence in danger, he fled back over
 * the sea to his home; just as formerly he had fled back over the Danube
 * from Turkey Land."
 *
 * "Good, good! oh, you so clever lady!" said Van Helsing,
 * enthusiastically, as he stooped and kissed her hand. A moment later he
 * said to me, as calmly as though we had been having a sick-room
 * consultation:--
 *
 * "Seventy-two only; and in all this excitement. I have hope." Turning to
 * her again, he said with keen expectation:--
 *
 * "But go on. Go on! there is more to tell if you will. Be not afraid;
 * John and I know. I do in any case, and shall tell you if you are right.
 * Speak, without fear!"
 *
 * "I will try to; but you will forgive me if I seem egotistical."
 *
 * "Nay! fear not, you must be egotist, for it is of you that we think."
 *
 * "Then, as he is criminal he is selfish; and as his intellect is small
 * and his action is based on selfishness, he confines himself to one
 * purpose. That purpose is remorseless. As he fled back over the Danube,
 * leaving his forces to be cut to pieces, so now he is intent on being
 * safe, careless of all. So his own selfishness frees my soul somewhat
 * from the terrible power which he acquired over me on that dreadful
 * night. I felt it! Oh, I felt it! Thank God, for His great mercy! My soul
 * is freer than it has been since that awful hour; and all that haunts me
 * is a fear lest in some trance or dream he may have used my knowledge for
 * his ends." The Professor stood up:--
 *
 * "He has so used your mind; and by it he has left us here in Varna,
 * whilst the ship that carried him rushed through enveloping fog up to
 * Galatz, where, doubtless, he had made preparation for escaping from us.
 * But his child-mind only saw so far; and it may be that, as ever is in
 * God's Providence, the very thing that the evil-doer most reckoned on for
 * his selfish good, turns out to be his chiefest harm. The hunter is taken
 * in his own snare, as the great Psalmist says. For now that he think he
 * is free from every trace of us all, and that he has escaped us with so
 * many hours to him, then his selfish child-brain will whisper him to
 * sleep. He think, too, that as he cut himself off from knowing your mind,
 * there can be no knowledge of him to you; there is where he fail! That
 * terrible baptism of blood which he give you makes you free to go to him
 * in spirit, as you have as yet done in your times of freedom, when the
 * sun rise and set. At such times you go by my volition and not by his;
 * and this power to good of you and others, as you have won from your
 * suffering at his hands. This is now all the more precious that he know
 * it not, and to guard himself have even cut himself off from his
 * knowledge of our where. We, however, are not selfish, and we believe
 * that God is with us through all this blackness, and these many dark
 * hours. We shall follow him; and we shall not flinch; even if we peril
 * ourselves that we become like him. Friend John, this has been a great
 * hour; and it have done much to advance us on our way. You must be scribe
 * and write him all down, so that when the others return from their work
 * you can give it to them; then they shall know as we do."
 *
 * And so I have written it whilst we wait their return, and Mrs. Harker
 * has written with her typewriter all since she brought the MS. to us.
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
 * \page chapter_XXVI CHAPTER XXVI: Dr. Seward's Diary
 * DR. SEWARD'S DIARY
 *
 *
 * _29 October._--This is written in the train from Varna to Galatz. Last
 * night we all assembled a little before the time of sunset. Each of us
 * had done his work as well as he could; so far as thought, and endeavour,
 * and opportunity go, we are prepared for the whole of our journey, and
 * for our work when we get to Galatz. When the usual time came round Mrs.
 * Harker prepared herself for her hypnotic effort; and after a longer and
 * more serious effort on the part of Van Helsing than has been usually
 * necessary, she sank into the trance. Usually she speaks on a hint; but
 * this time the Professor had to ask her questions, and to ask them pretty
 * resolutely, before we could learn anything; at last her answer came:--
 *
 * "I can see nothing; we are still; there are no waves lapping, but only a
 * steady swirl of water softly running against the hawser. I can hear
 * men's voices calling, near and far, and the roll and creak of oars in
 * the rowlocks. A gun is fired somewhere; the echo of it seems far away.
 * There is tramping of feet overhead, and ropes and chains are dragged
 * along. What is this? There is a gleam of light; I can feel the air
 * blowing upon me."
 *
 * Here she stopped. She had risen, as if impulsively, from where she lay
 * on the sofa, and raised both her hands, palms upwards, as if lifting a
 * weight. Van Helsing and I looked at each other with understanding.
 * Quincey raised his eyebrows slightly and looked at her intently, whilst
 * Harker's hand instinctively closed round the hilt of his Kukri. There
 * was a long pause. We all knew that the time when she could speak was
 * passing; but we felt that it was useless to say anything. Suddenly she
 * sat up, and, as she opened her eyes, said sweetly:--
 *
 * "Would none of you like a cup of tea? You must all be so tired!" We
 * could only make her happy, and so acquiesced. She bustled off to get
 * tea; when she had gone Van Helsing said:--
 *
 * "You see, my friends. _He_ is close to land: he has left his
 * earth-chest. But he has yet to get on shore. In the night he may lie
 * hidden somewhere; but if he be not carried on shore, or if the ship do
 * not touch it, he cannot achieve the land. In such case he can, if it be
 * in the night, change his form and can jump or fly on shore, as he did
 * at Whitby. But if the day come before he get on shore, then, unless he
 * be carried he cannot escape. And if he be carried, then the customs men
 * may discover what the box contain. Thus, in fine, if he escape not on
 * shore to-night, or before dawn, there will be the whole day lost to him.
 * We may then arrive in time; for if he escape not at night we shall come
 * on him in daytime, boxed up and at our mercy; for he dare not be his
 * true self, awake and visible, lest he be discovered."
 *
 * There was no more to be said, so we waited in patience until the dawn;
 * at which time we might learn more from Mrs. Harker.
 *
 * Early this morning we listened, with breathless anxiety, for her
 * response in her trance. The hypnotic stage was even longer in coming
 * than before; and when it came the time remaining until full sunrise was
 * so short that we began to despair. Van Helsing seemed to throw his whole
 * soul into the effort; at last, in obedience to his will she made
 * reply:--
 *
 * "All is dark. I hear lapping water, level with me, and some creaking as
 * of wood on wood." She paused, and the red sun shot up. We must wait till
 * to-night.
 *
 * And so it is that we are travelling towards Galatz in an agony of
 * expectation. We are due to arrive between two and three in the morning;
 * but already, at Bucharest, we are three hours late, so we cannot
 * possibly get in till well after sun-up. Thus we shall have two more
 * hypnotic messages from Mrs. Harker; either or both may possibly throw
 * more light on what is happening.
 *
 *        *       *       *       *       *
 *
 * _Later._--Sunset has come and gone. Fortunately it came at a time when
 * there was no distraction; for had it occurred whilst we were at a
 * station, we might not have secured the necessary calm and isolation.
 * Mrs. Harker yielded to the hypnotic influence even less readily than
 * this morning. I am in fear that her power of reading the Count's
 * sensations may die away, just when we want it most. It seems to me that
 * her imagination is beginning to work. Whilst she has been in the trance
 * hitherto she has confined herself to the simplest of facts. If this goes
 * on it may ultimately mislead us. If I thought that the Count's power
 * over her would die away equally with her power of knowledge it would be
 * a happy thought; but I am afraid that it may not be so. When she did
 * speak, her words were enigmatical:--
 *
 * "Something is going out; I can feel it pass me like a cold wind. I can
 * hear, far off, confused sounds--as of men talking in strange tongues,
 * fierce-falling water, and the howling of wolves." She stopped and a
 * shudder ran through her, increasing in intensity for a few seconds,
 * till, at the end, she shook as though in a palsy. She said no more, even
 * in answer to the Professor's imperative questioning. When she woke from
 * the trance, she was cold, and exhausted, and languid; but her mind was
 * all alert. She could not remember anything, but asked what she had said;
 * when she was told, she pondered over it deeply for a long time and in
 * silence.
 *
 *        *       *       *       *       *
 *
 * _30 October, 7 a. m._--We are near Galatz now, and I may not have time
 * to write later. Sunrise this morning was anxiously looked for by us all.
 * Knowing of the increasing difficulty of procuring the hypnotic trance,
 * Van Helsing began his passes earlier than usual. They produced no
 * effect, however, until the regular time, when she yielded with a still
 * greater difficulty, only a minute before the sun rose. The Professor
 * lost no time in his questioning; her answer came with equal quickness:--
 *
 * "All is dark. I hear water swirling by, level with my ears, and the
 * creaking of wood on wood. Cattle low far off. There is another sound, a
 * queer one like----" She stopped and grew white, and whiter still.
 *
 * "Go on; go on! Speak, I command you!" said Van Helsing in an agonised
 * voice. At the same time there was despair in his eyes, for the risen sun
 * was reddening even Mrs. Harker's pale face. She opened her eyes, and we
 * all started as she said, sweetly and seemingly with the utmost
 * unconcern:--
 *
 * "Oh, Professor, why ask me to do what you know I can't? I don't remember
 * anything." Then, seeing the look of amazement on our faces, she said,
 * turning from one to the other with a troubled look:--
 *
 * "What have I said? What have I done? I know nothing, only that I was
 * lying here, half asleep, and heard you say go on! speak, I command you!'
 * It seemed so funny to hear you order me about, as if I were a bad
 * child!"
 *
 * "Oh, Madam Mina," he said, sadly, "it is proof, if proof be needed, of
 * how I love and honour you, when a word for your good, spoken more
 * earnest than ever, can seem so strange because it is to order her whom I
 * am proud to obey!"
 *
 * The whistles are sounding; we are nearing Galatz. We are on fire with
 * anxiety and eagerness.
 *
 *
 * _Mina Harker's Journal._
 *
 * _30 October._--Mr. Morris took me to the hotel where our rooms had been
 * ordered by telegraph, he being the one who could best be spared, since
 * he does not speak any foreign language. The forces were distributed
 * much as they had been at Varna, except that Lord Godalming went to the
 * Vice-Consul, as his rank might serve as an immediate guarantee of some
 * sort to the official, we being in extreme hurry. Jonathan and the two
 * doctors went to the shipping agent to learn particulars of the arrival
 * of the _Czarina Catherine_.
 *
 *        *       *       *       *       *
 *
 * _Later._--Lord Godalming has returned. The Consul is away, and the
 * Vice-Consul sick; so the routine work has been attended to by a clerk.
 * He was very obliging, and offered to do anything in his power.
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _30 October._--At nine o'clock Dr. Van Helsing, Dr. Seward, and I called
 * on Messrs. Mackenzie & Steinkoff, the agents of the London firm of
 * Hapgood. They had received a wire from London, in answer to Lord
 * Godalming's telegraphed request, asking us to show them any civility in
 * their power. They were more than kind and courteous, and took us at once
 * on board the _Czarina Catherine_, which lay at anchor out in the river
 * harbour. There we saw the Captain, Donelson by name, who told us of his
 * voyage. He said that in all his life he had never had so favourable a
 * run.
 *
 * "Man!" he said, "but it made us afeard, for we expeckit that we should
 * have to pay for it wi' some rare piece o' ill luck, so as to keep up the
 * average. It's no canny to run frae London to the Black Sea wi' a wind
 * ahint ye, as though the Deil himself were blawin' on yer sail for his
 * ain purpose. An' a' the time we could no speer a thing. Gin we were nigh
 * a ship, or a port, or a headland, a fog fell on us and travelled wi' us,
 * till when after it had lifted and we looked out, the deil a thing could
 * we see. We ran by Gibraltar wi'oot bein' able to signal; an' till we
 * came to the Dardanelles and had to wait to get our permit to pass, we
 * never were within hail o' aught. At first I inclined to slack off sail
 * and beat about till the fog was lifted; but whiles, I thocht that if the
 * Deil was minded to get us into the Black Sea quick, he was like to do it
 * whether we would or no. If we had a quick voyage it would be no to our
 * miscredit wi' the owners, or no hurt to our traffic; an' the Old Mon who
 * had served his ain purpose wad be decently grateful to us for no
 * hinderin' him." This mixture of simplicity and cunning, of superstition
 * and commercial reasoning, aroused Van Helsing, who said:--
 *
 * "Mine friend, that Devil is more clever than he is thought by some; and
 * he know when he meet his match!" The skipper was not displeased with the
 * compliment, and went on:--
 *
 * "When we got past the Bosphorus the men began to grumble; some o' them,
 * the Roumanians, came and asked me to heave overboard a big box which had
 * been put on board by a queer lookin' old man just before we had started
 * frae London. I had seen them speer at the fellow, and put out their twa
 * fingers when they saw him, to guard against the evil eye. Man! but the
 * supersteetion of foreigners is pairfectly rideeculous! I sent them aboot
 * their business pretty quick; but as just after a fog closed in on us I
 * felt a wee bit as they did anent something, though I wouldn't say it was
 * agin the big box. Well, on we went, and as the fog didn't let up for
 * five days I joost let the wind carry us; for if the Deil wanted to get
 * somewheres--well, he would fetch it up a'reet. An' if he didn't, well,
 * we'd keep a sharp lookout anyhow. Sure eneuch, we had a fair way and
 * deep water all the time; and two days ago, when the mornin' sun came
 * through the fog, we found ourselves just in the river opposite Galatz.
 * The Roumanians were wild, and wanted me right or wrong to take out the
 * box and fling it in the river. I had to argy wi' them aboot it wi' a
 * handspike; an' when the last o' them rose off the deck wi' his head in
 * his hand, I had convinced them that, evil eye or no evil eye, the
 * property and the trust of my owners were better in my hands than in the
 * river Danube. They had, mind ye, taken the box on the deck ready to
 * fling in, and as it was marked Galatz _via_ Varna, I thocht I'd let it
 * lie till we discharged in the port an' get rid o't althegither. We
 * didn't do much clearin' that day, an' had to remain the nicht at anchor;
 * but in the mornin', braw an' airly, an hour before sun-up, a man came
 * aboard wi' an order, written to him from England, to receive a box
 * marked for one Count Dracula. Sure eneuch the matter was one ready to
 * his hand. He had his papers a' reet, an' glad I was to be rid o' the
 * dam' thing, for I was beginnin' masel' to feel uneasy at it. If the Deil
 * did have any luggage aboord the ship, I'm thinkin' it was nane ither
 * than that same!"
 *
 * "What was the name of the man who took it?" asked Dr. Van Helsing with
 * restrained eagerness.
 *
 * "I'll be tellin' ye quick!" he answered, and, stepping down to his
 * cabin, produced a receipt signed "Immanuel Hildesheim." Burgen-strasse
 * 16 was the address. We found out that this was all the Captain knew; so
 * with thanks we came away.
 *
 * We found Hildesheim in his office, a Hebrew of rather the Adelphi
 * Theatre type, with a nose like a sheep, and a fez. His arguments were
 * pointed with specie--we doing the punctuation--and with a little
 * bargaining he told us what he knew. This turned out to be simple but
 * important. He had received a letter from Mr. de Ville of London, telling
 * him to receive, if possible before sunrise so as to avoid customs, a box
 * which would arrive at Galatz in the _Czarina Catherine_. This he was to
 * give in charge to a certain Petrof Skinsky, who dealt with the Slovaks
 * who traded down the river to the port. He had been paid for his work by
 * an English bank note, which had been duly cashed for gold at the Danube
 * International Bank. When Skinsky had come to him, he had taken him to
 * the ship and handed over the box, so as to save porterage. That was all
 * he knew.
 *
 * We then sought for Skinsky, but were unable to find him. One of his
 * neighbours, who did not seem to bear him any affection, said that he had
 * gone away two days before, no one knew whither. This was corroborated by
 * his landlord, who had received by messenger the key of the house
 * together with the rent due, in English money. This had been between ten
 * and eleven o'clock last night. We were at a standstill again.
 *
 * Whilst we were talking one came running and breathlessly gasped out that
 * the body of Skinsky had been found inside the wall of the churchyard of
 * St. Peter, and that the throat had been torn open as if by some wild
 * animal. Those we had been speaking with ran off to see the horror, the
 * women crying out "This is the work of a Slovak!" We hurried away lest we
 * should have been in some way drawn into the affair, and so detained.
 *
 * As we came home we could arrive at no definite conclusion. We were all
 * convinced that the box was on its way, by water, to somewhere; but where
 * that might be we would have to discover. With heavy hearts we came home
 * to the hotel to Mina.
 *
 * When we met together, the first thing was to consult as to taking Mina
 * again into our confidence. Things are getting desperate, and it is at
 * least a chance, though a hazardous one. As a preliminary step, I was
 * released from my promise to her.
 *
 *
 * _Mina Harker's Journal._
 *
 * _30 October, evening._--They were so tired and worn out and dispirited
 * that there was nothing to be done till they had some rest; so I asked
 * them all to lie down for half an hour whilst I should enter everything
 * up to the moment. I feel so grateful to the man who invented the
 * "Traveller's" typewriter, and to Mr. Morris for getting this one for
 * me. I should have felt quite; astray doing the work if I had to write
 * with a pen....
 *
 * It is all done; poor dear, dear Jonathan, what he must have suffered,
 * what must he be suffering now. He lies on the sofa hardly seeming to
 * breathe, and his whole body appears in collapse. His brows are knit; his
 * face is drawn with pain. Poor fellow, maybe he is thinking, and I can
 * see his face all wrinkled up with the concentration of his thoughts. Oh!
 * if I could only help at all.... I shall do what I can.
 *
 * I have asked Dr. Van Helsing, and he has got me all the papers that I
 * have not yet seen.... Whilst they are resting, I shall go over all
 * carefully, and perhaps I may arrive at some conclusion. I shall try to
 * follow the Professor's example, and think without prejudice on the facts
 * before me....
 *
 *        *       *       *       *       *
 *
 * I do believe that under God's providence I have made a discovery. I
 * shall get the maps and look over them....
 *
 *        *       *       *       *       *
 *
 * I am more than ever sure that I am right. My new conclusion is ready, so
 * I shall get our party together and read it. They can judge it; it is
 * well to be accurate, and every minute is precious.
 *
 *
 * _Mina Harker's Memorandum._
 *
 * (Entered in her Journal.)
 *
 * _Ground of inquiry._--Count Dracula's problem is to get back to his own
 * place.
 *
 * (_a_) He must be _brought back_ by some one. This is evident; for had he
 * power to move himself as he wished he could go either as man, or wolf,
 * or bat, or in some other way. He evidently fears discovery or
 * interference, in the state of helplessness in which he must be--confined
 * as he is between dawn and sunset in his wooden box.
 *
 * (_b_) _How is he to be taken?_--Here a process of exclusions may help
 * us. By road, by rail, by water?
 *
 * 1. _By Road._--There are endless difficulties, especially in leaving the
 * city.
 *
 * (_x_) There are people; and people are curious, and investigate. A hint,
 * a surmise, a doubt as to what might be in the box, would destroy him.
 *
 * (_y_) There are, or there may be, customs and octroi officers to pass.
 *
 * (_z_) His pursuers might follow. This is his highest fear; and in order
 * to prevent his being betrayed he has repelled, so far as he can, even
 * his victim--me!
 *
 * 2. _By Rail._--There is no one in charge of the box. It would have to
 * take its chance of being delayed; and delay would be fatal, with enemies
 * on the track. True, he might escape at night; but what would he be, if
 * left in a strange place with no refuge that he could fly to? This is not
 * what he intends; and he does not mean to risk it.
 *
 * 3. _By Water._--Here is the safest way, in one respect, but with most
 * danger in another. On the water he is powerless except at night; even
 * then he can only summon fog and storm and snow and his wolves. But were
 * he wrecked, the living water would engulf him, helpless; and he would
 * indeed be lost. He could have the vessel drive to land; but if it were
 * unfriendly land, wherein he was not free to move, his position would
 * still be desperate.
 *
 * We know from the record that he was on the water; so what we have to do
 * is to ascertain _what_ water.
 *
 * The first thing is to realise exactly what he has done as yet; we may,
 * then, get a light on what his later task is to be.
 *
 * _Firstly._--We must differentiate between what he did in London as part
 * of his general plan of action, when he was pressed for moments and had
 * to arrange as best he could.
 *
 * _Secondly_ we must see, as well as we can surmise it from the facts we
 * know of, what he has done here.
 *
 * As to the first, he evidently intended to arrive at Galatz, and sent
 * invoice to Varna to deceive us lest we should ascertain his means of
 * exit from England; his immediate and sole purpose then was to escape.
 * The proof of this, is the letter of instructions sent to Immanuel
 * Hildesheim to clear and take away the box _before sunrise_. There is
 * also the instruction to Petrof Skinsky. These we must only guess at; but
 * there must have been some letter or message, since Skinsky came to
 * Hildesheim.
 *
 * That, so far, his plans were successful we know. The _Czarina Catherine_
 * made a phenomenally quick journey--so much so that Captain Donelson's
 * suspicions were aroused; but his superstition united with his canniness
 * played the Count's game for him, and he ran with his favouring wind
 * through fogs and all till he brought up blindfold at Galatz. That the
 * Count's arrangements were well made, has been proved. Hildesheim cleared
 * the box, took it off, and gave it to Skinsky. Skinsky took it--and here
 * we lose the trail. We only know that the box is somewhere on the water,
 * moving along. The customs and the octroi, if there be any, have been
 * avoided.
 *
 * Now we come to what the Count must have done after his arrival--_on
 * land_, at Galatz.
 *
 * The box was given to Skinsky before sunrise. At sunrise the Count could
 * appear in his own form. Here, we ask why Skinsky was chosen at all to
 * aid in the work? In my husband's diary, Skinsky is mentioned as dealing
 * with the Slovaks who trade down the river to the port; and the man's
 * remark, that the murder was the work of a Slovak, showed the general
 * feeling against his class. The Count wanted isolation.
 *
 * My surmise is, this: that in London the Count decided to get back to his
 * castle by water, as the most safe and secret way. He was brought from
 * the castle by Szgany, and probably they delivered their cargo to Slovaks
 * who took the boxes to Varna, for there they were shipped for London.
 * Thus the Count had knowledge of the persons who could arrange this
 * service. When the box was on land, before sunrise or after sunset, he
 * came out from his box, met Skinsky and instructed him what to do as to
 * arranging the carriage of the box up some river. When this was done, and
 * he knew that all was in train, he blotted out his traces, as he thought,
 * by murdering his agent.
 *
 * I have examined the map and find that the river most suitable for the
 * Slovaks to have ascended is either the Pruth or the Sereth. I read in
 * the typescript that in my trance I heard cows low and water swirling
 * level with my ears and the creaking of wood. The Count in his box, then,
 * was on a river in an open boat--propelled probably either by oars or
 * poles, for the banks are near and it is working against stream. There
 * would be no such sound if floating down stream.
 *
 * Of course it may not be either the Sereth or the Pruth, but we may
 * possibly investigate further. Now of these two, the Pruth is the more
 * easily navigated, but the Sereth is, at Fundu, joined by the Bistritza
 * which runs up round the Borgo Pass. The loop it makes is manifestly as
 * close to Dracula's castle as can be got by water.
 *
 *
 * _Mina Harker's Journal--continued._
 *
 * When I had done reading, Jonathan took me in his arms and kissed me. The
 * others kept shaking me by both hands, and Dr. Van Helsing said:--
 *
 * "Our dear Madam Mina is once more our teacher. Her eyes have been where
 * we were blinded. Now we are on the track once again, and this time we
 * may succeed. Our enemy is at his most helpless; and if we can come on
 * him by day, on the water, our task will be over. He has a start, but he
 * is powerless to hasten, as he may not leave his box lest those who carry
 * him may suspect; for them to suspect would be to prompt them to throw
 * him in the stream where he perish. This he knows, and will not. Now men,
 * to our Council of War; for, here and now, we must plan what each and all
 * shall do."
 *
 * "I shall get a steam launch and follow him," said Lord Godalming.
 *
 * "And I, horses to follow on the bank lest by chance he land," said Mr.
 * Morris.
 *
 * "Good!" said the Professor, "both good. But neither must go alone. There
 * must be force to overcome force if need be; the Slovak is strong and
 * rough, and he carries rude arms." All the men smiled, for amongst them
 * they carried a small arsenal. Said Mr. Morris:--
 *
 * "I have brought some Winchesters; they are pretty handy in a crowd, and
 * there may be wolves. The Count, if you remember, took some other
 * precautions; he made some requisitions on others that Mrs. Harker could
 * not quite hear or understand. We must be ready at all points." Dr.
 * Seward said:--
 *
 * "I think I had better go with Quincey. We have been accustomed to hunt
 * together, and we two, well armed, will be a match for whatever may come
 * along. You must not be alone, Art. It may be necessary to fight the
 * Slovaks, and a chance thrust--for I don't suppose these fellows carry
 * guns--would undo all our plans. There must be no chances, this time; we
 * shall, not rest until the Count's head and body have been separated, and
 * we are sure that he cannot re-incarnate." He looked at Jonathan as he
 * spoke, and Jonathan looked at me. I could see that the poor dear was
 * torn about in his mind. Of course he wanted to be with me; but then the
 * boat service would, most likely, be the one which would destroy the ...
 * the ... the ... Vampire. (Why did I hesitate to write the word?) He was
 * silent awhile, and during his silence Dr. Van Helsing spoke:--
 *
 * "Friend Jonathan, this is to you for twice reasons. First, because you
 * are young and brave and can fight, and all energies may be needed at the
 * last; and again that it is your right to destroy him--that--which has
 * wrought such woe to you and yours. Be not afraid for Madam Mina; she
 * will be my care, if I may. I am old. My legs are not so quick to run as
 * once; and I am not used to ride so long or to pursue as need be, or to
 * fight with lethal weapons. But I can be of other service; I can fight in
 * other way. And I can die, if need be, as well as younger men. Now let
 * me say that what I would is this: while you, my Lord Godalming and
 * friend Jonathan go in your so swift little steamboat up the river, and
 * whilst John and Quincey guard the bank where perchance he might be
 * landed, I will take Madam Mina right into the heart of the enemy's
 * country. Whilst the old fox is tied in his box, floating on the running
 * stream whence he cannot escape to land--where he dares not raise the lid
 * of his coffin-box lest his Slovak carriers should in fear leave him to
 * perish--we shall go in the track where Jonathan went,--from Bistritz
 * over the Borgo, and find our way to the Castle of Dracula. Here, Madam
 * Mina's hypnotic power will surely help, and we shall find our way--all
 * dark and unknown otherwise--after the first sunrise when we are near
 * that fateful place. There is much to be done, and other places to be
 * made sanctify, so that that nest of vipers be obliterated." Here
 * Jonathan interrupted him hotly:--
 *
 * "Do you mean to say, Professor Van Helsing, that you would bring Mina,
 * in her sad case and tainted as she is with that devil's illness, right
 * into the jaws of his death-trap? Not for the world! Not for Heaven or
 * Hell!" He became almost speechless for a minute, and then went on:--
 *
 * "Do you know what the place is? Have you seen that awful den of hellish
 * infamy--with the very moonlight alive with grisly shapes, and every
 * speck of dust that whirls in the wind a devouring monster in embryo?
 * Have you felt the Vampire's lips upon your throat?" Here he turned to
 * me, and as his eyes lit on my forehead he threw up his arms with a cry:
 * "Oh, my God, what have we done to have this terror upon us!" and he sank
 * down on the sofa in a collapse of misery. The Professor's voice, as he
 * spoke in clear, sweet tones, which seemed to vibrate in the air, calmed
 * us all:--
 *
 * "Oh, my friend, it is because I would save Madam Mina from that awful
 * place that I would go. God forbid that I should take her into that
 * place. There is work--wild work--to be done there, that her eyes may not
 * see. We men here, all save Jonathan, have seen with their own eyes what
 * is to be done before that place can be purify. Remember that we are in
 * terrible straits. If the Count escape us this time--and he is strong and
 * subtle and cunning--he may choose to sleep him for a century, and then
 * in time our dear one"--he took my hand--"would come to him to keep him
 * company, and would be as those others that you, Jonathan, saw. You have
 * told us of their gloating lips; you heard their ribald laugh as they
 * clutched the moving bag that the Count threw to them. You shudder; and
 * well may it be. Forgive me that I make you so much pain, but it is
 * necessary. My friend, is it not a dire need for the which I am giving,
 * possibly my life? If it were that any one went into that place to stay,
 * it is I who would have to go to keep them company."
 *
 * "Do as you will," said Jonathan, with a sob that shook him all over, "we
 * are in the hands of God!"
 *
 *        *       *       *       *       *
 *
 * _Later._--Oh, it did me good to see the way that these brave men worked.
 * How can women help loving men when they are so earnest, and so true, and
 * so brave! And, too, it made me think of the wonderful power of money!
 * What can it not do when it is properly applied; and what might it do
 * when basely used. I felt so thankful that Lord Godalming is rich, and
 * that both he and Mr. Morris, who also has plenty of money, are willing
 * to spend it so freely. For if they did not, our little expedition could
 * not start, either so promptly or so well equipped, as it will within
 * another hour. It is not three hours since it was arranged what part each
 * of us was to do; and now Lord Godalming and Jonathan have a lovely steam
 * launch, with steam up ready to start at a moment's notice. Dr. Seward
 * and Mr. Morris have half a dozen good horses, well appointed. We have
 * all the maps and appliances of various kinds that can be had. Professor
 * Van Helsing and I are to leave by the 11:40 train to-night for Veresti,
 * where we are to get a carriage to drive to the Borgo Pass. We are
 * bringing a good deal of ready money, as we are to buy a carriage and
 * horses. We shall drive ourselves, for we have no one whom we can trust
 * in the matter. The Professor knows something of a great many languages,
 * so we shall get on all right. We have all got arms, even for me a
 * large-bore revolver; Jonathan would not be happy unless I was armed like
 * the rest. Alas! I cannot carry one arm that the rest do; the scar on my
 * forehead forbids that. Dear Dr. Van Helsing comforts me by telling me
 * that I am fully armed as there may be wolves; the weather is getting
 * colder every hour, and there are snow-flurries which come and go as
 * warnings.
 *
 *        *       *       *       *       *
 *
 * _Later._--It took all my courage to say good-bye to my darling. We may
 * never meet again. Courage, Mina! the Professor is looking at you keenly;
 * his look is a warning. There must be no tears now--unless it may be that
 * God will let them fall in gladness.
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _October 30. Night._--I am writing this in the light from the furnace
 * door of the steam launch: Lord Godalming is firing up. He is an
 * experienced hand at the work, as he has had for years a launch of his
 * own on the Thames, and another on the Norfolk Broads. Regarding our
 * plans, we finally decided that Mina's guess was correct, and that if any
 * waterway was chosen for the Count's escape back to his Castle, the
 * Sereth and then the Bistritza at its junction, would be the one. We took
 * it, that somewhere about the 47th degree, north latitude, would be the
 * place chosen for the crossing the country between the river and the
 * Carpathians. We have no fear in running at good speed up the river at
 * night; there is plenty of water, and the banks are wide enough apart to
 * make steaming, even in the dark, easy enough. Lord Godalming tells me to
 * sleep for a while, as it is enough for the present for one to be on
 * watch. But I cannot sleep--how can I with the terrible danger hanging
 * over my darling, and her going out into that awful place.... My only
 * comfort is that we are in the hands of God. Only for that faith it would
 * be easier to die than to live, and so be quit of all the trouble. Mr.
 * Morris and Dr. Seward were off on their long ride before we started;
 * they are to keep up the right bank, far enough off to get on higher
 * lands where they can see a good stretch of river and avoid the following
 * of its curves. They have, for the first stages, two men to ride and lead
 * their spare horses--four in all, so as not to excite curiosity. When
 * they dismiss the men, which shall be shortly, they shall themselves look
 * after the horses. It may be necessary for us to join forces; if so they
 * can mount our whole party. One of the saddles has a movable horn, and
 * can be easily adapted for Mina, if required.
 *
 * It is a wild adventure we are on. Here, as we are rushing along through
 * the darkness, with the cold from the river seeming to rise up and strike
 * us; with all the mysterious voices of the night around us, it all comes
 * home. We seem to be drifting into unknown places and unknown ways; into
 * a whole world of dark and dreadful things. Godalming is shutting the
 * furnace door....
 *
 *        *       *       *       *       *
 *
 * _31 October._--Still hurrying along. The day has come, and Godalming is
 * sleeping. I am on watch. The morning is bitterly cold; the furnace heat
 * is grateful, though we have heavy fur coats. As yet we have passed only
 * a few open boats, but none of them had on board any box or package of
 * anything like the size of the one we seek. The men were scared every
 * time we turned our electric lamp on them, and fell on their knees and
 * prayed.
 *
 *        *       *       *       *       *
 *
 * _1 November, evening._--No news all day; we have found nothing of the
 * kind we seek. We have now passed into the Bistritza; and if we are wrong
 * in our surmise our chance is gone. We have over-hauled every boat, big
 * and little. Early this morning, one crew took us for a Government boat,
 * and treated us accordingly. We saw in this a way of smoothing matters,
 * so at Fundu, where the Bistritza runs into the Sereth, we got a
 * Roumanian flag which we now fly conspicuously. With every boat which we
 * have over-hauled since then this trick has succeeded; we have had every
 * deference shown to us, and not once any objection to whatever we chose
 * to ask or do. Some of the Slovaks tell us that a big boat passed them,
 * going at more than usual speed as she had a double crew on board. This
 * was before they came to Fundu, so they could not tell us whether the
 * boat turned into the Bistritza or continued on up the Sereth. At Fundu
 * we could not hear of any such boat, so she must have passed there in the
 * night. I am feeling very sleepy; the cold is perhaps beginning to tell
 * upon me, and nature must have rest some time. Godalming insists that he
 * shall keep the first watch. God bless him for all his goodness to poor
 * dear Mina and me.
 *
 *        *       *       *       *       *
 *
 * _2 November, morning._--It is broad daylight. That good fellow would not
 * wake me. He says it would have been a sin to, for I slept peacefully and
 * was forgetting my trouble. It seems brutally selfish to me to have slept
 * so long, and let him watch all night; but he was quite right. I am a new
 * man this morning; and, as I sit here and watch him sleeping, I can do
 * all that is necessary both as to minding the engine, steering, and
 * keeping watch. I can feel that my strength and energy are coming back to
 * me. I wonder where Mina is now, and Van Helsing. They should have got to
 * Veresti about noon on Wednesday. It would take them some time to get the
 * carriage and horses; so if they had started and travelled hard, they
 * would be about now at the Borgo Pass. God guide and help them! I am
 * afraid to think what may happen. If we could only go faster! but we
 * cannot; the engines are throbbing and doing their utmost. I wonder how
 * Dr. Seward and Mr. Morris are getting on. There seem to be endless
 * streams running down the mountains into this river, but as none of them
 * are very large--at present, at all events, though they are terrible
 * doubtless in winter and when the snow melts--the horsemen may not have
 * met much obstruction. I hope that before we get to Strasba we may see
 * them; for if by that time we have not overtaken the Count, it may be
 * necessary to take counsel together what to do next.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _2 November._--Three days on the road. No news, and no time to write it
 * if there had been, for every moment is precious. We have had only the
 * rest needful for the horses; but we are both bearing it wonderfully.
 * Those adventurous days of ours are turning up useful. We must push on;
 * we shall never feel happy till we get the launch in sight again.
 *
 *        *       *       *       *       *
 *
 * _3 November._--We heard at Fundu that the launch had gone up the
 * Bistritza. I wish it wasn't so cold. There are signs of snow coming; and
 * if it falls heavy it will stop us. In such case we must get a sledge and
 * go on, Russian fashion.
 *
 *        *       *       *       *       *
 *
 * _4 November._--To-day we heard of the launch having been detained by an
 * accident when trying to force a way up the rapids. The Slovak boats get
 * up all right, by aid of a rope and steering with knowledge. Some went up
 * only a few hours before. Godalming is an amateur fitter himself, and
 * evidently it was he who put the launch in trim again. Finally, they got
 * up the rapids all right, with local help, and are off on the chase
 * afresh. I fear that the boat is not any better for the accident; the
 * peasantry tell us that after she got upon smooth water again, she kept
 * stopping every now and again so long as she was in sight. We must push
 * on harder than ever; our help may be wanted soon.
 *
 *
 * _Mina Harker's Journal._
 *
 * _31 October._--Arrived at Veresti at noon. The Professor tells me that
 * this morning at dawn he could hardly hypnotise me at all, and that all I
 * could say was: "dark and quiet." He is off now buying a carriage and
 * horses. He says that he will later on try to buy additional horses, so
 * that we may be able to change them on the way. We have something more
 * than 70 miles before us. The country is lovely, and most interesting; if
 * only we were under different conditions, how delightful it would be to
 * see it all. If Jonathan and I were driving through it alone what a
 * pleasure it would be. To stop and see people, and learn something of
 * their life, and to fill our minds and memories with all the colour and
 * picturesqueness of the whole wild, beautiful country and the quaint
 * people! But, alas!--
 *
 *        *       *       *       *       *
 *
 * _Later._--Dr. Van Helsing has returned. He has got the carriage and
 * horses; we are to have some dinner, and to start in an hour. The
 * landlady is putting us up a huge basket of provisions; it seems enough
 * for a company of soldiers. The Professor encourages her, and whispers to
 * me that it may be a week before we can get any good food again. He has
 * been shopping too, and has sent home such a wonderful lot of fur coats
 * and wraps, and all sorts of warm things. There will not be any chance of
 * our being cold.
 *
 *        *       *       *       *       *
 *
 * We shall soon be off. I am afraid to think what may happen to us. We are
 * truly in the hands of God. He alone knows what may be, and I pray Him,
 * with all the strength of my sad and humble soul, that He will watch over
 * my beloved husband; that whatever may happen, Jonathan may know that I
 * loved him and honoured him more than I can say, and that my latest and
 * truest thought will be always for him.
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
 * \page chapter_XXVII CHAPTER XXVII: Mina Harker's Journal
 * MINA HARKER'S JOURNAL
 *
 *
 * _1 November._--All day long we have travelled, and at a good speed. The
 * horses seem to know that they are being kindly treated, for they go
 * willingly their full stage at best speed. We have now had so many
 * changes and find the same thing so constantly that we are encouraged to
 * think that the journey will be an easy one. Dr. Van Helsing is laconic;
 * he tells the farmers that he is hurrying to Bistritz, and pays them well
 * to make the exchange of horses. We get hot soup, or coffee, or tea; and
 * off we go. It is a lovely country; full of beauties of all imaginable
 * kinds, and the people are brave, and strong, and simple, and seem full
 * of nice qualities. They are _very, very_ superstitious. In the first
 * house where we stopped, when the woman who served us saw the scar on my
 * forehead, she crossed herself and put out two fingers towards me, to
 * keep off the evil eye. I believe they went to the trouble of putting an
 * extra amount of garlic into our food; and I can't abide garlic. Ever
 * since then I have taken care not to take off my hat or veil, and so have
 * escaped their suspicions. We are travelling fast, and as we have no
 * driver with us to carry tales, we go ahead of scandal; but I daresay
 * that fear of the evil eye will follow hard behind us all the way. The
 * Professor seems tireless; all day he would not take any rest, though he
 * made me sleep for a long spell. At sunset time he hypnotised me, and he
 * says that I answered as usual "darkness, lapping water and creaking
 * wood"; so our enemy is still on the river. I am afraid to think of
 * Jonathan, but somehow I have now no fear for him, or for myself. I write
 * this whilst we wait in a farmhouse for the horses to be got ready. Dr.
 * Van Helsing is sleeping, Poor dear, he looks very tired and old and
 * grey, but his mouth is set as firmly as a conqueror's; even in his sleep
 * he is instinct with resolution. When we have well started I must make
 * him rest whilst I drive. I shall tell him that we have days before us,
 * and we must not break down when most of all his strength will be
 * needed.... All is ready; we are off shortly.
 *
 *        *       *       *       *       *
 *
 * _2 November, morning._--I was successful, and we took turns driving all
 * night; now the day is on us, bright though cold. There is a strange
 * heaviness in the air--I say heaviness for want of a better word; I mean
 * that it oppresses us both. It is very cold, and only our warm furs keep
 * us comfortable. At dawn Van Helsing hypnotised me; he says I answered
 * "darkness, creaking wood and roaring water," so the river is changing as
 * they ascend. I do hope that my darling will not run any chance of
 * danger--more than need be; but we are in God's hands.
 *
 *        *       *       *       *       *
 *
 * _2 November, night._--All day long driving. The country gets wilder as
 * we go, and the great spurs of the Carpathians, which at Veresti seemed
 * so far from us and so low on the horizon, now seem to gather round us
 * and tower in front. We both seem in good spirits; I think we make an
 * effort each to cheer the other; in the doing so we cheer ourselves. Dr.
 * Van Helsing says that by morning we shall reach the Borgo Pass. The
 * houses are very few here now, and the Professor says that the last horse
 * we got will have to go on with us, as we may not be able to change. He
 * got two in addition to the two we changed, so that now we have a rude
 * four-in-hand. The dear horses are patient and good, and they give us no
 * trouble. We are not worried with other travellers, and so even I can
 * drive. We shall get to the Pass in daylight; we do not want to arrive
 * before. So we take it easy, and have each a long rest in turn. Oh, what
 * will to-morrow bring to us? We go to seek the place where my poor
 * darling suffered so much. God grant that we may be guided aright, and
 * that He will deign to watch over my husband and those dear to us both,
 * and who are in such deadly peril. As for me, I am not worthy in His
 * sight. Alas! I am unclean to His eyes, and shall be until He may deign
 * to let me stand forth in His sight as one of those who have not incurred
 * His wrath.
 *
 *
 * _Memorandum by Abraham Van Helsing._
 *
 * _4 November._--This to my old and true friend John Seward, M.D., of
 * Purfleet, London, in case I may not see him. It may explain. It is
 * morning, and I write by a fire which all the night I have kept
 * alive--Madam Mina aiding me. It is cold, cold; so cold that the grey
 * heavy sky is full of snow, which when it falls will settle for all
 * winter as the ground is hardening to receive it. It seems to have
 * affected Madam Mina; she has been so heavy of head all day that she was
 * not like herself. She sleeps, and sleeps, and sleeps! She who is usual
 * so alert, have done literally nothing all the day; she even have lost
 * her appetite. She make no entry into her little diary, she who write so
 * faithful at every pause. Something whisper to me that all is not well.
 * However, to-night she is more _vif_. Her long sleep all day have refresh
 * and restore her, for now she is all sweet and bright as ever. At sunset
 * I try to hypnotise her, but alas! with no effect; the power has grown
 * less and less with each day, and to-night it fail me altogether. Well,
 * God's will be done--whatever it may be, and whithersoever it may lead!
 *
 * Now to the historical, for as Madam Mina write not in her stenography, I
 * must, in my cumbrous old fashion, that so each day of us may not go
 * unrecorded.
 *
 * We got to the Borgo Pass just after sunrise yesterday morning. When I
 * saw the signs of the dawn I got ready for the hypnotism. We stopped our
 * carriage, and got down so that there might be no disturbance. I made a
 * couch with furs, and Madam Mina, lying down, yield herself as usual, but
 * more slow and more short time than ever, to the hypnotic sleep. As
 * before, came the answer: "darkness and the swirling of water." Then she
 * woke, bright and radiant and we go on our way and soon reach the Pass.
 * At this time and place, she become all on fire with zeal; some new
 * guiding power be in her manifested, for she point to a road and say:--
 *
 * "This is the way."
 *
 * "How know you it?" I ask.
 *
 * "Of course I know it," she answer, and with a pause, add: "Have not my
 * Jonathan travelled it and wrote of his travel?"
 *
 * At first I think somewhat strange, but soon I see that there be only one
 * such by-road. It is used but little, and very different from the coach
 * road from the Bukovina to Bistritz, which is more wide and hard, and
 * more of use.
 *
 * So we came down this road; when we meet other ways--not always were we
 * sure that they were roads at all, for they be neglect and light snow
 * have fallen--the horses know and they only. I give rein to them, and
 * they go on so patient. By-and-by we find all the things which Jonathan
 * have note in that wonderful diary of him. Then we go on for long, long
 * hours and hours. At the first, I tell Madam Mina to sleep; she try, and
 * she succeed. She sleep all the time; till at the last, I feel myself to
 * suspicious grow, and attempt to wake her. But she sleep on, and I may
 * not wake her though I try. I do not wish to try too hard lest I harm
 * her; for I know that she have suffer much, and sleep at times be
 * all-in-all to her. I think I drowse myself, for all of sudden I feel
 * guilt, as though I have done something; I find myself bolt up, with the
 * reins in my hand, and the good horses go along jog, jog, just as ever. I
 * look down and find Madam Mina still sleep. It is now not far off sunset
 * time, and over the snow the light of the sun flow in big yellow flood,
 * so that we throw great long shadow on where the mountain rise so steep.
 * For we are going up, and up; and all is oh! so wild and rocky, as though
 * it were the end of the world.
 *
 * Then I arouse Madam Mina. This time she wake with not much trouble, and
 * then I try to put her to hypnotic sleep. But she sleep not, being as
 * though I were not. Still I try and try, till all at once I find her and
 * myself in dark; so I look round, and find that the sun have gone down.
 * Madam Mina laugh, and I turn and look at her. She is now quite awake,
 * and look so well as I never saw her since that night at Carfax when we
 * first enter the Count's house. I am amaze, and not at ease then; but she
 * is so bright and tender and thoughtful for me that I forget all fear. I
 * light a fire, for we have brought supply of wood with us, and she
 * prepare food while I undo the horses and set them, tethered in shelter,
 * to feed. Then when I return to the fire she have my supper ready. I go
 * to help her; but she smile, and tell me that she have eat already--that
 * she was so hungry that she would not wait. I like it not, and I have
 * grave doubts; but I fear to affright her, and so I am silent of it. She
 * help me and I eat alone; and then we wrap in fur and lie beside the
 * fire, and I tell her to sleep while I watch. But presently I forget all
 * of watching; and when I sudden remember that I watch, I find her lying
 * quiet, but awake, and looking at me with so bright eyes. Once, twice
 * more the same occur, and I get much sleep till before morning. When I
 * wake I try to hypnotise her; but alas! though she shut her eyes
 * obedient, she may not sleep. The sun rise up, and up, and up; and then
 * sleep come to her too late, but so heavy that she will not wake. I have
 * to lift her up, and place her sleeping in the carriage when I have
 * harnessed the horses and made all ready. Madam still sleep, and she look
 * in her sleep more healthy and more redder than before. And I like it
 * not. And I am afraid, afraid, afraid!--I am afraid of all things--even
 * to think but I must go on my way. The stake we play for is life and
 * death, or more than these, and we must not flinch.
 *
 *        *       *       *       *       *
 *
 * _5 November, morning._--Let me be accurate in everything, for though you
 * and I have seen some strange things together, you may at the first think
 * that I, Van Helsing, am mad--that the many horrors and the so long
 * strain on nerves has at the last turn my brain.
 *
 * All yesterday we travel, ever getting closer to the mountains, and
 * moving into a more and more wild and desert land. There are great,
 * frowning precipices and much falling water, and Nature seem to have held
 * sometime her carnival. Madam Mina still sleep and sleep; and though I
 * did have hunger and appeased it, I could not waken her--even for food. I
 * began to fear that the fatal spell of the place was upon her, tainted as
 * she is with that Vampire baptism. "Well," said I to myself, "if it be
 * that she sleep all the day, it shall also be that I do not sleep at
 * night." As we travel on the rough road, for a road of an ancient and
 * imperfect kind there was, I held down my head and slept. Again I waked
 * with a sense of guilt and of time passed, and found Madam Mina still
 * sleeping, and the sun low down. But all was indeed changed; the frowning
 * mountains seemed further away, and we were near the top of a
 * steep-rising hill, on summit of which was such a castle as Jonathan tell
 * of in his diary. At once I exulted and feared; for now, for good or ill,
 * the end was near.
 *
 * I woke Madam Mina, and again tried to hypnotise her; but alas!
 * unavailing till too late. Then, ere the great dark came upon us--for
 * even after down-sun the heavens reflected the gone sun on the snow, and
 * all was for a time in a great twilight--I took out the horses and fed
 * them in what shelter I could. Then I make a fire; and near it I make
 * Madam Mina, now awake and more charming than ever, sit comfortable amid
 * her rugs. I got ready food: but she would not eat, simply saying that
 * she had not hunger. I did not press her, knowing her unavailingness. But
 * I myself eat, for I must needs now be strong for all. Then, with the
 * fear on me of what might be, I drew a ring so big for her comfort, round
 * where Madam Mina sat; and over the ring I passed some of the wafer, and
 * I broke it fine so that all was well guarded. She sat still all the
 * time--so still as one dead; and she grew whiter and ever whiter till the
 * snow was not more pale; and no word she said. But when I drew near, she
 * clung to me, and I could know that the poor soul shook her from head to
 * feet with a tremor that was pain to feel. I said to her presently, when
 * she had grown more quiet:--
 *
 * "Will you not come over to the fire?" for I wished to make a test of
 * what she could. She rose obedient, but when she have made a step she
 * stopped, and stood as one stricken.
 *
 * "Why not go on?" I asked. She shook her head, and, coming back, sat
 * down in her place. Then, looking at me with open eyes, as of one waked
 * from sleep, she said simply:--
 *
 * "I cannot!" and remained silent. I rejoiced, for I knew that what she
 * could not, none of those that we dreaded could. Though there might be
 * danger to her body, yet her soul was safe!
 *
 * Presently the horses began to scream, and tore at their tethers till I
 * came to them and quieted them. When they did feel my hands on them, they
 * whinnied low as in joy, and licked at my hands and were quiet for a
 * time. Many times through the night did I come to them, till it arrive to
 * the cold hour when all nature is at lowest; and every time my coming was
 * with quiet of them. In the cold hour the fire began to die, and I was
 * about stepping forth to replenish it, for now the snow came in flying
 * sweeps and with it a chill mist. Even in the dark there was a light of
 * some kind, as there ever is over snow; and it seemed as though the
 * snow-flurries and the wreaths of mist took shape as of women with
 * trailing garments. All was in dead, grim silence only that the horses
 * whinnied and cowered, as if in terror of the worst. I began to
 * fear--horrible fears; but then came to me the sense of safety in that
 * ring wherein I stood. I began, too, to think that my imaginings were of
 * the night, and the gloom, and the unrest that I have gone through, and
 * all the terrible anxiety. It was as though my memories of all Jonathan's
 * horrid experience were befooling me; for the snow flakes and the mist
 * began to wheel and circle round, till I could get as though a shadowy
 * glimpse of those women that would have kissed him. And then the horses
 * cowered lower and lower, and moaned in terror as men do in pain. Even
 * the madness of fright was not to them, so that they could break away. I
 * feared for my dear Madam Mina when these weird figures drew near and
 * circled round. I looked at her, but she sat calm, and smiled at me; when
 * I would have stepped to the fire to replenish it, she caught me and held
 * me back, and whispered, like a voice that one hears in a dream, so low
 * it was:--
 *
 * "No! No! Do not go without. Here you are safe!" I turned to her, and
 * looking in her eyes, said:--
 *
 * "But you? It is for you that I fear!" whereat she laughed--a laugh, low
 * and unreal, and said:--
 *
 * "Fear for _me_! Why fear for me? None safer in all the world from them
 * than I am," and as I wondered at the meaning of her words, a puff of
 * wind made the flame leap up, and I see the red scar on her forehead.
 * Then, alas! I knew. Did I not, I would soon have learned, for the
 * wheeling figures of mist and snow came closer, but keeping ever without
 * the Holy circle. Then they began to materialise till--if God have not
 * take away my reason, for I saw it through my eyes--there were before me
 * in actual flesh the same three women that Jonathan saw in the room, when
 * they would have kissed his throat. I knew the swaying round forms, the
 * bright hard eyes, the white teeth, the ruddy colour, the voluptuous
 * lips. They smiled ever at poor dear Madam Mina; and as their laugh came
 * through the silence of the night, they twined their arms and pointed to
 * her, and said in those so sweet tingling tones that Jonathan said were
 * of the intolerable sweetness of the water-glasses:--
 *
 * "Come, sister. Come to us. Come! Come!" In fear I turned to my poor
 * Madam Mina, and my heart with gladness leapt like flame; for oh! the
 * terror in her sweet eyes, the repulsion, the horror, told a story to my
 * heart that was all of hope. God be thanked she was not, yet, of them. I
 * seized some of the firewood which was by me, and holding out some of the
 * Wafer, advanced on them towards the fire. They drew back before me, and
 * laughed their low horrid laugh. I fed the fire, and feared them not; for
 * I knew that we were safe within our protections. They could not
 * approach, me, whilst so armed, nor Madam Mina whilst she remained within
 * the ring, which she could not leave no more than they could enter. The
 * horses had ceased to moan, and lay still on the ground; the snow fell on
 * them softly, and they grew whiter. I knew that there was for the poor
 * beasts no more of terror.
 *
 * And so we remained till the red of the dawn to fall through the
 * snow-gloom. I was desolate and afraid, and full of woe and terror; but
 * when that beautiful sun began to climb the horizon life was to me again.
 * At the first coming of the dawn the horrid figures melted in the
 * whirling mist and snow; the wreaths of transparent gloom moved away
 * towards the castle, and were lost.
 *
 * Instinctively, with the dawn coming, I turned to Madam Mina, intending
 * to hypnotise her; but she lay in a deep and sudden sleep, from which I
 * could not wake her. I tried to hypnotise through her sleep, but she made
 * no response, none at all; and the day broke. I fear yet to stir. I have
 * made my fire and have seen the horses, they are all dead. To-day I have
 * much to do here, and I keep waiting till the sun is up high; for there
 * may be places where I must go, where that sunlight, though snow and mist
 * obscure it, will be to me a safety.
 *
 * I will strengthen me with breakfast, and then I will to my terrible
 * work. Madam Mina still sleeps; and, God be thanked! she is calm in her
 * sleep....
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _4 November, evening._--The accident to the launch has been a terrible
 * thing for us. Only for it we should have overtaken the boat long ago;
 * and by now my dear Mina would have been free. I fear to think of her,
 * off on the wolds near that horrid place. We have got horses, and we
 * follow on the track. I note this whilst Godalming is getting ready. We
 * have our arms. The Szgany must look out if they mean fight. Oh, if only
 * Morris and Seward were with us. We must only hope! If I write no more
 * Good-bye, Mina! God bless and keep you.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _5 November._--With the dawn we saw the body of Szgany before us dashing
 * away from the river with their leiter-wagon. They surrounded it in a
 * cluster, and hurried along as though beset. The snow is falling lightly
 * and there is a strange excitement in the air. It may be our own
 * feelings, but the depression is strange. Far off I hear the howling of
 * wolves; the snow brings them down from the mountains, and there are
 * dangers to all of us, and from all sides. The horses are nearly ready,
 * and we are soon off. We ride to death of some one. God alone knows who,
 * or where, or what, or when, or how it may be....
 *
 *
 * _Dr. Van Helsing's Memorandum._
 *
 * _5 November, afternoon._--I am at least sane. Thank God for that mercy
 * at all events, though the proving it has been dreadful. When I left
 * Madam Mina sleeping within the Holy circle, I took my way to the castle.
 * The blacksmith hammer which I took in the carriage from Veresti was
 * useful; though the doors were all open I broke them off the rusty
 * hinges, lest some ill-intent or ill-chance should close them, so that
 * being entered I might not get out. Jonathan's bitter experience served
 * me here. By memory of his diary I found my way to the old chapel, for I
 * knew that here my work lay. The air was oppressive; it seemed as if
 * there was some sulphurous fume, which at times made me dizzy. Either
 * there was a roaring in my ears or I heard afar off the howl of wolves.
 * Then I bethought me of my dear Madam Mina, and I was in terrible plight.
 * The dilemma had me between his horns.
 *
 * Her, I had not dare to take into this place, but left safe from the
 * Vampire in that Holy circle; and yet even there would be the wolf! I
 * resolve me that my work lay here, and that as to the wolves we must
 * submit, if it were God's will. At any rate it was only death and
 * freedom beyond. So did I choose for her. Had it but been for myself the
 * choice had been easy, the maw of the wolf were better to rest in than
 * the grave of the Vampire! So I make my choice to go on with my work.
 *
 * I knew that there were at least three graves to find--graves that are
 * inhabit; so I search, and search, and I find one of them. She lay in her
 * Vampire sleep, so full of life and voluptuous beauty that I shudder as
 * though I have come to do murder. Ah, I doubt not that in old time, when
 * such things were, many a man who set forth to do such a task as mine,
 * found at the last his heart fail him, and then his nerve. So he delay,
 * and delay, and delay, till the mere beauty and the fascination of the
 * wanton Un-Dead have hypnotise him; and he remain on and on, till sunset
 * come, and the Vampire sleep be over. Then the beautiful eyes of the fair
 * woman open and look love, and the voluptuous mouth present to a
 * kiss--and man is weak. And there remain one more victim in the Vampire
 * fold; one more to swell the grim and grisly ranks of the Un-Dead!...
 *
 * There is some fascination, surely, when I am moved by the mere presence
 * of such an one, even lying as she lay in a tomb fretted with age and
 * heavy with the dust of centuries, though there be that horrid odour such
 * as the lairs of the Count have had. Yes, I was moved--I, Van Helsing,
 * with all my purpose and with my motive for hate--I was moved to a
 * yearning for delay which seemed to paralyse my faculties and to clog my
 * very soul. It may have been that the need of natural sleep, and the
 * strange oppression of the air were beginning to overcome me. Certain it
 * was that I was lapsing into sleep, the open-eyed sleep of one who yields
 * to a sweet fascination, when there came through the snow-stilled air a
 * long, low wail, so full of woe and pity that it woke me like the sound
 * of a clarion. For it was the voice of my dear Madam Mina that I heard.
 *
 * Then I braced myself again to my horrid task, and found by wrenching
 * away tomb-tops one other of the sisters, the other dark one. I dared not
 * pause to look on her as I had on her sister, lest once more I should
 * begin to be enthrall; but I go on searching until, presently, I find in
 * a high great tomb as if made to one much beloved that other fair sister
 * which, like Jonathan I had seen to gather herself out of the atoms of
 * the mist. She was so fair to look on, so radiantly beautiful, so
 * exquisitely voluptuous, that the very instinct of man in me, which calls
 * some of my sex to love and to protect one of hers, made my head whirl
 * with new emotion. But God be thanked, that soul-wail of my dear Madam
 * Mina had not died out of my ears; and, before the spell could be wrought
 * further upon me, I had nerved myself to my wild work. By this time I had
 * searched all the tombs in the chapel, so far as I could tell; and as
 * there had been only three of these Un-Dead phantoms around us in the
 * night, I took it that there were no more of active Un-Dead existent.
 * There was one great tomb more lordly than all the rest; huge it was, and
 * nobly proportioned. On it was but one word
 *
 *                                 DRACULA.
 *
 * This then was the Un-Dead home of the King-Vampire, to whom so many more
 * were due. Its emptiness spoke eloquent to make certain what I knew.
 * Before I began to restore these women to their dead selves through my
 * awful work, I laid in Dracula's tomb some of the Wafer, and so banished
 * him from it, Un-Dead, for ever.
 *
 * Then began my terrible task, and I dreaded it. Had it been but one, it
 * had been easy, comparative. But three! To begin twice more after I had
 * been through a deed of horror; for if it was terrible with the sweet
 * Miss Lucy, what would it not be with these strange ones who had survived
 * through centuries, and who had been strengthened by the passing of the
 * years; who would, if they could, have fought for their foul lives....
 *
 * Oh, my friend John, but it was butcher work; had I not been nerved by
 * thoughts of other dead, and of the living over whom hung such a pall of
 * fear, I could not have gone on. I tremble and tremble even yet, though
 * till all was over, God be thanked, my nerve did stand. Had I not seen
 * the repose in the first place, and the gladness that stole over it just
 * ere the final dissolution came, as realisation that the soul had been
 * won, I could not have gone further with my butchery. I could not have
 * endured the horrid screeching as the stake drove home; the plunging of
 * writhing form, and lips of bloody foam. I should have fled in terror and
 * left my work undone. But it is over! And the poor souls, I can pity them
 * now and weep, as I think of them placid each in her full sleep of death
 * for a short moment ere fading. For, friend John, hardly had my knife
 * severed the head of each, before the whole body began to melt away and
 * crumble in to its native dust, as though the death that should have come
 * centuries agone had at last assert himself and say at once and loud "I
 * am here!"
 *
 * Before I left the castle I so fixed its entrances that never more can
 * the Count enter there Un-Dead.
 *
 * When I stepped into the circle where Madam Mina slept, she woke from her
 * sleep, and, seeing, me, cried out in pain that I had endured too much.
 *
 * "Come!" she said, "come away from this awful place! Let us go to meet my
 * husband who is, I know, coming towards us." She was looking thin and
 * pale and weak; but her eyes were pure and glowed with fervour. I was
 * glad to see her paleness and her illness, for my mind was full of the
 * fresh horror of that ruddy vampire sleep.
 *
 * And so with trust and hope, and yet full of fear, we go eastward to meet
 * our friends--and _him_--whom Madam Mina tell me that she _know_ are
 * coming to meet us.
 *
 *
 * _Mina Harker's Journal._
 *
 * _6 November._--It was late in the afternoon when the Professor and I
 * took our way towards the east whence I knew Jonathan was coming. We did
 * not go fast, though the way was steeply downhill, for we had to take
 * heavy rugs and wraps with us; we dared not face the possibility of being
 * left without warmth in the cold and the snow. We had to take some of our
 * provisions, too, for we were in a perfect desolation, and, so far as we
 * could see through the snowfall, there was not even the sign of
 * habitation. When we had gone about a mile, I was tired with the heavy
 * walking and sat down to rest. Then we looked back and saw where the
 * clear line of Dracula's castle cut the sky; for we were so deep under
 * the hill whereon it was set that the angle of perspective of the
 * Carpathian mountains was far below it. We saw it in all its grandeur,
 * perched a thousand feet on the summit of a sheer precipice, and with
 * seemingly a great gap between it and the steep of the adjacent mountain
 * on any side. There was something wild and uncanny about the place. We
 * could hear the distant howling of wolves. They were far off, but the
 * sound, even though coming muffled through the deadening snowfall, was
 * full of terror. I knew from the way Dr. Van Helsing was searching about
 * that he was trying to seek some strategic point, where we would be less
 * exposed in case of attack. The rough roadway still led downwards; we
 * could trace it through the drifted snow.
 *
 * In a little while the Professor signalled to me, so I got up and joined
 * him. He had found a wonderful spot, a sort of natural hollow in a rock,
 * with an entrance like a doorway between two boulders. He took me by the
 * hand and drew me in: "See!" he said, "here you will be in shelter; and
 * if the wolves do come I can meet them one by one." He brought in our
 * furs, and made a snug nest for me, and got out some provisions and
 * forced them upon me. But I could not eat; to even try to do so was
 * repulsive to me, and, much as I would have liked to please him, I could
 * not bring myself to the attempt. He looked very sad, but did not
 * reproach me. Taking his field-glasses from the case, he stood on the top
 * of the rock, and began to search the horizon. Suddenly he called out:--
 *
 * "Look! Madam Mina, look! look!" I sprang up and stood beside him on the
 * rock; he handed me his glasses and pointed. The snow was now falling
 * more heavily, and swirled about fiercely, for a high wind was beginning
 * to blow. However, there were times when there were pauses between the
 * snow flurries and I could see a long way round. From the height where we
 * were it was possible to see a great distance; and far off, beyond the
 * white waste of snow, I could see the river lying like a black ribbon in
 * kinks and curls as it wound its way. Straight in front of us and not far
 * off--in fact, so near that I wondered we had not noticed before--came a
 * group of mounted men hurrying along. In the midst of them was a cart, a
 * long leiter-wagon which swept from side to side, like a dog's tail
 * wagging, with each stern inequality of the road. Outlined against the
 * snow as they were, I could see from the men's clothes that they were
 * peasants or gypsies of some kind.
 *
 * On the cart was a great square chest. My heart leaped as I saw it, for I
 * felt that the end was coming. The evening was now drawing close, and
 * well I knew that at sunset the Thing, which was till then imprisoned
 * there, would take new freedom and could in any of many forms elude all
 * pursuit. In fear I turned to the Professor; to my consternation,
 * however, he was not there. An instant later, I saw him below me. Round
 * the rock he had drawn a circle, such as we had found shelter in last
 * night. When he had completed it he stood beside me again, saying:--
 *
 * "At least you shall be safe here from _him_!" He took the glasses from
 * me, and at the next lull of the snow swept the whole space below us.
 * "See," he said, "they come quickly; they are flogging the horses, and
 * galloping as hard as they can." He paused and went on in a hollow
 * voice:--
 *
 * "They are racing for the sunset. We may be too late. God's will be
 * done!" Down came another blinding rush of driving snow, and the whole
 * landscape was blotted out. It soon passed, however, and once more his
 * glasses were fixed on the plain. Then came a sudden cry:--
 *
 * "Look! Look! Look! See, two horsemen follow fast, coming up from the
 * south. It must be Quincey and John. Take the glass. Look before the snow
 * blots it all out!" I took it and looked. The two men might be Dr. Seward
 * and Mr. Morris. I knew at all events that neither of them was Jonathan.
 * At the same time I _knew_ that Jonathan was not far off; looking around
 * I saw on the north side of the coming party two other men, riding at
 * break-neck speed. One of them I knew was Jonathan, and the other I took,
 * of course, to be Lord Godalming. They, too, were pursuing the party with
 * the cart. When I told the Professor he shouted in glee like a schoolboy,
 * and, after looking intently till a snow fall made sight impossible, he
 * laid his Winchester rifle ready for use against the boulder at the
 * opening of our shelter. "They are all converging," he said. "When the
 * time comes we shall have gypsies on all sides." I got out my revolver
 * ready to hand, for whilst we were speaking the howling of wolves came
 * louder and closer. When the snow storm abated a moment we looked again.
 * It was strange to see the snow falling in such heavy flakes close to us,
 * and beyond, the sun shining more and more brightly as it sank down
 * towards the far mountain tops. Sweeping the glass all around us I could
 * see here and there dots moving singly and in twos and threes and larger
 * numbers--the wolves were gathering for their prey.
 *
 * Every instant seemed an age whilst we waited. The wind came now in
 * fierce bursts, and the snow was driven with fury as it swept upon us in
 * circling eddies. At times we could not see an arm's length before us;
 * but at others, as the hollow-sounding wind swept by us, it seemed to
 * clear the air-space around us so that we could see afar off. We had of
 * late been so accustomed to watch for sunrise and sunset, that we knew
 * with fair accuracy when it would be; and we knew that before long the
 * sun would set. It was hard to believe that by our watches it was less
 * than an hour that we waited in that rocky shelter before the various
 * bodies began to converge close upon us. The wind came now with fiercer
 * and more bitter sweeps, and more steadily from the north. It seemingly
 * had driven the snow clouds from us, for, with only occasional bursts,
 * the snow fell. We could distinguish clearly the individuals of each
 * party, the pursued and the pursuers. Strangely enough those pursued did
 * not seem to realise, or at least to care, that they were pursued; they
 * seemed, however, to hasten with redoubled speed as the sun dropped lower
 * and lower on the mountain tops.
 *
 * Closer and closer they drew. The Professor and I crouched down behind
 * our rock, and held our weapons ready; I could see that he was determined
 * that they should not pass. One and all were quite unaware of our
 * presence.
 *
 * All at once two voices shouted out to: "Halt!" One was my Jonathan's,
 * raised in a high key of passion; the other Mr. Morris' strong resolute
 * tone of quiet command. The gypsies may not have known the language, but
 * there was no mistaking the tone, in whatever tongue the words were
 * spoken. Instinctively they reined in, and at the instant Lord Godalming
 * and Jonathan dashed up at one side and Dr. Seward and Mr. Morris on the
 * other. The leader of the gypsies, a splendid-looking fellow who sat his
 * horse like a centaur, waved them back, and in a fierce voice gave to his
 * companions some word to proceed. They lashed the horses which sprang
 * forward; but the four men raised their Winchester rifles, and in an
 * unmistakable way commanded them to stop. At the same moment Dr. Van
 * Helsing and I rose behind the rock and pointed our weapons at them.
 * Seeing that they were surrounded the men tightened their reins and drew
 * up. The leader turned to them and gave a word at which every man of the
 * gypsy party drew what weapon he carried, knife or pistol, and held
 * himself in readiness to attack. Issue was joined in an instant.
 *
 * The leader, with a quick movement of his rein, threw his horse out in
 * front, and pointing first to the sun--now close down on the hill
 * tops--and then to the castle, said something which I did not understand.
 * For answer, all four men of our party threw themselves from their horses
 * and dashed towards the cart. I should have felt terrible fear at seeing
 * Jonathan in such danger, but that the ardour of battle must have been
 * upon me as well as the rest of them; I felt no fear, but only a wild,
 * surging desire to do something. Seeing the quick movement of our
 * parties, the leader of the gypsies gave a command; his men instantly
 * formed round the cart in a sort of undisciplined endeavour, each one
 * shouldering and pushing the other in his eagerness to carry out the
 * order.
 *
 * In the midst of this I could see that Jonathan on one side of the ring
 * of men, and Quincey on the other, were forcing a way to the cart; it was
 * evident that they were bent on finishing their task before the sun
 * should set. Nothing seemed to stop or even to hinder them. Neither the
 * levelled weapons nor the flashing knives of the gypsies in front, nor
 * the howling of the wolves behind, appeared to even attract their
 * attention. Jonathan's impetuosity, and the manifest singleness of his
 * purpose, seemed to overawe those in front of him; instinctively they
 * cowered, aside and let him pass. In an instant he had jumped upon the
 * cart, and, with a strength which seemed incredible, raised the great
 * box, and flung it over the wheel to the ground. In the meantime, Mr.
 * Morris had had to use force to pass through his side of the ring of
 * Szgany. All the time I had been breathlessly watching Jonathan I had,
 * with the tail of my eye, seen him pressing desperately forward, and had
 * seen the knives of the gypsies flash as he won a way through them, and
 * they cut at him. He had parried with his great bowie knife, and at first
 * I thought that he too had come through in safety; but as he sprang
 * beside Jonathan, who had by now jumped from the cart, I could see that
 * with his left hand he was clutching at his side, and that the blood was
 * spurting through his fingers. He did not delay notwithstanding this, for
 * as Jonathan, with desperate energy, attacked one end of the chest,
 * attempting to prize off the lid with his great Kukri knife, he attacked
 * the other frantically with his bowie. Under the efforts of both men the
 * lid began to yield; the nails drew with a quick screeching sound, and
 * the top of the box was thrown back.
 *
 * By this time the gypsies, seeing themselves covered by the Winchesters,
 * and at the mercy of Lord Godalming and Dr. Seward, had given in and made
 * no resistance. The sun was almost down on the mountain tops, and the
 * shadows of the whole group fell long upon the snow. I saw the Count
 * lying within the box upon the earth, some of which the rude falling from
 * the cart had scattered over him. He was deathly pale, just like a waxen
 * image, and the red eyes glared with the horrible vindictive look which I
 * knew too well.
 *
 * As I looked, the eyes saw the sinking sun, and the look of hate in them
 * turned to triumph.
 *
 * But, on the instant, came the sweep and flash of Jonathan's great knife.
 * I shrieked as I saw it shear through the throat; whilst at the same
 * moment Mr. Morris's bowie knife plunged into the heart.
 *
 * It was like a miracle; but before our very eyes, and almost in the
 * drawing of a breath, the whole body crumble into dust and passed from
 * our sight.
 *
 * I shall be glad as long as I live that even in that moment of final
 * dissolution, there was in the face a look of peace, such as I never
 * could have imagined might have rested there.
 *
 * The Castle of Dracula now stood out against the red sky, and every stone
 * of its broken battlements was articulated against the light of the
 * setting sun.
 *
 * The gypsies, taking us as in some way the cause of the extraordinary
 * disappearance of the dead man, turned, without a word, and rode away as
 * if for their lives. Those who were unmounted jumped upon the
 * leiter-wagon and shouted to the horsemen not to desert them. The wolves,
 * which had withdrawn to a safe distance, followed in their wake, leaving
 * us alone.
 *
 * Mr. Morris, who had sunk to the ground, leaned on his elbow, holding his
 * hand pressed to his side; the blood still gushed through his fingers. I
 * flew to him, for the Holy circle did not now keep me back; so did the
 * two doctors. Jonathan knelt behind him and the wounded man laid back his
 * head on his shoulder. With a sigh he took, with a feeble effort, my hand
 * in that of his own which was unstained. He must have seen the anguish of
 * my heart in my face, for he smiled at me and said:--
 *
 * "I am only too happy to have been of any service! Oh, God!" he cried
 * suddenly, struggling up to a sitting posture and pointing to me, "It was
 * worth for this to die! Look! look!"
 *
 * The sun was now right down upon the mountain top, and the red gleams
 * fell upon my face, so that it was bathed in rosy light. With one impulse
 * the men sank on their knees and a deep and earnest "Amen" broke from all
 * as their eyes followed the pointing of his finger. The dying man
 * spoke:--
 *
 * "Now God be thanked that all has not been in vain! See! the snow is not
 * more stainless than her forehead! The curse has passed away!"
 *
 * And, to our bitter grief, with a smile and in silence, he died, a
 * gallant gentleman.
 *
 *
 *
 *
 *                                   NOTE
 *
 *
 * Seven years ago we all went through the flames; and the happiness of
 * some of us since then is, we think, well worth the pain we endured. It
 * is an added joy to Mina and to me that our boy's birthday is the same
 * day as that on which Quincey Morris died. His mother holds, I know, the
 * secret belief that some of our brave friend's spirit has passed into
 * him. His bundle of names links all our little band of men together; but
 * we call him Quincey.
 *
 * In the summer of this year we made a journey to Transylvania, and went
 * over the old ground which was, and is, to us so full of vivid and
 * terrible memories. It was almost impossible to believe that the things
 * which we had seen with our own eyes and heard with our own ears were
 * living truths. Every trace of all that had been was blotted out. The
 * castle stood as before, reared high above a waste of desolation.
 *
 * When we got home we were talking of the old time--which we could all
 * look back on without despair, for Godalming and Seward are both happily
 * married. I took the papers from the safe where they had been ever since
 * our return so long ago. We were struck with the fact, that in all the
 * mass of material of which the record is composed, there is hardly one
 * authentic document; nothing but a mass of typewriting, except the later
 * note-books of Mina and Seward and myself, and Van Helsing's memorandum.
 * We could hardly ask any one, even did we wish to, to accept these as
 * proofs of so wild a story. Van Helsing summed it all up as he said, with
 * our boy on his knee:--
 *
 * "We want no proofs; we ask none to believe us! This boy will some day
 * know what a brave and gallant woman his mother is. Already he knows her
 * sweetness and loving care; later on he will understand how some men so
 * loved her, that they did dare much for her sake."
 *
 * JONATHAN HARKER.
 */
#endif // DOXYGEN_TEST_PAGES

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

import static java.lang.System.out;

public enum Dictionary {
    ADVERB("adverb", "noun", " Adverb is a word that adds more infomation about place, time, manner, cause or degree to a verb, an adjective, a phrase or another adverb."),
    ARROW("Arrow", "noun", " Here is one arrow: <IMG> -=>> </IMG>"),
    BOOK1("book", "noun", " A set of pages."),
    BOOK2("book", "noun", " A written work published in printed or electronic form."),
    BOOK3("book", "verb", " To arrange for someone to have a seat on a plane."),
    BOOK4("book", "verb", " To arrange something on a particular date."),
    CSC220_1("csc220", "adjective", " Ready to create complex data structures."),
    CSC220_2("csc220", "verb", " To create data structures"),
    CSC340_1("csc340", "adjective", " C++ version of CSC210 + CSC220 + mpre."),
    CSC340_2("csc340", "noun", " A CS upper division course."),
    CSC340_3("csc340", "noun", " Many hours outside of class."),
    CSC340_4("csc340", "noun", " Programing Methodology."),
    DISTINCT1("Distinct", "adjective", " Familiar. Worked in Java."),
    DISTINCT2("Distinct", "adjective", " Unique. No Duplicates. Clearly different or of a different kind."),
    DISTINCT3("Distinct", "adverb", "Uniquely. Written 'distincly'."),
    DISTINCT4("Distinct", "noun", " A keyword in this assignment."),
    DISTINCT5("Distinct", "noun", " A keyword in this assignment."),
    DISTINCT6("Distinct", "noun", " A keyword in this assignment."),
    DISTINCT7("Distinct", "noun", " An advanced search option."),
    DISTINCT8("Distinct", "noun", " Distinct is a parameter in this assignment."),
    INTERJECTION("interjection", "noun", "Interjection is a short sound, word or phrase spoken suddenly to express an emotion. oh!, Look out! and Ow! are interjections."),
    NOUN("noun", "noun", " is a word that refers to a person, (such as Ann or doctor), a place (such as Paris or city), or thing, a quality or an activity (such as plant, sorrow or tennis."),
    PLACEHOLDER1("Placeholder", "adjective", "To be updated..."),
    PLACEHOLDER10("Placeholder", "pronoun", "To be updated..."),
    PLACEHOLDER11("Placeholder", "verb", "To be updated..."),
    PLACEHOLDER2("Placeholder", "adjective", "To be updated..."),
    PLACEHOLDER3("Placeholder", "adverb", "To be updated..."),
    PLACEHOLDER4("Placeholder", "conjunction", "To be updated..."),
    PLACEHOLDER5("Placeholder", "interjection", "To be updated..."),
    PLACEHOLDER6("Placeholder", "noun", "To be updated..."),
    PLACEHOLDER7("Placeholder", "noun", "To be updated..."),
    PLACEHOLDER8("Placeholder", "noun", "To be updated..."),
    PLACEHOLDER9("Placeholder", "preposition", "To be updated...");

    protected final String general = "Vocabulary";
    private String keyWord;
    private String partOfSpeech;
    private String definition;


    Dictionary(String keyWord, String partOfSpeech, String definition) {
        this.keyWord = keyWord;
        this.partOfSpeech = partOfSpeech;
        this.definition = definition;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        out.println("! Loading data...");


        HashMap<String, ArrayList<Dictionary>> hashmap = new HashMap<String, ArrayList<Dictionary>>();


        for (Dictionary dictionary : Dictionary.values()) {


            String keyWord = dictionary
                    .getKeyWord();


            ArrayList<Dictionary> list = (hashmap.containsKey(keyWord)) ? hashmap.get(keyWord) : new ArrayList<Dictionary>();
            list.add(dictionary);
            hashmap.put(keyWord, list);
        }

        out.println("! Loading Complete...");


        out.println("\nIf you would like to exit the program enter \"stop\" \n");

        Boolean stop = true;


        do {

            out.print("Search: ");
            String userinput = input.nextLine();
            String[] split = userinput.split(" ");

            String word = null;
            Boolean requestDistinct = false;
            String partOfSpeech = null;

            if (split.length > 0) {
                word = split[0];
            }

            String[] partOfSpeeches = {"noun", "verb", "adjective", "adverb", "pronoun", "preposition", "conjunction", "interjection"};
            if (split.length > 1 && split[1]!= null) {
                if (split[1].equalsIgnoreCase("distinct")) {
                    requestDistinct = true;
                } else if (Arrays.asList(partOfSpeeches).contains(split[1].toLowerCase())){
                    partOfSpeech = split[1];
                } else {
                    out.println("|");
                    out.println(" <2nd argument must be a part of speech or \"distinct\">");
                    out.println("|");
                    continue;
                }
            }
            if (split.length > 2 && split[2]!= null) {
                if (split[2].equalsIgnoreCase("distinct")) {
                    requestDistinct = true;
                } else if (Arrays.asList(partOfSpeeches).contains(split[2].toLowerCase())){
                    partOfSpeech = split[2];
                } else {
                    out.println("|");
                    out.println(" <2nd argument must be a part of speech or \"distinct\">");
                    out.println("|");
                    continue;
                }
            }

            if(!userinput.equalsIgnoreCase("stop")) {
                out.println("|");
                ArrayList<Dictionary> result = hashmap.get(word.toUpperCase());
                ArrayList<Dictionary> secondResult = (requestDistinct) ? returnDictionaryWithDistinctPartOfSpeech(result) : result;
                ArrayList<Dictionary> thirdResult = (partOfSpeech != null) ? returnDictionaryWithSamePartOfSpeech(secondResult, partOfSpeech) : secondResult;
                //System.exit(0);////////////////////
                if (thirdResult != null && thirdResult.size()>0) {
                    for(Dictionary key : thirdResult) {
                        out.print("    " + key + "\n");
                    }
                } else {
                    out.println("<Not Found>");
                }
                out.println("|");
            } else {
                out.println("\n----Thank You---");
                System.exit(0);
                stop = false;


            }


        } while(stop);


    }

    public static ArrayList<Dictionary> returnDictionaryWithDistinctPartOfSpeech(ArrayList<Dictionary> dictionaryList) {
        HashMap<String, Dictionary> hashMap = new HashMap<String, Dictionary>();
        if (dictionaryList != null) {
            for(Dictionary dictionary : dictionaryList) {
                String partOfSpeech = dictionary.partOfSpeech();
                if(!hashMap.containsKey(partOfSpeech)) {
                    hashMap.put(partOfSpeech, dictionary);
                }
            }
        }
        return new ArrayList<Dictionary>(hashMap.values());
    }

    public static ArrayList<Dictionary> returnDictionaryWithSamePartOfSpeech(ArrayList<Dictionary> dictionaryList, String partOfSpeech) {
        ArrayList<Dictionary> result = new ArrayList<Dictionary>();
        if (dictionaryList != null) {
            for(Dictionary dictionary : dictionaryList) {
                if (dictionary.partOfSpeech().equalsIgnoreCase(partOfSpeech)) {
                    result.add(dictionary);
                }
            }
        }
        return result;
    }

    public String getKeyWord() {
        return this.keyWord.toUpperCase();
    }

    public String partOfSpeech() {
        return this.partOfSpeech;
    }

    @Override
    public String toString() {
        return this.keyWord + " [" + this.partOfSpeech + "] : " + this.definition;
    }
}

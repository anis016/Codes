package wonders;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Objects;

// Use assertions in try block to avoid OBL_UNSATISFIED_OBLIGATION
public class TryButNotCatch {

    static void readJson() throws IOException, ParseException {
        ClassLoader classLoader = Thread.currentThread().getClass().getClassLoader();
        final String inputJsonPath = Objects.requireNonNull(classLoader.getResource("sample.json")).getPath();

        try(InputStream inputStream = new FileInputStream(inputJsonPath);
            Reader fileReader = new InputStreamReader(inputStream, StandardCharsets.UTF_8)) {

            JSONParser parser = new JSONParser();
            Object object = parser.parse(fileReader);
            JSONObject jsonObject = (JSONObject) object;
            JSONArray msg = (JSONArray) jsonObject.get("colors");

            assert msg.size() == 6;

            for (Object iterator : msg) {
                System.out.println(iterator);
            }

            // Assertions.assertSOMETHNG();
        }
    }

    public static void main(String... args) throws IOException, ParseException {
        readJson();
    }
}

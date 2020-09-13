package common;

import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Collectors;

public class Commons {

    public static List<String> getFilePath(String fileName) throws IOException {
        ClassLoader loader = Thread.currentThread().getContextClassLoader();
        URL resource = loader.getResource(fileName);
        assert resource != null;
        return Files.lines(Paths.get(resource.getPath())).collect(Collectors.toList());
    }
}

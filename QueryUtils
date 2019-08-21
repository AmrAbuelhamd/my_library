package com.example.android.quakereport;

import android.text.TextUtils;
import android.util.Log;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;

import javax.net.ssl.HttpsURLConnection;

/**
 * Helper methods related to requesting and receiving earthquake data from USGS.
 */
public final class QueryUtils {

    public static final String LOG_TAG = EarthquakeActivity.class.getName();



    /**
     * Create a private constructor because no one should ever create a {@link QueryUtils} object.
     * This class is only meant to hold static variables and methods, which can be accessed
     * directly from the class name QueryUtils (and an object instance of QueryUtils is not needed).
     */
    private QueryUtils() {
    }

    /**
     * Return a list of {@link Earthquake} objects that has been built up from
     * parsing a JSON response, that is extracted from the url, that is made up here.
     * @param ussgsUrl
     */
    public static List<Earthquake> fetchEarthquakeData(String ussgsUrl) {

        //creaete the url
        URL url = makeUrl(ussgsUrl);

        //get the json response from the server

        String jsonResponse = "";
        try {
            jsonResponse = makeHttpRequest(url);
        }catch (IOException e){
            Log.e("myerror",e.toString());
        }

        // Return the list of earthquakes
        return extractFeatureFromJson(jsonResponse);
    }

    private static List<Earthquake> extractFeatureFromJson(String jsonResponse) {
        // If the JSON string is empty or null, then return early.
        if (TextUtils.isEmpty(jsonResponse)) {
            return null;
        }

        // Create an empty ArrayList that we can start adding earthquakes to
        List<Earthquake> earthquakes = new ArrayList<>();

        // Try to parse the SAMPLE_JSON_RESPONSE. If there's a problem with the way the JSON
        // is formatted, a JSONException exception object will be thrown.
        // Catch the exception so the app doesn't crash, and print the error message to the logs.
        try {
            JSONObject root = new JSONObject(jsonResponse);
            JSONArray earthquakeArray = root.getJSONArray("features");
            for (int i = 0; i < earthquakeArray.length(); i++){

                JSONObject currentEarthquake = earthquakeArray.getJSONObject(i);
                JSONObject properties = currentEarthquake.getJSONObject("properties");

                double mag = properties.getDouble("mag");
                String location = properties.getString("place");
                Long epcheDateTime = properties.getLong("time");
                String earthquakeUrl = properties.getString("url");

                earthquakes.add(new Earthquake(mag,location, epcheDateTime,earthquakeUrl));
            }
        } catch (JSONException e) {
            // If an error is thrown when executing any of the above statements in the "try" block,
            // catch the exception here, so the app doesn't crash. Print a log message
            // with the message from the exception.
            Log.e("QueryUtils", "Problem parsing the earthquake JSON results", e);
        }
        return earthquakes;
    }

    private static String makeHttpRequest(URL url) throws IOException {
        String jsonResponse = "";

        if(url == null)
            return jsonResponse;

        InputStream stream = null;
        HttpsURLConnection connection = null;

        try {
            connection = (HttpsURLConnection) url.openConnection();
            // Timeout for reading InputStream arbitrarily set to 3000ms.
            connection.setReadTimeout(3000);
            // Timeout for connection.connect() arbitrarily set to 3000ms.
            connection.setConnectTimeout(3000);
            // For this use case, set HTTP method to GET.
            connection.setRequestMethod("GET");
            // Already true by default but setting just in case; needs to be true since this request
            // is carrying an input (response) body.
            connection.setDoInput(true);
            // Open communications link (network traffic occurs here).
            connection.connect();

            int responseCode = connection.getResponseCode();
            if (responseCode == HttpsURLConnection.HTTP_OK) {
                // Retrieve the response body as an InputStream.
                stream = connection.getInputStream();
                jsonResponse = readStream(stream);

            }else {
                Log.e(LOG_TAG,"Error response cond "+responseCode);
            }
        }catch (IOException e) {
            Log.e(LOG_TAG, "Problem retrieving the earthquake JSON results.", e);
        } finally {
            // Close Stream and disconnect HTTPS connection.
            if (stream != null) {
                stream.close();
            }
            if (connection != null) {
                connection.disconnect();
            }
        }
        return jsonResponse;
    }

    private static String readStream(InputStream inputStream) throws IOException {

        StringBuilder output = new StringBuilder();
        if (inputStream != null) {
            InputStreamReader inputStreamReader = new InputStreamReader(inputStream, Charset.forName("UTF-8"));
            BufferedReader reader = new BufferedReader(inputStreamReader);
            String line = reader.readLine();
            while (line != null) {
                output.append(line);
                line = reader.readLine();
            }
        }
        return output.toString();
    }

    private static URL makeUrl(String ussgsUrl) {
        URL url = null;
        try {
            url = new URL(ussgsUrl);
        } catch (MalformedURLException e) {
            Log.e("myerror",e.toString());
        }
        return url;
    }


}

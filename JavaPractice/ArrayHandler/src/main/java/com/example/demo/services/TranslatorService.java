package com.example.demo.services;

import com.example.demo.models.DTOs.TranslatorRequestDTO;
import com.example.demo.models.DTOs.TranslatorResponseDTO;
import org.springframework.stereotype.Service;

@Service
public class TranslatorService {

    private TranslatorResponseDTO translate(TranslatorRequestDTO toTranslate) {
        String[] vowels = {"a", "e", "i", "o", "u", "é", "É", "á", "Á", "A", "E", "I", "O", "U"};
        String temp = toTranslate.getText();
        for (String vowel : vowels) {
            temp = temp.replaceAll(vowel, (vowel + "v" + vowel.toLowerCase()));
        }
        return new TranslatorResponseDTO(temp, "teve");
    }

    public TranslatorResponseDTO translatorResponse(TranslatorRequestDTO translatorRequest) {
        if (    translatorRequest != null &&
                translatorRequest.getLang() != null &&
                translatorRequest.getText() != null) {

            return translate(translatorRequest);
        } else {
            throw new IllegalArgumentException("I can't translate that shiet!");
        }
    }
}

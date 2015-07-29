package com.ciandt.hackathon.bitcoin.roulette.service;

import java.util.UUID;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class RoulleteService {

	@RequestMapping(value = "/", method = RequestMethod.GET)
    @ResponseBody
    public String healthcheck() {
        return UUID.randomUUID().toString();
    }
}
